# Práctica Sistemas Programables - Casa Domótica 
## Equipo: 
- Ramirez Francia Juan Santiago

## Profesor: 
- Ing. Levy Rojas Carlos Rafael
_________________________________________________________________________________________

## TODO EL PROYECTO FUE PROGRAMADO EN SOFTWARE LIBRE 
_________________________________________________________________________________________

## Material Utilizado:
1. Sensor de luz

<img src="https://github.com/Santiagofrancia/casadomotica/blob/master/material/luz.jpg?raw=true" width="400" height="350" /> 

1. Sensor de humedad

<img src="https://github.com/Santiagofrancia/casadomotica/blob/master/material/humedad.jpg?raw=true" width="400" height="350" /> 

1. Sensor de distancia

<img src="https://github.com/Santiagofrancia/casadomotica/blob/master/material/distancia.jpg?raw=true" width="400" height="350" />

1. Arduino UNO.

<img src="https://github.com/Santiagofrancia/casadomotica/blob/master/material/Arduino-UNO-frontal.jpg?raw=true" width="400" height="350" />
          

1. Protoboar.

<img src="https://github.com/Santiagofrancia/casadomotica/blob/master/material/proto.jpg?raw=true" width="300" height="400" />

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

El funcionamiento principal del proyecto es una casa domótica con 3 sensores diferentes: Luz, Distancia, Humedad, este consiste en que te va mostrando la humedad que hay en el ambiente y la misma temperatura dada en grados C°, tiene el código para que este te arroje en Kelvin o en Fahrenheit.

Además de que cuando se acerca un objeto a menos de 10 cm del sensor de distancia, este arroja una señal al buzzer para que empiece a sonar, y un mensaje de Peligro. Cuando verifica que hay más distancia el mismo buzzer deja de sonar de forma automática.

El sensor de luz, controla un led que siempre esta prendido y te arroja un mensaje de "Buenas Noches", cuando hay demasiado luz el mensaje cambia a "Buenos Días" y el led se apaga, ya que la casa no necesita luz adicional, este proceso se envía por la conexión con el ethernet y se utiliza de forma automática cada 5 segundos

________________________________________________________________________________________


