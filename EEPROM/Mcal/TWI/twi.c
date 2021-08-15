/*
 * TWI_Prog.c
 *
 *  Created on: July 25, 2021
 *      Author: Ahmed
 */

/*INCLUDES-------------------------------*/

#include"twi.h"
#include"twiReg.h"

/*----GLOBAL STATIC VARIABLES----*/
Ptr_VoidFuncVoid_t G_TWI_CALLBACK=NULL_PTR;
static uint8_t gu8_InitFlag = NOT_INIT;

/*LOCAL MACROS--------------------------*/

//STATUS
#define ST_CONDITION  (uint8_t)0x08 // START CONDITION HAS BEEN SENT
#define SLA_W_ACK     (uint8_t)0x18 // SLAVE ADDRESS WITH WRITE OPERATION WITH ACK
#define SLA_W_NACK    (uint8_t)0x20 // SLAVE ADDRESS WITH WRITE OPERATION WITH NACK
#define DATA_TR_ACK   (uint8_t)0x28 // DATA BYTE HAS BEEN TRANSMITTED WITH ACK
#define DATA_TR_NACK  (uint8_t)0x30 // DATA BYTE HAS BEEN TRANSMITTED WITH NACK
#define ARBIT_LOST    (uint8_t)0x38 // ARBITRATION LOST
#define SLA_R_ACK     (uint8_t)0x40 // SLAVE ADDRESS WITH READ OPERATION WITH ACK
#define SLA_R_NACK    (uint8_t)0x48 // SLAVE ADDRESS WITH READ OPERATION WITH NACK
#define DATA_REC_ACK  (uint8_t)0x50 // DATA BYTE HAS BEEN RECEUVED WITH ACK
#define DATA_REC_NACK (uint8_t)0x58 // DATA BYTE HAS BEEN TRANSMITTED WITH NACK
//PERSCALER IN TWI
#define PRESCALER_1  0b11111100
#define PRESCALER_4  0b11111101
#define PRESCALER_16 0b11111110
#define PRESCALER_64 0b11111111
// TWI_Control_REGISTER
#define TWINT      7
#define TWEA       6
#define TWSTA      5
#define TWSTO      4
#define TWWE       3
#define TWEN       2
#define RESERVED   1
#define TWIE       0

#define EN_INT     0b00000001
#define EN_TWI     0b00000100
#define SEND_STOP  0b00010000
#define SEND_START 0b00100000
#define SEND_ACK   0b01000000
#define CLR_FLAG   0b10000000

