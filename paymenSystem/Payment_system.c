/*INCLUDES
 ---------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include "TypeDef.h"
#include "Payment_system.h"
/*- MACROS
 ------------------------------------------*/
#define MAX_AMOUNT       5000.0


/*LOCAL FUNCTIONS PROTOTYPE
 ----------------------*/
 static uint8_t StringCmpr(uint8_t*string1,uint8_t*string2);


/*GLOBAL STATIC VARIABLE
 ----------------------------*/
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
uint8_t gu8_index_in_data_base=0;



/*LOCAL FUNCTIONS DECLARATION
 ----------------------*/
 /***********************************
 *THIS FFUNCTION COMPARE TWO STRINGS*
 ************************************/
static uint8_t StringCmpr(uint8_t*string1,uint8_t*string2){
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


/*- APIs IMPLEMENTATION
 -----------------------------------*/
/******************************************************
*THIS FUNCTION RESER ALL DATA TO MAKE A NEW TRANSACTION*
********************************************************/
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
  gu8_index_in_data_base=0;


}
/***********************************************************
*THIS FUNCTION GETS CARD NAME,CARD NUMBERR, AND EXPIRY DTAE*
************************************************************/
void cardDataRead(void)
{
	printf("Please Enter Card Holder Name:\n");
	scanf("%s",cardInfo.cardHolderName);
	fflush(stdin);
	while(1){
		/*----Ask the user to enter the Card number(9-digit)---*/
		printf("Please Enter The 9 Digits Card Number\n");
		scanf("%s",cardInfo.primaryAccountNumber);
		fflush(stdin);
		uint8_t i=0;
		/*checking for the number of entered digits*/
		while(cardInfo.primaryAccountNumber[i]!='\0')
		{
			i++;
		}
		if(i<9){

			printf("Invalid Card number!!\n");
		}
		else{
			break ;
		}
    }
	/*----Ask the user to enter the expiry date---*/
	printf("Please Enter Card Expiry Date MM/YY:\n");
	scanf("%s",cardInfo.cardExpirationDate);
	fflush(stdin);
	return APPROVED;
}
/***************************************************
*THIS FUNCTION GETS THE DESIRED AMOUNT AND THE DATE*
****************************************************/
void terminalDataRead(void){
    TerminalData.maxTransAmount  = MAX_AMOUNT ;
	/*Terminal asks the user of the amount he needs*/
    printf("Please enter the desired amount you need\n");
    scanf("%f",&TerminalData.transAmount);
    fflush(stdin);
	/*Terminal asks the user to enter the date*/
    printf("Please Enter The Date DD/MM/YYYY:\n");
	scanf("%s",TerminalData.transactionDate);
	fflush(stdin);
}
/***************************************************
*COMPARRE THE DESIRED AMOUNT WITH THE TERMINAL MAX*
****************************************************/
EN_transStat_t checkIfAcceptedAmountByTerminal(void){
    /*--check if the desired amount is less then the max amount--*/
	if(TerminalData.maxTransAmount<TerminalData.transAmount){
        return DECLINED;
	}
	else{
		return APPROVED;
	}
}
/**********************
*CHECK FOR EXPIRY DATE*
************************/
EN_transStat_t checkIfExpired(void){
    /*Check if the card is expired or no*/
    uint8_t Month[2]={0,0};
    uint8_t Year[2]={0,0};
    if(TransactionData.transStat==APPROVED){
        Month[0]=(TerminalData.transactionDate[4]-'0')+((TerminalData.transactionDate[3]-'0')*10);
        Year[0]=(TerminalData.transactionDate[9]-'0')+((TerminalData.transactionDate[8]-'0')*10);
        Month[1]=(cardInfo.cardExpirationDate[1]-'0')+((cardInfo.cardExpirationDate[0]-'0')*10);
        Year[1]=(cardInfo.cardExpirationDate[4]-'0')+((cardInfo.cardExpirationDate[3]-'0')*10);

        if(Year[0]>Year[1]){
            return DECLINED;
        }
        else if(Year[0]<Year[1]){
             return APPROVED;

        }
        else if((Year[0]==Year[1])&&(Month[1]>Month[0])){
             return APPROVED;

        }
        else if ((Year[0]==Year[1])&&(Month[1]<=Month[0])){
            return DECLINED;
        }
    }
    else{
        return DECLINED;
    }


}

