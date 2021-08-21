/*- INCLUDES
----------------------------------------------*/
#include"TIMER_REG.h"
#include"TIMER.h"

/*- LOCAL MACROS
------------------------------------------*/
// TCCR0 BITS
#define FOC0   (uint8_t)7  //Force
#define WGM00  (uint8_t)6
#define WGM01  (uint8_t)3
#define CS02   (uint8_t)2
#define CS01   (uint8_t)1
#define CS00   (uint8_t)0
#define COM01  (uint8_t)5
#define COM00  (uint8_t)4
//TCCR1A BITS
#define COM1A1  (uint8_t)7
#define COM1A0  (uint8_t)6
#define COM1B1  (uint8_t)5
#define COM1B0  (uint8_t)4
#define FOC01B  (uint8_t)3
#define FOC1A   (uint8_t)2
#define WGM11   (uint8_t)1
#define WGM10   (uint8_t)0
//TCCR1B BITS
#define ICNC1  (uint8_t)7
#define ICES1  (uint8_t)6
#define WGM13  (uint8_t)4
#define WGM12  (uint8_t)3
#define CS12   (uint8_t)2
#define CS11   (uint8_t)1
#define CS10   (uint8_t)0

// TCCR2 BITS
#define FOC2   (uint8_t)7
#define WGM20  (uint8_t)6
#define WGM21  (uint8_t)3
#define CS22   (uint8_t)2
#define CS21   (uint8_t)1
#define CS20   (uint8_t)0
#define COM21  (uint8_t)5
#define COM20  (uint8_t)4
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

//TIMER MODES for TIMER (0&2)
#define NormalMD              (uint8_t)0x00
#define PWM_PhaseCorrect      (uint8_t)0x08 //0b00001000
#define CTC                   (uint8_t)0x40 //0b01000000
#define FastPWM               (uint8_t)0x48 //0b01001000
//TIMER MODES ONLY FOR TIMER1
#define PWM_PhaseCorrect_8B      (uint8_t)1 //0b00001000
#define PWM_PhaseCorrect_9B      (uint8_t)2 //0b00001000
#define PWM_PhaseCorrect_10B     (uint8_t)3 //0b00001000
#define T1_CTC                   (uint8_t)4 //0b01000000
#define FastPWM_8B               (uint8_t)5 //0b01001000
#define FastPWM_9B               (uint8_t)6 //0b01001000
#define FastPWM_10B              (uint8_t)7 //0b01001000
#define PWM_PhFreqCorrect_ICR1   (uint8_t)8 //0b00001000
#define PWM_PhFreqCorrect_OCR1A  (uint8_t)9 //0b00001000
#define PWM_PhaseCorrect_ICR1    (uint8_t)10 //0b00001000
#define PWM_PhaseCorrect_OCR1A   (uint8_t)11 //0b00001000
#define CTC_ICR1                 (uint8_t)12 //0b01000000
#define FastPWM_ICR1             (uint8_t)14 //0b01001000
#define FastPWM_OCR1A            (uint8_t)15 //0b01001000

//OCN PIN
#define OCN_NormalOper      (uint8_t)0x00
#define OCN_Toggle          (uint8_t)0x10
#define OCN_Clr             (uint8_t)0x20
#define OCN_Set             (uint8_t)0x30
#define OCN_Disconnected	(uint8_t)0x00
//OC1A PIN
#define OC1A_Toggle          (uint8_t)0x40
#define OC1A_Clr             (uint8_t)0x80
#define OC1A_Set             (uint8_t)0xC0
#define OC1A_Disconnected	 (uint8_t)0x00
//OC1B PIN
#define OC1B_Toggle          (uint8_t)0x10
#define OC1B_Clr             (uint8_t)0x20
#define OC1B_Set             (uint8_t)0x30
#define OC1B_Disconnected	 (uint8_t)0x00

// PRESCALER
#define NO_CLOCK_SOURCE		   (uint8_t)0x00 //stops the timer/ counter
#define NO_PRESCALER           (uint8_t)0x01 //clock source/1
#define PRESCALER_8            (uint8_t)0x02 // clock source/8
#define PRESCALER_64           (uint8_t)0x03 //clock source/64
#define PRESCALER_256          (uint8_t)0x04 //clock source/256
#define PRESCALER_1024         (uint8_t)0x05 //clock source/1024
#define EXClockFllEdg          (uint8_t)0x06 //External clock on TN, Clock on falling edge
#define EXClockRisEdg  		   (uint8_t)0x07 //External clock on TN, Clock on rising edge
//INERRUPTS
#define OV0_INTERRUPT            (uint8_t)0x01
#define CTC0_INTERRUPT           (uint8_t)0x02

