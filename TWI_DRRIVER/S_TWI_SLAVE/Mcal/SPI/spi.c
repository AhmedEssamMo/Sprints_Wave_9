#include"spi.h"
#include"spi_reg.h"

/*CPOL FUNCTIONALITY*/
#define RISING_FALLING       (uint8_t)0x00
#define FALLLING_RISING      (uint8_t)0x08

/*CLOCK PHASE BIT*/
#define SAMPLE_SETUP         (uint8_t)0x00
#define SETUP_SAMPLE         (uint8_t)0x04

/*PRESCALER*/
#define FREQ_4               (uint8_t)0x00
#define FREQ_16              (uint8_t)0x01
#define FREQ_64              (uint8_t)0x02
#define FREQ_128             (uint8_t)0x03

/*DATA ORDER MODES*/
#define LSB_FIRST            (uint8_t)0x20
#define MSB_FIRST            (uint8_t)0x00

#define SPIE (uint8_t)7
#define SPE  (uint8_t)6
#define DORD (uint8_t)5
#define MSTR (uint8_t)4
#define CPOL (uint8_t)3
#define CPHA (uint8_t)2
#define SPR1 (uint8_t)1
#define SPR0 (uint8_t)0
#define SPI2X (uint8_t)0
#define SPIF (uint8_t)7

Ptr_VoidFuncVoid_t G_SPI_CALLBACK ;
#if MODE_MSRT_SLAVE
static uint8_t SPI_SlaveInit(void);
static uint8_t SPI_SlaveInit(void) {
#if MODE_MSRT_SLAVE
#if SLAVE_1
	DIO_SetPinDirection(SLAVE_1_PORT, SLAVE_1_PIN, PIN_OUTPUT);
	DIO_WritePin(SLAVE_1_PORT, SLAVE_1_PIN, PIN_HIGH);
#endif
#if SLAVE_2
	DIO_SetPinDirection(SLAVE_2_PORT,SLAVE_2_PIN,PIN_OUTPUT);
	DIO_WritePin(SLAVE_2_PORT,SLAVE_2_PIN,PORT_HIGH);
#endif
#if SLAVE_3
	DIO_SetPinDirection(SLAVE_3_PORT,SLAVE_3_PIN,PIN_OUTPUT);
	DIO_WritePin(SLAVE_3_PORT,SLAVE_3_PIN,PIN_HIGH);
#endif
#if SLAVE_4
	DIO_SetPinDirection(SLAVE_4_PORT,SLAVE_4_PIN,PIN_OUTPUT);
	DIO_WritePin(SLAVE_4_PORT,SLAVE_4_PIN,PIN_HIGH);
#endif
#if SLAVE_5
	DIO_SetPinDirection(SLAVE_5_PORT,SLAVE_5_PIN,PIN_OUTPUT);
	DIO_WritePin(SLAVE_5_PORT,SLAVE_5_PIN,PIN_HIGH);
#endif
#if SLAVE_6
	DIO_SetPinDirection(SLAVE_6_PORT,SLAVE_6_PIN,PIN_OUTPUT);
	DIO_WritePin(SLAVE_6_PORT,SLAVE_6_PIN,PIN_HIGH);
#endif
#if SLAVE_7
	DIO_SetPinDirection(SLAVE_7_PORT,SLAVE_7_PIN,PIN_OUTPUT);
	DIO_WritePin(SLAVE_7_PORT,SLAVE_7_PIN,PIN_HIGH);
#endif
#if SLAVE_8
	DIO_SetPinDirection(SLAVE_8_PORT,SLAVE_8_PIN,PIN_OUTPUT);
	DIO_WritePin(SLAVE_8_PORT,SLAVE_8_PIN,PIN_HIGH);
#endif
#else
#endif

	return 0;
}
#endif
uint8_t SPI_Init(uint8_t SpiNumber) {
#if MODE_MSRT_SLAVE
	Set_Bit(SPCR, SPE);
	Set_Bit(SPCR, MSTR);
	SPCR |= (CPOL_FUNCTIONALITY ) | (CLK_PHASE_BIT ) | (PRESCALER )
	| (DATA_ORDER );
	DIO_SetPinDirection(SPI_CH0_MISO_PORT, SPI_CH0_MISO_PIN, PIN_INPUT);
	DIO_SetPinDirection(SPI_CH0_MOSI_PORT, SPI_CH0_MOSI_PIN, PIN_OUTPUT);
	DIO_SetPinDirection(SPI_CH0_SCK_PORT, SPI_CH0_SCK_PIN, PIN_OUTPUT);
	DIO_SetPinDirection(SPI_CH0_SS_PORT, SPI_CH0_SS_PIN, PIN_INPUT);
	SPI_SlaveInit();
#if DOUBLE_SPEED
	Set_Bit(SPSR,SPI2X);
#else
	Clr_Bit(SPSR, SPI2X);
#endif /*DOUBLE_SPEED*/

#else
	Clr_Bit(SPCR, MSTR);
	Set_Bit(SPCR, SPE);
	DIO_SetPinDirection(SPI_CH0_MISO_PORT, SPI_CH0_MISO_PIN, PIN_OUTPUT);
	DIO_SetPinDirection(SPI_CH0_MOSI_PORT, SPI_CH0_MOSI_PIN, PIN_INPUT);
	DIO_SetPinDirection(SPI_CH0_SCK_PORT, SPI_CH0_SCK_PIN, PIN_INPUT);
	DIO_SetPinDirection(SPI_CH0_SS_PORT, SPI_CH0_SS_PIN, PIN_INPUT);
#endif/*MODE_MSRT_SLAVE*/
	return 0;
}

