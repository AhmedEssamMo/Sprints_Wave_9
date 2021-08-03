/*
 * EXINT_Int.h
 *
 *  Created on: Apr 10, 2021
 *      Author: Ahmed
 */

#ifndef EXINT_INT_H_
#define EXINT_INT_H_

#include"../../Infrastructure/TypeDef.h"
#include"../../Infrastructure/Macros.h"

#define EX_INT0 0
#define EX_INT1 1
#define EX_INT2 2

#define EX_SENSE_FALLING_EDGE   0
#define EX_SENSE_RAISING_EDGE   1
#define EX_SENSE_LOW_LEVEL      2
#define EX_SENSE_LOGIACL_CHANGE 3

void EX_vdDisable(uint8_t CopyInterrupt);

void EX_vdConfigInterrupt(uint8_t CopyInterrupt,uint8_t CopyControlSense);

void __vector_1 (void) __attribute__((signal));
void __vector_2 (void) __attribute__((signal));


#endif /* EXINT_INT_H_ */