#define IPCAP1_INTERRUPT         (uint8_t)0x04
#define CTC1A_INTERRUPT          (uint8_t)0x08
#define CTC1B_INTERRUPT          (uint8_t)0x10
#define OV1_INTERRUPT            (uint8_t)0x20

#define OV2_INTERRUPT            (uint8_t)0x40
#define CTC2_INTERRUPT           (uint8_t)0x80
//#define I_BIT                   (uint8_t)7

/*- GLOBAL STATIC VARIABLES
-------------------------------*/
/*POINTER TO FUNCTION FORR THE CALL BACK FUNCTION*/
static Ptr_VoidFuncVoid_t Gptr_OV0INT=NULL_PTR;
static Ptr_VoidFuncVoid_t Gptr_CTC0INT=NULL_PTR;
static Ptr_VoidFuncVoid_t Gptr_IPCAP1=NULL_PTR;
static Ptr_VoidFuncVoid_t Gptr_CTC1A=NULL_PTR;
static Ptr_VoidFuncVoid_t Gptr_CTC1B=NULL_PTR;
static Ptr_VoidFuncVoid_t Gptr_OV1INT=NULL_PTR;
static Ptr_VoidFuncVoid_t Gptr_OV2INT=NULL_PTR;
static Ptr_VoidFuncVoid_t Gptr_CTC2INT=NULL_PTR;

