#include"LIB/BIT_MATH.h"
#include"LIB/STD_TYPES.h"
#include"MCAL/DIO/DIO.h"
#include"HAL/BUTTONS/Button.h"
#include"HAL/LED/LED.h"
//#include <util/delay.h>

int main() {
	LED_Init(PORTA, PIN7);
	uint8_t state = 0;
	uint8_t PushedButton = 1;
	Button_Init(BUTTON1);

	while (1) {
		Button_getState(BUTTON1,&PushedButton);
		//_delay_ms(20);
		if (PushedButton == 0) {
			Button_getState(BUTTON1,&PushedButton);
			if (PushedButton == 1) {
				LED_toggle(PORTA, PIN7);
			}
		}
	}

	return 0;
}
