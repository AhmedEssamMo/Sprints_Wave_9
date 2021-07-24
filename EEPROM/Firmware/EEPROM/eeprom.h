#ifndef EEPRROM_H_
#define EEPRROM_H_
/*----INCLUDES----*/
#include"../../Infrastructure/Macros.h"
#include"../../Infrastructure/TypeDef.h"
#include"../../Mcal/TWI/twi.h"
#include"../../Mcal/UART/uart.h"
#include"eepromConfig.h"

/*----MACROS----*/
#define EEPROM_1_B1 0b01010000
#define EEPROM_1_B2 0b01010001
#define EEPROM_1_B3 0b01010010
#define EEPROM_1_B4 0b01010011
#define EEPROM_1_B5 0b01010100
#define EEPROM_1_B6 0b01010101
#define EEPROM_1_B7 0b01010110
#define EEPROM_1_B8 0b01010111

/*----Function declarations----*/

uint8_t EEPROM_Read(uint8_t EEPROM_CH, uint8_t address, uint8_t * data);
uint8_t EEPROM_Write(uint8_t EEPROM_CH, uint8_t address, uint8_t data);



#endif  /*EEPRROM_H_*/
