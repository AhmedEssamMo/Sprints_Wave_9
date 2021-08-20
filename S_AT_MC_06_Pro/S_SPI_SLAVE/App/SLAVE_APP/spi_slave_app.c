/*
 * app.c
 *
 *  Created on: Jul 18, 2021
 *      Author: Ahmed
 */
#include "spi_slave_app.h"
uint8_t GU8_Bufer=0b11110000;
void SPI_ReceiveingInt(void);



void App_Init(void) {

	SPI_Init(SPI_CH1);
	DIO_setPortDirection(PORTA,PORT_OUTPUT);
//	SPI_SetCallback(SPI_CH1,&SPI_ReceiveingInt);
//	SPI_EnableInterrupt(SPI_CH1);
//	GI_EnableGI();

}
void App_Update(void) {
	SPI_ReceiveChar(SPI_CH1,&GU8_Bufer,SLAVE_CH1);
	DIO_writePort(PORTA,GU8_Bufer);
}

void SPI_ReceiveingInt(void){

}

