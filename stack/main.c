#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
#include "TypeDef.h"
void TEST1_PARENTHESES(void){
    uint8_t* expression="(){}";
    printf("The expression is %s\t",expression);
    if(balancedParentheses(expression)==BALANCED){
         printf("The expression is BALANCED\n");
         printf("TEST 1 PASSED\n");
    }
    else if(balancedParentheses(expression)==UNBALANCED){
         printf("The expression is UNBALANCED\n");
         printf("TEST 1 FAILED\n");
    }
}

void TEST2_PARENTHESES(void){
    uint8_t* expression="({)}";
    printf("The expression is %s \t",expression);
    if(balancedParentheses(expression)==BALANCED){
         printf("The expression is BALANCED\n");
         printf("TEST 2 FAILED\n");

    }
    else if(balancedParentheses(expression)==UNBALANCED){
         printf("The expression is UNBALANCED\n");
         printf("TEST 2 PASSED\n");
    }
    }
void TEST3_PARENTHESES(void){
    uint8_t*expression=")({}";
    printf("The expression is %s \t",expression);
    if(balancedParentheses(expression)==BALANCED){
         printf("The expression is BALANCED\n");
         printf("TEST 3 FAILED\n");

    }
    else if(balancedParentheses(expression)==UNBALANCED){
         printf("The expression is UNBALANCED\n");
         printf("TEST 3 PASSED\n");
    }
    }
void TEST4_PARENTHESES(void){
    uint8_t*expression="((({{{}}})))";
    printf("The expression is %s \t",expression);
    if(balancedParentheses(expression)==BALANCED){
         printf("The expression is BALANCED\n");
         printf("TEST 4 PASSED\n");

    }
    else if(balancedParentheses(expression)==UNBALANCED){
         printf("The expression is UNBALANCED\n");
         printf("TEST 4 FAILED\n");
    }

}
void TEST5_PARENTHESES(void){
    uint8_t* expression="((({{{)}}}))";
    printf("The expression is %s \t",expression);
    if(balancedParentheses(expression)==BALANCED){
         printf("The expression is BALANCED\n");
         printf("TEST 5 FAILED\n");

    }
    else if(balancedParentheses(expression)==UNBALANCED){
         printf("The expression is UNBALANCED\n");
         printf("TEST 5 PASSED\n");
    }
}

void main(void){
    TEST1_PARENTHESES();
    TEST2_PARENTHESES();
    TEST3_PARENTHESES();
    TEST4_PARENTHESES();
    TEST5_PARENTHESES();
}

