/*
 * Internal_eeprom.cpp
 *
 * Created: 04/11/2023 15:55:23
 * Author: Fabrício Ribeiro
 * Versão: 1.0
 */ 

#include "Arduino.h"
#include <EEPROM.h>
#include "Internal_eeprom.h"

//---------------------------------------------------------------------------

//Escreve 1 bit
void write_int1_eeprom(uint16_t Address, uint8_t bitPosition, bool data)
{
	//Só grava se o dado atual for diferente do dado gravado
	if(read_int1_eeprom(Address, bitPosition) != data){

		uint8_t stored_data;

		stored_data = EEPROM.read(Address);

		if(data){
			bitSet(stored_data, bitPosition);
		}
		else{
			bitClear(stored_data, bitPosition);
		}

		EEPROM.write(Address, stored_data);
	}
}

//Lê 1 bit
bool read_int1_eeprom(uint16_t Address, uint8_t bitPosition)
{
   return bitRead(EEPROM.read(Address), bitPosition);
}

//---------------------------------------------------------------------------

//Escreve 8 bit
void write_int8_eeprom(uint16_t Address, uint8_t data)
{
	//Só grava se o dado atual for diferente do dado gravado
	if(read_int8_eeprom(Address) != data){
		EEPROM.write(Address, data);
	}
}

//Lê 8 bits
uint8_t read_int8_eeprom(uint16_t Address)
{
   return EEPROM.read(Address);
}

//---------------------------------------------------------------------------

//Escreve 16 bit
void write_int16_eeprom(uint16_t Address, uint16_t data)
{
	//Só grava se o dado atual for diferente do dado gravado
	if(read_int16_eeprom(Address) != data){
		for(uint8_t i=0; i<2; i++){
			EEPROM.write(Address + i, *((uint8_t *)(&data) + i));
		}
	}
}

//Lê 16 bits
uint16_t read_int16_eeprom(uint16_t Address)
{
   uint16_t data;

   for(uint8_t i=0; i<2; ++i){
     *((uint8_t *)(&data) + i) = EEPROM.read(Address + i);
   }

   return(data);
}

//---------------------------------------------------------------------------

//Escreve 32 bit
void write_int32_eeprom(uint16_t Address, uint32_t data)
{ 
	if(read_int32_eeprom(Address) != data){
		for(uint8_t i=0; i<4; i++){
			EEPROM.write(Address + i, *((uint8_t *)(&data) + i));
		}
	}
}

//Lê 32 bits
uint32_t read_int32_eeprom(uint16_t Address)
{
	uint32_t data;
   
	for(uint8_t i=0; i<4; i++){
		*((uint8_t *)(&data) + i) = EEPROM.read(Address + i);
	}

	return(data);
}

//---------------------------------------------------------------------------

//Escreve int 16 bit
void write_int_eeprom(uint16_t Address, int data)
{
	int data_aux = read_int_eeprom(Address);

	if(data_aux != data){
		for(uint8_t i=0; i<2; i++){
			EEPROM.write(Address + i, *((uint8_t *)(&data) + i));
		}		
	} 
}

//Lê int 16 bit
int read_int_eeprom(uint16_t Address)
{
	int data;
   
	for(uint8_t i=0; i<2; i++){
		*((uint8_t *)(&data) + i) = EEPROM.read(Address + i);
	}

   return(data);
}

//---------------------------------------------------------------------------

//Escreve long 32 bit
void write_long_eeprom(uint16_t Address, long data)
{
	long data_aux = read_long_eeprom(Address);

	if(data_aux != data){
		for(uint8_t i=0; i<4; i++){
			EEPROM.write(Address + i, *((uint8_t *)(&data) + i));
		}		
	} 
}

//Lê long 32 bit
long read_long_eeprom(uint16_t Address)
{
	long data;
   
	for(uint8_t i=0; i<4; i++){
		*((uint8_t *)(&data) + i) = EEPROM.read(Address + i);
	}

   return(data);
}

//---------------------------------------------------------------------------

//Escreve float 32 bit
void write_float_eeprom(uint16_t Address, float data)
{
	float data_aux = read_float_eeprom(Address);

	if(data_aux != data){
		for(uint8_t i=0; i<4; i++){
			EEPROM.write(Address + i, *((uint8_t *)(&data) + i));
		}		
	} 
}

//Lê float 32 bit
float read_float_eeprom(uint16_t Address)
{
	float data;
   
	for(uint8_t i=0; i<4; i++){
		*((uint8_t *)(&data) + i) = EEPROM.read(Address + i);
	}

   return(data);
}

//---------------------------------------------------------------------------