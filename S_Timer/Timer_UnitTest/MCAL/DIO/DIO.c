/*- INCLUDES----------------------------------------------*/
#include"DIO.h"
#include"DIO_REG.h"

/*- APIs IMPLEMENTATION----------------------------------------------*/
/* API to Set Port Direction */
ERROR_STATE_t DIO_setPortDirection(uint8_t PortID, uint8_t PortDirection) {
    ERROR_STATE_t u8_ERROR_STAT = ERROR_OK;
	//Check for the ports if it is between 0 to 3
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
    default:
        u8_ERROR_STAT = ERROR_NOK;
        break;
    } //END of SWITCH
    return u8_ERROR_STAT ;
}	  //END DIO_setPortDirection
/* API to Set Pin Direction */
ERROR_STATE_t DIO_setPinDirection(uint8_t PortID, uint8_t PinNumber,uint8_t PinDirection) {
    ERROR_STATE_t u8_ERROR_STAT = ERROR_OK;
	if ((PinNumber >= PIN0 )&& (PinNumber <= PIN7 )) {
		if (PIN_OUTPUT==PinDirection) {
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
            default:
                u8_ERROR_STAT = ERROR_NOK;
                break;
			} //END of SWITCH
		} // END of IF that check for the direction if it is INPUT
		else if (PIN_INPUT==PinDirection) {
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
            default:
                u8_ERROR_STAT = ERROR_NOK;
                break;
			} //END of SWITCH
		} // END of ELSE IF that check for the direction if it is INPUT
		else {
			u8_ERROR_STAT = ERROR_NOK;
		} //END OF ELSE
	}	  //END of IF That checking the port and pin number
	else {
		u8_ERROR_STAT = ERROR_NOK;

	}	  //END of ELSE
	return u8_ERROR_STAT;
}	  //END DIO_setPinDirection

/* API to Write Port  Value */
ERROR_STATE_t DIO_writePortValue(uint8_t PortID, uint8_t PortValue)
{
    ERROR_STATE_t u8_ERROR_STAT = ERROR_OK;
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
    default:
        u8_ERROR_STAT = ERROR_NOK;
        break;
    } //END of SWITCH
    return u8_ERROR_STAT ;
}	  //END DIO_writePortValue

/* API to Write Pin  Value */
ERROR_STATE_t DIO_writePinValue(uint8_t PortID, uint8_t PinNumber,uint8_t PinDirection)
{
    ERROR_STATE_t u8_ERROR_STAT = ERROR_OK;
    /*CHECK IF VALID PIN NUMBER*/
	if ((PinNumber >= PIN0 )&& (PinNumber <= PIN7 )) {
		if (PIN_HIGH==PinDirection) {
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
            default:
                u8_ERROR_STAT = ERROR_NOK;
                break;
			} //END of SWITCH
		} // END of IF that check for the direction if it is INPUT
		else if (PIN_LOW==PinDirection) {
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
            default:
                /*INVALID PORT NUMBER*/
                u8_ERROR_STAT = ERROR_NOK;
                break;
			} //END of SWITCH
		} // END OF ELSE IF
		else
        {
            /*INVALID PIN DIRECTION*/
			u8_ERROR_STAT = ERROR_NOK;
		} //END OF ELSE
	}	  //END OF IF
	else
	{
        /*INVALID PIN NUMBER*/
		u8_ERROR_STAT = ERROR_NOK;
	}	  //END of ELSE
	return u8_ERROR_STAT ;
}	  //END of DIO_writePinValue

/* API to Read Port  Value */
ERROR_STATE_t DIO_readPort(uint8_t PortID, uint8_t* PortState)
{
    ERROR_STATE_t u8_ERROR_STAT = ERROR_OK;
    /*CHECK IF PinState=NULL POINTER*/
	if(NULL_PTR==PortState)
    {
        u8_ERROR_STAT = ERROR_NOK;
	}
	else
	{
    switch (PortID)
    {
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
    default:
            /*INVALID PORT NUMBER*/
        u8_ERROR_STAT = ERROR_NOK;
        break;

		} //END of SWITCH
	}
	return u8_ERROR_STAT ;
}	  //END of DIO_readPort

