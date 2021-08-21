#ifndef TIMER_H_
#define TIMER_H_
/*- INCLUDES
----------------------------------------------*/
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include"TIMER_CONFIG.h"
/*- MACROS
------------------------------------------*/
// Timer channels
#define TIMER0  (uint8_t)0 // 8-Bits timer
#define TIMER1  (uint8_t)1 // 16-Bits timer
#define TIMER2  (uint8_t)2 // 8-Bits timer

//TIMER OC PINS
#define TIMER0_OC0   (uint8_t)0
#define TIMER1_OC1A  (uint8_t)1
#define TIMER1_OC1B  (uint8_t)2
#define TIMER2_OC2   (uint8_t)3
//TIMER OCR REGISTER
#define TIMER0_OCR0   (uint8_t)0
#define TIMER1_OCR1A  (uint8_t)1
#define TIMER1_OCR1B  (uint8_t)2
#define TIMER2_OCR2   (uint8_t)3
//TIMER INTERRUPTS
#define TIMER0_OVF_INTERRUPT     (uint8_t)0
#define TIMER0_CTC_INTERRUPT     (uint8_t)1

#define TIMER1_ICU_INTERRUPT     (uint8_t)2
#define TIMER1_CTCA_INTERRUPT    (uint8_t)3
#define TIMER1_CTCB_INTERRUPT    (uint8_t)4
#define TIMER1_OVF_INTERRUPT     (uint8_t)5

#define TIMER2_OVF_INTERRUPT     (uint8_t)6
#define TIMER2_CTC_INTERRUPT     (uint8_t)7



/*- FUNCTION DECLARATIONS ----------------------------------*/
/*API TO INIT THE TIMER*/
ERROR_STATE_t TIMER_init(uint8_t timer_no);
/*API TO START THE TIMER*/
ERROR_STATE_t TIMER_start(uint8_t timer_no);
/*API TO STOP THE TIMER*/
ERROR_STATE_t TIMER_stop(uint8_t timer_no);
/*API TO ENABLE TIMER INTERRUPT*/
ERROR_STATE_t TIMER_EN_Interrupt(uint8_t timer_interrupt_no);
/*API TO DISABLE TIMER INTERRUPT*/
ERROR_STATE_t TIMER_DIS_Interrupt(uint8_t timer_interrupt_no);
/*API TO SET CALL BACK FUNCTION*/
ERROR_STATE_t TIMER_callBackFunc(uint8_t interrupt_ch, Ptr_VoidFuncVoid_t callBack);
/*API TO CONNECT TIMER PINS*/
ERROR_STATE_t TIMER_pinConnect(uint8_t timer_pin);
/*API TO DISCONNECT TIMER PINS*/
ERROR_STATE_t TIMER_pinDisconnect(uint8_t timer_pin);
/*API TO SET PRELOAD*/
ERROR_STATE_t TIMER_preload(uint8_t timer_no,uint16_t value);
/*API TO SET VALUE TO COMPARE*/
ERROR_STATE_t TIMER_cmprValue(uint8_t timer_cmpReg,uint16_t value);


#endif /*TIMER_H_*/
