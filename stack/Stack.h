#ifndef Stack_H_
#define Stack_H_
/*INCLUDES
 --------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include "TypeDef.h"
/*ENUMS
 --------------------------------*/
enum EN_Isbalanced{BALANCED, UNBALANCED};
/*FUNCTIONS DECLARATIONS
--------------------------------*/
void push(uint8_t u8_data);
uint8_t pull();
void printStack(void);
enum EN_Isbalanced balancedParentheses(uint8_t* expression);


#endif
