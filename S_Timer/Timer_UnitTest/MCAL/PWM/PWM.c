/*- INCLUDES
----------------------------------------------*/
#include"PWM.h"
#include"../TIMER/TIMER_REG.h"

/*- LOCAL MACROS
------------------------------------------*/
#define TIMER_8B_REG_MAX  (uint8_t)256
#define HUNDRED_PERCNT    (uint8_t)100


/*- APIs IMPLEMENTATION
-----------------------------------*/
ERROR_STATE_t PWM_init(uint8_t pwm_no)
 {
	ERROR_STATE_t u8_ERROR_STAT = ERROR_OK;
    switch (pwm_no) {
    case PWM0 :
        TIMER_init(PWM0);
        break;
    case PWM1 :
        TIMER_init(PWM1);
        break;
    case PWM2 :
        TIMER_init(PWM2);
        break;
    default:
        u8_ERROR_STAT = ERROR_NOK;
        break;
    } //END of the SWITCH
      return u8_ERROR_STAT;
}

ERROR_STATE_t PWM_dutyCycle(uint8_t pwm_no, uint8_t dutyCycle) {
    ERROR_STATE_t u8_ERROR_STAT = ERROR_OK;
    switch (pwm_no)
    {
    case PWM0 :
        OCR0=(uint8_t)(((dutyCycle/HUNDRED_PERCNT)*TIMER_8B_REG_MAX));//DUTY CYCLE IS A PERCENTAGE FROM 0% TO 100%
        break;
    case PWM1 :
        break;
    case PWM2 :
        OCR2=(dutyCycle/HUNDRED_PERCNT)*TIMER_8B_REG_MAX;//DUTY CYCLE IS A PERCENTAGE FROM 0% TO 100%
        break;
    default:
        u8_ERROR_STAT = ERROR_NOK;
        break;
    } //END of the SWITCH
      return u8_ERROR_STAT;
}
