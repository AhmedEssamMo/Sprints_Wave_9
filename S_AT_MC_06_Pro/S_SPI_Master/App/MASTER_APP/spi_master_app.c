/*
 * app.c
 *
 *  Created on: Jul 18, 2021
 *      Author: Ahmed
 */
#include "spi_master_app.h"

void App_Init(void){
	UART_Init(UART_1);
	SPI_Init(SPI_CH1);

}
void App_Update(void){


	SPI_TransmitChar(SPI_CH1,'0',SLAVE_CH1);

}

