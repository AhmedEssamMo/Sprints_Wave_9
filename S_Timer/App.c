#include<util/delay.h>
#include"TypeDef.h"
#include"Macros.h"
#include"TIMER.h"
#include"DIO_retval.h"
#include"DIO.h"
#include"PWM.h"
void OV_TGL_FUNC(void);
void CTC_TGL_FUNC(void);
int main(){
	uint8_t state;
	uint8_t counter;
	state=DIO_setPinDirection(PORTA,PIN0,PIN_OUTPUT);
	state=DIO_setPinDirection(PORTB,PIN0,PIN_OUTPUT);
	state=DIO_setPinDirection(PORTC,PIN0,PIN_OUTPUT);
	state=DIO_setPinDirection(PORTD,PIN0,PIN_OUTPUT);
	state=DIO_setPinDirection(PORTB,PIN3,PIN_OUTPUT);
	PWM_init(PWM0);
	//TIMER_callBackFunc(TIMER0,TIMER_OV_INTERRUPT,&OV_TGL_FUNC);
	//TIMER_callBackFunc(TIMER0,TIMER_CTC_INTERRUPT,&CTC_TGL_FUNC);
	//TIMER_EN_Interrupt(TIMER0);
	GI_vdEnableGI();
	TIMER_start(TIMER0);

	while(1){

		for(counter=1;counter<255;counter++){
			PWM_dutyCycle(PWM0,counter);
			_delay_ms(10);
		}
		for(;counter>0;counter--){
			PWM_dutyCycle(PWM0,counter);
			_delay_ms(10);
		}
	}
}

void OV_TGL_FUNC(void){
	static volatile uint32_t OV_counter = 0;
	OV_counter++;
	if((OV_counter%4000)==0){
		DIO_TogglePin(PORTC,PIN0);
	}
	if ((OV_counter%8000)==0){
		DIO_TogglePin(PORTD,PIN0);
	}
}
void CTC_TGL_FUNC(void){
	static volatile uint32_t CTC_counter = 0;
	CTC_counter++;
	if((CTC_counter%2000)==0){
		DIO_TogglePin(PORTB,PIN0);
	}
	if ((CTC_counter%4000)==0){
		DIO_TogglePin(PORTA,PIN0);
	}

}
