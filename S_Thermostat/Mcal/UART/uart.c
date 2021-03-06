/*INCLUDES
 -------------------------------*/
#include"uartReg.h"
#include"uart.h"

/*LOCAL MACROS
 --------------------------*/
//UART CONTROL AND STATUS REGISTER A BITS (UCSRA)
#define RXC    (uint8_t)7 //READ ONLY , INIT VALUE 0
#define TXC    (uint8_t)6 //READ/WRITE, INIT VALUE 0
#define UDRE   (uint8_t)5 //READ ONLY , INIT VALUE 1
#define FE     (uint8_t)4 //READ ONLY , INIT VALUE 0
#define DOR    (uint8_t)3 //READ ONLY , INIT VALUE 0
#define PE     (uint8_t)2 //READ ONLY , INIT VALUE 0
#define U2X    (uint8_t)1 //READ/WRITE, INIT VALUE 0
#define MPCM   (uint8_t)0 //READ/WRITE, INIT VALUE 0

//UART CONTROL AND STATUS REGISTER B BITS (UCSRB)
#define RXCIE  (uint8_t)7 //READ/WRITE, INIT VALUE 0
#define TXCIE  (uint8_t)6 //READ/WRITE, INIT VALUE 0
#define UDRIE  (uint8_t)5 //READ/WRITE, INIT VALUE 0
#define RXEN   (uint8_t)4 //READ/WRITE, INIT VALUE 0
#define TXEN   (uint8_t)3 //READ/WRITE, INIT VALUE 0
#define UCSZ2  (uint8_t)2 //READ/WRITE, INIT VALUE 0
#define RXB8   (uint8_t)1 //READ ONLY , INIT VALUE 0
#define TXB8   (uint8_t)0 //READ/WRITE, INIT VALUE 0

//UART CONTROL AND STATUS REGISTER C BITS (UCSRC)
#define URSEL  (uint8_t)7 //READ/WRITE, INIT VALUE 1
#define UMSEL  (uint8_t)6 //READ/WRITE, INIT VALUE 0
#define UPM1   (uint8_t)5 //READ/WRITE, INIT VALUE 0
#define UPM0   (uint8_t)4 //READ/WRITE, INIT VALUE 0
#define USBS   (uint8_t)3 //READ/WRITE, INIT VALUE 0
#define UCSZ1  (uint8_t)2 //READ/WRITE, INIT VALUE 1
#define UCSZ0  (uint8_t)1 //READ/WRITE, INIT VALUE 1
#define UCPOL  (uint8_t)0 //READ/WRITE, INIT VALUE 0

/*UCSRC MODES*/
#define ASYNCHRONOUS   (uint8_t)0b10111111
#define SYNCHRONOUS    (uint8_t)0b11111111
#define ONE_STOP_BIT   (uint8_t)0b11110111
#define TWO_STOP_BIT   (uint8_t)0b11111111
#define FIVE_BITS      (uint8_t)0b11111001
#define SIX_BITS       (uint8_t)0b11111011
#define SEVEN_BITS     (uint8_t)0b11111101
#define EIGHT_BITS     (uint8_t)0b11111111
#define NINE_BITS      (uint8_t)0b11111111
#define PARITY_DISABLE (uint8_t)0b11001111
#define EVEN_PARITY    (uint8_t)0b11101111
#define ODD_PARITY     (uint8_t)0b11111111
#define DISABLE_CLOCK       (uint8_t)0b11111110
#define TRANSIMT_ON_RISING  (uint8_t)0b11111110
#define TRANSIMT_ON_FALLING (uint8_t)0b11111111

/*BAUD RATES*/
#define BT_2400_8MHz  207
#define BT_4800_8MHz  103
#define BT_9600_8MHz  51
#define BT_14400_8MHz 34
#define BT_19200_8MHz 25
#define BT_28800_8MHz 16
#define BT_38400_8MHz 12

/*RECEIVEING*/
#define RECEIVER_EN          1
#define RECEIVER_DIS         0
/*TRANSMITTING*/
#define TRANSMITTER_EN       1
#define TRANSMITTER_DIS      0
/*UART SPEEDS*/
#define NORMAL_SPEED         0
#define DOUBLE_SPEED         1

