/*- INCLUDES 
-----------------------------------------------*/
#include "App/INTERFACE_MCU_WITH_EEPROM/interface_mcu_with_eeprom.h"

int main(){
	App_Init();
	while(1){
	App_Update();
	}

}
