/*
 * keypad.c
 *
 *  Created on: July 25, 2021
 *      Author: Ahmed
 */
/*INCLUDES
 ---------------------------------*/
#include"keypad.h"
/*GLOBAL STATIC VARIABLE
 ----------------------------*/
/*uint8_t symbol[ROWS][COLUMNS] = {
 { '1', '2', '3', '+' },
 { '4', '5','6',  '-' },
 { '7', '8', '9', '*' },
 { '0', '=', '/', '%' }
 };*/
//MOCKING THE KEYPAD BUTTONS
uint8_t gu8_symbol[ROWS][COLUMNS] = {
		{ '1', '2', '3' },
		{ '4', '5', '6' },
		{ '7', '8', '9' },
		{ '*', '0', '#' } };

uint8_t Keypad_Initialization(void) {
	DIO_SetPortDirection(KEYPAD_U8_PORT, COLS_ROWS_DIRECTION);
	DIO_writePort(KEYPAD_U8_PORT, COLS_ROWS_VALUE);
	return 0;
}

uint8_t KP_GetTheButton(uint8_t* PressedBtn) {

	uint8_t LOC_u8RowsCounter, LOC_u8ColoumsCounter, LOC_u8StatusButton;
	/*********************LOOPS FOR THE ROWS********************/
	for (LOC_u8RowsCounter = 0; LOC_u8RowsCounter < ROWS;
			LOC_u8RowsCounter++) {
		/*SET 1 PIN LOW EACH TIME TO CHECK IF THERE ANY BUTTON PRESSED*/
//		UART_TransmitString(UART_1,"CHECK POINT 1");
		DIO_WritePin(KEYPAD_U8_PORT, LOC_u8RowsCounter, PIN_LOW);
		/*********************LOOPS FOR THE COLS********************/
		for (LOC_u8ColoumsCounter = 0; LOC_u8ColoumsCounter < COLUMNS;
				LOC_u8ColoumsCounter++) {
//		UART_TransmitString(UART_1,"CHECK POINT 2");
			/*CHECK IF THERE ANY PRESSED BBUTTON IN THIS ROW*/
			DIO_ReadPin(KEYPAD_U8_PORT, LOC_u8ColoumsCounter + 4,
					&LOC_u8StatusButton);
			if (LOC_u8StatusButton != PIN_HIGH) {
//		UART_TransmitString(UART_1,"CHECK POINT 3");
//				_delay_ms(20);//for debounce
				/*CHECK IF THE BUTTON HAS BEEN RELEASED*/
				DIO_ReadPin(KEYPAD_U8_PORT, LOC_u8ColoumsCounter + 4,
						&LOC_u8StatusButton);
				/*IF IT HASN"T BEEN RELESED YET IT STUCK IN THIS WHILE LOOP*/
				while (LOC_u8StatusButton != PIN_HIGH ) {
					/*KEEP CHECKING UNTIL RELEASING*/
					DIO_ReadPin(KEYPAD_U8_PORT, LOC_u8ColoumsCounter + 4,
							&LOC_u8StatusButton);
				}
				/*WHEN RELEASE RETURN*/
				*PressedBtn= gu8_symbol[LOC_u8RowsCounter][LOC_u8ColoumsCounter];
				return 1;//BUTTON HAS BEEN PRESSED
			}
		}
		DIO_WritePin(KEYPAD_U8_PORT, LOC_u8RowsCounter, PIN_HIGH);
	}
	return 0;//NO BUTTON HAS BEEN PRESSED
}

