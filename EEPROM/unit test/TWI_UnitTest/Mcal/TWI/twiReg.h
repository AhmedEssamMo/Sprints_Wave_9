/*
 * TWI_Reg.h
 *
 *  Created on: May 25, 2021
 *      Author: Ahmed
 */
#ifndef TWI_REG_H_
#define TWI_REG_H_

#define TESTING 1
#if !TESTING
#define TWI_Bit_Rate_REGISTER   *((volatile uint8_t*)0x20)
#define TWI_Control_REGISTER    *((volatile uint8_t*)0x56)
#define TWI_Status_REGISTER     *((volatile uint8_t*)0x21)
#define TWI_Data_REGISTER       *((volatile uint8_t*)0x23)
#define TWI_Adress_REGISTER     *((volatile uint8_t*)0x22)
#else
extern uint8_t TWI_Bit_Rate_REGISTER;
extern uint8_t TWI_Control_REGISTER;
extern uint8_t TWI_Status_REGISTER;
extern uint8_t TWI_Data_REGISTER;
extern uint8_t TWI_Adress_REGISTER;
#endif

#endif /* TWI_REG_H_ */