/*----APIs IMPLEMENTATION----*/
void TWI_SetSlaveAddress(void) {

	TWI_Adress_REGISTER = (SlaveAddr << 1); //Shift the register left

}
TWI_ERROR_state_t TWI_Init(uint8_t I2C_CH) {
    uint8_t au8_ERROR_STAT=TWI_SUCCESS;//ERRROR STAT HAS A SUCCESS VALUE AS DEFAULT
    if (I2C_CH>TWI_1){
		au8_ERROR_STAT=TWI_INVALID_CHANNEL;
	}
	else{
        if (INIT==gu8_InitFlag){
            au8_ERROR_STAT=TWI_SEC_INIT;
        }
        else if (NOT_INIT==gu8_InitFlag){
	/*-----SET ADDRESS IN CASE OF IT'S IN SLAVE MODE---- */
            TWI_SetSlaveAddress();
            /*-----SETTING THE FREQ-----*/
            TWI_Bit_Rate_REGISTER = Bit_rate;
            TWI_Status_REGISTER &= Prescaler;
            /*Initial Value for TWI_Control_REGISTER is zeros so I set only what I need and ignore the rest*/
            /*-----ENABLE ACKNOWLEDGE----*/
            Set_Bit(TWI_Control_REGISTER, TWEA);
            /*-----ENABLE THE PREIPHERAL ITSELF-----*/
            Set_Bit(TWI_Control_REGISTER, TWEN);
            gu8_InitFlag = INIT;
        }
	}
	return au8_ERROR_STAT;
}
TWI_ERROR_state_t TWI_SendStartCondition(uint8_t I2C_CH) {
    uint8_t au8_ERROR_STAT=TWI_SUCCESS;//ERRROR STAT HAS A SUCCESS VALUE AS DEFAULT
    if (I2C_CH>TWI_1){
		au8_ERROR_STAT=TWI_INVALID_CHANNEL;
	}
	else{
        if(NOT_INIT==gu8_InitFlag){
            au8_ERROR_STAT=TWI_NOT_INIT;
        }
        else if (INIT==gu8_InitFlag){
            TWI_Control_REGISTER = (EN_TWI | SEND_START | CLR_FLAG);
            while ((Get_Bit(TWI_Control_REGISTER, TWINT)) != 1)
                ;/*Wait for TWINT Flag set.
		 This indicates that the START condition has been transmitted*/
        }
    }
		 return au8_ERROR_STAT;
}
TWI_ERROR_state_t TWI_SendStopCondition(uint8_t I2C_CH) {
    uint8_t au8_ERROR_STAT=TWI_SUCCESS;//ERRROR STAT HAS A SUCCESS VALUE AS DEFAULT
        if (I2C_CH>TWI_1){
		au8_ERROR_STAT=TWI_INVALID_CHANNEL;
	}
	else{
        if(NOT_INIT==gu8_InitFlag){
            au8_ERROR_STAT=TWI_NOT_INIT;
        }
        else if (INIT==gu8_InitFlag){
            TWI_Control_REGISTER = (EN_TWI | CLR_FLAG | SEND_STOP);
        }
	}
	return au8_ERROR_STAT;
}
TWI_ERROR_state_t TWI_SendSLAWrite(uint8_t I2C_CH, uint8_t SlvAdr) {
    uint8_t au8_ERROR_STAT=TWI_SUCCESS;//ERRROR STAT HAS A SUCCESS VALUE AS DEFAULT
        if (I2C_CH>TWI_1){
		au8_ERROR_STAT=TWI_INVALID_CHANNEL;
	}
	else{
        if(NOT_INIT==gu8_InitFlag){
            au8_ERROR_STAT=TWI_NOT_INIT;
        }
        else if (INIT==gu8_InitFlag){
            TWI_Data_REGISTER = ((SlvAdr << 1) | 0);
            TWI_Control_REGISTER = (EN_TWI | CLR_FLAG);// CLEAR FLAG TO SEND DATA
            while (Get_Bit(TWI_Control_REGISTER,TWINT) == 0)
                ;
        }
	}
    return au8_ERROR_STAT;

}
TWI_ERROR_state_t TWI_SendSLARead(uint8_t I2C_CH, uint8_t SlvAdr) {
	uint8_t au8_ERROR_STAT=TWI_SUCCESS;//ERRROR STAT HAS A SUCCESS VALUE AS DEFAULT
    if (I2C_CH>TWI_1){
		au8_ERROR_STAT=TWI_INVALID_CHANNEL;
	}
	else{
        if(NOT_INIT==gu8_InitFlag){
            au8_ERROR_STAT=TWI_NOT_INIT;
        }
        else if (INIT==gu8_InitFlag){
        TWI_Data_REGISTER = ((SlvAdr << 1) | 1);
        TWI_Control_REGISTER = (EN_TWI | CLR_FLAG);
        while (Get_Bit(TWI_Control_REGISTER,TWINT) == 0)
            ;
        }
	}
    return au8_ERROR_STAT;

}
TWI_ERROR_state_t TWI_SendData(uint8_t I2C_CH, uint8_t Data){
	uint8_t au8_ERROR_STAT=TWI_SUCCESS;//ERRROR STAT HAS A SUCCESS VALUE AS DEFAULT
	    if (I2C_CH>TWI_1){
		au8_ERROR_STAT=TWI_INVALID_CHANNEL;
	}
	else{
        if(NOT_INIT==gu8_InitFlag){
            au8_ERROR_STAT=TWI_NOT_INIT;
        }
        else if (INIT==gu8_InitFlag){
        TWI_Data_REGISTER = Data;
        TWI_Control_REGISTER = (EN_TWI | CLR_FLAG);
        while (Get_Bit(TWI_Control_REGISTER,TWINT) == 0)
            ;
        }
	}
    return au8_ERROR_STAT;
}
TWI_ERROR_state_t TWI_SendChar(uint8_t I2C_CH, uint8_t SlvAdr, uint8_t Data) {
    uint8_t au8_ERROR_STAT=TWI_SUCCESS;//ERRROR STAT HAS A SUCCESS VALUE AS DEFAULT
    if (I2C_CH>TWI_1){
		au8_ERROR_STAT=TWI_INVALID_CHANNEL;
	}
	else{
        if(NOT_INIT==gu8_InitFlag){
            au8_ERROR_STAT=TWI_NOT_INIT;
        }
        else if (INIT==gu8_InitFlag){
        /*SENDING START CONDITION*/
        TWI_SendStartCondition(I2C_CH);
        /*--SEND SALVE ADDRESS WITH WRITE OPERATION--*/
        TWI_SendSLAWrite(I2C_CH, SlvAdr);
        /*--SENDING DATA--*/
        TWI_SendData(I2C_CH, Data);
        /*--SENDING STOP CONDITION*/
        TWI_SendStopCondition(I2C_CH);
        }
	}
	return au8_ERROR_STAT;
}
TWI_ERROR_state_t TWI_RecDataAck(uint8_t I2C_CH, uint8_t* data) {
	uint8_t au8_ERROR_STAT=TWI_SUCCESS;//ERRROR STAT HAS A SUCCESS VALUE AS DEFAULT
    if(NULL_PTR==data){
        au8_ERROR_STAT=TWI_NULL_POINTER;
    }//if
    else{
        if (I2C_CH>TWI_1){
            au8_ERROR_STAT=TWI_INVALID_CHANNEL;
        }//if
        else{
            if(NOT_INIT==gu8_InitFlag){
                au8_ERROR_STAT=TWI_NOT_INIT;
            }//if
            else if (INIT==gu8_InitFlag){
                Set_Bit(TWI_Control_REGISTER, TWEA);
                Set_Bit(TWI_Control_REGISTER, TWINT);
                while (Get_Bit(TWI_Control_REGISTER,TWINT) == 0)
                    ;
                *data = TWI_Data_REGISTER;
            }//else if
            else{
                //DO NOTHING
            }//else
        }//else
    }//else
	return au8_ERROR_STAT;
}
TWI_ERROR_state_t TWI_RecChar(uint8_t I2C_CH, uint8_t SlvAdr, uint8_t* Data) {
    uint8_t au8_ERROR_STAT=TWI_SUCCESS;//ERRROR STAT HAS A SUCCESS VALUE AS DEFAULT
    if(NULL_PTR==Data){
        au8_ERROR_STAT=TWI_NULL_POINTER;
    }//if
    else{
        if (I2C_CH>TWI_1){
            au8_ERROR_STAT=TWI_INVALID_CHANNEL;
        }//if
        else{
            if(NOT_INIT==gu8_InitFlag){
                au8_ERROR_STAT=TWI_NOT_INIT;
            }//if
            else if (INIT==gu8_InitFlag){
                TWI_SendStartCondition(I2C_CH);
                TWI_SendSLARead(I2C_CH, SlvAdr);
                TWI_RecDataAck(I2C_CH, Data);
                TWI_SendStopCondition(I2C_CH);
            }//else if
            else{
                    //DO NOTHING
            }//else
        }//else
    }//else
	return au8_ERROR_STAT;
}

