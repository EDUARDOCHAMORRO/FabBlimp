# [Fab Blimp] Workshop

 Workshop developped for Fab15 Egypt Conference by Eduardo Chamorro and Santi Fuentemilla

 Workshop of producing and fabricating a phone controlled blimp. Pcb fabricated with a Roland SRM20, blimp balloon produced by sealing a plastics bags with a CO2 lasercutter and frame made out of cardboard cutted also with the lasercutter.
 Control of the blimp via an smartphone accessing the ip address of the ESP12 via an internal wifi access point(wifi connection required)

![](https://eduardochamorro.github.io/FabBlimp/img/fabblimp.jpg)

[PDF DOWNLOAD GUIDE ON HOW TO ASSEMBLE IT](https://eduardochamorro.github.io/FabBlimp/fabblimp.pdf)

## Hardware Requirements

- Pcb Fr1
- 3x brushed motors 0615 size
- 3x propellers tinywhoop
- Ftdi cable 3.3v
- Corrugated Card 360 kg/m3
- Glue gun
-	Double side tape
- Cutters
-	Scissors
- Helium Kit ,Tank 14.9 cu.ft
- 36 Inch Giant Latex Balloon White
- Electronics		RES 100 OHM 1/4W 1% 1206 SMD
- Electronics		RES 10.0K OHM 1/4W 1% 1206 SMD
- Electronics		CAP CER 4.7UF 35V Y5V 1206
- Electronics		CAP CER 10UF 35V Y5V 1206
- Electronics		MOSFET N-CH 30V 1.7A SSOT3
- Electronics		SMT RT Angle Male Header 0.1" (36pos)
- Electronics		SWITCH TACT SMD W-GND 160GF
- Electronics		Esp8266 Esp-12e
- Electronics		IC REG LDO 3.3V 1A SOT223-3


## PCB production files

![Electronic Components](https://eduardochamorro.github.io/FabBlimp/img/ComponentsZeppelin.png)

**FILES WITH MOTOR HOLDER**
![Interior Cut PCB](https://eduardochamorro.github.io/FabBlimp/img/IncutZeppelin.png)
![Exterior Cut PCB](https://eduardochamorro.github.io/FabBlimp/img/OutcutZeppelin.png)

**FILES WITHOUT MOTOR HOLDER**
![Interior Cut PCB](https://eduardochamorro.github.io/FabBlimp/img/bliboard_trace.png)
![Exterior Cut PCB](https://eduardochamorro.github.io/FabBlimp/img/bliboard_cut.png)

## Cut out file for a lasercutter motor holder

[Download Laser Cut file dxf](https://eduardochamorro.github.io/FabBlimp/dock.dxf)


## Control app via browser

![](https://eduardochamorro.github.io/FabBlimp/img/control.jpg)

There is two version of the code.

1- WIFI SERVER : the blimp connects to an already existing wifi hotspot and uses that network to increase the control range and improved webpage control.(longer range and more visual)

2- WIFI HOTSPOT : for not stable or fast enough wifi hotspots, the blimp creates his own hotspot and get controlled by publishing an control webpage.(faster control,shorter range and less visual)


## Copyright and License

Copyright3-2019 FabLab BCN - IaaC. Code released under the [MIT](https://github.com/BlackrockDigital/startbootstrap-freelancer/blob/gh-pages/LICENSE) license.
Developped by Eduardo Chamorro and Santi Fuentemilla. July 2019
Updated by Miriam Choi February 2020
