#ifndef TIMER_CONFIG_H_
#define TIMER_CONFIG_H_


/*This file to set configuration
 * Timer mode
 * OCN pin
 * Prescaler
 */


/**********************************************************************************************************/

/*Configured mode for timer0:
 * NormalMD
 * PWM_PhaseCorrect
 * CTC
 * FastPWM
 */
#define TIMER0_MODE   FastPWM;
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
 * BOTH_INTERRRUPT //You can't choose this unless TIMER_MODE is CTC
 * */
//#define TIMER2_INTERRUPT BOTH2_INTERRRUPT  //NEED A CHANGE !!



















#endif /*TIMER_CONFIG_H_*/
