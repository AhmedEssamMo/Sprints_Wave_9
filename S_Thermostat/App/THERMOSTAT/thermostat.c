/*
 * app.c
 *
 *  Created on: Jul 18, 2021
 *      Author: Ahmed
 */
/*INCLUDES
 ---------------------------------*/
#include "thermostat.h"
/*GLOBAL STATIC VARIABLE
 ----------------------------*/
uint16_t gu8_desired_temp = 0;
uint8_t gu8_ActualTemp = 0;
uint8_t gu8_PressedBtn = NULL_TERMINATOR;
uint8_t gu8_EnteredTemp[4] = { NULL_TERMINATOR, NULL_TERMINATOR, NULL_TERMINATOR,
NULL_TERMINATOR };
uint8_t gu8_counter = 0;

/*LOCAL FUNCTION IMPLEMENTATION
 ----------------------------*/
/*Dummy delay*/
static void delay(uint16_t mSec) {
	volatile uint16_t dummy1 = 0;
	volatile uint16_t dummy2 = 0;
	mSec = (mSec / 3) + 1;
	for (dummy1 = 0; dummy1 <= mSec; dummy1++) {
		for (dummy2 = 0; dummy2 <= 2666; dummy2++)
			;
	}
}
static void THERMOSTAT_STRING_2(void){
	gu8_PressedBtn = NULL_TERMINATOR;

	LCD_WriteString((uint8_t*) "ENTER TEMP THEN");
	LCD_CrsSecRow();
	LCD_WriteString((uint8_t*) "PRESS *");
	while (gu8_PressedBtn == NULL_TERMINATOR) {
		KP_GetTheButton(&gu8_PressedBtn);
	}
	gu8_PressedBtn = NULL_TERMINATOR;
	LCD_ClearDisplay();

}
/*CONVERTS THE NUMBER FROM CHAR TO DECIMAL*/
static void THERMOSTAT_CHAR_TO_DEC(uint8_t* string) {
	uint8_t LU8_ITERATOR = 0; //This is for the EnterTemp Index
	uint8_t LU8_COUNTER = 0; //This counter for number of digits
	gu8_PressedBtn = NULL_TERMINATOR;
	/*Gets the number of digits*/
	while (*(string + LU8_COUNTER) != NULL_TERMINATOR) {
		LU8_COUNTER++;
	}
	/**/
	gu8_desired_temp = (*(string) - ZERO_ASCII); //get the number as a decimal
	for (LU8_ITERATOR = 0; LU8_ITERATOR < (LU8_COUNTER - 1); LU8_ITERATOR++) {
		gu8_desired_temp = gu8_desired_temp * 10;
		gu8_desired_temp = (gu8_desired_temp)
				+ (*(string + LU8_ITERATOR + 1) - ZERO_ASCII);
	}
}



static void THERMOSTAT_DesiredTemp(void) {
	LCD_ClearDisplay();
	delay(1);
	for (uint8_t i = 0; i < 4; i++) {
		gu8_EnteredTemp[i] = NULL_TERMINATOR;
	}
	gu8_PressedBtn = NULL_TERMINATOR;
	while (1) {
		do {
			gu8_PressedBtn = KP_GetTheButton(gu8_EnteredTemp + gu8_counter);
		} while (gu8_PressedBtn == 0);
		LCD_SendChar(*(gu8_EnteredTemp + gu8_counter));
		delay(1);
		if (gu8_EnteredTemp[gu8_counter] == '*') {
			gu8_EnteredTemp[gu8_counter] = NULL_TERMINATOR;
			break;
		}
		gu8_counter++;
		if (gu8_counter == 4) {
			delay(1);
			LCD_ClearDisplay();
			delay(1);
			LCD_WriteString((uint8_t*) "INVALID");
			delay(1000);
			gu8_counter = 0;
			LCD_ClearDisplay();
			delay(1);
			THERMOSTAT_STRING_2();
		}
	}
	gu8_counter = 0;
	LCD_ClearDisplay();
	delay(1);
	LCD_WriteString((uint8_t*) "WANTED TEMP ");
	delay(1);
	LCD_WriteString(gu8_EnteredTemp);
	THERMOSTAT_CHAR_TO_DEC(gu8_EnteredTemp);
	do {
		gu8_PressedBtn = KP_GetTheButton(gu8_EnteredTemp + gu8_counter);
	} while (gu8_PressedBtn == NULL_TERMINATOR);
	gu8_PressedBtn = NULL_TERMINATOR;
	LCD_ClearDisplay();
}
static void THERMOSTAT_CurrentTemp(void) {
	//LCD_ClearDisplay();
	delay(1);
	LCD_WriteString((uint8_t*) "CURRENT TEMP:");
	TEMP_GetTemp(TEMP_CH_7, &gu8_ActualTemp);
	LCD_WriteNumber(gu8_ActualTemp);
	LCD_CrsSecRow();
	delay(1);
	LCD_WriteString((uint8_t*) "DESIRED TEMP");
	delay(1);
	LCD_WriteNumber(gu8_desired_temp);

}
static void Thermostat_SetTemp(void) {
	/*Wait until user press '#'*/
	LCD_WriteString((uint8_t*) "PRS # to SET");
	while (gu8_PressedBtn != '#') {
		KP_GetTheButton(&gu8_PressedBtn);
	}
	gu8_PressedBtn = NULL_TERMINATOR;
	/*Clear Display*/
	LCD_ClearDisplay();
	delay(1);
	THERMOSTAT_STRING_2();
	delay(1);
	/*Get desired temperature */
	THERMOSTAT_DesiredTemp();
	/*check if temp is bigger than 150*/
	while (gu8_desired_temp > 150) {
		delay(1);
		LCD_WriteString((uint8_t*) "TEMP EXCEEDED");
		LCD_CrsSecRow();
		delay(1);
		LCD_WriteString((uint8_t*) "PRS ANY KEY");
		do {
			gu8_PressedBtn = KP_GetTheButton(gu8_EnteredTemp + gu8_counter);
		} while (gu8_PressedBtn == NULL_TERMINATOR);
		gu8_PressedBtn = NULL_TERMINATOR;
		THERMOSTAT_DesiredTemp();
	}
	delay(1);
}
/*- APIs IMPLEMENTATION
 -----------------------------------*/
void App_Init(void) {
	/*--Initialization--*/
	LCD_Initialization();
	Keypad_Initialization();
	TEMP_Init(TEMP_CH_0);
	MOTOR_init();

}
void App_Update(void) {
	Thermostat_SetTemp();
	while (1) {
		gu8_PressedBtn = NULL_TERMINATOR;
		THERMOSTAT_CurrentTemp();
		if (gu8_ActualTemp >= gu8_desired_temp) {
			MOTOR_start(MOTER1, MOTOR1_FORWARD);
		} else {
			MOTOR_stop(MOTER1);
		}
		delay(1000);
	}
	gu8_PressedBtn = NULL_TERMINATOR;

}
