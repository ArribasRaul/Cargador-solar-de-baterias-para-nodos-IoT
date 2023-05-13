///////// INA 3221 /////////
#include <Wire.h>                 // Inclusión de la librería para la comunicación por I2C
#include "SDL_Arduino_INA3221.h"  // Inclusión de la librería para usar el INA 3221
SDL_Arduino_INA3221 ina3221;
#define LIPO_BATTERY_CHANNEL 1    // Definición del canal 1 para la batería
#define SOLAR_CELL_CHANNEL 2      // Definición del canal 2 para el panel solar
#define OUTPUT_CHANNEL 3          // Definición del canal 3 para la carga

/////////// SD ////////////
#include <SPI.h>  // Inclusión de la librería para la comunicación por SPI
#include <SD.h>   // Inclusión de la librería para usar la SD
#define SSpin 10  // Inclusión del pin 10 para la comunicación con el esclavo
File archivo;

/////////// RTC ///////////
int seg = 0;  // Definición de la variable seg
int minu = 0; // Definición de la variable minu
int hora= 0;  // Definición de la variable hora
int dia = 0;  // Definición de la variable dia

////// Temporización //////
int periodo_ms=8000;
unsigned long t=0;

void setup(void){
  Wire.begin();
  ina3221.begin();            // Inicialización del INA 3221
  int MID;                    // Definición de la variable MID
  MID = ina3221.getManufID(); 
  SD.begin(SSpin);            // Inicialización de la comunicación con el módulo microSD
}

