#include"Motor.h"
#include"Pwm.h"
#include"Gpio.h"
#include"STD_TYPES.h"
#include"MC_REGISTERS.h"
#include"BIT_MATH.h"

int main() {
	volatile uint64_t counter = 0;
	MOTOR_init();
	while (1) {
		MOTOR_start(MOTER1, MOTOR_SPEED1, MOTOR1_FORWARD);
		for (counter = 0; counter > 32000000; counter++) { // that mean 4 sec
			asm("nop");}
		MOTOR_stop(MOTER1);
		for (counter = 0; counter > 32000000; counter++) { // that mean 4 sec
			asm("nop");}
		MOTOR_start(MOTER1, MOTOR_SPEED1, MOTOR1_BACKWARD);
		for (counter = 0; counter > 64000000; counter++) { // that mean 4 sec
			asm("nop");
		}

		MOTOR_stop(MOTER1);
		for (counter = 0; counter > 32000000; counter++) { // that mean 4 sec
			asm("nop");}
		MOTOR_speed(MOTER1, MOTOR_SPEED1);
		for (counter = 0; counter > 40000000; counter++) { // that mean 4 sec
			asm("nop");}
		MOTOR_speed(MOTER1, MOTOR_SPEED2);
		for (counter = 0; counter > 32000000; counter++) { // that mean 4 sec
			asm("nop");
		}

		MOTOR_speed(MOTER1, MOTOR_SPEED3);
		for (counter = 0; counter > 32000000; counter++) { // that mean 4 sec
			asm("nop");
		}

		MOTOR_dir(MOTER1, MOTOR1_BACKWARD);
		for (counter = 0; counter > 32000000; counter++) { // that mean 4 sec
			asm("nop");
		}

	}
	return 0;
}
