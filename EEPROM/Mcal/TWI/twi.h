/*
 * twi.h
 *  Created on: July 21, 2021
 *      Author: Ahmed
 */

#ifndef TWI_H_
#define TWI_H_
/*-----------INCLUDES-------------*/
#include "twiConfig.h"
#include "twiRetVal.h"
#include"../../Infrastructure/Macros.h"

/*-----------MACROS-------------*/
#define TWI_1 (uint8_t)1


/*-----------FUNCTION DECLERATIONS-------------*/

/* INIITIALIZE TWI */
int8_t TWI_Init(uint8_t I2C_CH);

/*SEND START CONDITION*/
int8_t TWI_SendStartCondition(uint8_t I2C_CH);

/*SEND STOP CONDITION*/
int8_t TWI_SendStopCondition(uint8_t I2C_CH);

/*SEND SLAVE ADDRESS WITH WRITE OPERATION*/
int8_t TWI_SendSLAWrite(uint8_t I2C_CH,uint8_t SlvAdr);

/*SEND SLAVE ADDRESS WITH READ OPERATION*/
int8_t TWI_SendSLARead(uint8_t I2C_CH,uint8_t SlvAdr);

/*SEND DATA*/
int8_t TWI_SendData(uint8_t I2C_CH,uint8_t Data);

/*SEND THE WHOLE FRAME(START->SLAVE ADDRESS WITH W-OPER->SEND DATA->STOP */
int8_t TWI_SendChar(uint8_t I2C_CH,uint8_t SlvAdr,uint8_t Data);
/*READ DATA WITH ACK*/
int8_t TWI_RecDataAck(uint8_t I2C_CH,uint8_t* data);

/*RECEIVE THE WHOLE FRAME(START->SLAVE ADDRESS WITH R-OPER->READ DATA->STOP */
int8_t TWI_RecChar(uint8_t I2C_CH,uint8_t SlvAdr,uint8_t* Data);

/*ENABLE THE TWI INTERRUPT*/
int8_t TWI_EnableInterrupt(uint8_t I2C_CH);

/*DISABLE THE TWI INTERRUPT*/
int8_t TWI_DisableInterrupt(uint8_t I2C_CH);

/*DETERMIN WEATHER IT'S READ OR WRITE OPERATION */
int8_t TWI_SlaOperDetermination(uint8_t I2C_CH,uint8_t* Oper);

/*ASSIGNE THE FUNCTION  TO THE PTR TO FFUNCTION*/
int8_t TWI_SetCallback(uint8_t I2CNumber, Ptr_VoidFuncVoid_t Callback);

/*SET SLAVE ADDRESS*/
void TWI_SetSlaveAddress(void);

//uint8_t TWI_Status(uint8_t I2C_CH, uint8_t * Status);
#endif /* TWI_INT_H_ */
