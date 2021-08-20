#ifndef Button_H_
#define Button_H_
/*- INCLUDES----------------------------------------------*/
#include "Button_Conifg.h"
#include "../../MCAL/DIO/DIO.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
/*- MACROS------------------------*/
#define BUTTON1         (uint8_t)0
#define BUTTON2         (uint8_t)1
#define BUTTON3         (uint8_t)2
#define BUTTON4         (uint8_t)3
#define BUTTON5         (uint8_t)4
#define BUTTON_PUSHED   (uint8_t)0
#define BUTTON_RELEASED (uint8_t)1
/*- APIs DECLARATION------------------------*/
ERROR_STATE_t Button_Init(uint8_t Button_ID);
ERROR_STATE_t Button_getState(uint8_t Button_ID,ptr_uint8_t State);
#endif  /*Button_H_*/
