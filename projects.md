# Studentenprojekte (30h)

## Raumtemperatur/Feuchtigkeitsüberwachung mit Remote-Logging & Alarm

- Server-Abschaltung bei Übertemperatur (mc-kontrolliert)
- Webserver-basiertes Monitoring (grafische Anzeige) 
	
## kombinierte RFID / Zahlencode-basierte Zugangskontrolle 

- mit Remote-Logging & Remote-Deaktivierung
- Webserver-basiertes Monitoring (grafische Anzeige) 
- zusätzlich: Einmalcodes vom Server

## Arduino-basiertes Leistungsmessgerät für PC

- Spannung+Strom für 5/12V Strecke im PC messen
- Ausgabe auf Display
- Webserver-basiertes Monitoring (grafische Anzeige) 

## WISS: Gruppenarbeit (first thoughts)

### Fachbereichsübergreifende Projektarbeit

**Ziel:** Die Lernenden erstellen in Zweier/Dreier-Gruppen ein WIFI-basiertes Netzwerk mit "intelligenten" Sensoren/Aktoren und Webserver-basierten Daten-Logging / Monitoring zur Anwendung und Vertiefung der theoretischen Kenntnisse über Mikrocontroller.

**Vorkentnisse:** Die Lernenden (API und SYS) haben Vorkentnisse in folgenden Themen:

- HTML, PHP, JS (API)
- Netzwerke (WiFi) einrichten (SYS)
- Webserver und Datenbankserver betreiben (API/SYS)
- Strom und Spannungen messen (Modul ??)

### Hardware:

#### TODO: Entscheidung

- Arduino UNO R3 + Ethernet-Shield mit SD-Card Slot
	- [http://www.mikroshop.ch/Warenkorb.html?gruppe=3&artikel=501](http://www.mikroshop.ch/Warenkorb.html?gruppe=3&artikel=501)
	-[http://www.mikroshop.ch/Warenkorb.html?gruppe=3&artikel=849](http://www.mikroshop.ch/Warenkorb.html?gruppe=3&artikel=849)
	- unter 20 Fr (!)
	- 20 DI/O
	- 6 AI
	- U=5V, I=40mA je DO
 	- Atmel AVR, 8bit


- Alternative: Arduino UNO WiFi (UNO kompatibel) (ca. 43 Fr/Stück)
	- [https://blog.play-zone.ch/2016/06/01/arduino-wifi/2/](https://blog.play-zone.ch/2016/06/01/arduino-wifi/2/)
	- 20 DI/O
	- 6 AI
	- U=5V, I=40mA je DO
	- onboard ESP8266 mit 4MB flash, 8MB instruction + 12MB data memory
 	- Atmel AVR, 8bit

- Alternative: Genuino MKR1000 (inkl. WiFi); ca 45 Fr/Stück (playzone.ch)
	- [http://www.play-zone.ch/de/genuino-mkr1000.html](http://www.play-zone.ch/de/genuino-mkr1000.html)
	- löten!
	- 8 DI/O
	- 7 AI, 1 AO 
	- 3.3V; 7mA je DO
	- 256kB Flash, 32kB SRAM
	- 32bit controller
- Ausblick Miniatur-Versionen (Arduino-Mini)
	- für produktionsreife Prototypen...

#### Zubehör

je Team:

- Sensorshield (Komplettpaket mit Temp, Feucht, Poti IR uvm.); [http://www.play-zone.ch/de/sensor-und-io-shield-fur-arduino.html](http://www.play-zone.ch/de/sensor-und-io-shield-fur-arduino.html)

- alternativ (Fun-Faktor!)
	- DHT11 Temp, Feucht.. Sensoren (ca. 3 Fr/Stück)
	- LEDs, Widerstände, Breadboards, Breadboard Kabelsätze (sollte vorhanden sein)

- LCD Display 16x2 [http://mikroshop.ch/LED_LCD.html?gruppe=7&artikel=15](http://mikroshop.ch/LED_LCD.html?gruppe=7&artikel=15)
- RFID Sensor + Karten; ca. 17 Fr; [http://www.play-zone.ch/de/mfrc522-rfid-reader-breakout-inkl-2-keys.html](http://www.play-zone.ch/de/mfrc522-rfid-reader-breakout-inkl-2-keys.html)
- PC's mit Bastelfestplatte für Web/Datenbankserver + Arduino IDE (am einfachsten mit Debian8 oder (X)Ubuntu1604)

für gesamte Klasse: ein konfigurierbarer WLAN-Accesspoint mit LAN-Anschlüssen (sollte vorhanden sein)

### Durchführung

TODO elaborate...
