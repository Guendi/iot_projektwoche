---
title: Arduino oder ESP-basierte Gamesteuerung
subtitle: IoT - Kursprojekt
author: <img src="../img/title.jpg" style="max-width:400px"/>

---
# Aktueller Zustand

Prototypische Implementierung auf LoLin NodeMCU V3, RobiGame ist auf Laptop installiert

**Game:**

	* erster Robi ist vom Micocontroller steuerbar
	* andere Robis sind KI-gesteuert
	* UDP-Kommunikation funktional und für mehrere Controller vorbereitet
	* **TODO:** Zustandautomat zum anmelden mehrerer Controller muss noch implementiert werden
	* **TODO:** Kommunikationsprotokoll für *bullets* erweitern
	* **TODO:** Debugging-Console wenn Game ohne Eclipse-IDE gestartet wird

# Projektbeschreibung

Das Nintendo Wii war seinerzeit sehr erfolgreich, weil sich die Spieler zur Steuerung bewegen mussten anstatt am PC zu hocken. Sie erstellen für ein einfaches 2D-PC-Spiel eine ähnliche Fernsteuerung mit Microcontroller(n).

Für die Kommunikation mit dem Game setzen Sie das UDP-Protokoll ein.

## Stufe 1:

Sie kontrollieren die Bewegung (hoch-runter, rechts-links) des ersten Roboters über den Lagesensor ADXL345, dessen Werte permanent vom Microcontroller an den Spiele-PC geschickt werden.

## Stufe 2:

Sie können das Spiel mit mehreren Personen (je ein Controller kontrolliert je einen Roboter) spielen.

## Stufe 3

Das Spiel bietet die Möglichkeit, gegnerische Roboter mit *bullets* zu betäuben. Schaffen Sie eine Möglichkeit, per Tasterdruck (am Microcontroller) *bullets* in der aktuellen Richtung abzufeuern.

# Vorgehen

Gehen Sie nach dem *Teile und herrsche* Prinzip vor und erarbeiten Sie sich zunächst Teillösungen: 

1. Spielen Sie eine Runde Robi-Game mit der Tastatur. 

2. Informieren Sie sich über die Funktionsweise des ADXL345 mit dem Arduino UNO R3. Visualisieren Sie die Messwerte über den seriellen Monitor der Arduino-IDE. Was beobachten Sie, wenn Sie die Lage des Sensors verändern? Wie können Sie saubere Bewegungen aufgrund der Messwerte realisieren?

3. Lesen Sie den Quellcode der Klassen `RemoteServerUdp.java` und `RobiMoveProtocol.java`. Was ist Microcontroller-seitig für die Spielsteuerung zu bewerkstelligen? Sorgen Sie auf Ihrer Zielhardware (Arduino+Ethercard oder ESP+WiFi) dafür, dass eine Kommunikation mit dem Game_PC zustande kommt. Beim Anschluss des ESP an die Arduino-IDE muss ggf. noch das richtige Board über den Boardmanager installiert werden.

4. Fügen Sie 2. und 3. zusammen. Bringen Sie die Fernsteuerung zum Laufen.

5. Weiter mit Stufe 2 und 3, oder eigenen Erweiterungen :-)

Viel Spass!

<span class="wiss">
# Erwartetes Ergebnis

Sie liefern einen funktionstüchtigen Prototyp für die Zugangskontrolle samst dokumentierten Code und Projektdokumentation.

# Bewertungsraster

**TODO**


</span>

# Stückliste

* Raspberry oder Laptop mit Processing und Eclipse IDE
* Arduino R3 + Ethernet-Aufsatz + Netzwerkkabel oder ESP8266
* ADXL345 Gyroskop
* Breadboard, Breadboard-Kabel, LED, Taster, Widerstände 100R+5K