#ifndef TIMER_CONFIG_H_
#define TIMER_CONFIG_H_


/*This file to set configuration
 * Timer mode
 * OCN pin
 * Prescaler
 */


/**********************************************/





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
#define OCN_OUTPUT OCN_Clr
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
 * OV_INTERRUPT
 * CTC_INTERRUPT
 * BOTH_INTERRRUPT //You can't choose this unless TIMER_MODE is CTC
 * */
#define TIMER0_INTERRUPT BOTH_INTERRRUPT





/*Configured mode for timer0:
 * NormalMD
 * PWM_PhaseCorrect
 * CTC
 *FastPWM
 */
#define TIMER1_MODE   NormalMD

/*Configured mode for timer0:
 * NormalMD
 * PWM_PhaseCorrect
 * CTC
 *FastPWM
 */
#define TIMER2_MODE   NormalMD


















#endif /*TIMER_CONFIG_H_*/
