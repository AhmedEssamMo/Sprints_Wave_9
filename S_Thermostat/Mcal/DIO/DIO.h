#ifndef _DIO_H_
#define _DIO_H_
/*INCLUDES
 ******************/
#include"../../Infrastructure/Macros.h"
#include"../../Infrastructure/TypeDef.h"
#include"DIO_retval.h"

typedef uint8_t DIO_ERROR_state_t;
//
/*MACROS
 ***************/
#define NUMBER_OF_PORTS (uint8_t) 3
//PORTS
#define PORTA (uint8_t)0
#define PORTB (uint8_t)1
#define PORTC (uint8_t)2
#define PORTD (uint8_t)3
//Port state
#define PORT_INPUT  (uint8_t)0   //0 sets the port output
#define PORT_OUTPUT (uint8_t)255 //255 sets the port output
#define PORT_LOW  (uint8_t)0     //0 sets the port low
#define PORT_HIGH (uint8_t)255   //255 sets the port high
//PINS
#define PIN0 (uint8_t)0
#define PIN1 (uint8_t)1
#define PIN2 (uint8_t)2
#define PIN3 (uint8_t)3
#define PIN4 (uint8_t)4
#define PIN5 (uint8_t)5
#define PIN6 (uint8_t)6
#define PIN7 (uint8_t)7
//PINS States
#define PIN_INPUT  (uint8_t)0 //0 sets the pin input
#define PIN_OUTPUT (uint8_t)1 //1 sets the pin output
#define PIN_HIGH (uint8_t)1
#define PIN_LOW  (uint8_t)0
/*
 * APIs Declaration
 */
DIO_ERROR_state_t DIO_SetPortDirection(uint8_t PORTID, uint8_t PortDirection);
DIO_ERROR_state_t DIO_SetPinDirection(uint8_t PortID , uint8_t PinNumber, uint8_t PinDirection);
DIO_ERROR_state_t DIO_writePort(uint8_t PortID, uint8_t PortValue);
DIO_ERROR_state_t DIO_WritePin(uint8_t PortID, uint8_t PinNumber,uint8_t PinDirection);
DIO_ERROR_state_t DIO_ReadPort(uint8_t PortID, uint8_t* PortState);
DIO_ERROR_state_t DIO_ReadPin(uint8_t PortID,uint8_t PinNumber, uint8_t* PinState);
DIO_ERROR_state_t DIO_TogglePin(uint8_t PortID, uint8_t PinNumber);
DIO_ERROR_state_t DIO_EnablePinPullup(uint8_t PortID, uint8_t PinNumber);
#endif /* _DIO_H_ */
