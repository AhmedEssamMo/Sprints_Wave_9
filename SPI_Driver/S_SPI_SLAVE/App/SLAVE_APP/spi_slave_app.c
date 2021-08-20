/*
 * app.c
 *
 *  Created on: Jul 18, 2021
 *      Author: Ahmed
 */
#include "spi_slave_app.h"
uint8_t buffer[255];
void SPI_ReceiveingInt(void);



void App_Init(void) {
	UART_Init(UART_1);
	SPI_Init(SPI_CH1);
	SPI_SetCallback(SPI_CH1,&SPI_ReceiveingInt);
	SPI_EnableInterrupt(SPI_CH1);
	GI_EnableGI();

}
void App_Update(void) {
}

void SPI_ReceiveingInt(void){
	SPI_ReceiveString(SPI_CH1, buffer, SLAVE_CH1);
	UART_TransmitString(UART_1,buffer);
}

