#include"DIO_REG.h"
#include"DIO.h"



/* APIs IMPLEMENTATION */

/* API to Set Port Direction */
DIO_ERROR_state_t DIO_setPortDirection(uint8_t PortID, uint8_t PortDirection) {
	//Check for the ports if it is between 0 to 3
	if ((PortID <= PORTD ) && (PortID >= PORTA )) {
		switch (PortID) {
		case PORTA :
			PORTA_DIR = PortDirection;
			break;
		case PORTB :
			PORTB_DIR = PortDirection;
			break;
		case PORTC :
			PORTC_DIR = PortDirection;
			break;
		case PORTD :
			PORTD_DIR = PortDirection;
			break;

		} //END of SWITCH
		return E_DIO_SUCCESS ;
	}	  //END of IF
	else {
		return E_DIO_INVALID_PORT_NUMBER ;

	}	  //END of ELSE
}	  //END DIO_setPortDirection

/* API to Set Pin Direction */
DIO_ERROR_state_t DIO_SetPinDirection(uint8_t PortID, uint8_t PinNumber,
		uint8_t PinDirection) {
	//Check for the ports if it is between 0 to 3
	if ((PortID <= PORTD ) && (PortID >= PORTA ) && (PinNumber >= PIN0 )
			&& (PinNumber <= PIN7 )) {
		if (PinDirection == PIN_OUTPUT) {
			switch (PortID) {
			case PORTA :
				Set_Bit(PORTA_DIR, PinNumber);
				break;
			case PORTB :
				Set_Bit(PORTB_DIR, PinNumber);
				break;
			case PORTC :
				Set_Bit(PORTC_DIR, PinNumber);
				break;
			case PORTD :
				Set_Bit(PORTD_DIR, PinNumber);
				break;

			} //END of SWITCH
			return E_DIO_SUCCESS ;
		} // END of IF that check for the direction if it is INPUT
		else if (PinDirection == PIN_INPUT) {
			switch (PortID) {
			case PORTA :
				Clr_Bit(PORTA_DIR, PinNumber);
				break;
			case PORTB :
				Clr_Bit(PORTB_DIR, PinNumber);
				break;
			case PORTC :
				Clr_Bit(PORTC_DIR, PinNumber);
				break;
			case PORTD :
				Clr_Bit(PORTD_DIR, PinNumber);
				break;

			} //END of SWITCH
			return E_DIO_SUCCESS ;
		} // END of ELSE IF that check for the direction if it is INPUT
		else {
			return E_DIO_INVALID_PIN_DIRECTION ;
		} //END OF ELSE

	}	  //END of IF That checking the port and pin number

	else {
		return E_DIO_INVALID_PORT_NUMBER ;

	}	  //END of ELSE
}	  //END DIO_setPinDirection

/* API to Write Port  Value */
DIO_ERROR_state_t DIO_writePort(uint8_t PortID, uint8_t PortValue) {
	//Check for the ports if it is between 0 to 3
	if ((PortID <= PORTD ) && (PortID >= PORTA )) {
		switch (PortID) {
		case PORTA :
			PORTA_DATA = PortValue;
			break;
		case PORTB :
			PORTB_DATA = PortValue;
			break;
		case PORTC :
			PORTC_DATA = PortValue;
			break;
		case PORTD :
			PORTD_DATA = PortValue;
			break;

		} //END of SWITCH
		return E_DIO_SUCCESS ;
	}	  //END of IF
	else {
		return E_DIO_INVALID_PORT_NUMBER ;

	}	  //END of ELSE
}	  //END DIO_writePortValue

/* API to Write Pin  Value */
DIO_ERROR_state_t DIO_WritePin(uint8_t PortID, uint8_t PinNumber,
		uint8_t PinDirection) {
	//Check for the ports if it is between 0 to 3
	if ((PortID <= PORTD ) && (PortID >= PORTA ) && (PinNumber >= PIN0 )
			&& (PinNumber <= PIN7 )) {
		if (PinDirection == PIN_HIGH) {
			switch (PortID) {
			case PORTA :
				Set_Bit(PORTA_DATA, PinNumber);
				break;
			case PORTB :
				Set_Bit(PORTB_DATA, PinNumber);
				break;
			case PORTC :
				Set_Bit(PORTC_DATA, PinNumber);
				break;
			case PORTD :
				Set_Bit(PORTD_DATA, PinNumber);
				break;

			} //END of SWITCH
			return E_DIO_SUCCESS ;
		} // END of IF that check for the direction if it is INPUT
		else if (PinDirection == PIN_LOW) {
			switch (PortID) {
			case PORTA :
				Clr_Bit(PORTA_DATA, PinNumber);
				break;
			case PORTB :
				Clr_Bit(PORTB_DATA, PinNumber);
				break;
			case PORTC :
				Clr_Bit(PORTC_DATA, PinNumber);
				break;
			case PORTD :
				Clr_Bit(PORTD_DATA, PinNumber);
				break;

			} //END of SWITCH
			return E_DIO_SUCCESS ;
		} // END of ELSE IF that check for the direction if it is INPUT
		else {
			return E_DIO_INVALID_PIN_DIRECTION ;
		} //END OF ELSE

	}	  //END of IF That checking the port and pin number

	else {
		return E_DIO_INVALID_PORT_NUMBER ;

	}	  //END of ELSE
}	  //END of DIO_writePinValue

