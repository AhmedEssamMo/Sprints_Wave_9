/*
 * TWI_Reg.h
 *
 *  Created on: May 25, 2021
 *      Author: Ahmed
 */

#ifndef TWI_REG_H_
#define TWI_REG_H_
#define TWI_Bit_Rate_REGISTER   *((volatile uint8_t*)0x20)
#define TWI_Control_REGISTER    *((volatile uint8_t*)0x56)
#define TWI_Status_REGISTER     *((volatile uint8_t*)0x21)
#define TWI_Data_REGISTER       *((volatile uint8_t*)0x23)
#define TWI_Adress_REGISTER     *((volatile uint8_t*)0x22)


#endif /* TWI_REG_H_ */
