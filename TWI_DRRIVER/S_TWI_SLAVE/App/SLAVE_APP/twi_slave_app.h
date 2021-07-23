/*
 * app.h
 *
 *  Created on: Jul 18, 2021
 *      Author: Ahmed
 */

#ifndef APP_APP_H_
#define APP_APP_H_

#include"../../Mcal/DIO/DIO.h"
#include"../../Mcal/UART/uart.h"
#include"../../Mcal/TWI/twi.h"
#include"../../Mcal/GLOBAL_INTERRUPT/globalInterrupt.h"
void App_Init(void);
void App_Update(void);

#endif /* APP_APP_H_ */
