#include "DuplicateFinder.h"

int main(int argc, char* argv[]) {
    std::string path = (argc > 1) ? argv[1] : ".";
    std::string outputFile = "duplicates.txt";

    DuplicateFinder finder;
    finder.findDuplicates(path);
    finder.writeResults(outputFile);

    std::cout << "Duplikatsuche abgeschlossen. Ergebnisse in '" << outputFile << "' gespeichert.\n";
    return 0;
}