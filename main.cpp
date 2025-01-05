#include "DuplicateFinder.h"

int main(int argc, char* argv[]) {
    DuplicateFinder finder;

    // Verzeichnis festlegen
    fs::path path = (argc > 1) ? fs::path(argv[1]) : fs::current_path();
    fs::path outputFilePath = "duplicates.txt";

    if (!fs::exists(path) || !fs::is_directory(path)) {
        std::cerr << "Ungültiges Verzeichnis: " << path << "\n";
        return 1;
    }

    std::cout << "Scanne Verzeichnis: " << path << "\n";

    finder.ScanDirectory(path);
    finder.PrintDuplicates(outputFilePath);

    return 0;
}