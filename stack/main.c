#include <stdio.h>
#include <stdlib.h>
#include "TypeDef.h"
#include "Stack.h"

int main()
{

    uint8_t* temp;
    uint8_t* expression="(){}";
    printf("The expression is %s\t",expression);
    temp=balancedParentheses(expression);
    printf("The expression is %s\n",temp);

    expression="({)}";
    printf("The expression is %s \t",expression);
    temp=balancedParentheses(expression);
    printf("The expression is %s \n",temp);

    expression=")({}";
    printf("The expression is %s \t",expression);
    temp=balancedParentheses(expression);
    printf("The expression is %s \n",temp);

    expression="((({{{}}})))";
    printf("The expression is %s \t",expression);
    temp=balancedParentheses(expression);
    printf("The expression is %s \n",temp);

    expression="((({{{)}}}))";
    printf("The expression is %s \t",expression);
    temp=balancedParentheses(expression);
    printf("The expression is %s \n",temp);

    return 0;
}

