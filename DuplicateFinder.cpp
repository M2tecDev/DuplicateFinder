#include "DuplicateFinder.h"
#include <sstream>
#include <iomanip>
#include <thread>
#include <chrono>

// Hilfsfunktion zur Formatierung der Dateigröße
std::string formatFileSize(uintmax_t size) {
    std::ostringstream oss;
    if (size < 1024)
        oss << size << " B";
    else if (size < 1024 * 1024)
        oss << std::fixed << std::setprecision(2) << (size / 1024.0) << " KB";
    else
        oss << std::fixed << std::setprecision(2) << (size / (1024.0 * 1024.0)) << " MB";
    return oss.str();
}

// Hashing von Datei-Inhalten
std::string DuplicateFinder::calculateFileHash(const fs::path& filePath) {
    std::ifstream file(filePath, std::ios::binary);
    if (!file) {
        LOG("Fehler beim Öffnen der Datei: " << filePath);
        return "";
    }

    std::ostringstream oss;
    char buffer[4096];
    while (file.read(buffer, sizeof(buffer)) || file.gcount()) {
        oss.write(buffer, file.gcount());
    }

    return std::to_string(std::hash<std::string>{}(oss.str()));
}

// Datei verarbeiten
void DuplicateFinder::processFile(const fs::path& filePath) {
    try {
        auto hash = calculateFileHash(filePath);
        if (!hash.empty()) {
            std::lock_guard<std::mutex> lock(mtx);

            // Gruppierung nach Hash **und** Dateiname
            std::string key = hash + "_" + filePath.filename().string();
            duplicates[key].emplace_back(filePath, fs::file_size(filePath));
        }
    }
    catch (const std::exception& e) {
        LOG("Fehler bei der Verarbeitung von " << filePath << ": " << e.what());
    }
}

// Worker-Thread-Funktion
void DuplicateFinder::worker() {
    while (true) {
        fs::path filePath;

        {
            std::unique_lock<std::mutex> lock(queueMutex);
            cv.wait(lock, [this]() { return !fileQueue.empty() || done; });

            if (done && fileQueue.empty()) {
                return;
            }

            filePath = std::move(fileQueue.front());
            fileQueue.pop();
        }

        processFile(filePath);
    }
}

// Duplikate finden
void DuplicateFinder::findDuplicates(const std::string& path) {
    LOG("Starte Duplikatsuche in: " << path);

    auto start = std::chrono::high_resolution_clock::now(); // Zeitmessung starten

    // Dateien in die Queue laden
    for (const auto& entry : fs::recursive_directory_iterator(path)) {
        if (entry.is_regular_file()) {
            std::lock_guard<std::mutex> lock(queueMutex);
            fileQueue.push(entry.path());
            cv.notify_one();
        }
    }

    // Worker-Threads starten
    const int threadCount = std::thread::hardware_concurrency();
    std::vector<std::thread> threads;

    for (int i = 0; i < threadCount; ++i) {
        threads.emplace_back(&DuplicateFinder::worker, this);
    }

    {
        std::lock_guard<std::mutex> lock(queueMutex);
        done = true;
    }
    cv.notify_all();

    // Warten, bis alle Threads abgeschlossen sind
    for (auto& t : threads) {
        if (t.joinable()) {
            t.join();
        }
    }

    auto end = std::chrono::high_resolution_clock::now(); // Zeitmessung stoppen
    std::chrono::duration<double> elapsed = end - start;

#ifdef _DEBUG
    std::cout << std::fixed << std::setprecision(2)
        << "Duplikatsuche abgeschlossen in " << elapsed.count() << " Sekunden.\n";
#endif

    LOG("Duplikatsuche abgeschlossen.");
}

// Ergebnisse in eine Datei schreiben
void DuplicateFinder::writeResults(const std::string& outputFile) {
    std::ofstream outFile(outputFile);
    if (!outFile) {
        LOG("Fehler beim Öffnen der Ausgabedatei: " << outputFile);
        return;
    }

    for (const auto& [key, files] : duplicates) {
        if (files.size() > 1) {
            outFile << "Datei: " << files[0].first.filename().string()
                << " (Größe: " << formatFileSize(files[0].second) << ")\n";

            for (const auto& [path, size] : files) {
                outFile << " - " << path.string() << "\n";
            }
            outFile << "-----------------------------\n";
        }
    }

    LOG("Ergebnisse wurden in die Datei geschrieben: " << outputFile);
}
