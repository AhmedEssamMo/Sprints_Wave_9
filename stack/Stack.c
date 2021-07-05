#include "TypeDef.h"
#include "Stack.h"
#include <stdio.h>

#include <stdlib.h>

uint8_t stack[stack_size];
uint8_t* StackPtr=NULL;
uint8_t stackCounter=255;
uint8_t* Parentheses=NULL;



void push(uint8_t u8_data)
{

    if(stackCounter==254){
        printf("Stack overflow!\n");
    }
    else if((stackCounter>=0)||(stackCounter<=253)||(stackCounter==255)){//push if stack counter between range -1:253
    stackCounter++;
    stack[stackCounter]=u8_data;
    StackPtr=(stack+stackCounter);
    }
    else{}
}


uint8_t pull(){
    if(stackCounter==255){
        printf("Stack underflow!\n");
    }
    else if((stackCounter>=0)||(stackCounter<=254)){
    uint8_t temp=stack[stackCounter];
    stackCounter--;
    StackPtr=(stack+stackCounter);
    return temp;
    }
    return 0;
}

void printStack(){

    uint8_t locCounter=0;
    for(locCounter=0;locCounter<=stackCounter;locCounter++){
        if (stackCounter==255){
            printf("Stack is empty\n");
            break;
        }
        else{
            printf("%c\t",stack[locCounter]);
        }
    }
    printf("\n");
}
uint8_t* balancedParentheses(uint8_t* expression){
    uint8_t stringCounter=0;
    uint8_t pullingCounter=0;
    uint8_t sqParenthesesCounter=0;
    uint8_t crParenthesesCounter=0;
    uint8_t typeOfParenth=-1;
    uint8_t temp=0;

    while(expression[stringCounter]!=NULL){

        push(*(expression+stringCounter));
        stringCounter++;
    }

    for(pullingCounter=0;pullingCounter<stringCounter;pullingCounter++)
        {
            temp=pull();
            if(temp==')')
            {
                sqParenthesesCounter++;
                typeOfParenth=0;
            }
            else if ((temp=='(')&&(sqParenthesesCounter!=0)&&(typeOfParenth==0))
            {

                sqParenthesesCounter--;
                if(sqParenthesesCounter==0){
                    typeOfParenth=1;

                 }
            }
            else if (temp=='}')
            {
                crParenthesesCounter++;
                typeOfParenth=1;
            }
            else if ((temp=='{')&&(crParenthesesCounter!=0)&&(typeOfParenth==1))
            {
                crParenthesesCounter--;
                if(crParenthesesCounter==0){
                    typeOfParenth=0;
                    }
            }
            else{}

        }
        if((sqParenthesesCounter==0)&&(crParenthesesCounter==0)){
                Parentheses="balanced";

        }
        else{
            Parentheses="Unbalanced";
        }



    return Parentheses;
}
