/*
 * twiConfig.h
 *
 * Created: July 21, 2021
 *  Author: Ahmed
 */


#ifndef TWICONFIG_H_
#define TWICONFIG_H_

/*-----------MACROS-------------*/
/*
 * It's 7-Bit address in the TWI_Adress_REGISTER for Bit 1 to bit 7
 * Bit-0 is TWI General Call Recognition Enable Bit
 * Addresses from 0b1111000 To 0b1111111 Are reserved, Can't Use!!
 * Address 0b0000000 is for General Call  Can't Use!!
*/
#define SlaveAddr (uint8_t)0x18

/*
 *According to this equ. SCL freq.=(Cpu Clock Freq)/(16+2*(Bit rate)*4^prescaler)
 *choose the prescaler and the bit rate while the clock freq. is 8000000HZ
 *the SCL should be less than 400000HZ
 */
/*THIS MACRO CONTROLS THE PRESCALER
 * PRESCALER_1
 * PRESCALER_4
 * PRESCALER_16
 * PRESCALER_64
 * */
#define Prescaler  PRESCALER_1 //choose the Prescaler 0--> 1 // 1--> 4 // 2-->16 // 3--> 64
#define Bit_rate   30//choose the value between 0 to 255 to meet the requirements



#endif
