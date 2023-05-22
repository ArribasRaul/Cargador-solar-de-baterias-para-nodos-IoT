////////Comunicación///////
#include <Wire.h>                 // Incluimos la librería para comunicarnos por I2C
#define DEVICE_I2C_ADDRESS 0x6A
byte reg0E;
byte reg0F;
byte reg11;
byte reg12;
byte reg14;
///////////////////////////

void setup(void) {
  Wire.begin();
//  Wire.beginTransmission(DEVICE_I2C_ADDRESS);
//  Wire.write(0x02);
//  Wire.write(0b01000000);
//  Wire.endTransmission();
  Serial.begin(9600);
  Serial.println("Arrancado");
}

void loop() {
  Serial.println("Escritura registro");
  Wire.begin();
  Wire.beginTransmission(DEVICE_I2C_ADDRESS);
  Wire.write(0x02);
  Wire.write(0b10111101);
  Wire.endTransmission();
  delay(100);
 /* 
  Serial.println("Escritura registro");
  Wire.begin();
  Wire.beginTransmission(DEVICE_I2C_ADDRESS);
  Wire.write(0x09);
  Wire.write(0b01000100);
  Wire.endTransmission();
  delay(100);

  Serial.println("Escritura registro");
  Wire.begin();
  Wire.beginTransmission(DEVICE_I2C_ADDRESS);
  Wire.write(0x04);
  Wire.write(0b00010000);
  Wire.endTransmission();
  delay(100);
  
  Serial.println("Escritura registro");
  Wire.begin();
  Wire.beginTransmission(DEVICE_I2C_ADDRESS);
  Wire.write(0x03);
  Wire.write(0b00011010);
  Wire.endTransmission();
  delay(100);

  Serial.println("Escritura registro");
  Wire.begin();
  Wire.beginTransmission(DEVICE_I2C_ADDRESS);
  Wire.write(0x07);
  Wire.write(0b10001100);
  Wire.endTransmission();
  delay(100); */
  
  Wire.beginTransmission(DEVICE_I2C_ADDRESS);
  Wire.write(0x00);
  Wire.endTransmission();
  Serial.print("Read REG 0x00: ");
  Wire.requestFrom(DEVICE_I2C_ADDRESS, 1);
  reg14 = Wire.read();

  int x7 = bitRead(reg14, 7);
  Serial.print(x7);
  Serial.print(" ");

  int x6 = bitRead(reg14, 6);
  Serial.print(x6);
  Serial.print(" ");

  int x5 = bitRead(reg14, 5);
  Serial.print(x5);
  Serial.print(" ");

  int x4 = bitRead(reg14, 4);
  Serial.print(x4);
  Serial.print(" ");

  int x3 = bitRead(reg14, 3);
  Serial.print(x3);
  Serial.print(" ");

  int x2 = bitRead(reg14, 2);
  Serial.print(x2);
  Serial.print(" ");

  int x1 = bitRead(reg14, 1);
  Serial.print(x1);
  Serial.print(" ");

  int x0 = bitRead(reg14, 0);
  Serial.print(x0);
  Serial.println(" ");

  delay(200);

  Wire.beginTransmission(DEVICE_I2C_ADDRESS);
  Wire.write(0x01);
  Wire.endTransmission();
  Serial.print("Read REG 0x01: ");
  Wire.requestFrom(DEVICE_I2C_ADDRESS, 1);
  reg14 = Wire.read();


  int x8 = bitRead(reg14, 7);
  Serial.print(x8);
  Serial.print(" ");

  int x9 = bitRead(reg14, 6);
  Serial.print(x9);
  Serial.print(" ");

  int x10 = bitRead(reg14, 5);
  Serial.print(x10);
  Serial.print(" ");

  int x11 = bitRead(reg14, 4);
  Serial.print(x11);
  Serial.print(" ");

  int x12 = bitRead(reg14, 3);
  Serial.print(x12);
  Serial.print(" ");

  int x13 = bitRead(reg14, 2);
  Serial.print(x13);
  Serial.print(" ");

  int x14 = bitRead(reg14, 1);
  Serial.print(x14);
  Serial.print(" ");

  int x15 = bitRead(reg14, 0);
  Serial.print(x15);
  Serial.println(" ");
  
  delay(200);

  Wire.beginTransmission(DEVICE_I2C_ADDRESS);
  Wire.write(0x02);
  Wire.endTransmission();
  Serial.print("Read REG 0x02: ");
  Wire.requestFrom(DEVICE_I2C_ADDRESS, 1);
  reg14 = Wire.read();


  int x16 = bitRead(reg14, 7);
  Serial.print(x16);
  Serial.print(" ");

  int x17 = bitRead(reg14, 6);
  Serial.print(x17);
  Serial.print(" ");

  int x18 = bitRead(reg14, 5);
  Serial.print(x18);
  Serial.print(" ");

  int x19 = bitRead(reg14, 4);
  Serial.print(x19);
  Serial.print(" ");

  int x20 = bitRead(reg14, 3);
  Serial.print(x20);
  Serial.print(" ");

  int x21 = bitRead(reg14, 2);
  Serial.print(x21);
  Serial.print(" ");

  int x22 = bitRead(reg14, 1);
  Serial.print(x22);
  Serial.print(" ");

  int x23 = bitRead(reg14, 0);
  Serial.print(x23);
  Serial.println(" ");
  
  delay(200);

  Wire.beginTransmission(DEVICE_I2C_ADDRESS);
  Wire.write(0x03);
  Wire.endTransmission();
  Serial.print("Read REG 0x03: ");
  Wire.requestFrom(DEVICE_I2C_ADDRESS, 1);
  reg14 = Wire.read();


  int x24 = bitRead(reg14, 7);
  Serial.print(x24);
  Serial.print(" ");

  int x25 = bitRead(reg14, 6);
  Serial.print(x25);
  Serial.print(" ");

  int x26 = bitRead(reg14, 5);
  Serial.print(x26);
  Serial.print(" ");

  int x27 = bitRead(reg14, 4);
  Serial.print(x27);
  Serial.print(" ");

  int x28 = bitRead(reg14, 3);
  Serial.print(x28);
  Serial.print(" ");

  int x29 = bitRead(reg14, 2);
  Serial.print(x29);
  Serial.print(" ");

  int x30 = bitRead(reg14, 1);
  Serial.print(x30);
  Serial.print(" ");

  int x31 = bitRead(reg14, 0);
  Serial.print(x31);
  Serial.println(" ");
  
  delay(200);

  Wire.beginTransmission(DEVICE_I2C_ADDRESS);
  Wire.write(0x04);
  Wire.endTransmission();
  Serial.print("Read REG 0x04: ");
  Wire.requestFrom(DEVICE_I2C_ADDRESS, 1);
  reg14 = Wire.read();


  int x32 = bitRead(reg14, 7);
  Serial.print(x32);
  Serial.print(" ");

  int x33 = bitRead(reg14, 6);
  Serial.print(x33);
  Serial.print(" ");

  int x34 = bitRead(reg14, 5);
  Serial.print(x34);
  Serial.print(" ");

  int x35 = bitRead(reg14, 4);
  Serial.print(x35);
  Serial.print(" ");

  int x36 = bitRead(reg14, 3);
  Serial.print(x36);
  Serial.print(" ");

  int x37 = bitRead(reg14, 2);
  Serial.print(x37);
  Serial.print(" ");

  int x38 = bitRead(reg14, 1);
  Serial.print(x38);
  Serial.print(" ");

  int x39 = bitRead(reg14, 0);
  Serial.print(x39);
  Serial.println(" ");
  
  delay(200);

  Wire.beginTransmission(DEVICE_I2C_ADDRESS);
  Wire.write(0x05);
  Wire.endTransmission();
  Serial.print("Read REG 0x05: ");
  Wire.requestFrom(DEVICE_I2C_ADDRESS, 1);
  reg14 = Wire.read();


  int x40 = bitRead(reg14, 7);
  Serial.print(x40);
  Serial.print(" ");

  int x41 = bitRead(reg14, 6);
  Serial.print(x41);
  Serial.print(" ");

  int x42 = bitRead(reg14, 5);
  Serial.print(x42);
  Serial.print(" ");

  int x43 = bitRead(reg14, 4);
  Serial.print(x43);
  Serial.print(" ");

  int x44 = bitRead(reg14, 3);
  Serial.print(x44);
  Serial.print(" ");

  int x45 = bitRead(reg14, 2);
  Serial.print(x45);
  Serial.print(" ");

  int x46 = bitRead(reg14, 1);
  Serial.print(x46);
  Serial.print(" ");

  int x47 = bitRead(reg14, 0);
  Serial.print(x47);
  Serial.println(" ");
  
  delay(200);

  Wire.beginTransmission(DEVICE_I2C_ADDRESS);
  Wire.write(0x06);
  Wire.endTransmission();
  Serial.print("Read REG 0x06: ");
  Wire.requestFrom(DEVICE_I2C_ADDRESS, 1);
  reg14 = Wire.read();


  int x48 = bitRead(reg14, 7);
  Serial.print(x48);
  Serial.print(" ");

  int x49 = bitRead(reg14, 6);
  Serial.print(x49);
  Serial.print(" ");

  int x50 = bitRead(reg14, 5);
  Serial.print(x50);
  Serial.print(" ");

  int x51 = bitRead(reg14, 4);
  Serial.print(x51);
  Serial.print(" ");

  int x52 = bitRead(reg14, 3);
  Serial.print(x52);
  Serial.print(" ");

  int x53 = bitRead(reg14, 2);
  Serial.print(x53);
  Serial.print(" ");

  int x54 = bitRead(reg14, 1);
  Serial.print(x54);
  Serial.print(" ");

  int x55 = bitRead(reg14, 0);
  Serial.print(x55);
  Serial.println(" ");
  
  delay(200);

  Wire.beginTransmission(DEVICE_I2C_ADDRESS);
  Wire.write(0x07);
  Wire.endTransmission();
  Serial.print("Read REG 0x07: ");
  Wire.requestFrom(DEVICE_I2C_ADDRESS, 1);
  reg14 = Wire.read();


  int x56 = bitRead(reg14, 7);
  Serial.print(x56);
  Serial.print(" ");

  int x57 = bitRead(reg14, 6);
  Serial.print(x57);
  Serial.print(" ");

  int x58 = bitRead(reg14, 5);
  Serial.print(x58);
  Serial.print(" ");

  int x59 = bitRead(reg14, 4);
  Serial.print(x59);
  Serial.print(" ");

  int x60 = bitRead(reg14, 3);
  Serial.print(x60);
  Serial.print(" ");

  int x61 = bitRead(reg14, 2);
  Serial.print(x61);
  Serial.print(" ");

  int x62 = bitRead(reg14, 1);
  Serial.print(x62);
  Serial.print(" ");

  int x63 = bitRead(reg14, 0);
  Serial.print(x63);
  Serial.println(" ");
  
  delay(200);

  Wire.beginTransmission(DEVICE_I2C_ADDRESS);
  Wire.write(0x08);
  Wire.endTransmission();
  Serial.print("Read REG 0x08: ");
  Wire.requestFrom(DEVICE_I2C_ADDRESS, 1);
  reg14 = Wire.read();


  int x64 = bitRead(reg14, 7);
  Serial.print(x64);
  Serial.print(" ");

  int x65 = bitRead(reg14, 6);
  Serial.print(x65);
  Serial.print(" ");

  int x66 = bitRead(reg14, 5);
  Serial.print(x66);
  Serial.print(" ");

  int x67 = bitRead(reg14, 4);
  Serial.print(x67);
  Serial.print(" ");

  int x68 = bitRead(reg14, 3);
  Serial.print(x68);
  Serial.print(" ");

  int x69 = bitRead(reg14, 2);
  Serial.print(x69);
  Serial.print(" ");

  int x70 = bitRead(reg14, 1);
  Serial.print(x70);
  Serial.print(" ");

  int x71 = bitRead(reg14, 0);
  Serial.print(x71);
  Serial.println(" ");
  
  delay(200);

  Wire.beginTransmission(DEVICE_I2C_ADDRESS);
  Wire.write(0x09);
  Wire.endTransmission();
  Serial.print("Read REG 0x09: ");
  Wire.requestFrom(DEVICE_I2C_ADDRESS, 1);
  reg14 = Wire.read();


  int x72 = bitRead(reg14, 7);
  Serial.print(x72);
  Serial.print(" ");

  int x73 = bitRead(reg14, 6);
  Serial.print(x73);
  Serial.print(" ");

  int x74 = bitRead(reg14, 5);
  Serial.print(x74);
  Serial.print(" ");

  int x75 = bitRead(reg14, 4);
  Serial.print(x75);
  Serial.print(" ");

  int x76 = bitRead(reg14, 3);
  Serial.print(x76);
  Serial.print(" ");

  int x77 = bitRead(reg14, 2);
  Serial.print(x77);
  Serial.print(" ");

  int x78 = bitRead(reg14, 1);
  Serial.print(x78);
  Serial.print(" ");

  int x79 = bitRead(reg14, 0);
  Serial.print(x79);
  Serial.println(" ");
  
  delay(200);

  Wire.beginTransmission(DEVICE_I2C_ADDRESS);
  Wire.write(0x0A);
  Wire.endTransmission();
  Serial.print("Read REG 0x0A: ");
  Wire.requestFrom(DEVICE_I2C_ADDRESS, 1);
  reg14 = Wire.read();


  int x80 = bitRead(reg14, 7);
  Serial.print(x80);
  Serial.print(" ");

  int x81 = bitRead(reg14, 6);
  Serial.print(x81);
  Serial.print(" ");

  int x82 = bitRead(reg14, 5);
  Serial.print(x82);
  Serial.print(" ");

  int x83 = bitRead(reg14, 4);
  Serial.print(x83);
  Serial.print(" ");

  int x84 = bitRead(reg14, 3);
  Serial.print(x84);
  Serial.print(" ");

  int x85 = bitRead(reg14, 2);
  Serial.print(x85);
  Serial.print(" ");

  int x86 = bitRead(reg14, 1);
  Serial.print(x86);
  Serial.print(" ");

  int x87 = bitRead(reg14, 0);
  Serial.print(x87);
  Serial.println(" ");
  
  delay(200);

  Wire.beginTransmission(DEVICE_I2C_ADDRESS);
  Wire.write(0x0B);
  Wire.endTransmission();
  Serial.print("Read REG 0x0B: ");
  Wire.requestFrom(DEVICE_I2C_ADDRESS, 1);
  reg14 = Wire.read();


  int x88 = bitRead(reg14, 7);
  Serial.print(x88);
  Serial.print(" ");

  int x89 = bitRead(reg14, 6);
  Serial.print(x89);
  Serial.print(" ");

  int x90 = bitRead(reg14, 5);
  Serial.print(x90);
  Serial.print(" ");

  int x91 = bitRead(reg14, 4);
  Serial.print(x91);
  Serial.print(" ");

  int x92 = bitRead(reg14, 3);
  Serial.print(x92);
  Serial.print(" ");

  int x93 = bitRead(reg14, 2);
  Serial.print(x93);
  Serial.print(" ");

  int x94 = bitRead(reg14, 1);
  Serial.print(x94);
  Serial.print(" ");

  int x95 = bitRead(reg14, 0);
  Serial.print(x95);
  Serial.println(" ");
  
  delay(200);

  Wire.beginTransmission(DEVICE_I2C_ADDRESS);
  Wire.write(0x0C);
  Wire.endTransmission();
  Serial.print("Read REG 0x0C: ");
  Wire.requestFrom(DEVICE_I2C_ADDRESS, 1);
  reg14 = Wire.read();


  int x96 = bitRead(reg14, 7);
  Serial.print(x96);
  Serial.print(" ");

  int x97 = bitRead(reg14, 6);
  Serial.print(x97);
  Serial.print(" ");

  int x98 = bitRead(reg14, 5);
  Serial.print(x98);
  Serial.print(" ");

  int x99 = bitRead(reg14, 4);
  Serial.print(x99);
  Serial.print(" ");

  int x100 = bitRead(reg14, 3);
  Serial.print(x100);
  Serial.print(" ");

  int x101 = bitRead(reg14, 2);
  Serial.print(x101);
  Serial.print(" ");

  int x102 = bitRead(reg14, 1);
  Serial.print(x102);
  Serial.print(" ");

  int x103 = bitRead(reg14, 0);
  Serial.print(x103);
  Serial.println(" ");
  
  delay(200);

  Wire.beginTransmission(DEVICE_I2C_ADDRESS);
  Wire.write(0x0D);
  Wire.endTransmission();
  Serial.print("Read REG 0x0D: ");
  Wire.requestFrom(DEVICE_I2C_ADDRESS, 1);
  reg14 = Wire.read();


  int x104 = bitRead(reg14, 7);
  Serial.print(x104);
  Serial.print(" ");

  int x105 = bitRead(reg14, 6);
  Serial.print(x105);
  Serial.print(" ");

  int x106 = bitRead(reg14, 5);
  Serial.print(x106);
  Serial.print(" ");

  int x107 = bitRead(reg14, 4);
  Serial.print(x107);
  Serial.print(" ");

  int x108 = bitRead(reg14, 3);
  Serial.print(x108);
  Serial.print(" ");

  int x109 = bitRead(reg14, 2);
  Serial.print(x109);
  Serial.print(" ");

  int x110 = bitRead(reg14, 1);
  Serial.print(x110);
  Serial.print(" ");

  int x111 = bitRead(reg14, 0);
  Serial.print(x111);
  Serial.println(" ");
  
  delay(200);

  Wire.beginTransmission(DEVICE_I2C_ADDRESS);
  Wire.write(0x0E);
  Wire.endTransmission();
  Serial.print("Read REG 0x0E: ");
  Wire.requestFrom(DEVICE_I2C_ADDRESS, 1);
  reg14 = Wire.read();


  int x112 = bitRead(reg14, 7);
  Serial.print(x112);
  Serial.print(" ");

  int x113 = bitRead(reg14, 6);
  Serial.print(x113);
  Serial.print(" ");

  int x114 = bitRead(reg14, 5);
  Serial.print(x114);
  Serial.print(" ");

  int x115 = bitRead(reg14, 4);
  Serial.print(x115);
  Serial.print(" ");

  int x116 = bitRead(reg14, 3);
  Serial.print(x116);
  Serial.print(" ");

  int x117 = bitRead(reg14, 2);
  Serial.print(x117);
  Serial.print(" ");

  int x118 = bitRead(reg14, 1);
  Serial.print(x118);
  Serial.print(" ");

  int x119 = bitRead(reg14, 0);
  Serial.print(x119);
  Serial.println(" ");
  
  delay(200);

  Wire.beginTransmission(DEVICE_I2C_ADDRESS);
  Wire.write(0x0F);
  Wire.endTransmission();
  Serial.print("Read REG 0x0F: ");
  Wire.requestFrom(DEVICE_I2C_ADDRESS, 1);
  reg14 = Wire.read();


  int x120 = bitRead(reg14, 7);
  Serial.print(x120);
  Serial.print(" ");

  int x121 = bitRead(reg14, 6);
  Serial.print(x121);
  Serial.print(" ");

  int x122 = bitRead(reg14, 5);
  Serial.print(x122);
  Serial.print(" ");

  int x123 = bitRead(reg14, 4);
  Serial.print(x123);
  Serial.print(" ");

  int x124 = bitRead(reg14, 3);
  Serial.print(x124);
  Serial.print(" ");

  int x125 = bitRead(reg14, 2);
  Serial.print(x125);
  Serial.print(" ");

  int x126 = bitRead(reg14, 1);
  Serial.print(x126);
  Serial.print(" ");

  int x127 = bitRead(reg14, 0);
  Serial.print(x127);
  Serial.println(" ");
  
  delay(200);

  Wire.beginTransmission(DEVICE_I2C_ADDRESS);
  Wire.write(0x10);
  Wire.endTransmission();
  Serial.print("Read REG 0x10: ");
  Wire.requestFrom(DEVICE_I2C_ADDRESS, 1);
  reg14 = Wire.read();


  int x128 = bitRead(reg14, 7);
  Serial.print(x128);
  Serial.print(" ");

  int x129 = bitRead(reg14, 6);
  Serial.print(x129);
  Serial.print(" ");

  int x130 = bitRead(reg14, 5);
  Serial.print(x130);
  Serial.print(" ");

  int x131 = bitRead(reg14, 4);
  Serial.print(x131);
  Serial.print(" ");

  int x132 = bitRead(reg14, 3);
  Serial.print(x132);
  Serial.print(" ");

  int x133 = bitRead(reg14, 2);
  Serial.print(x133);
  Serial.print(" ");

  int x134 = bitRead(reg14, 1);
  Serial.print(x134);
  Serial.print(" ");

  int x135 = bitRead(reg14, 0);
  Serial.print(x135);
  Serial.println(" ");
  
  delay(200);

  Wire.beginTransmission(DEVICE_I2C_ADDRESS);
  Wire.write(0x11);
  Wire.endTransmission();
  Serial.print("Read REG 0x11: ");
  Wire.requestFrom(DEVICE_I2C_ADDRESS, 1);
  reg14 = Wire.read();


  int x136 = bitRead(reg14, 7);
  Serial.print(x136);
  Serial.print(" ");

  int x137 = bitRead(reg14, 6);
  Serial.print(x137);
  Serial.print(" ");

  int x138 = bitRead(reg14, 5);
  Serial.print(x138);
  Serial.print(" ");

  int x139 = bitRead(reg14, 4);
  Serial.print(x139);
  Serial.print(" ");

  int x140 = bitRead(reg14, 3);
  Serial.print(x140);
  Serial.print(" ");

  int x141 = bitRead(reg14, 2);
  Serial.print(x141);
  Serial.print(" ");

  int x142 = bitRead(reg14, 1);
  Serial.print(x142);
  Serial.print(" ");

  int x143 = bitRead(reg14, 0);
  Serial.print(x143);
  Serial.println(" ");
  
  delay(200);

  Wire.beginTransmission(DEVICE_I2C_ADDRESS);
  Wire.write(0x12);
  Wire.endTransmission();
  Serial.print("Read REG 0x12: ");
  Wire.requestFrom(DEVICE_I2C_ADDRESS, 1);
  reg14 = Wire.read();


  int x144 = bitRead(reg14, 7);
  Serial.print(x144);
  Serial.print(" ");

  int x145 = bitRead(reg14, 6);
  Serial.print(x145);
  Serial.print(" ");

  int x146 = bitRead(reg14, 5);
  Serial.print(x146);
  Serial.print(" ");

  int x147 = bitRead(reg14, 4);
  Serial.print(x147);
  Serial.print(" ");

  int x148 = bitRead(reg14, 3);
  Serial.print(x148);
  Serial.print(" ");

  int x149 = bitRead(reg14, 2);
  Serial.print(x149);
  Serial.print(" ");

  int x150 = bitRead(reg14, 1);
  Serial.print(x150);
  Serial.print(" ");

  int x151 = bitRead(reg14, 0);
  Serial.print(x151);
  Serial.println(" ");
  
  delay(200);

  Wire.beginTransmission(DEVICE_I2C_ADDRESS);
  Wire.write(0x13);
  Wire.endTransmission();
  Serial.print("Read REG 0x13: ");
  Wire.requestFrom(DEVICE_I2C_ADDRESS, 1);
  reg14 = Wire.read();


  int x152 = bitRead(reg14, 7);
  Serial.print(x152);
  Serial.print(" ");

  int x153 = bitRead(reg14, 6);
  Serial.print(x153);
  Serial.print(" ");

  int x154 = bitRead(reg14, 5);
  Serial.print(x154);
  Serial.print(" ");

  int x155 = bitRead(reg14, 4);
  Serial.print(x155);
  Serial.print(" ");

  int x156 = bitRead(reg14, 3);
  Serial.print(x156);
  Serial.print(" ");

  int x157 = bitRead(reg14, 2);
  Serial.print(x157);
  Serial.print(" ");

  int x158 = bitRead(reg14, 1);
  Serial.print(x158);
  Serial.print(" ");

  int x159 = bitRead(reg14, 0);
  Serial.print(x159);
  Serial.println(" ");
  
  delay(200);

  Wire.beginTransmission(DEVICE_I2C_ADDRESS);
  Wire.write(0x14);
  Wire.endTransmission();
  Serial.print("Read REG 0x14: ");
  Wire.requestFrom(DEVICE_I2C_ADDRESS, 1);
  reg14 = Wire.read();


  int x160 = bitRead(reg14, 7);
  Serial.print(x160);
  Serial.print(" ");

  int x161 = bitRead(reg14, 6);
  Serial.print(x161);
  Serial.print(" ");

  int x162 = bitRead(reg14, 5);
  Serial.print(x162);
  Serial.print(" ");

  int x163 = bitRead(reg14, 4);
  Serial.print(x163);
  Serial.print(" ");

  int x164 = bitRead(reg14, 3);
  Serial.print(x164);
  Serial.print(" ");

  int x165 = bitRead(reg14, 2);
  Serial.print(x165);
  Serial.print(" ");

  int x166 = bitRead(reg14, 1);
  Serial.print(x166);
  Serial.print(" ");

  int x167 = bitRead(reg14, 0);
  Serial.print(x167);
  Serial.println(" ");
  
  delay(200);
}
