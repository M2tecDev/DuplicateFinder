#include "DuplicateFinder.h"

// Timer-Implementierung
Timer::Timer(const std::string& task) : task_(task), start_time_(std::chrono::high_resolution_clock::now()) {
#ifdef _DEBUG
    std::cout << "Timer gestartet: " << task_ << std::endl;
#endif
}

Timer::~Timer() {
#ifdef _DEBUG
    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time_).count();
    std::cout << "Timer gestoppt: " << task_ << ", Dauer: " << duration << " ms\n";
#endif
}

// Hash-Berechnung für Dateien
std::string DuplicateFinder::CalculateHash(const fs::path& filePath) {
    std::ifstream file(filePath, std::ios::binary);
    if (!file) return "";

    std::ostringstream oss;
    std::vector<char> buffer(4096);

    while (file.read(buffer.data(), buffer.size()) || file.gcount()) {
        std::streamsize bytesRead = file.gcount();
        oss << std::string(buffer.data(), static_cast<std::size_t>(bytesRead));
    }

    return std::to_string(std::hash<std::string>{}(oss.str())); // Beispiel-Hash
}

// Scannt ein Verzeichnis nach Dateien und prüft Duplikate
void DuplicateFinder::ScanDirectory(const fs::path& path) {
#ifdef _DEBUG
    Timer timer("ScanDirectory");
#endif

    for (const auto& entry : fs::recursive_directory_iterator(path)) {
        if (!fs::is_regular_file(entry)) continue;

        std::string fileName = entry.path().filename().string();
        std::string hash = CalculateHash(entry.path());

        std::lock_guard<std::mutex> lock(mutex_);
        duplicates_[fileName][hash].push_back(entry.path());
    }
}

// Gibt die gefundenen Duplikate in eine Datei aus
void DuplicateFinder::PrintDuplicates(const fs::path& outputFilePath) {
    std::ofstream outFile(outputFilePath);
    if (!outFile) {
        std::cerr << "Fehler beim Öffnen der Ausgabedatei: " << outputFilePath << "\n";
        return;
    }

    for (const auto& [fileName, hashMap] : duplicates_) {
        for (const auto& [hash, paths] : hashMap) {
            if (paths.size() > 1) {
                outFile << "Datei: " << fileName << "\n";
                for (const auto& path : paths) {
                    outFile << " - " << path << "\n";
                }
                outFile << "-----------------------------\n";
            }
        }
    }

    std::cout << "Duplikate wurden in die Datei '" << outputFilePath << "' geschrieben.\n";
}