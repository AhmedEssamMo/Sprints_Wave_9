#include "eeprom.h"




uint8_t EEPROM_Read(uint8_t EEPROM_CH, uint8_t address, uint8_t * data){

	TWI_SendStartCondition(TWI_1);

	TWI_SendSLAWrite(TWI_1,EEPROM_CH);

	TWI_SendData(TWI_1,address);

	TWI_SendStartCondition(TWI_1);

	TWI_SendSLARead(TWI_1,EEPROM_CH);

	TWI_RecDataAck(TWI_1,data);

	TWI_SendStopCondition(TWI_1);

	return 0;
}
uint8_t EEPROM_Write(uint8_t EEPROM_CH, uint8_t address, uint8_t data){

	TWI_SendStartCondition(TWI_1);

	TWI_SendSLAWrite(TWI_1,EEPROM_CH);

	TWI_SendData(TWI_1,address);

	TWI_SendData(TWI_1,data);

	TWI_SendStopCondition(TWI_1);

	return 0;
}
