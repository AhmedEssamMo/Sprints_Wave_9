#include "EchoSystem.h"
/*LOCAL FUNCTION PROTOTYPE
----------------------------*/


/*GLOBAL STATIC VARIABLE
----------------------------*/
uint8_t gu8_ReceiverBuffer;

/*LOCAL FUNCTION IMPLEMENTATION
----------------------------*/


/*- APIs IMPLEMENTATION
-----------------------------------*/


uint8_t AppInit(void) {
	UART_Init(UART_1);
	return 0;
}
uint8_t AppUpdate(void) {
	UART_ReceiveChar(UART_1, &gu8_ReceiverBuffer);
	UART_TransmitChar(UART_1,NEW_LINE);
	UART_TransmitChar(UART_1,gu8_ReceiverBuffer);
	UART_TransmitChar(UART_1,NEW_LINE);

	return 0;
}

