////////Comunicación///////
#include <Wire.h>                 // Se incluye la librería para comunicarnos por I2C
#define DEVICE_I2C_ADDRESS 0x6A   // Se declara la direccion del BQ25895
byte reg11;                       // Se declara una variable para almacenar un registro

void setup() {
  Wire.begin(); // Se inicia la libreria wire
}

void loop() {
  Wire.begin(); // Se inicia la librería wire
  Wire.beginTransmission(DEVICE_I2C_ADDRESS); // Se establece la comunicación con BQ25895
  Wire.write(0x02); // Se elige el registro 0x02
  Wire.write(0b10111101); // Se configura el registro 0x02 para hacer lecturas cada segundo
  Wire.endTransmission(); // Se finaliza la comunicación
  delay(200); // Se espera 200 milisegundos

  Wire.beginTransmission(DEVICE_I2C_ADDRESS); // Se establece la comunicación con BQ25895
  Wire.write(0x11); // Se elige el registro 0x11
  Wire.endTransmission(); // Se finaliza la comunicación
  Wire.requestFrom(DEVICE_I2C_ADDRESS, 1);  // Solicitud de un byte al BQ25895
  reg11 = Wire.read();  // Se almacena la lectura en una variable
  delay(200); // Se espera 200 milisegundos

  Wire.begin(); // Se inicia la librería wire
  Wire.beginTransmission(DEVICE_I2C_ADDRESS); // Se establece la comunicación con BQ25895
  Wire.write(0x0D); // Se elige el registro 0x0D
  Wire.write(reg11); // Se configura el registro 0x02 para hacer lecturas cada segundo
  Wire.endTransmission(); // Se finaliza la comunicación
  delay(200); // Se espera 200 milisegundos
}