TWI_ERROR_state_t TWI_EnableInterrupt(uint8_t I2C_CH) {
    uint8_t au8_ERROR_STAT=TWI_SUCCESS;//ERRROR STAT HAS A SUCCESS VALUE AS DEFAULT
    if (I2C_CH>TWI_1){
		au8_ERROR_STAT=TWI_INVALID_CHANNEL;
	}
	else{
        if(NOT_INIT==gu8_InitFlag){
            au8_ERROR_STAT=TWI_NOT_INIT;
        }
        else if (INIT==gu8_InitFlag){
            Set_Bit(TWI_Control_REGISTER, TWIE); //Disable ISR for the TWI peripheral
        }//else if
        else{
            //DO NOTHING
        }//else
	}//else
	return au8_ERROR_STAT;

}
TWI_ERROR_state_t TWI_DisableInterrupt(uint8_t I2C_CH) {
    uint8_t au8_ERROR_STAT=TWI_SUCCESS;//ERRROR STAT HAS A SUCCESS VALUE AS DEFAULT
    if (I2C_CH>TWI_1){
		au8_ERROR_STAT=TWI_INVALID_CHANNEL;
	}
	else{
        if(NOT_INIT==gu8_InitFlag){
            au8_ERROR_STAT=TWI_NOT_INIT;
        }
        else if (INIT==gu8_InitFlag){
            Clr_Bit(TWI_Control_REGISTER, TWIE); //Disable ISR for the TWI peripheral
        }//else if
        else{
            //DO NOTHING
        }//else
	}//else
	return au8_ERROR_STAT;

}
TWI_ERROR_state_t TWI_SlaOperDetermination(uint8_t I2C_CH, uint8_t* Oper) {
    uint8_t au8_ERROR_STAT=TWI_SUCCESS;//ERRROR STAT HAS A SUCCESS VALUE AS DEFAULT
    if(NULL_PTR==Oper){
        au8_ERROR_STAT=TWI_NULL_POINTER;
    }//if
    else{
        if (I2C_CH>TWI_1){
            au8_ERROR_STAT=TWI_INVALID_CHANNEL;
        }//if
        else{
            if(NOT_INIT==gu8_InitFlag){
                au8_ERROR_STAT=TWI_NOT_INIT;
            }//if
            else if (INIT==gu8_InitFlag){
                *Oper = Get_Bit(TWI_Data_REGISTER, 0);
            }//else if
            else{
                //DO NOTHING
            }//else
        }//else
    }//else
	return au8_ERROR_STAT;
}
TWI_ERROR_state_t TWI_SetCallback(uint8_t I2CNumber, Ptr_VoidFuncVoid_t Callback) {
    uint8_t au8_ERROR_STAT=TWI_SUCCESS;//ERRROR STAT HAS A SUCCESS VALUE AS DEFAULT
    if(NULL_PTR==Callback){
        au8_ERROR_STAT=TWI_NULL_POINTER;
    }//if
    else{
        if (I2CNumber>TWI_1){
            au8_ERROR_STAT=TWI_INVALID_CHANNEL;
        }
        else{
            if(NOT_INIT==gu8_InitFlag){
                au8_ERROR_STAT=TWI_NOT_INIT;
            }
            else if (INIT==gu8_InitFlag){
                G_TWI_CALLBACK = Callback;
            }//else i
            else{
                //DO NOTHING
            }//else
        }//else
    }
	return au8_ERROR_STAT;
}
void __vector_19(void) __attribute__((signal)); // Serial Transfer Complete
void __vector_19(void) {
	G_TWI_CALLBACK();
}
