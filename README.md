# 📄 **Duplicate Finder**

## 📚 **Inhaltsverzeichnis / Table of Contents**
- [Über das Projekt / About the Project](#über-das-projekt--about-the-project)  
- [Funktionen / Features](#funktionen--features)  
- [Systemanforderungen / System Requirements](#systemanforderungen--system-requirements)  
- [Installation und Verwendung / Installation and Usage](#installation-und-verwendung--installation-and-usage)  
- [Beispielausgabe / Example Output](#beispielausgabe--example-output)  
- [Lizenz / License](#lizenz--license)  

---

## 🛠️ **Über das Projekt / About the Project**

**Deutsch:**  
Dieses Projekt ist ein leistungsfähiges Konsolen-Tool, das doppelte Dateien basierend auf ihrem **Dateinamen** erkennt und deren Pfade in einer übersichtlichen Textdatei ausgibt. Es unterstützt sowohl rekursives Scannen von Ordnern als auch Multithreading für optimale Leistung.

**English:**  
This project is a powerful console tool designed to identify duplicate files based on their **file names** and output their paths into a clear text file. It supports both recursive folder scanning and multithreading for optimal performance.

---

## 🚀 **Funktionen / Features**

- 🔍 **Rekursives Scannen von Verzeichnissen / Recursive Directory Scanning**  
- ⚡ **Multithreading für bessere Performance / Multithreading for Improved Performance**  
- 📄 **Ausgabe in eine Textdatei (`duplicates.txt`) / Output to a Text File (`duplicates.txt`)**  
- 🕒 **Timer für Debug-Performance-Messungen / Timer for Debug Performance Measurements**  
- 🛡️ **Unterstützung von Windows 8, 10, 11 / Support for Windows 8, 10, 11**  

---

## 💻 **Systemanforderungen / System Requirements**

- **Betriebssystem / Operating System:** Windows 8, 10, 11  
- **Compiler:** MSVC mit Toolset v143  
- **C++ Standard:** C++17 oder neuer  

---

## 📦 **Installation und Verwendung / Installation and Usage**

1. **Projekt kompilieren / Compile the Project:**  
   Öffne das Projekt in Visual Studio und stelle sicher, dass das v143 Toolset ausgewählt ist.  
   Select the v143 toolset in Visual Studio and build the project.

2. **Programm starten / Run the Program:**  
   - Ohne Parameter: Scannt das aktuelle Verzeichnis.  
     ```cmd
     DuplicateFinder.exe
     ```
   - Mit Pfad-Parameter: Scannt das angegebene Verzeichnis.  
     ```cmd
     DuplicateFinder.exe "C:\Path\To\Scan"
     ```

3. **Ausgabe überprüfen / Check Output:**  
   Die Ergebnisse werden in der Datei `duplicates.txt` gespeichert.  
   The results will be saved in the `duplicates.txt` file.

---

## 📝 **Beispielausgabe / Example Output**

**duplicates.txt**  
```txt
Datei: example.txt
 - C:\Folder1\example.txt
 - C:\Folder2\example.txt
-----------------------------
Datei: image.jpg
 - C:\Folder\image.jpg
 - C:\Folder\backup\image.jpg
-----------------------------
