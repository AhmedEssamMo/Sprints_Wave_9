#ifndef TIMER_CONFIG_H_
#define TIMER_CONFIG_H_


/*This file to set configuration
 * Timer mode
 * OCN pin
 * Prescaler
 */
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


/**********************************************************************************************************/

/*Configured mode for timer0:
 * NormalMD
 * PWM_PhaseCorrect
 * CTC
 * FastPWM
 */
#define TIMER0_MODE   FastPWM
/* OCN_Toggle
 * OCN_Clr
 * OCN_Set
 * OCN_NormalOper
 * OCN_Disconnected
 * Don't choose OCN_Toggle unless TIMER_MODE is CTC or NormalMD !
 */
#define OC0_OUTPUT OCN_Clr
/*PRESCALERS FOR TIMER
 * No_Prescaler
 * Prescaler_8
 * Prescaler_64
 * Prescaler_256
 * Prescaler_1024
 * EXClockFllEdg
 * EXClockRisEdg
 * */
#define TIMER0_PRESCALER PRESCALER_8

/*TIMER0_INTERRUPT
 * OV0_INTERRUPT
 * CTC0_INTERRUPT
 * BOTH0_INTERRRUPT //You can't choose this unless TIMER_MODE is CTC
 * */
//#define TIMER0_INTERRUPT BOTH0_INTERRRUPT



/*Configured mode for timer0:
 *  NormalMD
 * PWM_PhaseCorrect_8B
 * PWM_PhaseCorrect_9B
 * PWM_PhaseCorrect_10B
 * T1_CTC
 * FastPWM_8B
 * FastPWM_9B
 * FastPWM_10B
 * PWM_PhFreqCorrect_ICR1
 * PWM_PhFreqCorrect_OCR1A
 * PWM_PhaseCorrect_ICR1
 * PWM_PhaseCorrect_OCR1A
 * CTC_ICR1
 * FastPWM_ICR1
 * FastPWM_OCR1A
 */
#define TIMER1_MODE   FastPWM_8B

/* OC1A_Toggle
 * OC1A_Clr
 * OC1A_Set
 * OC1A_Disconnected
 * In case the TIMER1_MODE is (FastPWM_OCR1A or PWM_PhFreqCorrect_OCR1A or FastPWM_ICR1 or any non-PWM MODE)
  & OC1A_OUTPUT is OC1A_Toggle , Will toggle OC1A else OC1A will be disconnected
 */
#define OC1A_OUTPUT OC1A_Toggle
/* OC1B_Toggle
 * OC1B_Clr
 * OC1B_Set
 * OC1B_Disconnected
 * In case the TIMER1_MODE is not NON_PWM MODE & OC1B_OUTPUT is OC1A_Toggle, OC1B will be disconnected
 */
#define OC1B_OUTPUT OC1B_Toggle
/*PRESCALERS FOR TIMER
 * No_Prescaler
 * Prescaler_8
 * Prescaler_64
 * Prescaler_256
 * Prescaler_1024
 * EXClockFllEdg
 * EXClockRisEdg
 * */
#define TIMER1_PRESCALER PRESCALER_8

/*TIMER1_INTERRUPT
 * OV_INTERRUPT
 * CTC_INTERRUPT
 * BOTH_INTERRRUPT //You can't choose this unless TIMER_MODE is CTC
 * */
//#define TIMER1_INTERRUPT BOTH0_INTERRRUPT//NEED A CHANGE !!

/*Configured mode for timer2:
 * NormalMD
 * PWM_PhaseCorrect
 * CTC
 *FastPWM
 */
#define TIMER2_MODE   NormalMD


/* OCN_Toggle
 * OCN_Clr
 * OCN_Set
 * OCN_NormalOper
 * OCN_Disconnected
 * Don't choose OCN_Toggle unless TIMER_MODE is CTC or NormalMD !
 */
#define OC2_OUTPUT OCN_Clr




/*PRESCALERS FOR TIMER2
 * No_Prescaler
 * Prescaler_8
 * Prescaler_64
 * Prescaler_256
 * Prescaler_1024
 * EXClockFllEdg
 * EXClockRisEdg
 * */
#define TIMER2_PRESCALER PRESCALER_8

/*TIMER2_INTERRUPT
 * OV_INTERRUPT
 * CTC_INTERRUPT
 * */
//#define TIMER2_INTERRUPT BOTH2_INTERRRUPT  //NEED A CHANGE !!



















#endif /*TIMER_CONFIG_H_*/
