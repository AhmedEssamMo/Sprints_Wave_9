#ifndef LED_H_
#define LED_H_

#include"../../Infrastructure/Macros.h"
#include"../../Infrastructure/TypeDef.h"
#include"../../Mcal/DIO/DIO.h"
#include"led_config.h"




uint8_t LED_Init(void);
uint8_t LED_On(uint8_t LedNumber);
uint8_t LED_Off(uint8_t LedNumber);
uint8_t LED_Toggle(uint8_t LedNumber);
uint8_t LED_Status(uint8_t LedNumber, uint8_t* LedState);

#endif /*LED_H_*/
