#Internal_eeprom

Biblioteca para trabalhar com eeprom do Arduino - versão 1.0

Esta biblioteca permite armazenar números na memória eeprom do arduino.

Permite trabalhar com bit, int, long, float, unsigned int8, unsigned int16, unsigned int32.

Antes de gravar o dado na memória, o dado é lido na posição e só grava se o dado for diferente.

Para guardar apenas um bit (0 ou 1) escolha um endereço e qual bit do byte você quer gravar.

Exemplo:

#define OFF 0
#define ON 1

#define status 0 //Define o endereço de status como 0x00
#define enable 0 //Define o bit 0 do registro de status como enable
#define port1 1 //Define o bit 1 do registro de status como port1
#define port2 2 //Define o bit 2 do registro de status como port2

//para gravar um bit nessa posição:
write_int1_eeprom(status, enable, ON); //(endereço, posição, dado)
write_int1_eeprom(status, port1, ON);
write_int1_eeprom(status, port2, OFF);

//para ler um bit no registro status
bool teste = read_int1_eeprom(status, port1);


Para adicionar a biblioteca, faça o download e na IDE do Arduino, vá em:
Sketch->Include Library->Add .ZIP Library "local da biblioteca .zip"

Essa biblioteca permite as seguintes funções:

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
