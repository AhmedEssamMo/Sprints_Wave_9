/*
 * LCD.c
 *
 *  Created on: Apr 2, 2021
 *      Author: Ahmed
 */

#include"lcd.h"

//#define F_CPU 8000000UL
//static uint8_t cursor_postion=0;

#define LCD_RetrunHome    0b00000010
#define LCD_DISP_CLEAR    0b00000001
#define LCD_ClrDisplay    0b00000001
#define LCD_firstRow      0b10000000
#define LCD_SecRow        0b11000000

//static uint8_t gu16_dummy=0;

static uint8_t LCD_SendCmd(uint8_t LOC_u8Command);

static uint8_t LCD_SendCmd(uint8_t LOC_u8Command) {
	DIO_WritePin(LCD_CTRL_PORT, LCD_RS_PIN, PIN_LOW);
	DIO_WritePin(LCD_CTRL_PORT, LCD_RW_PIN, PIN_LOW);

	DIO_writePort(LCD_DATA_PORT, LOC_u8Command);
	DIO_WritePin(LCD_CTRL_PORT, LCD_EN_PIN, PIN_HIGH);
	//DELAY 1 MS
	DIO_WritePin(LCD_CTRL_PORT, LCD_EN_PIN, PIN_LOW);
	//DELAY 1 MS
	return 0;
}

uint8_t LCD_SendChar(uint8_t LOC_u8Char) {
	DIO_WritePin(LCD_CTRL_PORT, LCD_RS_PIN, PIN_HIGH);
	DIO_WritePin(LCD_CTRL_PORT, LCD_RW_PIN, PIN_LOW);
	DIO_writePort(LCD_DATA_PORT, LOC_u8Char);
	DIO_WritePin(LCD_CTRL_PORT, LCD_EN_PIN, PIN_HIGH);
//	_delay_ms(1);
	DIO_WritePin(LCD_CTRL_PORT, LCD_EN_PIN, PIN_LOW);
//	_delay_ms(1);
	return 0;
}

uint8_t LCD_Initialization(void) {
	volatile uint32_t  Dummy_Delay=0;
	/*INIT THE LCD PINS*/
	DIO_SetPinDirection(LCD_CTRL_PORT, LCD_RS_PIN, PIN_OUTPUT);
	DIO_SetPinDirection(LCD_CTRL_PORT, LCD_RW_PIN, PIN_OUTPUT);
	DIO_SetPinDirection(LCD_CTRL_PORT, LCD_EN_PIN, PIN_OUTPUT);
	DIO_SetPortDirection(LCD_DATA_PORT, PORT_OUTPUT);
	for(Dummy_Delay=0;Dummy_Delay<=200000;Dummy_Delay++){

	}
//	_delay_ms(50);
	LCD_SendCmd(LCD_FUNC_SET);
	for(Dummy_Delay=0;Dummy_Delay<=40000;Dummy_Delay++){}
//	_delay_ms(10);
	LCD_SendCmd(LCD_DISP_ON_OFF_CTRL);
	for(Dummy_Delay=0;Dummy_Delay<=40000;Dummy_Delay++){}
//	_delay_ms(10);
	LCD_SendCmd(LCD_DISP_CLEAR);
	for(Dummy_Delay=0;Dummy_Delay<=40000;Dummy_Delay++){}
//	_delay_ms(10);
	LCD_SendCmd(LCD_ENTRY_MDE);
	for(Dummy_Delay=0;Dummy_Delay<=40000;Dummy_Delay++){}
//	_delay_ms(10);
	return 0;
}

uint8_t LCD_WriteString(uint8_t *LOC_u8Ptr) {
	if (*LOC_u8Ptr != '\0') {
		while (*LOC_u8Ptr != '\0') {
			LCD_SendChar(*LOC_u8Ptr);
			LOC_u8Ptr++;
		}
		return 0; // success
	}
	else{
		return 2 ; // STRING IS EMPTY
	}

}
uint8_t LCD_WriteNumber(uint16_t Number) {
	uint8_t Numbers[10];
	int8_t Count;
	if(Number==0)
	{
		LCD_SendChar(ZERO_ASCII);
		return 0;
	}
	for(Count=0;Number>0;Count++)
	{
		Numbers[Count]=(Number%10)+48;
		Number=Number/10;
	}
	for(Count--;Count>=0;Count--)
	{
		LCD_SendChar(Numbers[Count]);
	}
	return 0;


}

uint8_t LCD_Returnhome(void) {
	LCD_SendCmd(LCD_RetrunHome);
//	_delay_ms(10);
	return 0;
}
uint8_t LCD_ClearDisplay(void) {

	LCD_SendCmd(LCD_ClrDisplay);

//	_delay_ms(10);

	return 0;
}
uint8_t LCD_CrsSecRow(void) {
	LCD_SendCmd(LCD_SecRow);
//	_delay_ms(10);
	return 0;
}
uint8_t LCD_MoveCrsTo(uint8_t Row, uint8_t Pos) {
	if ((Row >= 0 || Row <= 1) && (Pos >= 0 || Pos <= 15)) {
		switch (Row) {
		case 0:
			LCD_SendCmd(LCD_firstRow + Pos);
			break;
		case 1:
			LCD_SendCmd(LCD_SecRow + Pos);
			break;
		}
	} else {
	}
	return 0; // success

}
