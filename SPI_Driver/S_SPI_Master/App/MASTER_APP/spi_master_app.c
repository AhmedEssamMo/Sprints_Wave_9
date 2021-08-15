/*
 * app.c
 *
 *  Created on: Jul 18, 2021
 *      Author: Ahmed
 */
#include "spi_master_app.h"
uint8_t buffer[255];
void App_Init(void){
	UART_Init(UART_1);
	SPI_Init(SPI_CH1);

}
void App_Update(void){
	while(1){
	UART_ReceiveString(UART_1,buffer);
	SPI_TransmitString(SPI_CH1,buffer,SLAVE_CH1);
	}
}

