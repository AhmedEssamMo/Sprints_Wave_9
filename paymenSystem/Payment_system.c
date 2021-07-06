#include <stdio.h>
#include <stdlib.h>
#include "TypeDef.h"
#include "Payment_system.h"
ST_accountBalance_t AccountsBalance[10]={	            { 100.00 ,	"123456789" },
														{ 6000.00,	"234567891" },
														{ 3250.25, 	"567891234" },
														{ 1500.12, 	"456789123" },
														{ 500.00 , 	"258649173" },
														{ 2100.00, 	"654823719" },
														{ 0.00   ,	"971362485" },
														{ 1.00   ,	"793148625" },
														{ 10.12  ,	"123123456" },
														{ 0.55	 ,	"456789321" }
};//data base
ST_cardData_t cardInfo;
ST_terminalData_t TerminalData;
ST_transaction_t TransactionData;
uint8_t flag=0;





void resetTheValue(void){
    uint8_t i=0;
    for(i=0;i<25;i++){
        if(i<6){
            cardInfo.cardExpirationDate[i]='\0';
            cardInfo.primaryAccountNumber[i]='\0';
            cardInfo.cardHolderName[i]='\0';
        }
        else if((i>=6)&&(i<10)){
            cardInfo.primaryAccountNumber[i]='\0';
            cardInfo.cardHolderName[i]='\0';
        }
        else{
            cardInfo.cardHolderName[i]='\0';
        }
    }
  TerminalData.transAmount=0;


}
void cardDataRead(void)
{
	printf("Please Enter Card Holder Name:\n");
	scanf("%s",cardInfo.cardHolderName);
	fflush(stdin);
	while(1){
	printf("Please Enter The 9 Digits Card Number\n");
	scanf("%s",cardInfo.primaryAccountNumber);
	fflush(stdin);
	uint8_t i=0;
	while(cardInfo.primaryAccountNumber[i]!='\0'){//This is checking for the umber of entered digits
        i++;
	}
	if(i<9){

        printf("Invalid Card number!!\n");
	}
	else{
        break ;
	}
            }
	printf("Please Enter Card Expiry Date MM/YY:\n");
	scanf("%s",cardInfo.cardExpirationDate);
	fflush(stdin);
}

EN_transStat_t terminalDataRead(void){
    uint8_t Month[2]={0,0};
    uint8_t Year[2]={0,0};


    TerminalData.maxTransAmount  = MAX_AMOUNT ;
    printf("Please enter the desired amount you need\n");
    scanf("%f",&TerminalData.transAmount);
    fflush(stdin);
	if(TerminalData.maxTransAmount<TerminalData.transAmount){

        return DECLINED;
	}
	else{

	}
    printf("Please Enter Card Expiry Date DD/MM/YYYY:\n");
	scanf("%s",TerminalData.transactionDate);
	fflush(stdin);

	Month[0]=(TerminalData.transactionDate[4]-'0')+((TerminalData.transactionDate[3]-'0')*10);
	Year[0]=(TerminalData.transactionDate[9]-'0')+((TerminalData.transactionDate[8]-'0')*10);
    Month[1]=(cardInfo.cardExpirationDate[1]-'0')+((cardInfo.cardExpirationDate[0]-'0')*10);
	Year[1]=(cardInfo.cardExpirationDate[4]-'0')+((cardInfo.cardExpirationDate[3]-'0')*10);
	if(Year[0]>Year[1]){
        printf("Expiry Date DECLINED\n");
        return DECLINED;
	}
	else if(Year[0]<Year[1]){
         printf("Expiry Date APPROVED\n");
         return APPROVED;

	}
	else if((Year[0]==Year[1])&&(Month[1]>Month[0])){
         printf("Expiry Date APPROVED\n");
         return APPROVED;

	}
	else if ((Year[0]==Year[1])&&(Month[1]<=Month[0])){
            printf("Expiry Date DECLINED\n");
        return DECLINED;
	}

}
EN_transStat_t sendTransactionToServer(void){
    TransactionData.transStat=terminalDataRead();
    if(TransactionData.transStat==APPROVED){
        TransactionData.cardHolderData=cardInfo;
        TransactionData.transData=TerminalData;
        return APPROVED;
    }

    else{
        return DECLINED;

    }

}


void searchingInDataBase(void){

        uint8_t i=0;

    if(sendTransactionToServer()==APPROVED){
    while(StringCmpr((cardInfo.primaryAccountNumber),(AccountsBalance[i].primaryAccountNumber))!=1){
    i++;
    if(i==numberOfAccounts){
       // printf("This number is NOT exist\n");
        printf("Transaction Is Declined \n");
        return DECLINED;
    }
    }
    if((TransactionData.transData.transAmount)>(AccountsBalance[i].balance)){
            //printf("Your number is APPROVED\n");
            //printf("Balance is not enough\n");
            printf("Transaction Is Declined\n");
            return DECLINED;
    }
    else{
        printf("Transaction Is Approved\n");
        AccountsBalance[i].balance=AccountsBalance[i].balance-TransactionData.transData.transAmount;
        printf("Your new balance now is %f \n",AccountsBalance[i].balance);

        return APPROVED;
    }
    }
    else{
        printf("Transaction Is Declined\n");

    }

}
uint8_t StringCmpr(uint8_t*string1,uint8_t*string2){
    uint8_t i=0;
    while((string1[i]!='\0')||(string2[i]!='\0')){
        if(string1[i]!=string2[i]){
            return 0;
        }
        else{}
        i++;
    }
    return 1;
}
void paymentSystem(void){
    cardDataRead();

    searchingInDataBase();

}
