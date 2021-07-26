/*
 * File: Test_Cases.c
 * Author: Ahmed
 * Date: 8 July 2021
 * Description: Test Cases for Payment App
*/


#include <stdio.h>
#include <stdlib.h>
#include "Payment_system.h"

void TestApprovedPayment(void)
{
    uint8_t c;
    do
    {
        readCardData();
        readTerminalData();

        if(checkTransactionStatus() == APPROVED)
        {
            printf("Accepted Transaction\n Test Case 1 Passed\n");
        }
        else
        {
            printf("Declined Transaction\n Test Case 1 Failed\n");
        }
        printf("\nDo You Want to continue(y/n)?\n");
        fflush(stdin);
        scanf("%c",&c);
    }
    while(c == 'y');
}

void TestDeclinedForExpiredCard(void)
{
    uint8_t c;
    do
    {
        readCardData();
        readTerminalData();

        if(checkIfExpired() == DECLINED)
        {
            printf("Declined Transaction\n Test Case 2 Passed\n");
        }
        else
        {
            printf("Accepted Transaction\n Test Case 2 Failed\n");
        }
        printf("\nDo You Want to continue(y/n)?\n");
        fflush(stdin);
        scanf("%c",&c);
    }
    while(c == 'y');
}

void TestForDeclinedAmountByServer(void)
{
    uint8_t c;
    do
    {
        readCardData();
        readTerminalData();

        if(checkIfAcceptedAmountByServer() == DECLINED)
        {
            printf("Declined Transaction\n Test Case 3 Passed\n");
        }
        else
        {
            printf("Accepted Transaction\n Test Case 3 Failed\n");
        }
        printf("\nDo You Want to continue(y/n)?\n");
        fflush(stdin);
        scanf("%c",&c);
    }
    while(c == 'y');
}

void TestForDeclinedAmountByTerminal(void)
{
    uint8_t c;
    do
    {
        readCardData();
        readTerminalData();

        if(checkIfAcceptedAmountByTerminal() == DECLINED)
        {
            printf("Declined Transaction\n Test Case 4 Passed\n");
        }
        else
        {
            printf("Accepted Transaction\n Test Case 4 Failed\n");
        }
        printf("\nDo You Want to continue(y/n)?\n");
        fflush(stdin);
        scanf("%c",&c);
    }
    while(c == 'y');
}

void TestFor_PAN_NotExist(void)
{
    readCardData();
    readTerminalData();

    if(checkIfPANExists() == DECLINED)
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
    TestApprovedPayment();	//u should enter all data right to pass
    //TestDeclinedForExpiredCard();
    //TestForDeclinedAmountByServer();
    //TestForDeclinedAmountByTerminal();	//u should enter payment amount > 5000.00
    //TestFor_PAN_NotExist();
    return 0;
}
