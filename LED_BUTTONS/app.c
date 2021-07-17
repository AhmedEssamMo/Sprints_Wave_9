#include"Macros.h"
#include"TypeDef.h"
#include"DIO_retval.h"
#include"DIO.h"
#include"Button_retval.h"
#include"Button.h"
#include"LED.h"
#include<util/delay.h>

int main() {
	LED_Init(PORTA, PIN7);

	uint8_t state = 0;
	uint8_t PushedButton = 1;
	state = Button_Init(PORTA, PIN4);

	while (1) {
		PushedButton=Button_getState(PORTA, PIN4);
		_delay_ms(20);
		if (PushedButton == 0) {
			PushedButton=Button_getState(PORTA, PIN4);
			if (PushedButton == 1) {
				LED_toggle(PORTA, PIN7);
			}
		}


	}

	return 0;
}
