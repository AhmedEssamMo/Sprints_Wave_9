#include"Macros.h"
#include"TypeDef.h"
#include"Button_retval.h"
#include"DIO_retval.h"
#include"DIO_REG.h"
#include"DIO.h"
#include<util/delay.h>

Button_ERROR_state_t Button_Init(uint8_t PortID, uint8_t PinNumber) {
	uint8_t state = 0;
	state = DIO_setPinDirection(PortID, PinNumber, PIN_INPUT);
	state = DIO_SetPullupRes(PortID, PIN_INPUT);
	if (state > E_DIO_SUCCESS) {
		return E_Button_INVALID ;
	}

	else {
		return E_Button_SUCCESS ;

	}
}
uint8_t Button_getState(uint8_t PortID, uint8_t PinNumber) {
	uint8_t currentValue = 0;
	uint8_t state=0;
	uint8_t oldValue = 0;
	volatile uint8_t counter = 0;
	volatile uint32_t Delay = 0;
	while (counter < 10) {
		state=DIO_readPin(PORTA, PIN4, &currentValue);
		if (currentValue == oldValue) {
			counter++;
		} else {
			counter = 0;
		}
		oldValue = currentValue;
	}
	return currentValue;
}
