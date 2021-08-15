#include"Motor.h"

void MOTOR_init(void) {

	/*SETTING MOTOR1 DIR PINS TO OUTPUT*/
	DIO_SetPinDirection(PORTD, PIN4, PIN_OUTPUT);//Control Pin
	DIO_SetPinDirection(PORTD, PIN3, PIN_OUTPUT);
	DIO_SetPinDirection(PORTD, PIN2, PIN_OUTPUT);


}
void MOTOR_start(uint8_t motor_no, uint8_t dir) {
	switch (motor_no) {
	case MOTER1 :
		DIO_WritePin(PORTD, PIN4, PIN_HIGH);
		switch (dir) {
		case MOTOR1_FORWARD :
			DIO_WritePin(PORTD, PIN2,PIN_HIGH);
			DIO_WritePin(PORTD, PIN3,PIN_LOW);
			break;
		case MOTOR1_BACKWARD :
			DIO_WritePin(PORTD, PIN2,PIN_LOW);
			DIO_WritePin(PORTD, PIN3,PIN_HIGH);
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}

}
void MOTOR_stop(uint8_t motor_no) {
	switch (motor_no){
	case MOTER1:
		DIO_WritePin(PORTD, PIN4,PIN_LOW);
		DIO_WritePin(PORTD, PIN2,PIN_LOW);
		DIO_WritePin(PORTD, PIN3,PIN_LOW);
		break;

	default:
		break;
	}
}

void MOTOR_dir(uint8_t motor_no, uint8_t dir) {
	switch (motor_no) {
		case MOTER1 :
			switch (dir) {
			case MOTOR1_FORWARD :
				DIO_WritePin(PORTD, PIN2,PIN_HIGH);
				DIO_WritePin(PORTD, PIN3,PIN_LOW);
				break;
			case MOTOR1_BACKWARD :
				DIO_WritePin(PORTD, PIN2,PIN_LOW);
				DIO_WritePin(PORTD, PIN3,PIN_HIGH);
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}
}
