# Práctica Sistemas Programables - Casa Domotica 
## Equipo: 
- Ramirez Francia Juan Santiago

## Profesor: 
- Ing. Levy Rojas Carlos Rafael
_________________________________________________________________________________________
## Material Utilizado:
1. Sensor de luz

<img src="https://github.com/Santiagofrancia/casadomotica/blob/master/material/luz.jpg?raw=true" />

1. Sensor de humedad

<img src="https://github.com/Santiagofrancia/casadomotica/blob/master/material/humedad.jpg?raw=true" />

1. Sensor de distancia

<img src="https://github.com/Santiagofrancia/casadomotica/blob/master/material/distancia.jpg?raw=true" width="400" height="350" />

1. Arduino UNO.

<img src="https://github.com/Santiagofrancia/casadomotica/blob/master/material/Arduino-UNO-frontal.jpg?raw=true" width="400" height="350" />
          

1. Protoboar.

<img src="https://github.com/Santiagofrancia/casadomotica/blob/master/material/material/proto.jpg?raw=true" width="300" height="400" />

- Leds de colores.

<img src="https://github.com/Santiagofrancia/casadomotica/blob/master/material/arduino-led-color.png?raw=true" />

- cables conectores (macho-hembra , macho-macho).

<img src="https://github.com/Santiagofrancia/casadomotica/blob/master/material/Cables-para-protoboard-macho-macho-imagen3.jpg?raw=true" width="400" height="350" />

- Resistencias de 220 ohms.

<img src="https://github.com/Santiagofrancia/casadomotica/blob/master/material/010651.jpg?raw=true" width="300" height="300" />

- Shield Ethernet

<img src="https://github.com/Santiagofrancia/casadomotica/blob/master/material/e.jpg?raw=true" width="400" height="350" />

- Computadora (Linux)

<img src="https://github.com/Santiagofrancia/casadomotica/blob/master/material/li.jpg?raw=true" width="400" height="350" />

_______________________________________________________________________________________

## FUNCIONAMIENTO

El funcionamiento principal del proyecto es una casa domotica con 3 sensores diferenctes: Luz, Distancia, Humedad, este conciste en que te va mostrando la humedad que hay en el ambiente y la misma temperatura dada en grados C°, tiene el codigo para que este te arroje en Kelvin o en Farenheit.

Ademas de que cuando se acerca un objeto a menos de 10 cm del sensor de distancia, este arroja una señal al buzzer para que empiece a sonar, y un mensaje de Peligro. Cuando verifica que hay mas distancia el mismo buzzer deja de sonar de forma automatica.

El sensor de luz, controla un led que siempre esta prendido y te arroja un mensaje de "Buenas noches", cuando hay demaciado luz el mensaje cambia a "Buenos Dias" y el led se apaga, ya que la casa no necesita luz adicional, este proceso se envia por la conexion con el ethernet y se autliza de forma automatica cada 5 segundos
________________________________________________________________________________________

**TODO EL PROYECTO FUE PROGRAMADO EN SOFTWARE LIBRE **
