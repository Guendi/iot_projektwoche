# Lehrvorträge / Posten

## Intro Mikroprozessoren / Sensoren (8 Lektionen)

1. Kurzvortrag (max. 30 Minuten)
    - Demo IoT
    - Arduino IDE vorstellen
2. Mini-Projekte mit Breadboards, LEDS, Tastern

3. Kurzvortrag (max. 30 Minuten)
    - aktive, passive Sensoren / Aktoren Grundlagen
    - Arduino Bibliotheken für aktive Sensoren, LCDs

4. Mini-Projekte mit Breadboards, Sensoren, Aktor (Lüfter via Transistor?) + LCD-Display-Miniprojekt (2h)

?? Löten oder nicht ?? Elektronik Grundlagen?

## Intro Mikroprozessor-Architektur (4 Lektionen)

1. Kurzvortrag Konzept Microcontroller (vs. PC)
	- kein OS
	- RISC vs. CISC; Register, Befehlssatz
	- [SimulAVR](https://www.mikrocontroller.net/articles/AVR-Simulation), 
[WDR-Papiercomputer](http://www.wolfgang-back.com/knowhow_home.php)
	- /home/sven/apps/papiercomputer/khcback.exe

2. Übung SimulAVR
	- Programmieren mit Registern
	- alà [http://www.instructables.com/id/Command-Line-Assembly-Language-Programming-for-Ard/](http://www.instructables.com/id/Command-Line-Assembly-Language-Programming-for-Ard/)

3. Kurzvortrag Interrupts und Sleep-Mode (20 min)
	- Hardware-Timer, externe Interrupts
	 
5. Übung Arduino-Interrupt - Programmierung

4. Bus Systeme (I²C, SPI, etc.)
	- zur Kommunikation mit Sensoren (RFID), Aktoren (LCD, TFT, Lichtmatrix...) 
	
## Intro Kommunikation Mikrocotroller - PC  (4 Lektionen)

1. Kurzvortrag (max. 30 Minuten)
	- UART... was notwendig ist, um HANOKs abzudecken
	- Seriell (am einfachsten und schnellsten)
	- WLAN-basiert

2. Mini-Projekt (3 Lektionen)
	- serielle Kommunikation zwischen Arduinos oder
	- WiFi basierte Kommunikation zwischen Arduinos / PCs

<div class="wiss">
### @WISS 4. Semester: Webserver mit PHP und Datenbanken (Raspberry)

- PHP, HTML, MySQL gut bekannt
- Client-Server Architektur teilweise bekannt
- Mini-Projekt: Sensordaten vom Arduino auf Pi laden, visualisieren mit Web-UI (4h)
</div>