/* API to Read Pin  Value */
ERROR_STATE_t DIO_readPin(uint8_t PortID, uint8_t PinNumber,uint8_t* PinState) {
    ERROR_STATE_t u8_ERROR_STAT = ERROR_OK;
    /*CHECK IF PinState=NULL POINTER*/
	if(NULL_PTR==PinState)
    {
        u8_ERROR_STAT = ERROR_NOK;
	}
	else
	{
        /*CHECK IF INVALID PIN NUMBER*/
        if ((PinNumber >= PIN0 )&& (PinNumber <= PIN7 ))
        {
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
            default:
                /*INVALID PORT NUMBER*/
                u8_ERROR_STAT = ERROR_NOK;
                break;
            } //END of SWITCH
        }	  //END of IF That checking the port and pin number
        else
        {
            u8_ERROR_STAT = ERROR_NOK;
        }	  //END of ELSE
	}
    return u8_ERROR_STAT ;
}    //END of DIO_readPint
/*
 * API to toggle pin
 * */
ERROR_STATE_t DIO_TogglePin(uint8_t PortID, uint8_t PinNumber){
    ERROR_STATE_t u8_ERROR_STAT = ERROR_OK;
    /*CHECK IF VALID PIN NUMBER*/
    if ((PinNumber >= PIN0 )&& (PinNumber <= PIN7 ))
    {
        switch (PortID)
        {
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
        default:
            /*INVALID PORT NUMBER*/
            u8_ERROR_STAT = ERROR_NOK;
            break;
        } //END OF SWITCH
    }	  //END OF IF
    else {
        /*INVALID PIN NUMBER*/
        u8_ERROR_STAT = ERROR_NOK;
    }	  //END of ELSE
    return u8_ERROR_STAT ;
}
ERROR_STATE_t DIO_SetPullupRes(uint8_t PortID, uint8_t PinNumber){
    ERROR_STATE_t u8_ERROR_STAT = ERROR_OK;
    /*CHECK IF VALID PIN NUMBER*/
    if ((PinNumber >= PIN0 )&& (PinNumber <= PIN7 ))
    {
        switch (PortID)
        {
        case PORTA :
            if(PIN_INPUT==Get_Bit(PORTA_DIR, PinNumber))
            {
                Set_Bit(PORTA_DATA, PinNumber);
            }// END of IF which checking if the  pin is INPUT
            else
            {
                u8_ERROR_STAT = ERROR_NOK;
            }
            break;
        case PORTB :
            if(PIN_INPUT==Get_Bit(PORTB_DIR, PinNumber))
            {
                Set_Bit(PORTB_DATA, PinNumber);
            }// END of IF which checking if the  pin is INPUT
            else
            {
                u8_ERROR_STAT = ERROR_NOK;
            }
            break;
        case PORTC :
            if(PIN_INPUT==Get_Bit(PORTC_DIR, PinNumber))
            {
                Set_Bit(PORTC_DATA, PinNumber);
            }// END of IF which checking if the  pin is INPUT
            else
            {
                u8_ERROR_STAT = ERROR_NOK;
            }
            break;
        case PORTD :
            if(PIN_INPUT==Get_Bit(PORTD_DIR, PinNumber))
            {
                Set_Bit(PORTD_DATA, PinNumber);
            }// END of IF which checking if the  pin is INPUT
            else
            {
                u8_ERROR_STAT = ERROR_NOK;
            }
            break;
        default:
            /*INVALID PORT NUMBER*/
            u8_ERROR_STAT = ERROR_NOK;
            break;
        } //END OF SWITCH
    }	  //END OF IF

    else
    {
        /*INVALID PIN NUMBER*/
        u8_ERROR_STAT = ERROR_NOK;
    } //END of ELSE
    return u8_ERROR_STAT ;
}
