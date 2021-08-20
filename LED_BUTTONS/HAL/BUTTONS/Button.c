/*- INCLUDES----------------------------------------------*/
#include "Button.h"
//#include<util/delay.h>
/*- APIs IMPLEMENTATION----------------------------------------------*/
ERROR_STATE_t Button_Init(uint8_t Button_ID)
{
	ERROR_STATE_t u8_ERROR_STAT = ERROR_OK;
	switch(Button_ID)
	{
	    case BUTTON1:
            DIO_setPinDirection(BUTTON_PORT1, BUTTON_PIN1, PIN_INPUT);
            DIO_SetPullupRes(BUTTON_PORT1, BUTTON_PIN1);
            break;
        case BUTTON2:
            DIO_setPinDirection(BUTTON_PORT2, BUTTON_PIN2, PIN_INPUT);
            DIO_SetPullupRes(BUTTON_PORT2, BUTTON_PIN2);
            break;
        case BUTTON3:
            DIO_setPinDirection(BUTTON_PORT3, BUTTON_PIN3, PIN_INPUT);
            DIO_SetPullupRes(BUTTON_PORT3, BUTTON_PIN3);
            break;
        default:
            u8_ERROR_STAT = ERROR_NOK;
            break;
	}
	return u8_ERROR_STAT;
}
ERROR_STATE_t Button_getState(uint8_t Button_ID,ptr_uint8_t State)
{
	ERROR_STATE_t u8_ERROR_STAT = ERROR_OK;
	uint8_t u8_currentValue = 0;
	uint8_t u8_oldValue = 0;
	volatile uint8_t u8_counter = 0;
	if(NULL_PTR==State)
    {
        u8_ERROR_STAT = ERROR_NOK;
	}
	else
    {
        /*Debounce handling*/

        switch(Button_ID)
        {
            case BUTTON1:
                for(u8_counter=0;u8_counter<10;u8_counter++)
                {
                DIO_readPin(BUTTON_PORT1, BUTTON_PIN1, &u8_currentValue);
                if (u8_currentValue == u8_oldValue)
                {
                    u8_counter++;
                }
                else
                {
                    u8_counter = 0;
                }
                u8_oldValue = u8_currentValue;
                }
                break;
            case BUTTON2:
                for(u8_counter=0;u8_counter<10;u8_counter++)
                {
                DIO_readPin(BUTTON_PORT2, BUTTON_PIN2, &u8_currentValue);
                if (u8_currentValue == u8_oldValue)
                {
                    u8_counter++;
                }
                else
                {
                    u8_counter = 0;
                }
                u8_oldValue = u8_currentValue;
                }
                break;
            case BUTTON3:
                for(u8_counter=0;u8_counter<10;u8_counter++)
                {
                DIO_readPin(BUTTON_PORT3, BUTTON_PIN3, &u8_currentValue);
                if (u8_currentValue == u8_oldValue)
                {
                    u8_counter++;
                }
                else
                {
                    u8_counter = 0;
                }
                u8_oldValue = u8_currentValue;
                }
                break;
            default:
                u8_ERROR_STAT = ERROR_NOK;
                break;
        }
	}
	*State=u8_currentValue;
	return u8_ERROR_STAT;
}
