#ifndef LED_H_
#define LED_H_
/*- INCLUDES
----------------------------------------------*/
#include "../../MCAL/DIO/DIO.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "LED_Config.h"
/*- MACROS------------------------*/
#define LED1       (uint8_t)0
#define LED2       (uint8_t)1
#define LED3       (uint8_t)2
#define LED4       (uint8_t)3
#define LED5       (uint8_t)4
/*- FUNCTION DECLARATIONS ----------------------------------*/
ERROR_STATE_t LED_Init(uint8_t LED_ID);
ERROR_STATE_t LED_toggle(uint8_t LED_ID);

#endif /*LED_H_*/