/* API to Read Port  Value */
DIO_ERROR_state_t DIO_ReadPort(uint8_t PortID, uint8_t* PortState) {
	//Check for the ports if it is between 0 to 3
	if ((PortID <= PORTD ) && (PortID >= PORTA )) {
		switch (PortID) {
		case PORTA :
			*(PortState) = PORTA_STAT;
			break;
		case PORTB :
			*(PortState) = PORTB_STAT;
			break;
		case PORTC :
			*(PortState) = PORTC_STAT;
			break;
		case PORTD :
			*(PortState) = PORTD_STAT;
			break;

		} //END of SWITCH
		return E_DIO_SUCCESS ;
	}	  //END of IF
	else {
		return E_DIO_INVALID_PORT_NUMBER ;

	}	  //END of ELSE
}	  //END of DIO_readPort

/* API to Read Pin  Value */
DIO_ERROR_state_t DIO_ReadPin(uint8_t PortID, uint8_t PinNumber,
		uint8_t* PinState) {
	//Check for the ports if it is between 0 to 3
	if ((PortID <= PORTD ) && (PortID >= PORTA ) && (PinNumber >= PIN0 )
			&& (PinNumber <= PIN7 )) {

		switch (PortID) {
		case PORTA :
			*(PinState) = Get_Bit(PORTA_STAT, PinNumber);
			break;
		case PORTB :
			*(PinState) = Get_Bit(PORTB_STAT, PinNumber);
			break;
		case PORTC :
			*(PinState) = Get_Bit(PORTC_STAT, PinNumber);
			break;
		case PORTD :
			*(PinState) = Get_Bit(PORTD_STAT, PinNumber);
			break;

		} //END of SWITCH
		return E_DIO_SUCCESS ;

	}	  //END of IF That checking the port and pin number

	else {
		return E_DIO_INVALID_PORT_NUMBER ;

	}	  //END of ELSE
}    //END of DIO_readPint

/* API to toggle pin*/
DIO_ERROR_state_t DIO_TogglePin(uint8_t PortID, uint8_t PinNumber){
	//Check for the ports if it is between 0 to 3
		if ((PortID <= PORTD ) && (PortID >= PORTA ) && (PinNumber >= PIN0 )
				&& (PinNumber <= PIN7 )) {
			switch (PortID) {
			case PORTA :
				Toggle_Bit(PORTA_DATA, PinNumber);
				break;
			case PORTB :
				Toggle_Bit(PORTB_DATA, PinNumber);
				break;
			case PORTC :
				Toggle_Bit(PORTC_DATA, PinNumber);
				break;
			case PORTD :
				Toggle_Bit(PORTD_DATA, PinNumber);
				break;

			} //END of SWITCH
			return E_DIO_SUCCESS ;

		}	  //END of IF That checking the port and pin number

		else {
			return E_DIO_INVALID_PORT_NUMBER ;

		}	  //END of ELSE

}
DIO_ERROR_state_t DIO_EnablePinPullup(uint8_t PortID, uint8_t PinNumber){
	//Check for the ports if it is between 0 to 3
		if ((PortID <= PORTD ) && (PortID >= PORTA ) && (PinNumber >= PIN0 )
				&& (PinNumber <= PIN7 )) {
			switch (PortID) {
			case PORTA :
				if(Get_Bit(PORTA_DIR, PinNumber)==PIN_INPUT){
					Set_Bit(PORTA_DATA, PinNumber);
				}// END of IF which checking if the  pin is INPUT
				else{
					return E_DIO_SET_TO_NON_INPUT;
				}
				break;
			case PORTB :
				if(Get_Bit(PORTB_DIR, PinNumber)==PIN_INPUT){
					Set_Bit(PORTB_DATA, PinNumber);
				}// END of IF which checking if the  pin is INPUT
				else{
					return E_DIO_SET_TO_NON_INPUT;
				}
				break;
			case PORTC :
				if(Get_Bit(PORTC_DIR, PinNumber)==PIN_INPUT){
					Set_Bit(PORTC_DATA, PinNumber);
				}// END of IF which checking if the  pin is INPUT
				else{
					return E_DIO_SET_TO_NON_INPUT;
				}
				break;
			case PORTD :
				if(Get_Bit(PORTD_DIR, PinNumber)==PIN_INPUT){
					Set_Bit(PORTD_DATA, PinNumber);
				}// END of IF which checking if the  pin is INPUT
				else{
					return E_DIO_SET_TO_NON_INPUT;
				}
				break;

			} //END of SWITCH
			return E_DIO_SUCCESS ;

		}	  //END of IF That checking the port and pin number

		else {
			return E_DIO_INVALID_PORT_NUMBER ;

		}	  //END of ELSE

}
