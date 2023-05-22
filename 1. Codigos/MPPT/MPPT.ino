////////Comunicación///////
#include <Wire.h>                 // Se incluye la librería para comunicarnos por I2C
#define DEVICE_I2C_ADDRESS 0x6A   // Se declara la direccion del BQ25895
byte reg0C;                       // Se declara una variable para almacenar un registro
byte reg11;                       // Se declara una variable para almacenar un registro
byte reg12;                       // Se declara una variable para almacenar un registro
int V65 = 0b00100001;             // 65% de la tensión de circuito abierto del panel solar
int V90 = 0b00110111;             // 90% de la tensión de circuito abierto del panel solar
byte Vlim;                        // Se declara una variable para almacenar el valor de la tensión limite
byte Vmppt;                       // Se declara una variable para almacenar el valor de la tensión MPPT

void setup() {
  Wire.begin(); // Se inicia la libreria wire  
}

void loop() {
  Wire.beginTransmission(DEVICE_I2C_ADDRESS); // Se establece la comunicación con BQ25895
  Wire.write(0x11); // Se elige el registro 0x11
  Wire.endTransmission(); // Se finaliza la comunicación
  Wire.requestFrom(DEVICE_I2C_ADDRESS, 1);  // Solicitud de un byte al BQ25895
  reg11 = Wire.read();  // Se almacena la lectura en una variable
  delay(200); // Se espera 200 milisegundos

  if (reg11 > 0b10000000){
    Wire.begin(); // Se inicia la librería wire
    Wire.beginTransmission(DEVICE_I2C_ADDRESS); // Se establece la comunicación con BQ25895
    Wire.write(0x07); // Se elige el registro 0x07
    Wire.write(0b10001100); // Se configura el registro 0x07 para desactivar el WATCHDOG
    Wire.endTransmission(); // Se finaliza la comunicación
    delay(200); // Se espera 200 milisegundos
    
    Wire.begin(); // Se inicia la librería wire
    Wire.beginTransmission(DEVICE_I2C_ADDRESS); // Se establece la comunicación con BQ25895
    Wire.write(0x13); // Se elige el registro 0x13
    Wire.write(0b00000000); // Se configura el registro 0x13 para deslimitar la corriente de entrada
    Wire.endTransmission(); // Se finaliza la comunicación
    delay(200); // Se espera 200 milisegundos

    Wire.begin(); // Se inicia la librería wire
    Wire.beginTransmission(DEVICE_I2C_ADDRESS); // Se establece la comunicación con BQ25895
    Wire.write(0x12); // Se elige el registro 0x12
    Wire.write(0b01111111); // Se configura el registro 0x12 para deslimitar la corriente de carga
    Wire.endTransmission(); // Se finaliza la comunicación
    delay(200); // Se espera 200 milisegundos
  }

  else{
    
    Wire.begin(); // Se inicia la librería wire
    Wire.beginTransmission(DEVICE_I2C_ADDRESS); // Se establece la comunicación con BQ25895
    Wire.write(0x07); // Se elige el registro 0x07
    Wire.write(0b00001100); // Se configura el registro 0x07 para activar el WATCHDOG
    Wire.endTransmission(); // Se finaliza la comunicación
    delay(200); // Se espera 200 milisegundos
    
    Wire.begin(); // Se inicia la librería wire
    Wire.beginTransmission(DEVICE_I2C_ADDRESS); // Se establece la comunicación con BQ25895
    Wire.write(0x00); // Se elige el registro 0x00
    Wire.write(0b11001000); // Se configura el registro 0x00 para activar el modo de alta impedancia
    Wire.endTransmission(); // Se finaliza la comunicación
    delay(200); // Se espera 200 milisegundos
  
    Wire.begin(); // Se inicia la librería wire
    Wire.beginTransmission(DEVICE_I2C_ADDRESS); // Se establece la comunicación con BQ25895
    Wire.write(0x02); // Se elige el registro 0x02
    Wire.write(0b10111101); // Se configura el registro 0x02 para hacer lecturas cada segundo
    Wire.endTransmission(); // Se finaliza la comunicación
    delay(200); // Se espera 200 milisegundos
  
    Vlim = V65; // Se fija el limite de Vbus al 65% del VOC del panel fotovoltaico
  
    Wire.begin(); // Se inicia la librería wire
    Wire.beginTransmission(DEVICE_I2C_ADDRESS); // Se establece la comunicación con BQ25895
    Wire.write(0x00); // Se elige el registro 0x00
    Wire.write(0b01001000); // Se configura el registro 0x00 para desactivar el modo de alta impedancia
    Wire.endTransmission(); // Se finaliza la comunicación
    delay(200); // Se espera 200 milisegundos
  
    Wire.begin(); // Se inicia la librería wire
    Wire.beginTransmission(DEVICE_I2C_ADDRESS); // Se establece la comunicación con BQ25895
    Wire.write(0x0D); // Se elige el registro 0x0D
    Wire.write(Vlim); // Se configura el registro 0x0D para limitar Vbus
    Wire.endTransmission(); // Se finaliza la comunicación
    delay(200); // Se espera 200 milisegundos

    Wire.begin(); // Se inicia la librería wire
    Wire.beginTransmission(DEVICE_I2C_ADDRESS); // Se establece la comunicación con BQ25895
    Wire.write(0x12); // Se elige el registro 0x12
    Wire.write(0b00000000); // Se configura el registro 0x12 para limitar la corriente de carga a 0 mA
    Wire.endTransmission(); // Se finaliza la comunicación
    delay(200); // Se espera 200 milisegundos
  
    while (Vlim <= V90){
      
      Wire.begin(); // Se inicia la librería wire
      Wire.beginTransmission(DEVICE_I2C_ADDRESS); // Se establece la comunicación con BQ25895
      Wire.write(0x02); // Se elige el registro 0x02
      Wire.write(0b10111101); // Se configura el registro 0x02 para hacer lecturas cada segundo
      Wire.endTransmission(); // Se finaliza la comunicación
      delay(200); // Se espera 200 milisegundos
      
      Wire.beginTransmission(DEVICE_I2C_ADDRESS); // Se establece la comunicación con BQ25895
      Wire.write(0x12); // Se elige el registro 0x12
      Wire.endTransmission(); // Se finaliza la comunicación
      Wire.requestFrom(DEVICE_I2C_ADDRESS, 1);  // Solicitud de un byte al BQ25895
      reg12 = Wire.read();  // Se almacena la lectura en una variable
      delay(200); // Se espera 200 milisegundos
      
      if (reg12 > 0b00000000){  // Se compara si la corriente de carga es mayor que 0 mA
        Vmppt = Vlim; // Se almacena el valor de tensión como tensión MPPT
      }
      
      Vlim += 0b00000001; // Se suman 100 mV al limite de tensión
      
      Wire.begin(); // Se inicia la librería wire
      Wire.beginTransmission(DEVICE_I2C_ADDRESS); // Se establece la comunicación con BQ25895
      Wire.write(0x0D); // Se elige el registro 0x0D
      Wire.write(Vlim); // Se configura el registro 0x0D para limitar Vbus
      Wire.endTransmission(); // Se finaliza la comunicación
      delay(200); // Se espera 200 milisegundos
    }

    Wire.begin(); // Se inicia la librería wire
    Wire.beginTransmission(DEVICE_I2C_ADDRESS); // Se establece la comunicación con BQ25895
    Wire.write(0x0D); // Se elige el registro 0x0D
    Wire.write(Vmppt); // Se configura el registro 0x0D para limitar Vbus
    Wire.endTransmission(); // Se finaliza la comunicación
    delay(200); // Se espera 200 milisegundos

    Wire.beginTransmission(DEVICE_I2C_ADDRESS); // Se establece la comunicación con BQ25895
    Wire.write(0x0C); // Se elige el registro 0x12
    Wire.endTransmission(); // Se finaliza la comunicación
    Wire.requestFrom(DEVICE_I2C_ADDRESS, 1);  // Solicitud de un byte al BQ25895
    reg0C = Wire.read();  // Se almacena la lectura en una variable
    delay(200); // Se espera 200 milisegundos
    
    while (reg0C <= 0b01111111){
      
      Wire.begin(); // Se inicia la librería wire
      Wire.beginTransmission(DEVICE_I2C_ADDRESS); // Se establece la comunicación con BQ25895
      Wire.write(0x0D); // Se elige el registro 0x0D
      Wire.write(Vmppt); // Se configura el registro 0x0D para limitar Vbus
      Wire.endTransmission(); // Se finaliza la comunicación
      delay(200); // Se espera 200 milisegundos

      Wire.beginTransmission(DEVICE_I2C_ADDRESS); // Se establece la comunicación con BQ25895
      Wire.write(0x12); // Se elige el registro 0x12
      Wire.endTransmission(); // Se finaliza la comunicación
      Wire.requestFrom(DEVICE_I2C_ADDRESS, 1);  // Solicitud de un byte al BQ25895
      reg12 = Wire.read();  // Se almacena la lectura en una variable
      delay(200); // Se espera 200 milisegundos
    }
  }
}
