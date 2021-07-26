/*
 * File: Test_Cases.c
 * Author: Ahmed
 * Date: 8 July 2021
 * Description: Test Cases for Payment App
*/


#include <stdio.h>
#include <stdlib.h>
#include "TypeDef.h"
#include "Payment_system.h"

void TestApprovedPayment(void)
{
    printf("TEST IF THE USER ENTER ALL THE DATA CORRECTLY\n");
    printf("*******************************************************\n");

    if(paymentSystem() == APPROVED)
    {
        printf("Accepted Transaction\n Test Case 1 Passed\n");
    }
    else
    {
        printf("Declined Transaction\n Test Case 1 Failed\n");
    }


}

void TestDeclinedForExpiredCard(void)
{
    printf("TEST IF THE USER ENTER EXPIRED DATE\n");
    printf("*******************************************************\n");

    cardDataRead();
    terminalDataRead();

    if(checkIfExpired() == DECLINED)
    {
        printf("Declined Transaction\n Test Case 2 Passed\n");
    }
    else
    {
        printf("Accepted Transaction\n Test Case 2 Failed\n");
    }


}

void TestForDeclinedAmountByServer(void)
{

    printf("TEST IF THE BALANCE IS NOT ENOUGH\n");
    printf("*******************************************************\n");
    cardDataRead();
    terminalDataRead();
    sendTransactionToServer();

    if(checkIfAcceptedAmountByServer() == DECLINED)
    {
        printf("Declined Transaction\n Test Case 3 Passed\n");
    }
    else
    {
        printf("Accepted Transaction\n Test Case 3 Failed\n");
    }


}

void TestForDeclinedAmountByTerminal(void)
{
    printf("TEST IF THE TERMINAL MAX AMOUNT IS LESS THAN DESIRED AMOUNT\n");
    printf("******************************************************************\n");

    cardDataRead();
    terminalDataRead();

    if(checkIfAcceptedAmountByTerminal() == DECLINED)
    {
        printf("Declined Transaction\n Test Case 4 Passed\n");
    }
    else
    {
        printf("Accepted Transaction\n Test Case 4 Failed\n");
    }

}

void TestFor_AccNumber_NotExist(void)
{
    printf("TEST IF THE CARD NUMBER IS NOT EXIST\n");
    printf("*******************************************************\n");
    cardDataRead();
    terminalDataRead();
    if(searchingInDataBase() == DECLINED)
    {
        printf("Declined Transaction\n Test Case 5 Passed\n");
    }
    else
    {
        printf("Accepted Transaction\n Test Case 5 Failed\n");
    }
}

int main(void)
{
    TestApprovedPayment();	            //TEST IF THE USER ENTER ALL THE DATA CORRECTLY
    printf("*******************************************************\n");
    TestDeclinedForExpiredCard();       //TEST IF THE USER ENTER EXPIRED DATE
    printf("*******************************************************\n");
    TestForDeclinedAmountByServer();    //TEST IF THE BALANCE IS NOT ENOUGH
    printf("*******************************************************\n");
    TestForDeclinedAmountByTerminal();	//TEST IF THE TERMINAL MAX AMOUNT IS LESS THAN DESIRED AMOUNT
    printf("*******************************************************\n");
    TestFor_AccNumber_NotExist();       //TEST IF THE CARD NUMBER IS NOT EXIST
    printf("*******************************************************\n");
    return 0;
}
