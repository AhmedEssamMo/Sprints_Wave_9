/*
 * app.c
 *
 *  Created on: Jul 18, 2021
 *      Author: Ahmed
 */
/*----INCLUDES---*/
#include "twi_slave_app.h"

void TWI_ISR(void);
uint8_t data=0;
void App_Init(void){

	TWI_Init(0);
	TWI_EnableInterrupt(0);
	TWI_SetCallback(0,&TWI_ISR);
	DIO_SetPortDirection(PORTA,PORT_OUTPUT);
	GI_EnableGI();
}
void App_Update(void){

}
void TWI_ISR(void){
	TWI_RecDataAck(TWI_1,&data);
	DIO_writePort(PORTA,data);

}

