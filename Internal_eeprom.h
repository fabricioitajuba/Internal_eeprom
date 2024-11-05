/*
 * Internal_eeprom.h
 *
 * Created: 04/11/2023 15:55:23
 * Author: Fabrício Ribeiro
 * Versão: 1.0
*/ 


#ifndef Internal_eeprom_H_
#define Internal_eeprom_H_

#include "Arduino.h"

void write_int1_eeprom(uint16_t Address, uint8_t bitPosition, bool data);//1 Byte x 8 bit
bool read_int1_eeprom(uint16_t Address, uint8_t bitPosition);//1 Byte x 8 bit

void write_int8_eeprom(uint16_t Address, uint8_t data);//1 Byte
uint8_t read_int8_eeprom(uint16_t Address);//1 Byte

void write_int16_eeprom(uint16_t Address, uint16_t data);//2 Byte
uint16_t read_int16_eeprom(uint16_t Address);//2 Byte

void write_int32_eeprom(uint16_t Address, uint32_t data);//4 Byte
uint32_t read_int32_eeprom(uint16_t Address);//4 Byte

void write_int_eeprom(uint16_t Address, int data);//2 Byte
int read_int_eeprom(uint16_t Address);//2 Byte

void write_long_eeprom(uint16_t Address, long data);//4 Byte
long read_long_eeprom(uint16_t Address);//4 Byte

void write_float_eeprom(uint16_t Address, float data);//4 Byte
float read_float_eeprom(uint16_t Address);//4 Byte

#endif /* Internal_eeprom_H_ */