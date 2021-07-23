/*
 * app.c
 *
 *  Created on: Jul 18, 2021
 *      Author: Ahmed
 */
#include "twi_slave_app.h"
void func(void);
uint8_t data=0;
void App_Init(void){

	DIO_SetPortDirection(PORTA,PORT_OUTPUT);
	TWI_Init(0);
	TWI_SetCallback(0,&func);
	TWI_EnableInterrupt(0);
	GI_EnableGI();
}
void App_Update(void){

}
void func(void){
	TWI_RecDataAck(TWI_1,&data);
	DIO_writePort(PORTA,data);

}