/*- APIs IMPLEMENTATION
-----------------------------------*/
ERROR_STATE_t TIMER_init(uint8_t timer_no) {
    ERROR_STATE_t u8_ERROR_STAT = ERROR_OK;
	uint8_t u8_timer1_mode = TIMER1_MODE;
    switch (timer_no) {
    case TIMER0 :
        TCCR0 |= TIMER0_MODE;
        break;
    case TIMER1 :
        switch (u8_timer1_mode) {
        case NormalMD :
            Clr_Bit(TCCR1A, WGM10);  //0000
            Clr_Bit(TCCR1A, WGM11);
            Clr_Bit(TCCR1B, WGM12);
            Clr_Bit(TCCR1B, WGM13);
            break;
        case PWM_PhaseCorrect_8B :
            Set_Bit(TCCR1A, WGM10);  //0001
            Clr_Bit(TCCR1A, WGM11);
            Clr_Bit(TCCR1B, WGM12);
            Clr_Bit(TCCR1B, WGM13);
            break;
        case PWM_PhaseCorrect_9B :
            Clr_Bit(TCCR1A, WGM10);  //0010
            Set_Bit(TCCR1A, WGM11);
            Clr_Bit(TCCR1B, WGM12);
            Clr_Bit(TCCR1B, WGM13);
            break;
        case PWM_PhaseCorrect_10B :
            Set_Bit(TCCR1A, WGM10);  //0011
            Set_Bit(TCCR1A, WGM11);
            Clr_Bit(TCCR1B, WGM12);
            Clr_Bit(TCCR1B, WGM13);
            break;
        case T1_CTC :
            Clr_Bit(TCCR1A, WGM10);  //0100
            Clr_Bit(TCCR1A, WGM11);
            Set_Bit(TCCR1B, WGM12);
            Clr_Bit(TCCR1B, WGM13);
            break;
        case FastPWM_8B :
            Set_Bit(TCCR1A, WGM10);  //0101
            Clr_Bit(TCCR1A, WGM11);
            Set_Bit(TCCR1B, WGM12);
            Clr_Bit(TCCR1B, WGM13);
            break;
        case FastPWM_9B :
            Clr_Bit(TCCR1A, WGM10);  //0110
            Set_Bit(TCCR1A, WGM11);
            Set_Bit(TCCR1B, WGM12);
            Clr_Bit(TCCR1B, WGM13);
            break;
        case FastPWM_10B :
            Set_Bit(TCCR1A, WGM10);  //0111
            Set_Bit(TCCR1A, WGM11);
            Set_Bit(TCCR1B, WGM12);
            Clr_Bit(TCCR1B, WGM13);
            break;
        case PWM_PhFreqCorrect_ICR1 :
            Clr_Bit(TCCR1A, WGM10);  //1000
            Clr_Bit(TCCR1A, WGM11);
            Clr_Bit(TCCR1B, WGM12);
            Set_Bit(TCCR1B, WGM13);
            break;
        case PWM_PhFreqCorrect_OCR1A :
            Set_Bit(TCCR1A, WGM10);  //1001
            Clr_Bit(TCCR1A, WGM11);
            Clr_Bit(TCCR1B, WGM12);
            Set_Bit(TCCR1B, WGM13);
            break;
        case PWM_PhaseCorrect_ICR1 :
            Clr_Bit(TCCR1A, WGM10);  //1010
            Set_Bit(TCCR1A, WGM11);
            Clr_Bit(TCCR1B, WGM12);
            Set_Bit(TCCR1B, WGM13);
            break;
        case PWM_PhaseCorrect_OCR1A :
            Set_Bit(TCCR1A, WGM10);  //1011
            Set_Bit(TCCR1A, WGM11);
            Clr_Bit(TCCR1B, WGM12);
            Set_Bit(TCCR1B, WGM13);
            break;
        case CTC_ICR1 :
            Clr_Bit(TCCR1A, WGM10);  //1100
            Clr_Bit(TCCR1A, WGM11);
            Set_Bit(TCCR1B, WGM12);
            Set_Bit(TCCR1B, WGM13);
            break;
        case FastPWM_ICR1 :
            Clr_Bit(TCCR1A, WGM10);  //1110
            Set_Bit(TCCR1A, WGM11);
            Set_Bit(TCCR1B, WGM12);
            Set_Bit(TCCR1B, WGM13);
            break;
        case FastPWM_OCR1A :
            Set_Bit(TCCR1A, WGM10);  //1111
            Set_Bit(TCCR1A, WGM11);
            Set_Bit(TCCR1B, WGM12);
            Set_Bit(TCCR1B, WGM13);
            break;
        default:
            u8_ERROR_STAT = ERROR_NOK;
            break;
        }

        break;
    case TIMER2 :
        TCCR2 |= TIMER2_MODE;
        break;
    default:
        u8_ERROR_STAT = ERROR_NOK;
        break;
    } //END of the SWITCH
    return u8_ERROR_STAT;

}
ERROR_STATE_t TIMER_start(uint8_t timer_no) {
    ERROR_STATE_t u8_ERROR_STAT = ERROR_OK;
    switch (timer_no) {
    case TIMER0 :
        TCCR0 |= TIMER0_PRESCALER;
        break;
    case TIMER1 :
        TCCR1B |= TIMER1_PRESCALER;
        break;
    case TIMER2 :
        TCCR0 |= TIMER2_PRESCALER;
        break;
    default:
        u8_ERROR_STAT = ERROR_NOK;
        break;
    } //END of the SWITCH
    return u8_ERROR_STAT;
}
ERROR_STATE_t TIMER_callBackFunc(uint8_t interrupt_ch, Ptr_VoidFuncVoid_t callBack) {
    ERROR_STATE_t u8_ERROR_STAT = ERROR_OK;
    if(NULL_PTR==callBack){
        u8_ERROR_STAT = ERROR_NOK;
    }
    else{
        switch (interrupt_ch) {
        case OV0_INTERRUPT :
            Gptr_OV0INT = callBack;
            break;
        case CTC0_INTERRUPT :
            Gptr_CTC0INT = callBack;
            break;
        case IPCAP1_INTERRUPT :
            Gptr_IPCAP1 = callBack;
            break;
        case CTC1A_INTERRUPT :
            Gptr_CTC1A = callBack;
            break;
        case CTC1B_INTERRUPT :
            Gptr_CTC1B = callBack;
            break;
        case OV1_INTERRUPT :
            Gptr_OV1INT = callBack;
            break;
        case OV2_INTERRUPT :
            Gptr_OV2INT = callBack;
            break;
        case CTC2_INTERRUPT :
            Gptr_CTC2INT = callBack;
            break;
        default:
            u8_ERROR_STAT = ERROR_NOK;
            break;
        } //END of the SWITCH
    }
	return u8_ERROR_STAT ;
}

