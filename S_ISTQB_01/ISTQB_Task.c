#include <stdio.h>
#include <stdlib.h>


int sum(unsigned char operand_1,unsigned char operand_2);
void SumUnitTest(int actual,int expected);


unsigned int Operand_1 = 0;
unsigned int Operand_2 = 0;
int expected_output = 0;
int actual_output = 0;
int main()
{
//Please define your infinite loop here.
    while(1)
    {
        fflush(stdin);
        printf("\nEnter the first Operand:");
        scanf("%d",&Operand_1);
        fflush(stdin);
        printf("\nEnter the second Operand:");
        scanf("%d",&Operand_2);
        fflush(stdin);
        printf("\nEnter the Expected result:");
        scanf("%d",&expected_output);
        SumUnitTest((sum(Operand_1,Operand_2)),expected_output);
    }
    return 0;
}

int sum(unsigned char operand_1,unsigned char operand_2)
{
    int result=0;
    result =(unsigned int)operand_1+(unsigned int)operand_2;
    return result;
}
void SumUnitTest(int actual,int expected)
{
    printf("Actual output=%d,Expected output=%d\n",actual,expected);
    if(actual==expected)
    {
        printf("Test Passed\n");
    }
    else
    {
        printf("Test Failed\n");
    }
}
