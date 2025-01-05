
# 📂 DuplicateFinder

## 📝 Inhaltsverzeichnis / Table of Contents  
- [Beschreibung / Description](#beschreibung--description)  
- [Funktionen / Features](#funktionen--features)  
- [Systemanforderungen / System Requirements](#systemanforderungen--system-requirements)  
- [Installation und Ausführung / Installation and Usage](#installation-und-ausführung--installation-and-usage)  
- [Beispielausgabe / Example Output](#beispielausgabe--example-output)  
- [Lizenz / License](#lizenz--license)  

---

## 📖 Beschreibung / Description  

**Deutsch:**  
DuplicateFinder ist ein Konsolenprogramm, das nach doppelten Dateien sucht, indem es die Inhalte der Dateien vergleicht. Es verwendet Multithreading für schnelle Verarbeitung und unterstützt rekursive Verzeichnisscans. Ergebnisse werden in einer Textdatei (`duplicates.txt`) gespeichert.  

**English:**  
DuplicateFinder is a console application that scans for duplicate files by comparing file contents. It uses multithreading for fast processing and supports recursive directory scans. Results are saved in a text file (`duplicates.txt`).  

---

## 🚀 Funktionen / Features  

**Deutsch:**  
- Multithreaded Dateisuche für maximale Geschwindigkeit  
- Hash-basierte Duplikaterkennung  
- Ausgabe von Duplikaten in einer übersichtlichen Textdatei  
- Unterstützung von rekursiven Scans in Verzeichnissen  
- Ausgabe der Verarbeitungsdauer im Debug-Modus  

**English:**  
- Multithreaded file scanning for maximum speed  
- Hash-based duplicate detection  
- Outputs duplicates in a neatly formatted text file  
- Supports recursive directory scanning  
- Displays processing time in debug mode  

---

## 💻 Systemanforderungen / System Requirements  

- Windows 8, 10, 11  
- Visual Studio 2022 mit Toolset **v143**  
- C++17 oder neuer  

---

## ⚙️ Installation und Ausführung / Installation and Usage  

**Deutsch:**  
1. Klone das Repository oder lade es herunter:  
   ```sh
   git clone https://github.com/M2tecDev/DuplicateFinder.git
   ```
2. Öffne das Projekt in **Visual Studio 2022**.  
3. Baue das Projekt im **Release-Modus**.  
4. Starte das Programm:  
   ```sh
   DuplicateFinder.exe [Pfad]
   ```
   - Ohne Parameter: Scannt das aktuelle Verzeichnis.  
   - Mit Parameter: Scannt das angegebene Verzeichnis.  

**English:**  
1. Clone the repository or download it:  
   ```sh
   git clone https://github.com/M2tecDev/DuplicateFinder.git
   ```
2. Open the project in **Visual Studio 2022**.  
3. Build the project in **Release mode**.  
4. Run the program:  
   ```sh
   DuplicateFinder.exe [path]
   ```
   - Without a parameter: Scans the current directory.  
   - With a parameter: Scans the specified directory.  

---

## 📊 Beispielausgabe / Example Output  

**Deutsch:**  
```
Datei: example.txt (Größe: 1.45 KB)
 - C:\Ordner1\example.txt
 - C:\Ordner2\example.txt
-----------------------------

Datei: image.jpg (Größe: 2.5 MB)
 - C:\Bilder\image.jpg
 - C:\Backup\image.jpg
-----------------------------
```

**English:**  
```
File: example.txt (Size: 1.45 KB)
 - C:\Folder1\example.txt
 - C:\Folder2\example.txt
-----------------------------

File: image.jpg (Size: 2.5 MB)
 - C:\Images\image.jpg
 - C:\Backup\image.jpg
-----------------------------
```

---

## 📜 Lizenz / License  

**Deutsch:**  
Dieses Projekt steht unter der **MIT-Lizenz**. Weitere Informationen findest du in der Datei [LICENSE](LICENSE).  

**English:**  
This project is licensed under the **MIT License**. See the [LICENSE](LICENSE) file for details.  

---

## 🤝 Beitrag / Contributing  

**Deutsch:**  
Beiträge sind willkommen! Bitte erstelle einen **Pull-Request** oder öffne ein **Issue**, um Änderungen vorzuschlagen.  

**English:**  
Contributions are welcome! Please create a **Pull Request** or open an **Issue** to suggest changes.  

---

## 📬 Kontakt / Contact  

**Entwickler / Developer:** [M2tecDev](https://github.com/M2tecDev)  
**Repository:** [DuplicateFinder](https://github.com/M2tecDev/DuplicateFinder)  
