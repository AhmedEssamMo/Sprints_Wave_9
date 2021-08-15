/*
 * LCD_Int.h
 *
 *  Created on: Apr 2, 2021
 *      Author: Ahmed
 */

#include"../../Infrastructure/Macros.h"
#include"../../Infrastructure/TypeDef.h"
#include"../../Mcal/DIO/DIO.h"
#include"lcdConfig.h"


#ifndef LCD_INT_H_
#define LCD_INT_H_






uint8_t LCD_SendChar(uint8_t LOC_u8Char);
uint8_t LCD_Initialization(void);
uint8_t LCD_WriteString(uint8_t *LOC_u8Ptr);
uint8_t LCD_WriteNumber(uint16_t number);
uint8_t LCD_CrtChar(uint8_t* charptr,uint8_t ByteNum);
uint8_t LCD_Returnhome(void);
uint8_t LCD_ClearDisplay(void);
uint8_t LCD_CrsSecRow(void);
uint8_t LCD_MoveCrsTo(uint8_t Row, uint8_t Pos);




#endif /* LCD_INT_H_ */
