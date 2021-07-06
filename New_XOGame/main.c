#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "XOgame.h"

int main()
{
    char pressedKey=0;




    while(1){
        X_O_Game();
        printf("Press 'y' to play again or press any key to terminate\n");
        scanf("%c",&pressedKey);
        //fflush(stdin);
        if(pressedKey!='y'){
            break;
        }
        else{
            reset();
        }

    }



    return 0;
}
