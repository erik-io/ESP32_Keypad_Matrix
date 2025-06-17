# ESP32 Keypad Matrix: Anbindung und Tasten-Ausgabe

Dieses Projekt wurde im Rahmen meiner Ausbildung zum Fachinformatiker für Anwendungsentwicklung realisiert. Ziel war es, die Grundlagen der Mikrocontroller-Programmierung mit dem ESP32 zu vertiefen, indem ein externes 4x4-Tastenfeld angebunden und dessen Eingaben verarbeitet werden.

### Projektübersicht

Das System liest die auf einem 4x4-Matrix-Keypad gedrückten Tasten aus und gibt das entsprechende Zeichen über die serielle Konsole aus. Dies bildet die Grundlage für komplexere Anwendungen wie Zugangskontrollsysteme, Smart-Home-Steuerungen oder Bedienfelder für Maschinen.

### Technische Umsetzung

Die Architektur basiert auf einem ESP32-Board, das über definierte GPIO-Pins mit den Reihen- und Spaltenleitungen des Keypads verbunden ist. Die Programmierung erfolgte in C++ unter Verwendung des Arduino-Frameworks und der `Keypad.h`-Bibliothek, welche die Abfrage der Tastenmatrix erheblich vereinfacht. Ein wesentlicher Aspekt des Codes ist die `keyMap`, die das Layout der physischen Tasten auf die gewünschten Zeichen abbildet.

Ein `if (key != NO_KEY)`-Statement in der Hauptschleife `loop()` stellt sicher, dass nur gültige Tastendrücke verarbeitet werden, um unerwünschtes Verhalten zu vermeiden.

### Herausforderungen und Lösungsansätze

Während der Inbetriebnahme traten zunächst Probleme auf, bei denen falsche oder gar keine Zeichen ausgegeben wurden. Die systematische Fehlersuche war ein zentraler Lerninhalt des Projekts:

1.  **Pin-Konflikte:** Die anfängliche Annahme über die Pinbelegung des Keypads war fehlerhaft.
    
2.  **Diagnose:** Mithilfe eines Multimeters im Durchgangsprüfungsmodus konnte ich die exakte Zuordnung der Reihen- und Spalten-Pins des Keypads identifizieren.
    
3.  **Korrektur:** Nach der Identifizierung der korrekten Pins wurden sowohl die physische Verkabelung als auch die Pin-Definitionen im Code (`rowPins` und `colPins`) entsprechend angepasst.
    
4.  **Debouncing:** Zur Sicherstellung einer stabilen Tastenerkennung wurde eine `debounceTime` von 5 ms konfiguriert, um das Prellen der mechanischen Kontakte zu filtern.
    

Dieses Projekt hat mein Verständnis für die Interaktion von Hard- und Software geschärft und mir gezeigt, wie wichtig eine strukturierte, methodische Fehlersuche bei der Embedded-Entwicklung ist.
