#ifndef TIMER_H_
#define TIMER_H_
// Timer channels
#define TIMER0  (uint8_t)0 // 8-Bits timer
#define TIMER1  (uint8_t)1 // 16-Bits timer
#define TIMER2  (uint8_t)2 // 8-Bits timer

#define TIMER_OV_INTERRUPT  (uint8_t)0
#define TIMER_CTC_INTERRUPT (uint8_t)1

void GI_vdEnableGI(void);
void GI_vdDisableGI(void);




void TIMER_init(uint8_t timer_no);
void TIMER_start(uint8_t timer_no);
void TIMER_stop(uint8_t timer_no);
void TIMER_EN_Interrupt(uint8_t timer_no);
void TIMER_DIS_Interrupt(uint8_t  timer_no);
void TIMER_callBackFunc(uint8_t timer_no, uint8_t interrupt_ch,void(*PTR_FUNC)(void));


#endif /*TIMER_H_*/
