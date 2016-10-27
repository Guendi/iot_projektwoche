<!--
pandoc -s iot_topics.md -o /tmp/md.html -t html5 --toc --toc-depth 2 --self-contained; firefox /tmp/md.html
-->

<!--style>
	body{
		font-family: sans-serif;
		width: 60%;
		margin: 20px auto;
	}

	header{
		text-align: center;
	}

	nav::before{
		content: "Inhaltsverzeichnis";
		font-size: 1.5em;
		font-weight: bold; 
	}
	figure{
		margin: 5px auto;
		border: 1px solid #333;
		padding: 5px;
	}
	figure img{
		max-width: 90%;
		display: block;
		margin: 5px auto;
		
	}
</style-->
<!-----
title: IoT - Topics
subtitle: Draft
author: Sven Schirmer
--->
# Aufbau der Projektwoche

1. kurzer Überblick Programmablauf
2. Einführung: Was ist IoT, Live-Demos demonstrieren (1h)
3. Workshops / Posten (9h)
4. Projekte (27h+nächtliches Hacking (requires Pizza+Kaffee))
5. Präsentationen und Abschluss (3h)

# Demos 

- Wetterdaten weltweit (mit Historie, Aktuelle Vorhersage): http://openweathermap.org/
- [http://www.buildinginternetofthings.com/list-of-projects/](http://www.buildinginternetofthings.com/list-of-projects/)
- [https://scanlibs.com/internet-things-arduino-cookbook/](https://scanlibs.com/internet-things-arduino-cookbook/)

```include 
intro.md
```

```include 
workshops.md
```

```include 
projects.md
```
