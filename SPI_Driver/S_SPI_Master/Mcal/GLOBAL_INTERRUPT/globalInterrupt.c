/*
 * GI_Prog.c
 *
 *  Created on: Apr 10, 2021
 *      Author: Ahmed
 */
#include"globalInterruptReg.h"
#include"globalInterrupt.h"

void GI_EnableGI (void)
{
	Set_Bit(SREG_REGISTER,I_BIT);
}


void GI_DisableGI (void)
{
	Clr_Bit(SREG_REGISTER, I_BIT);
}
