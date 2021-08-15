#include"led.h"

//PINS States
#define PIN_INPUT  (uint8_t)0 //0 sets the pin input
#define PIN_OUTPUT (uint8_t)1 //1 sets the pin output
#define PIN_HIGH (uint8_t)1
#define PIN_LOW  (uint8_t)0




uint8_t LED_Init(void){
#if LED_1
	DIO_SetPinDirection(LED_1_PORT,LED_1_PIN,PIN_OUTPUT);
#endif
#if LED_2
	DIO_SetPinDirection(LED_2_PORT,LED_2_PIN,PIN_OUTPUT);
#endif
#if LED_3
	DIO_SetPinDirection(LED_3_PORT,LED_3_PIN,PIN_OUTPUT);
#endif
	return 0;
}
uint8_t LED_On(uint8_t LedNumber){
	switch (LedNumber){
	case LED_1:
		DIO_WritePin(LED_1_PORT,LED_1_PIN,PIN_HIGH);
		break;
	case LED_2:
		DIO_WritePin(LED_2_PORT,LED_2_PIN,PIN_HIGH);
		break;
	case LED_3:
		DIO_WritePin(LED_3_PORT,LED_3_PIN,PIN_HIGH);
		break;
	}
	return 0;

}
uint8_t LED_Off(uint8_t LedNumber){
	switch (LedNumber){
	case LED_1:
		DIO_WritePin(LED_1_PORT,LED_1_PIN,PIN_LOW);
		break;
	case LED_2:
		DIO_WritePin(LED_2_PORT,LED_2_PIN,PIN_LOW);
		break;
	case LED_3:
		DIO_WritePin(LED_3_PORT,LED_3_PIN,PIN_LOW);
		break;
	}

	return 0;
}
uint8_t LED_Toggle(uint8_t LedNumber){
	switch (LedNumber){
	case LED_1:
		DIO_TogglePin(LED_1_PORT,LED_1_PIN);
		break;
	case LED_2:
		DIO_TogglePin(LED_2_PORT,LED_2_PIN);
		break;
	case LED_3:
		DIO_TogglePin(LED_3_PORT,LED_3_PIN);
		break;
	}
	return 0;

}
uint8_t LED_Status(uint8_t LedNumber, uint8_t* LedState){
	switch (LedNumber){
	case LED_1:
		DIO_ReadPin(LED_1_PORT,LED_1_PIN,LedState);
		break;
	case LED_2:
		DIO_ReadPin(LED_2_PORT,LED_2_PIN,LedState);
		break;
	case LED_3:
		DIO_ReadPin(LED_3_PORT,LED_3_PIN,LedState);
		break;
	}
	return 0;

}
