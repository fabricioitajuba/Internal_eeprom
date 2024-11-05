/*
Programa para leitura e escrita da memória EEPROM
Autor: Fabrício Ribeiro
Data: 05/11/2024
*/

#include <Internal_eeprom.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x20, 20, 4);

void setup() {

  bool bit0;
  uint8_t dado1;
  uint16_t dado2;
  uint32_t dado3;
  float dado4;
  int dado5;
  long dado6;

  lcd.init();
  lcd.backlight();

  //1 byte x 8 bits
  write_int1_eeprom(0, 0, 1);//Endereço, bit, dado 
  bit0 = read_int1_eeprom(0, 0);//Endereço, bit

  //1 byte
  write_int8_eeprom(1, 123);//Endereço, dado
  dado1 = read_int8_eeprom(1);//Endereço

  //2 byte
  write_int16_eeprom(2, 12345);//Endereço, dado
  dado2 = read_int16_eeprom(2);//Endereço

  //4 byte
  write_int32_eeprom(4, 123456);//Endereço, dado
  dado3 = read_int32_eeprom(4);//Endereço

  //4 byte
  write_float_eeprom(8, -1234.567);//Endereço, dado
  dado4 = read_float_eeprom(8);//Endereço  

  //2 byte
  write_int_eeprom(12, -32768);//Endereço, dado
  dado5 = read_int_eeprom(12);//Endereço   

  //4 byte
  write_long_eeprom(14, -2147483648);//Endereço, dado
  dado6 = read_long_eeprom(14);//Endereço      

  //bit0
  lcd.setCursor(0, 0);
  lcd.print("bit0=");
  if(bit0)
    lcd.print("1");
  else
    lcd.print("0");

  //dado1
  //lcd.setCursor(0, 1);
  //lcd.print("dado1=");
  //lcd.print(dado1, DEC);

  //dado2
  //lcd.setCursor(0, 2);
  //lcd.print("dado2=");
  //lcd.print(dado2, DEC);

  //dado3
  //lcd.setCursor(0, 3);
  //lcd.print("dado3=");
  //lcd.print(dado3, DEC);

  //dado4
  lcd.setCursor(0, 1);
  lcd.print("float: ");
  lcd.print(dado4, 3); 

  //dado5
  lcd.setCursor(0, 2);
  lcd.print("int: ");
  lcd.print(dado5, DEC);

  //dado6
  lcd.setCursor(0, 3);
  lcd.print("long: ");
  lcd.print(dado6, DEC);      

}

void loop() {


}
