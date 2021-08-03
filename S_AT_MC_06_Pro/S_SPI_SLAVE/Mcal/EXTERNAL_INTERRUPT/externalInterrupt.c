/*
 * EXINT_Prog.c
 *
 *  Created on: Apr 10, 2021
 *      Author: Ahmed
 */

#include"externalInterruptReg.h"
#include"externalInterrupt.h"


void EX_vdDisable(uint8_t CopyInterrupt)
{
	if(CopyInterrupt <= EX_INT2)
	{
		switch (CopyInterrupt)
		{
		case EX_INT0:
			Clr_Bit(GICR,6);
			break;
		case EX_INT1:
			Clr_Bit(GICR,7);
			break;
		case EX_INT2:
			Clr_Bit(GICR,5);
			break;
		default:
			break;
		}
	}
}

void EX_vdConfigInterrupt(uint8_t CopyInterrupt , uint8_t CopyControlSense)
{
	if(CopyInterrupt <= EX_INT2 && CopyControlSense <= EX_SENSE_LOGIACL_CHANGE)
	{
		switch (CopyInterrupt)
		{
			case EX_INT0:
				Set_Bit(GICR,6);
				switch (CopyControlSense)
				{
					case EX_SENSE_FALLING_EDGE:
						Clr_Bit(MCUCR,0);
						Set_Bit(MCUCR,1);
						break;
					case EX_SENSE_RAISING_EDGE:
						Set_Bit(MCUCR,0);
						Set_Bit(MCUCR,1);
						break;
					case EX_SENSE_LOW_LEVEL:
						Clr_Bit(MCUCR,0);
						Clr_Bit(MCUCR,1);
						break;
					case EX_SENSE_LOGIACL_CHANGE:
						Set_Bit(MCUCR,0);
						Clr_Bit(MCUCR,1);
						break;
				}
				break;
			case EX_INT1:
				Set_Bit(GICR,7);
				switch (CopyControlSense)
				{
					case EX_SENSE_FALLING_EDGE:
						Clr_Bit(MCUCR,2);
						Set_Bit(MCUCR,3);
						break;
					case EX_SENSE_RAISING_EDGE:
						Set_Bit(MCUCR,2);
						Set_Bit(MCUCR,3);
						break;
					case EX_SENSE_LOW_LEVEL:
						Clr_Bit(MCUCR,2);
						Clr_Bit(MCUCR,3);
						break;
					case EX_SENSE_LOGIACL_CHANGE:
						Set_Bit(MCUCR,2);
						Clr_Bit(MCUCR,3);
						break;
				}
				break;
			case EX_INT2:
				Set_Bit(GICR,5);
				switch (CopyControlSense)
				{
					case EX_SENSE_FALLING_EDGE:
						Clr_Bit(MCUCSR,6);
						break;
					case EX_SENSE_RAISING_EDGE:
						Set_Bit(MCUCSR,6);
						break;
				}
				break;
		}
	}
}
void __vector_1 (void)
{

}
void __vector_2 (void)
{

}


