#include <stdio.h>
#include <stdlib.h>
#include "TypeDef.h"
#include "Payment_system.h"

int main()
{
    uint8_t Continue=0;
    while(1){
    paymentSystem();
    printf("Do you want to continue\n");
    printf("Press y to continue or press any key to terminate\t");
    scanf("%c",&Continue);
    fflush(stdin);
    if(Continue!='y'){
		//check if you need to terminate
            break;

    }
    else{
		//do nothing

    }
    }
    return 0;
}
