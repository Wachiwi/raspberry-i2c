# Projektarbeit Raspberry Pi - I²C-Daten mittels Qt-GUI anzeigen

### Aufgabe

Die Aufgabe dieser Projektarbeit bezieht sich auf einen Ultraschallsensor als I²C-Slave. Ziel ist es, eine Anwendung mit grafischer Benutzerschnittstelle auf Basis der Qt-Bibliothek zu erstellen, welche eine Widget-Applikation zur Darstellung von Daten des möglichen I²C-Slaves realisiert.

Dabei besteht die Projektarbeit aus 2 separaten Programmen:

1. Auslesen der Daten vom I²C-Gerät über eine C-Anwendung und zeilenweises Schreiben der ermittelten Daten in eine Textdatei.

2. Darstellung der in der Textdatei fortlaufend geschriebenen Daten über eine in C++ geschriebene QT-GUI-Anwendung. Dabei soll ein zweidimensionales Diagramm der aufgenommen Werte des Ultraschallsensors bzw. das aktuell gültige Muster der LED-Matrix dargestellt werden.

Die beiden Anwendungen sollen auf dem ausgegebenen Raspberry Pi lauffähig sein (ARM-Architektur). Zur Entwicklung des C++-Programms bietet Qt eine eigene Entwicklungsumgebung an, den Qt-Creator.

### Anforderungen

Um die Problematik der Schreib-/Lese-Synchronisation zu umgehen, wird immer der Wert der vorletzten Zeile der Textdatei visualisiert. Die gelesenen Werte des Ultraschallsensors sollen in der GUI-Anwendung graphisch ausgegeben werden, der neueste Wert zudem wenn möglich auch in einem Textfeld. Zur Visualisierung wird die Bibliothek QCustomPlot verwendet.

### Testprotokoll

- [x] I²C Initialisierung
- [x] I²C Master-Slave-Konfiguration
- [x] I²C Kommunikation
- [x] I²C logging to file
- [ ] C++: GUI Event-Handling
- [ ] C++: Auslesen der Messdaten

### Abgabe

Packen Sie Ihre Ergebnisse in ein ZIP-Archiv.

Das Archiv sollte umfassen:

- Quellcode Ihrer Anwendung
- Code-Dokumentation
- Testprotokolle (Bildschirm-Drucke)

### Hinweise

Qt bietet nicht ausschließlich Komponenten zur Erzeugung von grafischen Oberflächen. Es bietet unter anderem auch ausführlich dokumentierte Module zur Kommunikation in Netzwerken oder dem Parsen von XML.