void loop(void){
  t=millis(); // Cálculo del tiempo que tarda en ejecutarse el codigo
  
  ///////// INA 3221 /////////
  
  archivo = SD.open("datosINA.txt", FILE_WRITE);  // Apertura para lectura/escritura del archivo datosINA.txt
  
  if (seg >= 60){ // Comprobación de si la variable seg es mayor o igual a 60
    seg -= 60;    // Resteo cada 60 segundos
    minu++;       // Suma 1 a minu
    }
  if (minu >= 60){  // Comprobación de si la variable minu es mayor o igual a 60
    minu -= 60;     // Resteo cada 60 minutos
    hora++;         // Suma 1 a hora
    }
  if (hora >= 24){  // Comprobación de si la variable hora es mayor o igual a 24
    hora -= 24;     // Resteo cada 24 horas
    dia++;          // Suma 1 a dia
    }
        
  archivo.print(dia);   // Escritura en la microSD del valor de dia
  archivo.print(" ");   // Escritura en la microSD de un espacio
  archivo.print(hora);  // Escritura en la microSD del valor de hora
  archivo.print(":");   // Escritura en la microSD de dos puntos
  archivo.print(minu);  // Escritura en la microSD del valor de minu
  archivo.print(":");   // Escritura en la microSD de dos puntos
  archivo.print(seg);   // Escritura en la microSD del valor de seg
  archivo.print(",");   // Escritura en la microSD de una coma
  archivo.print(" ");   // Escritura en la microSD de un espacio
  archivo.print(",");   // Escritura en la microSD de una coma
 
  float shuntvoltage1 = 0;  // Definición de la variable para la tensión que cae en la resistencia Shunt del canal 1
  float busvoltage1 = 0;    // Definición de la variable para la tensión que circula por el cable del canal 1
  float current_mA1 = 0;    // Definición de la variable para la corriente que circula por el cable del canal 1
  
  busvoltage1 = ina3221.getBusVoltage_V(LIPO_BATTERY_CHANNEL);      // Adquisición del valor de la tensión que circula por el cable del canal 1
  shuntvoltage1 = ina3221.getShuntVoltage_mV(LIPO_BATTERY_CHANNEL); // Adquisición del valor de la tensión que cae en la resistencia Shunt del canal 1
  current_mA1 = -ina3221.getCurrent_mA(LIPO_BATTERY_CHANNEL);       // Adquisición del valor de la corriente que circula por el cable del canal 1 
  
  archivo.print(busvoltage1);   // Escritura en la microSD del valor de la tensión en bus de la batería [V] del canal 1
  archivo.print(",");           // Escritura en la microSD de una coma
  archivo.print(shuntvoltage1); // Escritura en la microSD del valor de la tensión Shunt de la batería [mV] del canal 1
  archivo.print(",");           // Escritura en la microSD de una coma
  archivo.print(current_mA1);   // Escritura en la microSD del valor de la corriente de la batería [mA] del canal 1
  archivo.print(",");           // Escritura en la microSD de una coma
  archivo.print(" ");           // Escritura en la microSD de un espacio
  archivo.print(",");           // Escritura en la microSD de una coma
  
  float shuntvoltage2 = 0;  // Definición de la variable para la tensión que cae en la resistencia Shunt del canal 2
  float busvoltage2 = 0;    // Definición de la variable para la tensión que circula por el cable del canal 2
  float current_mA2 = 0;    // Definición de la variable para la corriente que circula por el cable del canal 2
  
  busvoltage2 = ina3221.getBusVoltage_V(SOLAR_CELL_CHANNEL);      // Adquisición del valor de la tensión que circula por el cable del canal 2
  shuntvoltage2 = ina3221.getShuntVoltage_mV(SOLAR_CELL_CHANNEL); // Adquisición del valor de la tensión que cae en la resistencia Shunt del canal 2
  current_mA2 = -ina3221.getCurrent_mA(SOLAR_CELL_CHANNEL);       // Adquisición del valor de la corriente que circula por el cable del canal 2
  
  archivo.print(busvoltage2);   // Escritura en la microSD del valor de la tensión en bus del panel solar [V] del canal 2
  archivo.print(",");           // Escritura en la microSD de una coma
  archivo.print(shuntvoltage2); // Escritura en la microSD del valor de la tensión Shunt del panel solar [mV] del canal 2
  archivo.print(",");           // Escritura en la microSD de una coma
  archivo.print(current_mA2);   // Escritura en la microSD del valor de la corriente del panel solar [mA] del canal 2
  archivo.print(",");           // Escritura en la microSD de una coma
  archivo.print(" ");           // Escritura en la microSD de un espacio
  archivo.print(",");           // Escritura en la microSD de una coma
  
  float shuntvoltage3 = 0;  // Definición de la variable para la tensión que cae en la resistencia Shunt del canal 3
  float busvoltage3 = 0;    // Definición de la variable para la tensión que circula por el cable del canal 3
  float current_mA3 = 0;    // Definición de la variable para la corriente que circula por el cable del canal 3
  
  busvoltage3 = ina3221.getBusVoltage_V(OUTPUT_CHANNEL);      // Adquisición del valor de la tensión que circula por el cable del canal 3
  shuntvoltage3 = ina3221.getShuntVoltage_mV(OUTPUT_CHANNEL); // Adquisición del valor de la tensión que cae en la resistencia Shunt del canal 3
  current_mA3 = ina3221.getCurrent_mA(OUTPUT_CHANNEL);        // Adquisición del valor de la corriente que circula por el cable del canal 3
  
  archivo.print(busvoltage3);   // Escritura en la microSD del valor de la tensión en bus de la salida [V] del canal 3
  archivo.print(",");           // Escritura en la microSD de una coma
  archivo.print(shuntvoltage3); // Escritura en la microSD del valor de la tensión Shunt de la salida [mV] del canal 3
  archivo.print(",");           // Escritura en la microSD de una coma
  archivo.println(current_mA3); // Escritura en la microSD del valor de la corriente de la salida [mA] del canal 3 y un final de línea
  
  archivo.close();  // Cierre de archivo
  
  seg=seg+8;        // Sumamos 8 a seg
  
  while(millis() < t + periodo_ms){ // Espera para completar los 8 segundos
  }
}
