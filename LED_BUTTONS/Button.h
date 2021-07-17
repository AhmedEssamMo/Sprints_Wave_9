#ifndef Button_H_
#define Button_H_

uint8_t Button_getState(uint8_t PortID, uint8_t PinNumber);
Button_ERROR_state_t Button_Init(uint8_t PortID, uint8_t PinNumber);
#endif  /*Button_H_*/
