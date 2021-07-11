#include"TypeDef.h"
#include"TIMER_REG.h"
#include"Macros.h"
#include"TIMER_CONFIG.h"
#include"TIMER.h"
void (*Gptr_OVINT)(void);  //Global pointer to function
void (*Gptr_CTCINT)(void);  //Global pointer to function
/*Local Macros*/
// TCCR0 BITS
#define FOC0   (uint8_t)7  //Force
#define WGM00  (uint8_t)6
#define WGM01  (uint8_t)3
#define CS02   (uint8_t)2
#define CS01   (uint8_t)1
#define CS00   (uint8_t)0
#define COM01  (uint8_t)5
#define COM00  (uint8_t)4

//TIMSK BITS  Interrupt Enable its
#define TOIE0  (uint8_t)0
#define OCIE0  (uint8_t)1
#define TOIE1  (uint8_t)2
#define OCIE1B (uint8_t)3
#define OCIE1A (uint8_t)4
#define TICIE1 (uint8_t)5
#define TOIE2  (uint8_t)6
#define OCIE2  (uint8_t)7

//TIFR BITS  Flags
#define TOV0   (uint8_t)0
#define OCF0   (uint8_t)1
#define TOV1   (uint8_t)2
#define OCF1B  (uint8_t)3
#define OCF1A  (uint8_t)4
#define ICF1   (uint8_t)5
#define TOV2   (uint8_t)6
#define OCF2   (uint8_t)7

// TCCR2 BITS
#define FOC2   (uint8_t)7
#define WGM20  (uint8_t)6
#define WGM21  (uint8_t)3
#define CS22   (uint8_t)2
#define CS21   (uint8_t)1
#define CS20   (uint8_t)0
#define COM21  (uint8_t)5
#define COM20  (uint8_t)4
//TIMER MODES
#define NormalMD              (uint8_t)0x00 //0b00000000
#define PWM_PhaseCorrect      (uint8_t)0x08 //0b00001000
#define CTC                   (uint8_t)0x40 //0b01000000
#define FastPWM               (uint8_t)0x48 //0b01001000
//OCN PIN
#define OCN_NormalOper      (uint8_t)0x00
#define OCN_Toggle          (uint8_t)0x10
#define OCN_Clr             (uint8_t)0x20
#define OCN_Set             (uint8_t)0x30
#define OCN_Disconnected	(uint8_t)0x00
// PRESCALER
#define NO_CLOCK_SOURCE		   (uint8_t)0x00 //stops the timer/ counter
#define NO_PRESCALER           (uint8_t)0x01 //clock source/1
#define PRESCALER_8            (uint8_t)0x02 // clock source/8
#define PRESCALER_64           (uint8_t)0x03 //clock source/64
#define PRESCALER_256          (uint8_t)0x04 //clock source/256
#define PRESCALER_1024         (uint8_t)0x05 //clock source/1024
#define EXClockFllEdg          (uint8_t)0x06 //External clock on T0, Clock on falling edge
#define EXClockRisEdg  		   (uint8_t)0x07 //External clock on T0, Clock on rising edge
//INERRUPT
#define OV_INTERRUPT            (uint8_t)0x01
#define CTC_INTERRUPT           (uint8_t)0x02
#define BOTH_INTERRRUPT         (uint8_t)0x03



#define I_BIT 7

/*TIMER APIs
 */
void TIMER_init(uint8_t timer_no) {
	if ((timer_no >= TIMER0 ) && (timer_no <= TIMER2 )) {
		switch (timer_no) {
		case TIMER0 :
			TCCR0 |= TIMER0_MODE;
			TCCR0 |= OCN_OUTPUT;

			OCR0 = 128; //NEED TO CHANGE,ONLY TO TEST
			break;
		case TIMER1 :
			break;
		case TIMER2 :
			TCCR2 |= TIMER0_MODE;
			break;
		} //END of the SWITCH
	} //End of the IF

}
void TIMER_start(uint8_t timer_no) {
	if ((timer_no >= TIMER0 ) && (timer_no <= TIMER2 )) {
		switch (timer_no) {
		case TIMER0 :
			TCCR0 |= TIMER0_PRESCALER;
			break;
		case TIMER1 :
			break;
		case TIMER2 :
			break;
		} //END of the SWITCH
	} //End of the IF
}
void TIMER_EN_Interrupt(uint8_t timer_no) {
	if ((timer_no >= TIMER0 ) && (timer_no <= TIMER2 )) {
		switch (timer_no) {
		case TIMER0 :
			TIMSK |= TIMER0_INTERRUPT;
			break;
		case TIMER1 :
			break;
		case TIMER2 :
			break;
		} //END of the SWITCH
	} //End of the IF
}

void TIMER_DIS_Interrupt(uint8_t timer_no) {
	if ((timer_no >= TIMER0 ) && (timer_no <= TIMER2 )) {
		switch (timer_no) {
		case TIMER0 :
			TIMSK &= ~(TIMER0_INTERRUPT );
			break;
		case TIMER1 :
			break;
		case TIMER2 :
			break;
		} //END of the SWITCH
	} //End of the IF
}
void TIMER_callBackFunc(uint8_t timer_no, uint8_t interrupt_ch,
		void (*PTR_FUNC)(void)) {
	if ((timer_no >= TIMER0 ) && (timer_no <= TIMER2 )) {
		switch (timer_no) {
		case TIMER0 :
			switch (interrupt_ch) {
			case TIMER_OV_INTERRUPT :
				Gptr_OVINT = PTR_FUNC;

				break;
			case TIMER_CTC_INTERRUPT :
				Gptr_CTCINT = PTR_FUNC;
				break;
			}
			break;
		case TIMER1 :
			break;
		case TIMER2 :
			break;
		} //END of the SWITCH
	} //End of the IF
}
void TIMER_stop(uint8_t timer_no) {
	if ((timer_no >= TIMER0 ) && (timer_no <= TIMER2 )) {
		switch (timer_no) {
		case TIMER0 :
			TCCR0 &= ~(TIMER0_PRESCALER );
			break;
		case TIMER1 :
			break;
		case TIMER2 :
			break;
		} //END of the SWITCH
	} //End of the IF
}
void GI_vdEnableGI (void)
{
	Set_Bit(SREG_REGISTER,I_BIT);
}


void GI_vdDisableGI (void)
{
	Clr_Bit(SREG_REGISTER, I_BIT);
}

void __vector_11(void) __attribute__((signal)); // Overflow Interrupt for timer/counter 0
void __vector_11(void) {
	Gptr_OVINT();
}
void __vector_10(void) __attribute__((signal)); //Compare Interrupt for timer/counter 0
void __vector_10(void) {
	Gptr_CTCINT();
	/*static volatile uint16 counter = 0;
	 counter++;
	 if ( counter == 5000)
	 {
	 Timer0ptr();
	 counter = 0;
	 }*/
}