ERROR_STATE_t TIMER_stop(uint8_t timer_no) {
    ERROR_STATE_t u8_ERROR_STAT = ERROR_OK;
    switch (timer_no)
    {
    case TIMER0 :
        TCCR0 &= ~(TIMER0_PRESCALER );
        break;
    case TIMER1 :
        TCCR1B &= ~(TIMER1_PRESCALER );
        break;
    case TIMER2 :
        TCCR2 &= ~(TIMER2_PRESCALER );
        break;
    default:
        u8_ERROR_STAT = ERROR_NOK;
        break;
    } //END of the SWITCH
    return u8_ERROR_STAT;
}

ERROR_STATE_t TIMER_EN_Interrupt(uint8_t timer_interrupt_no) {
    ERROR_STATE_t u8_ERROR_STAT = ERROR_OK;
    switch(timer_interrupt_no){
            /*TIMER 0 INTERRUPT*/
        case TIMER0_OVF_INTERRUPT:
            TIMSK |= OV0_INTERRUPT;
            break;
        case TIMER0_CTC_INTERRUPT:
            TIMSK |= CTC0_INTERRUPT;
            break;
            /*TIMER 1 INTERRUPT */
        case TIMER1_ICU_INTERRUPT:
            TIMSK |= IPCAP1_INTERRUPT;
            break;
        case TIMER1_CTCA_INTERRUPT:
            TIMSK |= CTC1A_INTERRUPT;
            break;
        case TIMER1_CTCB_INTERRUPT:
            TIMSK |= CTC1B_INTERRUPT;
            break;
        case TIMER1_OVF_INTERRUPT:
            TIMSK |= OV1_INTERRUPT;
            break;
            /*TIMER 2 INTERRUPT */
        case TIMER2_OVF_INTERRUPT:
            TIMSK |= OV2_INTERRUPT;
            break;
         case TIMER2_CTC_INTERRUPT:
            TIMSK |= CTC2_INTERRUPT;
            break;
        default:
            u8_ERROR_STAT = ERROR_NOK;
            break;
            }
	return u8_ERROR_STAT;
}
ERROR_STATE_t TIMER_DIS_Interrupt(uint8_t timer_interrupt_no) {
    ERROR_STATE_t u8_ERROR_STAT = ERROR_OK;
    switch(timer_interrupt_no){
        /*TIMER 0 INTERRUPT*/
    case TIMER0_OVF_INTERRUPT:
        TIMSK &= ~( OV0_INTERRUPT);
        break;
    case TIMER0_CTC_INTERRUPT:
        TIMSK &= ~( CTC0_INTERRUPT);
        break;
        /*TIMER 1 INTERRUPT */
    case TIMER1_ICU_INTERRUPT:
        TIMSK &= ~( IPCAP1_INTERRUPT);
        break;
    case TIMER1_CTCA_INTERRUPT:
        TIMSK &= ~( CTC1A_INTERRUPT);
        break;
    case TIMER1_CTCB_INTERRUPT:
        TIMSK &= ~( CTC1B_INTERRUPT);
        break;
    case TIMER1_OVF_INTERRUPT:
        TIMSK &= ~( OV1_INTERRUPT);
        break;
        /*TIMER 2 INTERRUPT */
    case TIMER2_OVF_INTERRUPT:
        TIMSK &= ~( OV2_INTERRUPT);
        break;
     case TIMER2_CTC_INTERRUPT:
        TIMSK &= ~( CTC2_INTERRUPT);
        break;
    default:
        u8_ERROR_STAT = ERROR_NOK;
        break;
        }
    return u8_ERROR_STAT;
}
ERROR_STATE_t TIMER_pinConnect(uint8_t timer_pin) {
    ERROR_STATE_t u8_ERROR_STAT = ERROR_OK;
    switch (timer_pin) {
    case TIMER0_OC0 :
        TCCR0 |= OC0_OUTPUT; //0b0010 0000
        break;
    case TIMER1_OC1A :
        TCCR1A |= OC1A_OUTPUT; //0b0010 0000
        break;
    case TIMER1_OC1B :
        TCCR1A |= OC1B_OUTPUT; //0b0010 0000
        break;
    case TIMER2_OC2 :
        TCCR2 |= OC2_OUTPUT; //0b0010 0000
        break;
    default:
        u8_ERROR_STAT = ERROR_NOK;
        break;
    } //END of the SWITCH
    return u8_ERROR_STAT;
}
ERROR_STATE_t TIMER_pinDisconnect(uint8_t timer_pin){
    ERROR_STATE_t u8_ERROR_STAT = ERROR_OK;
    switch (timer_pin)
    {
    case TIMER0_OC0 :
        TCCR0 &= ~(OC0_OUTPUT );
        break;
    case TIMER1_OC1A :
        TCCR1A &= ~(OC1A_OUTPUT );
        break;
    case TIMER1_OC1B :
        TCCR1A &= ~(OC1B_OUTPUT );
        break;
    case TIMER2_OC2 :
        TCCR2 &= ~(OC2_OUTPUT );
        break;
    default:
        u8_ERROR_STAT = ERROR_NOK;
        break;
    } //END of the SWITCH
    return u8_ERROR_STAT;
}
ERROR_STATE_t TIMER_cmprValue(uint8_t timer_cmpReg, uint16_t value) {
    ERROR_STATE_t u8_ERROR_STAT = ERROR_OK;
    switch (timer_cmpReg) {
    case TIMER0_OCR0 :
        OCR0 = value;
        break;
    case TIMER1_OCR1A :
        OCR1A = value;
        break;
    case TIMER1_OCR1B :
        OCR1B = value;
        break;
    case TIMER2_OCR2 :
        OCR2 = value;
        break;
    default:
        u8_ERROR_STAT = ERROR_NOK;
        break;
    } //END of the SWITCH
    return u8_ERROR_STAT;
}
ERROR_STATE_t TIMER_preload(uint8_t timer_no, uint16_t value) {
    ERROR_STATE_t u8_ERROR_STAT = ERROR_OK;
    switch (timer_no) {
    case TIMER0 :
        TCNT0 = value;
        break;
    case TIMER1 :
        TCNT1 = value;
        break;
    case TIMER2 :
        TCNT2 = value;
        break;
    default:
        u8_ERROR_STAT = ERROR_NOK;
        break;
    } //END of the SWITCH
	return u8_ERROR_STAT;
}

