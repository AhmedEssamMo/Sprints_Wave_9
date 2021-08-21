/*- INCLUDES----------------------------------------------*/
#include"LIB/STD_TYPES
#include"LIB/BIT_MATH.h"
#include"MCAL/TIMER/TIMER.h"
#include"MCAL/DIO/DIO.h"
#include"MCAL/GLOBAL_INTERRUPT/globalInterrupt.h"
#include"HAL/LED/LED.h"
/*- LOCAL FUNCTIONS PROTOTYPES----------------------------*/
/*CALL BACK FUNCTIONS*/
void OVF_TGL_FUNC(void);
void CTC_TGL_FUNC(void);
/*- MAIN------------------------*/
int main(){
	uint8_t u8_counter;
	/*INIT THE LEDS*/
	LED_Init(LED1);
	LED_Init(LED2);
	LED_Init(LED3);
	LED_Init(LED4);
	/*SET CALL BACK FUNCTIONS*/
	TIMER_callBackFunc(TIMER0_OVF_INTERRUPT,OVF_TGL_FUNC);
	TIMER_callBackFunc(TIMER0_CTC_INTERRUPT,CTC_TGL_FUNC);
	/*ENABLE TIMER INTERRUPTS*/
	TIMER_EN_Interrupt(TIMER0_OVF_INTERRUPT);
	TIMER_EN_Interrupt(TIMER0_CTC_INTERRUPT);
	/*SET A PRE-LOAD*/
	TIMER_preload(TIMER0,125);
	/*START THE TIMER*/
	TIMER_start(TIMER0);
	/*ENABLE GLOBAL INTERRUPT*/
	GI_EnableGI();
	while(1){
	}
}
/*- LOCAL FUNCTIONS IMPLEMENTATION------------------------*/
/*THIS FUNCTIONS TOGGLES 2 PINS EVERY 4000 AND 8000 COUNTS IN NORMAL MODE*/
void OVD_TGL_FUNC(void){
	static volatile uint32_t OV_counter = 0;
	OV_counter++;
	if(0==(OV_counter%4000)){
		LED_toggle(LED4);
	}
	if (0==(OV_counter%8000)){
		LED_toggle(LED3);
	}
}
/*THIS FUNCTIONS TOGGLES 2 PINS EVERY 2000 AND 4000 COUNTS IN CTC MODE*/
void CTC_TGL_FUNC(void){
	static volatile uint32_t CTC_counter = 0;
	CTC_counter++;
	if(0==(CTC_counter%2000)){
		LED_toggle(LED1);
	}
	if (0==(CTC_counter%4000)){
		LED_toggle(LED2);
	}
}

