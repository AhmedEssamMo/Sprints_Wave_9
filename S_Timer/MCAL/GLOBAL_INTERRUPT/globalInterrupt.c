/*
 * GI_Prog.c
 *
 *  Created on: Apr 10, 2021
 *      Author: Ahmed
 */
 /*- APIs IMPLEMENTATION
-----------------------------------*/
#include"globalInterruptReg.h"
#include"globalInterrupt.h"
/*- APIs IMPLEMENTATION
-----------------------------------*/
void GI_EnableGI (void)
{
	Set_Bit(SREG_REGISTER,I_BIT);
}

void GI_DisableGI (void)
{
	Clr_Bit(SREG_REGISTER, I_BIT);
}