void __vector_11(void) __attribute__((signal)); // Overflow Interrupt for timer/counter 0
void __vector_11(void) {
    if(NULL_PTR!=Gptr_OV0INT){
	Gptr_OV0INT();
    }
    else{
        //DO NOTHING
    }
}
void __vector_10(void) __attribute__((signal)); //Compare Interrupt for timer/counter 0
void __vector_10(void) {
    if(NULL_PTR!=Gptr_CTC0INT){
	Gptr_CTC0INT();
    }
    else{
        //DO NOTHING
    }
}
void __vector_9(void) __attribute__((signal)); // Overflow Interrupt for timer/counter 1
void __vector_9(void) {
    if(NULL_PTR!=Gptr_OV1INT){
        Gptr_OV1INT();
    }
    else{
        //DO NOTHING
    }
}
void __vector_8(void) __attribute__((signal)); //CompareB Interrupt for timer/counter 1
void __vector_8(void) {
    if(NULL_PTR!=Gptr_CTC1A){
        Gptr_CTC1A();
    }
    else{
        //DO NOTHING
    }
}

void __vector_7(void) __attribute__((signal)); //CompareA Interrupt for timer/counter 1
void __vector_7(void) {
    if(NULL_PTR!=Gptr_CTC1B){
        Gptr_CTC1B();
    }
    else{
        //DO NOTHING
    }
}

void __vector_6(void) __attribute__((signal)); //Capture Interrupt for timer/counter 1
void __vector_6(void) {
    if(NULL_PTR!=Gptr_IPCAP1){
        Gptr_IPCAP1();
    }
    else{
        //DO NOTHING
    }
}

void __vector_5(void) __attribute__((signal)); // Overflow Interrupt for timer/counter 2
void __vector_5(void) {
    if(NULL_PTR!=Gptr_OV2INT){
        Gptr_OV2INT();
    }
    else{
        //DO NOTHING
    }
}
void __vector_4(void) __attribute__((signal)); //Compare Interrupt for timer/counter 2
void __vector_4(void) {
    if(NULL_PTR!=Gptr_CTC2INT){
        Gptr_CTC2INT();
    }
    else{
        //DO NOTHING
    }
}
