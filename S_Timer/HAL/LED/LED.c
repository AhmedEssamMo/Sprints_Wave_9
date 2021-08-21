/*- INCLUDES
----------------------------------------------*/
#include "LED.h"
/*- APIs IMPLEMENTATION
-----------------------------------*/
ERROR_STATE_t LED_Init(uint8_t LED_ID){
	ERROR_STATE_t u8_ERROR_STAT = ERROR_OK;
	switch(LED_ID)
	{
	    case LED1:
            DIO_setPinDirection(LED_PORT1, LED_PIN1, PIN_OUTPUT);
            break;
        case LED2:
            DIO_setPinDirection(LED_PORT2, LED_PIN2, PIN_OUTPUT);
            break;
        case LED3:
            DIO_setPinDirection(LED_PORT3, LED_PIN3, PIN_OUTPUT);
            break;
        default:
            u8_ERROR_STAT = ERROR_NOK;
            break;
	}
	return u8_ERROR_STAT;
}
ERROR_STATE_t LED_toggle(uint8_t LED_ID){
	ERROR_STATE_t u8_ERROR_STAT = ERROR_OK;
	switch(LED_ID)
	{
	    case LED1:
            DIO_TogglePin(LED_PORT1, LED_PIN1);
            break;
        case LED2:
            DIO_TogglePin(LED_PORT2, LED_PIN2);
            break;
        case LED3:
            DIO_TogglePin(LED_PORT3, LED_PIN3);
            break;
        default:
            u8_ERROR_STAT = ERROR_NOK;
            break;
	}
	return u8_ERROR_STAT;
}
