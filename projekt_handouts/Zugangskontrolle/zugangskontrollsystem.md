---
title: RFID-Zugangskontrollsystem
subtitle: IoT - Kursprojekt
author: <img src="../img/title.jpg" style="max-width:400px"/>

---
# Aktueller Zustand

Prototypische Implementierung auf Arduino Mega 2650
Kommunikation via serieller Schnittstelle
Serverfunktion wird mit Python Skript und statischen IDs/PINs im Code bereitgestellt


# Projektbeschreibung
Der Zutritt zu Server- und Tresorräumen muss besonders geschützt werden. Einfache RFID-basierte Lösungen sind dafür nicht sicher genug, da die Daten von Karten mit speziellen Lesegeräten schnell und unbemerkt gestohlen werden können. 

Die Idee ist, die Zugangskontrolle der sensiblen Bereiche innerhalb einer Firma über eine Kombination von RFID und PIN-Code zu realisieren. Zur einfachen Wartbarkeit sollen RFID-IDs sowie die zugehörigen PINs zentral in einer Datenbank verwaltet werden. Die RFID-Lesegeräte und PIN-Eingabemodule werden über Arduino-Mikrcontroller betrieben. Die Arduinos senden die gelesenen RFID-IDs und PINs an einen Webserver, der die empfangenen Daten mit der Datenbank vergleicht. Passen RFID-ID und PIN-Code zu den Daten in der DB, sendet der Server eine OK-Meldung an den Arduino. Empfängt der Arduino das OK, gibt er den Zugang für einige Sekunden frei. Zur komfortablen Bedienung haben die Arduinos ein 16x2 LCD-Modul, auf welchen sinnvolle Bedienungshinweise und -meldungen ausgegeben werden.

## Stufe 1:

Webserver und Datenbank sind auf einem Raspberry-Pi vorinstalliert. Die IP des Webservers bekommen Sie von der Kursleitung. Sie müssen *nur* den Microcontroller programmieren und die RFIDs samst PINs in der Datenbank hinterlegen. Der Webserver antwortet auf folgende URL: **TODO**

## Stufe 2:

Aufgrund Ihrer Vorkenntnisse installieren und konfigurieren Sie Webserver und Datenbank auf einem Raspberry-Pi. Zusätzlich programmieren Sie eine PHP-Seite oder JSP-Seite, welche die Daten vom Arduino per GET-Request entgegen nimmt und darauf antwortet. Zudem programmieren Sie natürlich auch den Microcontroller. Die RFIDs samst PINs hinterlegen Sie in der Datenbank. 

## Stufe 3

Zusätzlich zu Stufe 2 sorgen Sie dafür, dass mehrere RFID+PIN-code Geräte unterschiedliche Räume absichern. Bestimmte Karten sollen Zugriff auf bestimmte Räume haben. Es gibt auch eine Mastercard.

## Stufe 4

Die Firma will auch sogenannte Einmal-Pincodes ausstellen. Diese funktionieren ohne RFID-Karte, und nur einmal. Sie kümmern sich um alles weitere.


# Vorgehen

Gehen Sie nach dem *Teile und herrsche* Prinzip vor und erarbeiten Sie sich zunächst Teillösungen: 

1. Studieren Sie zunächst, wie das RFID-Lesegerät am Arduino angeschlossen wird. Danach lesen Sie die IDs der RFID-Kärtchen aus. Nutzen Sie zunächst die Möglichkeit, die Daten per seriellem Monitor anzuzeigen. Dann geben Sie die RFIDs und PINs in der Datenbank ein (bzw. erstellen diese zunächst) und testen die Funktionalität des Webservers, indem Sie die Daten von Hand in das vorgegebene URL-Muster **TODO** eingeben und den Server per Web-Browser damit aufrufen.

2. Studieren Sie in einem zweiten Projekt, wie Sie mit dem Arduino Eingaben vom Pin-Pad einlesen und auf dem LCD-Display anzeigen können. Wie können mehrere Ziffern hintereinander eingelesen und angezeigt werden? Wie kann das *Absenden* eines PIN-Codes realisiert werden? 

3. Nutzen Sie das Ethernet-Modul ihres Arduino, um zunächst eine einfache Verbindung (mit fixen Daten) zum Webserver aufzubauen. Parsen Sie die Rückgabe des Servers.

4. Es ist Zeit, die Teile zusammen zu fügen. Um die Übergänge von RFID-Lesen, PIN eingeben, PIN absenden und Tür freigeben zu illustieren, erstellen Sie vielleicht zunächst einen Zustandsautomaten. Danach integrieren Sie die Teilprojekte zu einem Ganzen.

5. Überlegen Sie sich, wie Sie Stufe 3 und 4 umsetzen können.

Viel Spass!

<span class="wiss">
# Erwartetes Ergebnis

Sie liefern einen funktionstüchtigen Prototyp für die Zugangskontrolle samst dokumentierten Code und Projektdokumentation.

# Bewertungsraster

**TODO**


</span>

# Stückliste

* Raspberry oder Laptop mit MySQL + Apache Server
* Arduino R3 + Ethernet-Aufsatz + Netzwerkkabel
* MFRC522 RFID-Leser + RFID-Kärtchen
* LCD Display (mit SPI / I2C Modul)
* Folientastatur
* Buzzer, LED zur akkustischen oder visuellen Freigabeanzeige
* Breadboard, Breadboard-Kabel