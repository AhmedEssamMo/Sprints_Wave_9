#ifndef _Payment_system_h
#define _Payment_system_h

#define numberOfAccounts 10
#define MAX_AMOUNT       5000.0



typedef enum EN_Stat
{
	DECLINED = 0,
	APPROVED = 1
}EN_transStat_t;

//In which we store the card informaion
typedef struct ST_cardData
{
	uint8_t cardHolderName[25];
	uint8_t primaryAccountNumber[10];
	uint8_t cardExpirationDate[6];
}ST_cardData_t;

typedef struct ST_terminalData
{
	float transAmount;
	float maxTransAmount;
	uint8_t transactionDate[11];
}ST_terminalData_t;


typedef struct ST_transaction
{
	ST_cardData_t cardHolderData;
	ST_terminalData_t transData;
	EN_transStat_t transStat;
}ST_transaction_t;

typedef struct ST_accountBalance
{
	float balance;
	uint8_t primaryAccountNumber[10];
}ST_accountBalance_t;

void cardDataRead(void);
EN_transStat_t terminalDataRead(void);
EN_transStat_t sendTransactionToServer(void);
uint8_t StringCmpr(uint8_t*string1,uint8_t*string2);
void searchingInDataBase(void);
void paymentSystem(void);
void resetTheValue(void);



#endif // _Payment_system_h
