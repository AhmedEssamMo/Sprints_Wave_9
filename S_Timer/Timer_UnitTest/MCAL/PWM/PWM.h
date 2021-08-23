#ifndef PWM_H_
#define PWM_H_
/*- INCLUDES
----------------------------------------------*/
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include"../TIMER/TIMER.h"
/*- MACROS
------------------------------------------*/
#define PWM0  (uint8_t)0 // 8-Bits timer
#define PWM1  (uint8_t)1 // 16-Bits timer
#define PWM2  (uint8_t)2 // 8-Bits time
/*- FUNCTION DECLARATIONS ----------------------------------*/
ERROR_STATE_t PWM_init(uint8_t pwm_no);
ERROR_STATE_t PWM_dutyCycle(uint8_t pwm_no, uint8_t dutyCycle);

#endif /*PWM_H_*/
