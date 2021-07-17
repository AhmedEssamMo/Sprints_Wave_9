#include"Macros.h"
#include"TypeDef.h"
#include"DIO_REG.h"
#include"DIO_retval.h"
#include"DIO.h"


void LED_Init(uint8_t PortID, uint8_t PinNumber){
	uint8_t state=0;
	state=DIO_setPinDirection(PortID,PinNumber,PIN_OUTPUT);
}
void LED_toggle(uint8_t PortID, uint8_t PinNumber){
	uint8_t state=0;
	state=DIO_TogglePin(PortID,PinNumber);
}
