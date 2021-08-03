#ifndef _LCD_CONFIG_H_
#define _LCD_CONFIG_H_

/*LCD DATA PORT*/
#define LCD_DATA_PORT     PORTB
/*LCD CONTROL PORT*/
#define LCD_CTRL_PORT     PORTC
/*LCD CONTROL PINS*/
#define LCD_RS_PIN        PIN0
#define LCD_RW_PIN        PIN1
#define LCD_EN_PIN        PIN2

/*Configured bits:
 * 1- BIT4 DL: 0-> 4 bit    , 1-> 8 bit
 * 2- BIT3 N : 0-> 1 Line   , 1-> 2 Lines
 * 3- BIT2 F : 0-> 5*7 dots , 1-> 5*10 dots
 * */
#define LCD_FUNC_SET                0b00111000

/*Configured bits:
 * 1- BIT2 D : 0-> Display OFF      , 1-> Display ON
 * 2- BIT1 C : 0-> Cursor OFF       , 1-> Cursor ON
 * 3- BIT0 B : 0-> Cursor Blink OFF , 1-> Cursor Blink ON
 * */
#define LCD_DISP_ON_OFF_CTRL        0b00001100

/*Configured bits:
 * 1- BIT1 I/D : 0-> Decrement , 1-> Increment
 * 2- BIT0 SH  : 0-> Shift OFF , 1-> Shift ON
 */
#define LCD_ENTRY_MDE               0b00000110

#endif /*_LCD_CONFIG_H_*/
