# Lehrvorträge / Posten

## Intro Mikroprozessoren / Sensoren (8 Lektionen)

1. Kurzvortrag (max. 30 Minuten)
    - Demo IoT
    - Konzept Microcontroller (vs. PC)
    - Arduino IDE vorstellen

2. Hands ON Arduino anschliessen, serielle Kommunikation, Debugging (60 Minuten)

	/*Pause*/

3. Kurzvortrag Elektronik-Grundlagen (30 Minuten)
	 - Widerstände, LED, Transistoren...
    - ESD erwähnen

4. Mini-Projekte mit Breadboards, Widerstände, LEDS, Tastern (60 Minuten)

	/*Mittagspause*/

5. Löten Grundlagen (5 Minuten)

6. kurzes Hands on: einfache Schaltungen (Taster, LED...) auf Lochrasterplatine mit Stiftleistenanschluss löten (25 Minuten) 

	/* Pause*/

4. Kurzvortrag (max. 30 Minuten)
    - aktive, passive Sensoren / Aktoren Grundlagen (1-2 Folien)
    - Arduino Bibliotheken für aktive Sensoren, LCDs

5. Mini-Projekte mit Breadboards, Sensoren, Aktor (Lüfter via Transistor?) + LCD-Display-Miniprojekt (2h)

## Intro Mikroprozessor-Architektur (4 Lektionen)
1. Kurzvortrag Konzept Microcontroller vs. PC/Raspi (30 Minuten)
	- (fast) kein OS, kein user management
	- keine memory protection durch OS (kein Garbage Collector)
	- Hardware-Timer, externe Interrupts, Sleep Modes

2. Übung Arduino-Interrupt - Programmierung (60 Minuten)

	/* Z9i-Pause */

3. Bus-Systeme (I²C, SPI, etc.)
	- zur Kommunikation mit Sensoren (RFID), Aktoren (LCD, TFT, Lichtmatrix...) 
	- Experte Christoph!

4. Übung Bus-Systeme (I²C, SPI, etc.)

	/* Zmittag Pause */

<!-- WISS only
	- [SimulAVR](https://www.mikrocontroller.net/articles/AVR-Simulation), 
[WDR-Papiercomputer](http://www.wolfgang-back.com/knowhow_home.php)
	- /home/sven/apps/papiercomputer/khcback.exe
	- Experte: Wene

2. Übung SimulAVR
	- Programmieren mit Registern
	- alà [http://www.instructables.com/id/Command-Line-Assembly-Language-Programming-for-Ard/](http://www.instructables.com/id/Command-Line-Assembly-Language-Programming-for-Ard/)
-->

	 
	
## Intro Kommunikation Mikrocotroller - PC  (4 Lektionen)

1. Kurzvortrag (max. 30 Minuten)
	- UART... was notwendig ist, um HANOKs abzudecken
	- Seriell (am einfachsten und schnellsten)
	- LORA, WLAN-basierte Kommunikation

2. Mini-Projekt (3 Lektionen)
	- serielle Kommunikation zwischen Arduinos oder
	- WiFi basierte Kommunikation zwischen Arduinos / PCs

<div class="wiss">
### @WISS 4. Semester: Webserver mit PHP und Datenbanken (Raspberry)

- PHP, HTML, MySQL gut bekannt
- Client-Server Architektur teilweise bekannt
- Mini-Projekt: Sensordaten vom Arduino auf Pi laden, visualisieren mit Web-UI (4h)
</div>