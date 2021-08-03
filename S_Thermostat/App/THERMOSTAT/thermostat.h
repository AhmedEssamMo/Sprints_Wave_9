/*
 * app.h
 *
 *  Created on: Jul 18, 2021
 *      Author: Ahmed
 */

#ifndef APP_APP_H_
#define APP_APP_H_
/*INCLUDES
 --------------------------------*/
#include"../../Mcal/DIO/DIO.h"
#include"../../Firmware/LCD/lcd.h"
#include"../../Firmware/KEYPAD/keypad.h"
#include"../../Firmware/TEMP/temp.h"
#include"../../Firmware/Motor/Motor.h"

/*FUNCTIONS DECLARATIONS
--------------------------------*/
void App_Init(void);
void App_Update(void);

#endif /* APP_APP_H_ */
