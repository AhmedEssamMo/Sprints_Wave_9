#include"TrafficLight.h"
/*LOCAL FUNCTION PROTOTYPE
----------------------------*/
static uint8_t StringCmpr(ptr_uint8_t STRING_1, ptr_uint8_t STRING_2);

/*GLOBAL STATIC VARIABLE
----------------------------*/
static uint8_t gu8_Start[] = "START";
static uint8_t gu8_StartReply[] = "LED GREEN IS ON\r";
static uint8_t gu8_Wait[] = "WAIT";
static uint8_t gu8_WaitReply[] = "LED YELLOW IS ON\r";
static uint8_t gu8_Stop[] = "STOP";
static uint8_t gu8_StopReply[] = "LED RED IS ON\r";
static uint8_t gu8_ErrorReply[] = "NOT RECOGNIZED\r";
static uint8_t gu8_SystemCheck[] = "AT";
static uint8_t gu8_CheckReply[] = "SYSTEM IS OK\r";

uint8_t gu8_ReceiverBuffer[100];


/*LOCAL FUNCTION IMPLEMENTATION
----------------------------*/
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

/*- APIs IMPLEMENTATION
-----------------------------------*/


uint8_t TrafficLightInit(void) {
	uint8_t state;
	state = LED_Init();
	UART_Init(UART_1);
	return 0;
}
uint8_t TrafficLightUpdate(void) {
	UART_ReceiveString(UART_1, gu8_ReceiverBuffer);
	if (StringCmpr(gu8_Start, gu8_ReceiverBuffer) == 1) {
		UART_TransmitString(UART_1, gu8_StartReply);
		LED_On(LED_1);
		LED_Off(LED_2);
		LED_Off(LED_3);
	} else if (StringCmpr(gu8_Wait, gu8_ReceiverBuffer) == 1) {
		UART_TransmitString(UART_1, gu8_WaitReply);
		LED_Off(LED_1);
		LED_On(LED_2);
		LED_Off(LED_3);
	} else if (StringCmpr(gu8_Stop, gu8_ReceiverBuffer) == 1) {
		UART_TransmitString(UART_1, gu8_StopReply);
		LED_Off(LED_1);
		LED_Off(LED_2);
		LED_On(LED_3);
	} else if (StringCmpr(gu8_SystemCheck, gu8_ReceiverBuffer) == 1) {
		UART_TransmitString(UART_1, gu8_CheckReply);
	} else {
		UART_TransmitString(UART_1, gu8_ErrorReply);

		LED_Off(LED_1);
		LED_Off(LED_2);
		LED_Off(LED_3);

	}
	return 0;
}

