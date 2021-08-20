#ifndef _ADC_RETVAL_H_
#define _ADC_RETVAL_H_

/*- PRIMITIVE TYPES ----------------------------------------*/
typedef   int8_t      TWI_ERROR_state_t;


//INIT STAT
#define INIT     (uint8_t)1
#define NOT_INIT (uint8_t)0

/*- LOCAL MACROS
------------------------------------------*/
/*
		This Happens when API do what is suppose to do
 */
#define           TWI_SUCCESS             (TWI_ERROR_state_t)( 0 )

/*
		This Error happens if UART is already initialized before
*/
#define           TWI_SEC_INIT             (TWI_ERROR_state_t)( -1 )
/*
 *     This Error happens if UART is not  initialized before
 */
#define           TWI_NOT_INIT             (TWI_ERROR_state_t)(- 2 )

/*
 *     This Error happens if pointer is null
 */
#define           TWI_NULL_POINTER         (TWI_ERROR_state_t)( -3 )
/*
*      This Error happens if INVALID UART CHANNEL
*/
#define           TWI_INVALID_CHANNEL      (TWI_ERROR_state_t)( -4 )




#endif /*_ADC_RETVAL_H_*/
