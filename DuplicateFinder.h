#pragma once
#include <iostream>
#include <fstream>
#include <filesystem>
#include <unordered_map>
#include <vector>
#include <string>
#include <mutex>
#include <queue>
#include <condition_variable>

namespace fs = std::filesystem;

// Logging (nur im Debug-Modus)
#ifdef _DEBUG
#define LOG(msg) std::cout << "[DEBUG]: " << msg << std::endl
#else
#define LOG(msg)
#endif

class DuplicateFinder {
public:
    void findDuplicates(const std::string& path);
    void writeResults(const std::string& outputFile);

private:
    std::unordered_map<std::string, std::vector<std::pair<fs::path, uintmax_t>>> duplicates;
    std::mutex mtx;

    std::string calculateFileHash(const fs::path& filePath);
    void processFile(const fs::path& filePath);

    // Multithreading
    std::queue<fs::path> fileQueue;
    std::mutex queueMutex;
    std::condition_variable cv;
    bool done = false;

    void worker();
};
