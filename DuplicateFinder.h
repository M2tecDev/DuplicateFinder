#pragma once
#include <unordered_map>
#include <vector>
#include <filesystem>
#include <mutex>
#include <fstream>
#include <sstream>
#include <iostream>
#include <chrono>

namespace fs = std::filesystem;

// Timer-Klasse für die Laufzeitmessung (Debug-Modus)
class Timer {
public:
    Timer(const std::string& task);
    ~Timer();

private:
    std::string task_;
    std::chrono::time_point<std::chrono::high_resolution_clock> start_time_;
};

class DuplicateFinder {
public:
    void ScanDirectory(const fs::path& path);
    void PrintDuplicates(const fs::path& outputFilePath);

private:
    std::unordered_map<std::string, std::unordered_map<std::string, std::vector<fs::path>>> duplicates_;
    std::mutex mutex_;

    std::string CalculateHash(const fs::path& filePath);
};