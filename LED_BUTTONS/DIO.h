#ifndef _DIO_H_
#define _DIO_H_


//
#define ZERO  (uint8_t)0
#define NUMBER_OF_PORTS (uint8_t) 3
#define PORTA (uint8_t)0
#define PORTB (uint8_t)1
#define PORTC (uint8_t)2
#define PORTD (uint8_t)3
//Port state
#define PORT_INPUT  (uint8_t)0   //0 sets the port output
#define PORT_OUTPUT (uint8_t)255 //255 sets the port output

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
DIO_ERROR_state_t DIO_setPortDirection(uint8_t PORTID, uint8_t PortDirection);
DIO_ERROR_state_t DIO_setPinDirection(uint8_t PortID , uint8_t PinNumber, uint8_t PinDirection);
DIO_ERROR_state_t DIO_writePortValue(uint8_t PortID, uint8_t PortValue);
DIO_ERROR_state_t DIO_writePinValue(uint8_t PortID, uint8_t PinNumber,uint8_t PinDirection);
DIO_ERROR_state_t DIO_readPort(uint8_t PortID, uint8_t* PortState);
DIO_ERROR_state_t DIO_readPin(uint8_t PortID,uint8_t PinNumber, uint8_t* PinState);
DIO_ERROR_state_t DIO_TogglePin(uint8_t PortID, uint8_t PinNumber);
DIO_ERROR_state_t DIO_SetPullupRes(uint8_t PortID, uint8_t PinNumber);
#endif // _DIO_H_
