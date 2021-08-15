#ifndef DIO_retval_H_
#define DIO_retval_H



/*----------Set port direction succeed----------*/
#define           E_DIO_SUCCESS             (DIO_ERROR_state_t)( 0 )

/*----------This Error Happens if PORT_NUMBER is not between 0->3----------*/
#define           E_DIO_INVALID_PORT_NUMBER        (DIO_ERROR_state_t)( 1 )

/*----------This Error Happens if PIN_DIRECTION is not INPUT OR OUTPUT----------*/
#define           E_DIO_INVALID_PIN_DIRECTION        (DIO_ERROR_state_t)( 2 )

/*----------This Error Happens if setting PUR to non input pin----------*/
#define           E_DIO_SET_TO_NON_INPUT        (DIO_ERROR_state_t)( 3 )




#endif //"DIO_retval_H_"