uint8_t SPI_TransmitChar(uint8_t SpiNumber, uint8_t TxChar, uint8_t slave_CH) {
#if MODE_MSRT_SLAVE
	switch (slave_CH) {
		case SLAVE_CH1:
		DIO_WritePin(SLAVE_1_PORT, SLAVE_1_PIN, PIN_LOW);
		SPDR = TxChar;
		while (!(SPSR & (1 << SPIF )))
		;
//		while((Get_Bit(SPSR,SPIF))!=1);
		DIO_WritePin(SLAVE_1_PORT, SLAVE_1_PIN, PIN_HIGH);
		break;
		default:
		break;
	}
#else
	SPDR = TxChar;
	//trigger an external interrupt in master MCU
	while (!(SPSR & (1 << SPIF )))
		;
#endif
	return 0;
}
uint8_t SPI_TransmitString(uint8_t SpiNumber, ptr_uint8_t TxString,
		uint8_t slave_CH) {
	uint8_t counter = 0;
#if MODE_MSRT_SLAVE

	switch (slave_CH) {
		case SLAVE_CH1:
		DIO_WritePin(SLAVE_1_PORT, SLAVE_1_PIN, PIN_LOW);
		while (counter >= 255) {
			if ((*(TxString + counter)) == NULL_TERMINATOR) {
				break;
			}
			SPDR = *(TxString + counter);
			counter++;
			while ((Get_Bit(SPSR, SPIF)) != 1)
			;
		}
		DIO_WritePin(SLAVE_1_PORT, SLAVE_1_PIN, PIN_HIGH);
		break;
		default:
		break;
	}
#else
	while (counter >= 255) {
		if ((*(TxString + counter)) == NULL_TERMINATOR) {
			break;
		}
		SPDR = *(TxString + counter);
		counter++;
		//trigger an external interrupt in master MCU
		while (!(SPSR & (1 << SPIF )))
			;
	}
#endif
	return 0;
}

uint8_t SPI_ReceiveChar(uint8_t SpiNumber, ptr_uint8_t RxData, uint8_t slave_CH) {

#if MODE_MSRT_SLAVE
	uint8_t Dummy_Data = 0;
	switch (slave_CH) {
		case SLAVE_CH1:
		DIO_WritePin(SLAVE_1_PORT, SLAVE_1_PIN, PIN_LOW);
		SPI_TransmitChar(SPI_CH1, Dummy_Data, SLAVE_CH1);
		while ((Get_Bit(SPSR, SPIF)) != 1)
		;
		*(RxData) = SPDR;
		DIO_WritePin(SLAVE_1_PORT, SLAVE_1_PIN, PIN_HIGH);
		break;
		default:
		break;
	}
#else
	while (!(SPSR & (1 << SPIF )))
		;
	*(RxData) = SPDR;
#endif
	return 0;
}
uint8_t SPI_ReceiveString(uint8_t SpiNumber, ptr_uint8_t RxString,
		uint8_t slave_CH) {
	uint8_t counter = 0;
#if MODE_MSRT_SLAVE
	uint8_t Dummy_Data = 0;
	switch (slave_CH) {
		case SLAVE_CH1:
		DIO_WritePin(SLAVE_1_PORT, SLAVE_1_PIN, PIN_LOW);
		while (1) {
			SPI_TransmitChar(SPI_CH1,Dummy_Data,SLAVE_CH1);
			while ((Get_Bit(SPSR, SPIF)) != 1)
			;
			*(RxString+counter) = SPDR;
			if((*(RxString+counter))==NEW_LINE) {
				*(RxString+counter)=NULL_TERMINATOR;
				break;
			}
			counter++;
		}
		DIO_WritePin(SLAVE_1_PORT, SLAVE_1_PIN, PIN_HIGH);
		break;
		default:
		break;
	}
#else
	while (1) {
		while ((Get_Bit(SPSR, SPIF)) != 1);
		*(RxString + counter) = SPDR;
		if ((*(RxString + counter)) == NULL_TERMINATOR) {
			break;
		}
		counter++;
	}
#endif
	return 0;
}

uint8_t SPI_EnableInterrupt(uint8_t SpiNumber) {
	Set_Bit(SPCR, SPIE);
	return 0;
}
uint8_t SPI_DisableInterrupt(uint8_t SpiNumber) {
	Clr_Bit(SPCR, SPIE);
	return 0;
}

uint8_t SPI_SetCallback(uint8_t SpiNumber, Ptr_VoidFuncVoid_t Callback) {
	G_SPI_CALLBACK=Callback;
	return 0;
}

void __vector_12(void) __attribute__((signal)); // Serial Transfer Complete
void __vector_12(void) {
	G_SPI_CALLBACK();
}

