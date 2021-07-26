/*INCLUDES
 ---------------------------------*/
#include "Stack.h"

/*- LOCAL MACROS
 ------------------------------------------*/
#define stack_size 255
/*GLOBAL STATIC VARIABLE
 ----------------------------*/
uint8_t stack[stack_size];//THIS IS THE STACK OF SIZE 255
uint8_t* StackPtr=NULL;   //STACK POINTER
uint8_t stackCounter=stack_size;// STACK COUNTER
uint8_t* Parentheses=NULL;
/*- APIs IMPLEMENTATION
 -----------------------------------*/
 /***************************
 *THIS API PUSH TO THE STACK*
 ****************************/
void push(uint8_t u8_data)
{
    if(stackCounter==stack_size-1){
        printf("Stack overflow!\n");
    }
    else if((stackCounter>=0)||(stackCounter<=253)||(stackCounter==stack_size)){//push if stack counter between range -1:253
    stackCounter++;
    stack[stackCounter]=u8_data;
   // StackPtr=(stack+stackCounter);
    }
    else{}
}
 /***************************
 *THIS API PULL FROM THE STACK*
 ****************************/
uint8_t pull(){
    if(stackCounter==255){
        printf("COUNTER = %d Stack underflow!\n",stackCounter);
    }
    else if((stackCounter>=0)||(stackCounter<=254)){
    uint8_t temp=stack[stackCounter];
    stackCounter--;
    StackPtr=(stack+stackCounter);
    return temp;
    }
}
 /**************************
 *THIS API PRINTS THE STACK*
 ***************************/
void printStack(void){

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

 /*************************************
 *CHECK IF THE PARENTHESES ARE BALANCD*
 **************************************/
enum EN_Isbalanced balancedParentheses(uint8_t* expression){
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
                return BALANCED;

        }
        else{
            Parentheses="Unbalanced";
            return UNBALANCED;
        }

}