/*********************************************
*THIS FUNCTION SENDS TRNSACTION TO THE SERVER*
**********************************************/
/*This ffunction send the card data to the server*/
EN_transStat_t sendTransactionToServer(void){

    if(TransactionData.transStat==APPROVED){
        TransactionData.cardHolderData=cardInfo;
        TransactionData.transData=TerminalData;
        return APPROVED;
    }

    else{
        return DECLINED;

    }

}
/***********************************************************
*THIS FUNCTION CHECKS IF THE CARD NUMBER EXIST IN DATA BASE*
************************************************************/
/*This function check if the card number is in the data base*/
EN_transStat_t searchingInDataBase(void){

    uint8_t i=0;

    if(TransactionData.transStat==APPROVED){
    while(StringCmpr((cardInfo.primaryAccountNumber),(AccountsBalance[i].primaryAccountNumber))!=1){
        i++;
	/*Checking if the number exist in the data base*/
        if(i==numberOfAccounts){
       // printf("This number is NOT exist\n");
            printf("Transaction Is Declined \n");
            return DECLINED;
        }
        else{
            return DECLINED;
        }
    }
    gu8_index_in_data_base=i;

    return APPROVED;
    }

}
/*************************************************************
*THIS FUNCTION CHECKS IF THERE IS ENOUGH AMOUNT IN THE SERVER*
**************************************************************/
EN_transStat_t checkIfAcceptedAmountByServer(void){
    if(TransactionData.transStat==APPROVED){
            /*check if the desired amount if less than the balance*/
        if((TransactionData.transData.transAmount)>(AccountsBalance[gu8_index_in_data_base].balance)){
            printf("Transaction Is Declined\n");
            return DECLINED;
    }
        else{
            printf("Transaction Is Approved\n");
            AccountsBalance[gu8_index_in_data_base].balance=AccountsBalance[gu8_index_in_data_base].balance-TransactionData.transData.transAmount;
            printf("Your new balance now is %f \n",AccountsBalance[gu8_index_in_data_base].balance);
            return APPROVED;
    }

    }
    else{
        return DECLINED;
    }
}


/******************************************************
*THIS FUNCTION CALL ALL THE APIS TO MAKE A TRANSACTION*
*******************************************************/
EN_transStat_t paymentSystem(void){
    /*GET CARD DATA*/
    cardDataRead();

    /*GET TERMINAL DATA*/
    terminalDataRead();

    /*CHECK IF THE AMOUNT IS LESS THAN THE TERMINAL MAX*/
    TransactionData.transStat=checkIfAcceptedAmountByTerminal();
        if(TransactionData.transStat==APPROVED){
        }
        else{
            return DECLINED;
        }
    /*CHECK IF THE CARD IS NOT EXPIRED*/
    TransactionData.transStat=checkIfExpired();
        if(TransactionData.transStat==APPROVED){
        }
        else{
            return DECLINED;
        }
    /*SEND DATA TO SERRVER*/

    TransactionData.transStat=sendTransactionToServer();
        if(TransactionData.transStat==APPROVED){
        }
        else{
            return DECLINED;
        }
    /*SEARRCH FOR THE CARD NUMBER IN DATA BASE*/

    TransactionData.transStat=searchingInDataBase();
        if(TransactionData.transStat==APPROVED){
        }
        else{
            return DECLINED;
        }

    /*CHECK IF THE AMOUNT IS LESS THAN THE SERVER AMOUNT*/

    TransactionData.transStat=checkIfAcceptedAmountByServer();
        if(TransactionData.transStat==APPROVED){
            return APPROVED;
        }
        else{
            return DECLINED;
        }
}
