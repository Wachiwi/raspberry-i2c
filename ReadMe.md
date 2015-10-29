# Projektarbeit Raspberry Pi (RPi): 

## I²C-Daten mittels Qt-GUI anzeigen

### Aufgabe

Die Aufgabe dieser Projektarbeit bezieht sich auf zwei verschiedene I²C-Slaves: Ultraschallsensor und LED-Matrix. Ziel ist es, eine Anwendung mit grafischer Benutzerschnittstelle auf Basis der Qt-Bibliothek zu erstellen, welche eine Widget-Applikation zur Darstellung von Daten eines der beiden möglichen I²C-Slaves realisiert.

Dabei besteht die Projektarbeit aus 2 separaten Programmen:

1. Auslesen der Daten vom jeweiligen I²C-Gerät über eine C-Anwendung und zeilenweises Schreiben der ermittelten Daten in eine Textdatei.

2. Darstellung der in der Textdatei fortlaufend geschriebenen Daten über eine in C++ geschriebene QT-GUI-Anwendung. Dabei soll ein zweidimensionales Diagramm der aufgenommen Werte des Ultraschallsensors bzw. das aktuell gültige Muster der LED-Matrix dargestellt werden.

Die beiden Anwendungen sollen auf dem ausgegebenen Raspberry Pi lauffähig sein (ARM-Architektur). Zur Entwicklung des C++-Programms bietet Qt eine eigene Entwicklungsumgebung an, den Qt-Creator. Informationen zur Nutzung und Konfiguration dieses Programms und der zur Verfügung gestellten VM bzw. des RPi's entnehmen Sie bitte den weiteren Projekt-Dokumenten.

### Anforderungen
Die Beschreibung für das Auslesen der beiden I²C-Geräte entnehmen Sie bitte ebenfalls den weiteren Projektdokumenten.

Um die Problematik der Schreib-/Lese-Synchronisation zu umgehen, wird immer der Wert der vorletzten Zeile der Textdatei visualisiert. Die gelesenen Werte des Ultraschallsensors sollen in der GUI-Anwendung graphisch ausgegeben werden, der neueste Wert zudem wenn möglich auch in einem Textfeld. Zur Visualisierung nutzen Sie bitte die Bibliothek QCustomPlot o.ä.. Das aktuelle Muster der LED-Matrix soll sowohl graphisch, z.B. in Form einer Button-Matrix mit veränderlicher Hintergrundfarbe, als auch zeilenweise in Textform ausgegeben werden (z.B. LED's der ersten Zeile leuchten alle → Ausgabe 0xff).

### Abgabe

Packen Sie Ihre Ergebnisse in ein ZIP-Archiv und laden Sie dieses hoch.

Das Archiv sollte umfassen:

- Quellcode Ihrer Anwendung
- Code-Dokumentation
- Testprotokolle (Bildschirm-Drucke)

Hinweise
Qt bietet nicht ausschließlich Komponenten zur Erzeugung von grafischen Oberflächen. Es bietet unter anderem auch ausführlich dokumentierte Module zur Kommunikation in Netzwerken oder dem Parsen von XML.

