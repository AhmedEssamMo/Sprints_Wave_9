/*
 * keypad.h
 *
 *  Created on: Mar 30, 2021
 *      Author: Ahmed
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_
/*INCLUDES
 --------------------------------*/
#include"../../Infrastructure/Macros.h"
#include"../../Infrastructure/TypeDef.h"
#include"../../Mcal/UART/uart.h"
#include"../../Mcal/DIO/DIO.h"



/*MACROS
 * */
/*THIS MACRO CONTROLS THE KEYPAD PORTS*/
#define KEYPAD_U8_PORT             PORTA
/*Choose the size of your keypad
 * 3*3 -> KP_3R_3C
 * 4*3 -> KP_4R_3C
 * 4*4 -> KP_4R_4C
 */
#define KP_Size KP_4R_3C

// Number of rows and columns connecting the 8 switches
#define ROWS 	4
#define COLUMNS 3

// 0b00001111 -> 0x0F : To set output (LSB) and input (MSB)
#define COLS_ROWS_DIRECTION 0x0F

// 0b11111111 -> 0xFF : To set high value (LSB) and to enable pull-up resistor (MSB)
#define COLS_ROWS_VALUE 0xFF

/*FUNCTIONS DECLARATIONS
--------------------------------*/
uint8_t Keypad_Initialization (void);
uint8_t KP_GetTheButton(uint8_t* PressedBtn);

#endif /* KEYPAD_H_ */
