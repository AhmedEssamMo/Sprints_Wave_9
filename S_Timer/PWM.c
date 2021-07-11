#include"TypeDef.h"
#include"Macros.h"
#include"PWM.h"
#include"TIMER_REG.h"
#include"TIMER.h"

#define TIMER_8B_REG_MAX  (uint8_t)256
#define HUNDRED_PERCNT    (uint8_t)100



void PWM_init(uint8_t pwm_no) {
	if ((pwm_no >= PWM0 ) && (pwm_no <= PWM2 )) {
		switch (pwm_no) {
		case PWM0 :
			TIMER_init(PWM0);
			break;
		case PWM1 :
			break;
		case PWM2 :
			TIMER_init(PWM2);

			break;
		} //END of the SWITCH
	} //End of the IF
}

void PWM_dutyCycle(uint8_t pwm_no, uint8_t dutyCycle) {
	if ((pwm_no >= PWM0 ) && (pwm_no <= PWM2 )) {
		switch (pwm_no) {
		case PWM0 :
			OCR0=dutyCycle;//DUTY CYCLE IS A PERCENTAGE FROM 0% TO 100%
			break;
		case PWM1 :
			break;
		case PWM2 :
			OCR2=(dutyCycle/HUNDRED_PERCNT)*TIMER_8B_REG_MAX;//DUTY CYCLE IS A PERCENTAGE FROM 0% TO 100%
			break;
		} //END of the SWITCH
	} //End of the IF


}
