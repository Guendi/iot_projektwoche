
# Was ist IoT

- intelligente Sensoren und Aktoren, die miteiander und dem Internet kommunizieren

## Herkunft

"The IoT has its **technological roots in the decades-long effort to monitor and control the physical environment** in which people work and play. Its most basic components are embedded devices that **have existed for years: thermostats** that sense ambient temperature and control heating and cooling systems, **sensors that manage braking systems in automobiles (ABS)**, **pacemakers that regulate the heart**, airplane black boxes that track flight paths, and location devices that monitor the whereabouts of industrial equipment. In the past, some of these devices were wired together into more complex systems. But it wasn’t until they were provided with some intelligence, connected to the Internet, and empowered by a new wave of technological accessibility—through cloud computing, smartphones, and the prototyping capabilities of digital fabrication—that the IoT came into being." 

[Quelle: http://www.strategy-business.com/article/00294?gko=a9303](http://www.strategy-business.com/article/00294?gko=a9303)

## Beispiel: NEST Learning Thermostat

- reguliert Heizleistung für Wohnräume ggf. in Abhängigkeit von Luftfeuchtigkeit, Aussentemperatur, Helligkeit...
- lernt Benutzervorlieben
- Steuerung per Smartphone
- Leistung zu Peak-Zeiten reduzieren


## IoT aus Business-Sicht
"By **2020**, an estimated **50 billion devices** around the globe will be **connected to the Internet**. Perhaps a third of them will be computers, smartphones, tablets, and TVs. The remaining **two-thirds will be** other kinds of “things”: **sensors, actuators, and newly invented intelligent devices that monitor, control, analyze, and optimize our world.**"

"The arrival of the “Internet of Things” (IoT) represents a transformative shift for the economy, similar to the introduction of the PC itself. It **incorporates other major technology industry trends** such as cloud computing, data analytics, and mobile communications, but goes beyond them. Unlike earlier efforts to track and control large systems, such as radio-frequency identification (RFID), the Internet connection gives this shift almost limitless versatility."

"Much early work is likely to focus on boosting efficiency and cutting costs, but the greatest long-term business value of the Internet of Things will involve **getting to know customers** - both consumers and businesses - **more intimately**, and providing new digital services and experiences to delight them."

[Quelle: http://www.strategy-business.com/article/00294?gko=a9303](http://www.strategy-business.com/article/00294?gko=a9303)

**Ergo: IoT ist Big (Brother) Business.**

## Contra: IoT - Makerszene**

- mit 3D-Druckern, Lasercuttern, preiswerter Microcontroller-Hardware und Open-Source selbst IoT-Dinge basteln 
- Kontrolle über eigene Daten behalten
- Gegenpol zur Wegwerf- und Konsumgesellschaft 



## Aufbau IoT - Netze

### 1. Endpoints (Sensoren, Aktoren)

	- (ehemals) passive Sensoren: z.B. Thermometer, Spannungsmesser etc.
	- IoT: passive Sensoren via Mikrocontroller mit Aussenwelt verbunden
	- Aktoren: Relais, Leuchten, Motoren, Türöffner etc, ebenfalls via Microcontroller mit Aussenwelt verbunden

### 2. Simple Hubs (verbinden Endpoints mit Aussenwelt/Internet)

	- ein Hub für eine Sensoren-Art

### 3. Integrating Hubs (verbinden verschiedene Simple Hubs)

	- intelligentes Haus: Zur Schlafenszeit werden alle Lichter gelöscht, Wohnung verriegelt etc. (Apple HomeKit)
	- quantifyed self: Daten von Schrittzähler, Pulsmesser, Hautwiderstand, Schlafrhythmus etc. zusammenfassen für umfassendes Gesundheitsbild

### 4. Network & Cloud Services

	- liefern Infrastruktur für IoT
	- zuständig für Datenanalyse, SocialMedia sharing etc.

![Beispiel IoT E-Health, [Quelle: http://www.strategy-business.com/article/00294?gko=a9303](http://www.strategy-business.com/article/00294?gko=a9303)](img/00294_ex3.gif)

## The Players

Der IoT-Markt besteht im wesentlichen aus folgenden Anbietern:

![IoT-Anbieter: Rollen, [Quelle: http://www.strategy-business.com/article/00294?gko=a9303](http://www.strategy-business.com/article/00294?gko=a9303)](img/00294_ex2b.gif)

## Why IoT-Strategies fail (allenfalls informativ)

1. Insufficient Investment in Project Management
2. Failure to Get Buy-In Across the Organization
3. Not Being Able to Update or Replace IoT Components
4. Underestimating Vendor Risk
5. Not Having a Plan B or an Exit Strategy
6. Downplaying Security and Privacy Threats
7. Focusing on Technology over Business

[Quelle: http://www.ioti.com/iot-trends-and-analysis/how-not-manage-iot-project-7-common-pitfalls](http://www.ioti.com/iot-trends-and-analysis/how-not-manage-iot-project-7-common-pitfalls)


## Sicherheit (kurze Sensibilisierung)

- aktuell: ungesicherte *things* werden für gewaltige Bot-Netze gekapert


## Energiebedarf (kurze Sensibilisierung)

Inzwischen seien weltweit etwa 14 Milliarden Geräte mit dem Netz verbunden. Allein 2013 kamen diese Geräte so auf einen Verbrauch von rund 616 Terawattstunden (TWh) – von denen fast zwei Drittel, etwa 400 TWh, verschwendet worden sein sollen. Zum Vergleich: Das entspricht dem gesamten, kombinierten Jahresbedarf an Energie von Großbritannien und Norwegen. Laut IEA summiert sich der Verlust auf 80 Milliarden US-Dollar, bis 2020 soll er sich noch auf 120 Milliarden US-Dollar erhöhen.

### Ursachen:

- sparsamerer Standby-Modus nicht implementiert
- Verbindung mit dem Internet ohne Unterbrechung aufrecht erhalten
- Computer regeln zwar den Verbrauch intelligent, heben diesen Gewinn jedoch selbst wieder auf
- Rechner, die auch in der Nacht laufen oder Switches und Hubs, die gerade niemand braucht.

![IoT-Energyverbrauch vs. Einsparung, [Quelle: http://www.heise.de/ix/meldung/Studie-Internet-of-Things-frisst-zunehmend-Energie-2250476.html](http://www.heise.de/ix/meldung/Studie-Internet-of-Things-frisst-zunehmend-Energie-2250476.html)](img/iot_energy_consumption.png)



