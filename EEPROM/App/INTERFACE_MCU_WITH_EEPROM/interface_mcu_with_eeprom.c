/*
 * app.c
 *
 *  Created on: Jul 18, 2021
 *      Author: Ahmed
 */
/*INCLUDES
 ---------------------------------*/
#include "interface_mcu_with_eeprom.h"
/*LOCAL FUNCTIONS PROTOTYPE
 ----------------------*/
static uint8_t StringCmpr(ptr_uint8_t STRING_1, ptr_uint8_t STRING_2);
static uint8_t ConvertCh_Dec(ptr_uint8_t STRING_1, ptr_uint8_t Address);
/*- LOCAL MACROS
 ------------------------------------------*/
#define ADDRESS_SIZE 7

/*GLOBAL STATIC VARIABLE
 ----------------------------*/
static uint8_t gu8_OkMsg[] = "OK";
static uint8_t gu8_ErrorMsg[] = "ERORR!";
static uint8_t gu8_WriteMsg[] = "WRITE";
static uint8_t gu8_ReadMsg[] = "READ";
static uint8_t gu8_EnterTheData[] = "Enter The Char";
static uint8_t gu8_EnterTheADDR[] = "Enter The Address";
static uint8_t gu8_EnterTheAddrAga[] = "Enter The Address Again";
static uint8_t gu8_Empty[] = "This Place Has No data";
static uint8_t gu8_ReceiverBuffer[100];
static uint8_t gu8_ReceiverAddr[10];
static uint8_t gu8_WriteAddr = 0;
static uint8_t gu8_ReadAddr = 0;
static uint8_t data = 0;

/*LOCAL FUNCTION IMPLEMENTATION
 ----------------------------*/
/*COMPARE TWWO STRINGS*/
static uint8_t StringCmpr(ptr_uint8_t STRING_1, ptr_uint8_t STRING_2) {
	uint8_t i = 0;
	while ((STRING_1[i] != NULL_TERMINATOR) || (STRING_2[i] != NULL_TERMINATOR)) {
		if (STRING_1[i] != STRING_2[i]) {
			return 0;
		} else {
		}
		i++;
	}
	return 1;
}
/*CONVERTS THE ADDRESS FROM CHARACTERS TO DECIMAL NUMBER*/
static uint8_t ConvertCh_Dec(ptr_uint8_t STRING_1, ptr_uint8_t Address) {
	uint8_t lu8_counter = 0;
	uint8_t lu8_counter2 = 0;
	while (STRING_1[lu8_counter] != NULL_TERMINATOR) {
		if ((STRING_1[lu8_counter] != '0') && (STRING_1[lu8_counter] != '1')) {
			return 2;
		} else {
			STRING_1[lu8_counter] = gu8_ReceiverAddr[lu8_counter] - '0';
			lu8_counter++;
		}
	}
	lu8_counter = lu8_counter - 1;
	if (lu8_counter != ADDRESS_SIZE) {
		return 1;
	} else {
	}
	while (lu8_counter2 != 8) {
		*Address |= (STRING_1[lu8_counter] << lu8_counter2);
		lu8_counter--;
		lu8_counter2++;
	}
	return 0;

}

/*- APIs IMPLEMENTATION
 -----------------------------------*/
void App_Init(void) {
	/*--Initialization--*/
	DIO_SetPortDirection(PORTA, PORT_OUTPUT);
	UART_Init(UART_1);
	TWI_Init(TWI_1);
}
void App_Update(void) {
	/*GET THE COMMAND(READ/WRITE)*/
	UART_ReceiveString(UART_1, gu8_ReceiverBuffer);

	if ((StringCmpr(gu8_WriteMsg, gu8_ReceiverBuffer)) != 0) {
		/*GET THE ADDRESS*/
		UART_TransmitString(UART_1, gu8_EnterTheADDR);
		UART_ReceiveString(UART_1, gu8_ReceiverAddr);
		/*CONVERTS THE ADDRESS FROM CHARACTERS TO DECIMAL NUMBER
		 * AND CHECK IF THE ADRESS IS 8-BIT AND BINARY */
		while (ConvertCh_Dec(gu8_ReceiverAddr, &gu8_WriteAddr) != 0) {
			/*WORNG ADDRESS, ASK THE USER TO REENTER THE ADDRESS*/
			UART_TransmitString(UART_1, gu8_EnterTheAddrAga);
			UART_ReceiveString(UART_1, gu8_ReceiverAddr);
		}
			/*IF THE ADDRESS IS CORRECT*/
			/*GET THE CHAR*/
			UART_TransmitString(UART_1, gu8_EnterTheData);
			UART_ReceiveChar(UART_1, &data);
			UART_TransmitChar(UART_1, '\r');
			/*STORE THE CHARR IN EEPROM*/
			EEPROM_Write(EEPROM_1_B1, gu8_WriteAddr, data);

		/*SEND OK MSG TO INFORM THE USER THAT THE PROCESS WENT WELL*/
		UART_TransmitString(UART_1, gu8_OkMsg);

	} else if ((StringCmpr(gu8_ReceiverBuffer, gu8_ReadMsg)) == 1) {
		/*GET THE ADDRESS*/
		UART_TransmitString(UART_1, gu8_EnterTheADDR);
		UART_ReceiveString(UART_1, gu8_ReceiverAddr);
		/*CONVERTS THE ADDRESS FROM CHARACTERS TO DECIMAL NUMBER
		 * AND CHECK IF THE ADRESS IS 8-BIT AND BINARY */
		while (ConvertCh_Dec(gu8_ReceiverAddr, &gu8_ReadAddr) != 0) {
			/*WORNG ADDRESS, ASK THE USER TO REENTER THE ADDRESS*/
			UART_TransmitString(UART_1, gu8_EnterTheAddrAga);
			UART_ReceiveString(UART_1, gu8_ReceiverAddr);
		}
			/*READ THE CHAR FROM EEPROM*/
			EEPROM_Read(EEPROM_1_B1, gu8_ReadAddr, &data);
		/*CHECK IF THE DATA IS CORRECT*/
		if (data == 0xff) {
			UART_TransmitString(UART_1, gu8_Empty);
		} else {
			/*SEND OK MSG TO INFORM THE USER THAT THE PROCESS WENT WELL*/
			UART_TransmitString(UART_1, gu8_OkMsg);
			UART_TransmitChar(UART_1, data);
			UART_TransmitChar(UART_1, '\r');
		}
	} else {
		/*SEND ERORR MSG, NO SUCH COMMAND*/
		UART_TransmitString(UART_1, gu8_ErrorMsg);
	}

}