/*GLOBAL STATIC VARIABLES
 -------------------------------*/
Ptr_VoidFuncVoid_t Gptr_uartRxInt;
Ptr_VoidFuncVoid_t Gptr_uartDataEmptyRegInt;
Ptr_VoidFuncVoid_t Gptr_uartTxInt;

/*APIs IMPLEMENTATION
 -------------------------*/
uint8_t UART_Init(uint8_t UartNumber) {
#if RECEIVEING
	Set_Bit(UCSRB, RXEN);
#else
	Clr_Bit(UCSRB,RXEN);
#endif
#if TRANSMITTING
	Set_Bit(UCSRB, TXEN);
#else
	Clr_Bit(UCSRB,TXEN);
#endif
#if SPEED
	Set_Bit(UCSRA,U2X);
#else
	Clr_Bit(UCSRA, U2X);
#endif
#if NINE_BIT
	Set_Bit(UCSRB, UCSZ2);
#else
	Clr_Bit(UCSRB, UCSZ2);
#endif
	UCSRC |= ((SYNCHRONIZATION ) & (STOP_BITS ) & (CHARACTER_SIZE )
			& (PARITY_MODE ) & (CLOCK_POLARITY ));
	UBRRL = BUAD_RATE;
	return 0;
}
uint8_t UART_TransmitChar(uint8_t UartNumber, uint8_t TxChar) {
	UDR = TxChar;
	while ((Get_Bit(UCSRA, UDRE)) != 1) {
	}
	return 0;
}
uint8_t UART_TransmitString(uint8_t UartNumber, ptr_uint8_t TxString) {
	uint8_t counter = 0;
	while ((*(TxString + counter)) != NULL_TERMINATOR) {
		UDR = *(TxString + counter); //TxString[counter]
		while ((Get_Bit(UCSRA, UDRE)) != 1)
			;
		counter++;
	}
	UDR = '\r'; //TxString[counter]
	while ((Get_Bit(UCSRA, UDRE)) != 1)
		;
	return 0;
}
uint8_t UART_ReceiveChar(uint8_t UartNumber, ptr_uint8_t RxChar) {

	while (!(UCSRA & (1 << RXC )))
		;
	*(RxChar) = (uint8_t) UDR;

	return 0;
}
uint8_t UART_ReceiveString(uint8_t UartNumber, ptr_uint8_t RxString) {
	uint8_t counter = 0;
	while (1) {
		while (!(UCSRA & (1 << RXC )))
			;
		RxString[counter] = UDR;
		if (RxString[counter] == (NEW_LINE)) {
			RxString[counter] = NULL_TERMINATOR;
			break;
		}
		counter++;
		if ((RxString[counter-1] == (BACKSPACE)) && counter > 1) {
			counter = counter - 2;
		} else if ((RxString[counter-1] == (BACKSPACE)) && counter <= 1) {
			counter = 0;
		} else {

		}
		//UART_TransmitChar(UART_1,*(RxString+counter));
	}

	//*(RxString+counter)='\n';
	return 0;
}
uint8_t UART_EnableInterrupt(uint8_t UartNumber, uint8_t UartInterruptType) {
	switch (UartNumber) {
	case UART_1 :
		switch (UartInterruptType) {
		case RECIVE_INT :
			Set_Bit(UCSRB, RXCIE);
			break;
		case TRANSMIT_INT :
			Set_Bit(UCSRB, TXCIE);
			break;
		case EMPTY_BUFFERR_INT :
			Set_Bit(UCSRB, UDRIE);
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
	return 0;
}
uint8_t UART_DisableInterrupt(uint8_t UartNumber, uint8_t UartInterruptType) {
	switch (UartNumber) {
	case UART_1 :
		switch (UartInterruptType) {
		case RECIVE_INT :
			Clr_Bit(UCSRB, RXCIE);
			break;
		case TRANSMIT_INT :
			Clr_Bit(UCSRB, TXCIE);
			break;
		case EMPTY_BUFFERR_INT :
			Clr_Bit(UCSRB, UDRIE);
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
	return 0;
}

