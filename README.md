# Cargador solar de baterias para nodos IoT

Diseño y desarrollo de un sistema que permita gestionar la energía generada por paneles solares de baja potencia de hasta 14 V y 3A . El sistema empleará una PCB que alimentará una batería de litio de 3,7V y una carga variable que consuma 3,3V o 5V y hasta 2A.
Proyecto de fin de grado realizado en la UPNa por Raúl Arribas Antón y supervisado por el Dr. Santiago Tainta Ausejo.

![Universidad Publica de Navarra](https://upload.wikimedia.org/wikipedia/commons/thumb/5/5d/Lgotipo_UPNA.png/320px-Lgotipo_UPNA.png)

##  [1. Códigos](https://github.com/ArribasRaul/Cargador-solar-de-baterias-para-nodos-IoT/tree/main/1.%20Codigos "Heading link")

Repositorio de los códigos utilizados durante el proyecto.

- Lectura_BQ25895

Codigo para la lectura de los registros del BQ25895 y escritura de estos en el monitor serie (Arduino Uno o Atmega328P)

- MPPT

Código para la implementación de un controlador MPPT (Arduino Uno o Atmega328P)
 
- Sistema_de_medida

Código y montaje para un sistema de medión de la eficiencia de un sistema de carga de baterias, basado en el INA3221, Arduino Uno y un modulo de microSD.

##  [2. PCB](https://github.com/ArribasRaul/Cargador-solar-de-baterias-para-nodos-IoT/tree/main/2.%20PCB "Heading link")

- Gerbers

Diseño de la PCB del cargador

- Lista de componentes de la PCB

Lista de los componentes usados en la PCB, sus referencias, cantidades y referencias de compra.

- Controlador

Comparación de los diferentes controladores de carga en el mercado.

- Regulador 3,3 V

Comparación de los diferentes convertidores DC/DC de 3,3 V en el mercado.

- Regulador 5 V

Comparación de los diferentes convertidores DC/DC de 5 V en el mercado.

##  [3. Pruebas PCB](https://github.com/ArribasRaul/Cargador-solar-de-baterias-para-nodos-IoT/tree/main/3.%20Pruebas%20PCB "Heading link")

- Lecturas

Datos en bruto conseguidos con el sistema de medida

- Comparación DFRobot y Desarollada

Comparación de funcionamiento de una PCB comercial (Solar Power Manager for 9V/12V/18V solar panel) de la marca DFRobot y la PCB desarrollada en diferentes situaciones de uso, conectadas a una fuente de alimentación.

- DFRobot

Funcionamiento de la placa de DFRobot con una alimentacion de dos paneles solares de baja potencia (9 V y 400 mA)
