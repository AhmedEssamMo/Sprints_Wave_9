/*
 * EXINT_Registers.h
 *
 *  Created on: Apr 10, 2021
 *      Author: Ahmed
 */

#ifndef EXINT_REGISTERS_H_
#define EXINT_REGISTERS_H_
#define GICR   *((volatile uint8_t *)0x5B)
#define MCUCR  *((volatile uint8_t *)0x55)
#define MCUCSR *((volatile uint8_t *)0x54)
#define GIFR   *((volatile uint8_t *)0x5A)


#endif /* EXINT_REGISTERS_H_ */
