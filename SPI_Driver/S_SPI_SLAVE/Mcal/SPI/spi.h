#ifndef _SPI_H_
#define _SPI_H_
#include"../../Infrastructure/TypeDef.h"
#include"../../Infrastructure/Macros.h"
#include"../DIO/DIO.h"
#include"spiConfig.h"

#define SPI_CH1      0
#define SLAVE_CH1    0
#define SLAVE_CH2    1
#define SLAVE_CH3    2
#define SLAVE_CH4    3
#define SLAVE_CH5    4
#define SLAVE_CH6    5
#define SLAVE_CH7    6
#define SLAVE_CH8    7






//typedef void(*Ptr_VoidFuncVoid_t)(void);


uint8_t SPI_Init(uint8_t SpiNumber);

uint8_t SPI_TransmitChar(uint8_t SpiNumber,uint8_t TxChar,uint8_t slave_CH);
uint8_t SPI_TransmitString(uint8_t SpiNumber,ptr_uint8_t TxString,uint8_t slave_CH);

uint8_t SPI_ReceiveChar(uint8_t SpiNumber,ptr_uint8_t RxData,uint8_t slave_CH);
uint8_t SPI_ReceiveString(uint8_t SpiNumber,ptr_uint8_t RxString,uint8_t slave_CH);

uint8_t SPI_EnableInterrupt(uint8_t SpiNumber);
uint8_t SPI_DisableInterrupt(uint8_t SpiNumber);


uint8_t SPI_SetCallback(uint8_t SpiNumber,Ptr_VoidFuncVoid_t Callback);
#endif /*_SPI_H_*/
