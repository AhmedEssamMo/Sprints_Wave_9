#ifndef _Payment_system_h
#define _Payment_system_h
/*- MACROS
 ------------------------------------------*/
#define numberOfAccounts 10

/*- ENUMS
 ------------------------------------------*/
typedef enum EN_Stat
{
	DECLINED = 0,
	APPROVED = 1
}EN_transStat_t;

/*- STRUCTS AND UNIONS
 ------------------------------------------*/
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


/*FUNCTIONS DECLARATIONS
--------------------------------*/
EN_transStat_t paymentSystem(void);
EN_transStat_t checkIfExpired(void);
EN_transStat_t checkIfAcceptedAmountByTerminal(void);
EN_transStat_t checkIfAcceptedAmountByServer(void);
EN_transStat_t sendTransactionToServer(void);
EN_transStat_t searchingInDataBase(void);
void cardDataRead(void);
void terminalDataRead(void);
void resetTheValue(void);


#endif // _Payment_system_h
