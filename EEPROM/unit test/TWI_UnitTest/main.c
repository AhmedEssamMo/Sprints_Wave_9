/*- INCLUDES----------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include "Mcal/TWI/twi.h"
#include "Mcal/TWI/twiReg.h"
/*- LOCAL MACROS------------------------------------------*/
#define TWI_2            (uint8_t)2
#define DUMMY_SLA_ADD    (uint8_t)0x22
#define DUMMY_DATA       (uint8_t)0x11
//STATUS
#define ST_CONDITION  (uint8_t)0x08 // START CONDITION HAS BEEN SENT
#define SLA_W_ACK     (uint8_t)0x18 // SLAVE ADDRESS WITH WRITE OPERATION WITH ACK
#define SLA_W_NACK    (uint8_t)0x20 // SLAVE ADDRESS WITH WRITE OPERATION WITH NACK
#define DATA_TR_ACK   (uint8_t)0x28 // DATA BYTE HAS BEEN TRANSMITTED WITH ACK
#define DATA_TR_NACK  (uint8_t)0x30 // DATA BYTE HAS BEEN TRANSMITTED WITH NACK
#define ARBIT_LOST    (uint8_t)0x38 // ARBITRATION LOST
#define SLA_R_ACK     (uint8_t)0x40 // SLAVE ADDRESS WITH READ OPERATION WITH ACK
#define SLA_R_NACK    (uint8_t)0x48 // SLAVE ADDRESS WITH READ OPERATION WITH NACK
#define DATA_REC_ACK  (uint8_t)0x50 // DATA BYTE HAS BEEN RECEUVED WITH ACK
#define DATA_REC_NACK (uint8_t)0x58 // DATA BYTE HAS BEEN TRANSMITTED WITH NACK
//PERSCALER IN TWI
#define PRESCALER_1  0b11111100
#define PRESCALER_4  0b11111101
#define PRESCALER_16 0b11111110
#define PRESCALER_64 0b11111111
// TWI_Control_REGISTER
#define TWINT      7
#define TWEA       6
#define TWSTA      5
#define TWSTO      4
#define TWWE       3
#define TWEN       2
#define RESERVED   1
#define TWIE       0

#define EN_INT     0b00000001
#define EN_TWI     0b00000100
#define SEND_STOP  0b00010000
#define SEND_START 0b00100000
#define SEND_ACK   0b01000000
#define CLR_FLAG   0b10000000
/*- GLOBAL EXTERN VARIABLES-------------------------------*/
extern uint8_t gu8_InitFlag ;
extern Ptr_VoidFuncVoid_t G_TWI_CALLBACK;
/*- GLOBAL STATIC VARIABLES-------------------------------*/
uint8_t dummyChar;
uint8_t dummyString[5];

/*- LOCAL FUNCTIONS PROTOTYPES----------------------------*/
void Dummy_function(void);
void TEST1_NOT_INIT(void);
void TEST2_INVALID_CHANNEL(void);
void TEST3_TWI_INIT(void);
void TEST4_TWI_EN_INTERRUPT(void);
void TEST5_TWI_DIS_INTERRUPT(void);
void TEST6_TWI_SET_CALL(void);
void TEST7_TWI_SendStartCondition(void);
void TEST8_TWI_SendStopCondition(void);
void TEST9_TWI_SendSLAWrite(void);
void TEST10_TWI_SendSLARead(void);
void TEST11_TWI_SendData(void);
void TEST12_TWI_RecDataAck(void);
int main()
{
    printf("*************************************\n");
        /*TESTING CALLING APIS WITHOUT INIT*/
    printf("TEST1:TESTING CALLING APIS WITHOUT INIT\n");
    TEST1_NOT_INIT();
    printf("*************************************\n");
    /*TESTING CHOOSE INVALID TWI CHANNEL*/
    printf("TEST2:TESTING CHOOSE INVALID UART CHANNEL\n");
    TEST2_INVALID_CHANNEL();
    printf("*************************************\n");
    /*TESTING INIT API*/
    printf("TEST3:TESTING INIT API\n");
    TEST3_TWI_INIT();
    printf("*************************************\n");
    /*TESTING ENABLE INTERRUPT API*/
    printf("TEST4:TESTING ENABLE INTERRUPT API\n");
    TEST4_TWI_EN_INTERRUPT();
    printf("*************************************\n");
    /*TESTING DISABLE INTERRUPT API*/
    printf("TEST5:TESTING DISABLE INTERRUPT API\n");
    TEST5_TWI_DIS_INTERRUPT();
    printf("*************************************\n");
    /*TESTING CALL BACK FUNCTION API*/
    printf("TEST6:TESTING CALL BACK FUNCTION API\n");
    TEST6_TWI_SET_CALL();
    printf("*************************************\n");
    /*TESTING CALL BACK FUNCTION API*/
    printf("TEST7:TESTING SEND START CONDITION FUNCTION API\n");
    TEST7_TWI_SendStartCondition();
    printf("*************************************\n");
    /*TESTING CALL BACK FUNCTION API*/
    printf("TEST8:TESTING SEND STOP CONDITION FUNCTION API\n");
    TEST8_TWI_SendStopCondition();
    printf("*************************************\n");
    /*TESTING CALL BACK FUNCTION API*/
    printf("TEST9:TESTING SEND SLAVE ADD WITH WRITE OPERATION FUNCTION API\n");
    TEST9_TWI_SendSLAWrite();
    printf("*************************************\n");
    /*TESTING CALL BACK FUNCTION API*/
    printf("TEST10:TESTING SEND SLAVE ADD WITH READ OPERATION FUNCTION API\n");
    TEST10_TWI_SendSLARead();
    printf("*************************************\n");
    /*TESTING CALL BACK FUNCTION API*/
    printf("TEST11:TESTING SEND DATA FUNCTION API\n");
    TEST11_TWI_SendData();
    printf("*************************************\n");
    /*TESTING CALL BACK FUNCTION API*/
    printf("TEST12:TESTING RECEIVE DATA ADD WITH WRITE OPERATION FUNCTION API\n");
    TEST12_TWI_RecDataAck();
    return 0;
}
/*- LOCAL FUNCTIONS IMPLEMENTATION------------------------*/
void TEST1_NOT_INIT(void){
    /*TRANSMIT STIING WITHOUT INIT*/
    if(TWI_NOT_INIT==TWI_SendChar(TWI_1,DUMMY_SLA_ADD,dummyString)){
        printf("TEST 1-1 PASSED\n");
    }
    else{
       printf("TEST 1-1 FAILED\n");
    }
    /*RECEIVE STIING WITHOUT INIT*/
    if(TWI_NOT_INIT==TWI_RecChar(TWI_1,DUMMY_SLA_ADD,dummyString)){
        printf("TEST 1-2 PASSED\n");
    }
    else{
       printf("TEST 1-2 FAILED\n");
    }
}
void TEST2_INVALID_CHANNEL(void){

    /*INITLAZE WRRONG CHANNEL*/

   /* gu8_InitFlag = INIT;
    /*TRANSMIT STIING WITHOUT INIT*/
    if(TWI_INVALID_CHANNEL==TWI_SendChar(TWI_2,DUMMY_SLA_ADD,dummyString)){
        printf("TEST 2-1 PASSED\n");
    }
    else{
       printf("TEST 2-1 FAILED\n");
    }
    /*RECEIVE STIING WITHOUT INIT*/
    if(TWI_INVALID_CHANNEL==TWI_RecChar(TWI_2,DUMMY_SLA_ADD,dummyString)){
        printf("TEST 2-2 PASSED\n");
    }
    else{
       printf("TEST 2-2 FAILED\n");
    }
    gu8_InitFlag = NOT_INIT;
}
void TEST3_TWI_INIT(void){
    int8_t ERROR_STAT=TWI_SUCCESS;
    /*CALL INIT FUNCTION WITH WRONG CHANNEL*/
    ERROR_STAT=TWI_Init(TWI_2);
    if(TWI_INVALID_CHANNEL==ERROR_STAT){
        printf("TEST 3-1 PASSED\n");
    }
    else{
       printf("TEST 3-1 FAILED\n");
    }
    /*CALL INIT FUNCTION WITH ALL RIGHT PARAMETERRS */
    ERROR_STAT=TWI_Init(TWI_1);
    if(TWI_SUCCESS==ERROR_STAT){
        printf("TEST 3-2 PASSED\n");
    }
    else{
       printf("TEST 3-2 FAILED\n");
    }
    gu8_InitFlag = INIT;
    ERROR_STAT=TWI_Init(TWI_1);
    /*CALL INIT FUNCTION AFTER INIT BEFORE*/
    if(TWI_SEC_INIT==ERROR_STAT){
        printf("TEST 3-3 PASSED\n");
    }
    else{
       printf("TEST 3-3 FAILED\n");
    }
    gu8_InitFlag = NOT_INIT;
}
void TEST4_TWI_EN_INTERRUPT(void){
    int8_t ERROR_STAT=TWI_SUCCESS;
    /*PRE-CONDITION*/
    gu8_InitFlag = INIT;//INIT THE TWI
    /*CALLING THR ENABLE INTERRUPT API*/
    ERROR_STAT=TWI_EnableInterrupt(TWI_1);
    if(TWI_SUCCESS==ERROR_STAT){
        printf("TEST 4-1 PASSED\n");
    }
    else{
       printf("TEST 4-1 FAILED\n");
    }
    /*PRE-CONDITION*/
    ERROR_STAT=TWI_EnableInterrupt(TWI_2);
    if(TWI_INVALID_CHANNEL==ERROR_STAT){
        printf("TEST 4-2 PASSED\n");
    }
    else{
       printf("TEST 4-2 PASSED\n");
    }
    /*PRE-CONDITION*/
    gu8_InitFlag = NOT_INIT;//MAKE THE TWI NOT INIT
    ERROR_STAT=TWI_EnableInterrupt(TWI_1);
    if(TWI_NOT_INIT==ERROR_STAT){
        printf("TEST 4-3 PASSED\n");
    }
    else{
       printf("TEST 4-3 FAILED\n");
    }
}
void TEST5_TWI_DIS_INTERRUPT(void){
    int8_t ERROR_STAT=TWI_SUCCESS;
    gu8_InitFlag = INIT;
    ERROR_STAT=TWI_DisableInterrupt(TWI_1);
    if(TWI_SUCCESS==ERROR_STAT){
        printf("TEST 5-1 PASSED\n");
    }
    else{
       printf("TEST 5-1 FAILED\n");
    }

    ERROR_STAT=TWI_DisableInterrupt(TWI_2);
    if(TWI_INVALID_CHANNEL==ERROR_STAT){
        printf("TEST 5-1 PASSED\n");
    }
    else{
       printf("TEST 5-1 PASSED\n");
    }

    /*DISABLE INTERRRUPT BEFORE INIT */
    gu8_InitFlag = NOT_INIT;
    ERROR_STAT=TWI_DisableInterrupt(TWI_1);
    if(TWI_NOT_INIT==ERROR_STAT){
        printf("TEST 5-1 PASSED\n");
    }
    else{
       printf("TEST 5-1 FAILED\n");
    }
}
void TEST6_TWI_SET_CALL(void){
    int8_t ERROR_STAT=TWI_SUCCESS;
    gu8_InitFlag = INIT;//pre-condition
    /*SET CALL BACK FUNCTIONS WITH ALL RIGHT PARAMETERS*/
    ERROR_STAT=TWI_SetCallback(TWI_1,Dummy_function);
    if(TWI_SUCCESS==ERROR_STAT){
        printf("TEST 6-1 PASSED\n");
    }
    else{
       printf("TEST 6-1 FAILED\n");
    }
    /*PASS NULL POINTER*/
    ERROR_STAT=TWI_SetCallback(TWI_1,NULL_PTR);
    if(TWI_NULL_POINTER==ERROR_STAT){
        printf("TEST 6-2 PASSED\n");
    }
    else{
       printf("TEST 6-2 FAILED\n");
    }
    /*CHOOSE INVALID CHANNEL*/
    ERROR_STAT=TWI_SetCallback(TWI_2,Dummy_function);
    if(TWI_INVALID_CHANNEL==ERROR_STAT){
        printf("TEST 6-3 PASSED\n");
    }
    else{
       printf("TEST 6-3 FAILED\n");
    }
    /*PRE-CONDITION*/
    gu8_InitFlag = NOT_INIT;
    /*SET CALL BACK FUNCTIONS BEFORE INIT */
    ERROR_STAT=TWI_SetCallback(TWI_1,Dummy_function);
    if(TWI_NOT_INIT==ERROR_STAT){
        printf("TEST 6-4 PASSED\n");
    }
    else{
       printf("TEST 6-4 FAILED\n");
    }
}
void TEST7_TWI_SendStartCondition(void){
    int8_t ERROR_STAT=TWI_SUCCESS;
    gu8_InitFlag = INIT;//pre-condition
    TWI_Control_REGISTER=0x00;//pre-condition
    ERROR_STAT=TWI_SendStartCondition(TWI_1);
    if(TWI_SUCCESS==ERROR_STAT&&((EN_TWI | SEND_START | CLR_FLAG)==TWI_Control_REGISTER)){
        printf("TEST 7-1 PASSED\n");
    }
    else{
       printf("TEST 7-1 FAILED\n");
    }
    ERROR_STAT=TWI_SendStartCondition(TWI_2);
    if(TWI_INVALID_CHANNEL==ERROR_STAT){
        printf("TEST 7-2 PASSED\n");
    }
    else{
       printf("TEST 7-2 FAILED\n");
    }
    gu8_InitFlag = NOT_INIT;//pre-condition
    ERROR_STAT=TWI_SendStartCondition(TWI_1);
    if(TWI_NOT_INIT==ERROR_STAT){
        printf("TEST 7-3 PASSED\n");
    }
    else{
       printf("TEST 7-3 FAILED\n");
    }
}
void TEST8_TWI_SendStopCondition(void){
    int8_t ERROR_STAT=TWI_SUCCESS;
    gu8_InitFlag = INIT;//pre-condition
    TWI_Control_REGISTER=0x00;//pre-condition
    ERROR_STAT=TWI_SendStopCondition(TWI_1);
    if(TWI_SUCCESS==ERROR_STAT&&((EN_TWI | CLR_FLAG | SEND_STOP)==TWI_Control_REGISTER)){
        printf("TEST 8-1 PASSED\n");
    }
    else{
       printf("TEST 8-1 FAILED\n");
    }
    ERROR_STAT=TWI_SendStopCondition(TWI_2);
    if(TWI_INVALID_CHANNEL==ERROR_STAT){
        printf("TEST 8-2 PASSED\n");
    }
    else{
       printf("TEST 8-2 FAILED\n");
    }
    gu8_InitFlag = NOT_INIT;//pre-condition
    ERROR_STAT=TWI_SendStopCondition(TWI_1);
    if(TWI_NOT_INIT==ERROR_STAT){
        printf("TEST 8-3 PASSED\n");
    }
    else{
       printf("TEST 8-3 FAILED\n");
    }
}
void TEST9_TWI_SendSLAWrite(void){
        int8_t ERROR_STAT=TWI_SUCCESS;
    gu8_InitFlag = INIT;//pre-condition
    TWI_Control_REGISTER=0x00;//pre-condition
    ERROR_STAT=TWI_SendSLAWrite(TWI_1,DUMMY_SLA_ADD);
    if(TWI_SUCCESS==ERROR_STAT&&(((DUMMY_SLA_ADD << 1) | 0)==TWI_Data_REGISTER)&&((EN_TWI | CLR_FLAG)==TWI_Control_REGISTER)){
        printf("TEST 9-1 PASSED\n");
    }
    else{
       printf("TEST 9-1 FAILED\n");
    }
    ERROR_STAT=TWI_SendSLAWrite(TWI_2,DUMMY_SLA_ADD);
    if(TWI_INVALID_CHANNEL==ERROR_STAT){
        printf("TEST 9-2 PASSED\n");
    }
    else{
       printf("TEST 9-2 FAILED\n");
    }
    gu8_InitFlag = NOT_INIT;//pre-condition
    ERROR_STAT=TWI_SendSLAWrite(TWI_1,DUMMY_SLA_ADD);
    if(TWI_NOT_INIT==ERROR_STAT){
        printf("TEST 9-3 PASSED\n");
    }
    else{
       printf("TEST 9-3 FAILED\n");
    }
}
void TEST10_TWI_SendSLARead(void){
    int8_t ERROR_STAT=TWI_SUCCESS;
    gu8_InitFlag = INIT;//pre-condition
    TWI_Control_REGISTER=0x00;//pre-condition
    ERROR_STAT=TWI_SendSLARead(TWI_1,DUMMY_SLA_ADD);
    if(TWI_SUCCESS==ERROR_STAT&&(((DUMMY_SLA_ADD << 1) | 1)==TWI_Data_REGISTER)&&((EN_TWI | CLR_FLAG)==TWI_Control_REGISTER)){
        printf("TEST 10-1 PASSED\n");
    }
    else{
       printf("TEST 10-1 FAILED\n");
    }
    ERROR_STAT=TWI_SendSLARead(TWI_2,DUMMY_SLA_ADD);
    if(TWI_INVALID_CHANNEL==ERROR_STAT){
        printf("TEST 10-2 PASSED\n");
    }
    else{
       printf("TEST 10-2 FAILED\n");
    }
    gu8_InitFlag = NOT_INIT;//pre-condition
    ERROR_STAT=TWI_SendSLARead(TWI_1,DUMMY_SLA_ADD);
    if(TWI_NOT_INIT==ERROR_STAT){
        printf("TEST 10-3 PASSED\n");
    }
    else{
       printf("TEST 10-3 FAILED\n");
    }
}

void TEST11_TWI_SendData(void){
    int8_t ERROR_STAT=TWI_SUCCESS;
    gu8_InitFlag = INIT;//pre-condition
    TWI_Control_REGISTER=0x00;//pre-condition
    ERROR_STAT=TWI_SendData(TWI_1,DUMMY_DATA);
    if(TWI_SUCCESS==ERROR_STAT&&((DUMMY_DATA )==TWI_Data_REGISTER)&&((EN_TWI | CLR_FLAG)==TWI_Control_REGISTER)){
        printf("TEST 11-1 PASSED\n");
    }
    else{
       printf("TEST 11-1 FAILED\n");
    }
    ERROR_STAT=TWI_SendData(TWI_2,DUMMY_DATA);
    if(TWI_INVALID_CHANNEL==ERROR_STAT){
        printf("TEST 11-2 PASSED\n");
    }
    else{
       printf("TEST 11-2 FAILED\n");
    }
    gu8_InitFlag = NOT_INIT;//pre-condition
    ERROR_STAT=TWI_SendData(TWI_1,DUMMY_DATA);
    if(TWI_NOT_INIT==ERROR_STAT){
        printf("TEST 11-3 PASSED\n");
    }
    else{
       printf("TEST 11-3 FAILED\n");
    }
}
void TEST12_TWI_RecDataAck(void){
    int8_t ERROR_STAT=TWI_SUCCESS;
    gu8_InitFlag = INIT;//pre-condition
    TWI_Control_REGISTER=0x00;//pre-condition
    TWI_Data_REGISTER=DUMMY_DATA;
    ERROR_STAT=TWI_RecDataAck(TWI_1,&dummyChar);
    if(TWI_SUCCESS==ERROR_STAT&&((DUMMY_DATA )==dummyChar)&&(1==Get_Bit(TWI_Control_REGISTER,TWEA))){
        printf("TEST 12-1 PASSED\n");
    }
    else{
       printf("TEST 12-1 FAILED\n");
    }
    ERROR_STAT=TWI_RecDataAck(TWI_2,&dummyChar);
    if(TWI_INVALID_CHANNEL==ERROR_STAT){
        printf("TEST 12-2 PASSED\n");
    }
    else{
       printf("TEST 12-2 FAILED\n");
    }
    ERROR_STAT=TWI_RecDataAck(TWI_2,NULL_PTR);
    if(TWI_NULL_POINTER==ERROR_STAT){
        printf("TEST 12-3 PASSED\n");
    }
    else{
       printf("TEST 12-3 FAILED\n");
    }
    gu8_InitFlag = NOT_INIT;//pre-condition
    ERROR_STAT=TWI_RecDataAck(TWI_1,&dummyChar);
    if(TWI_NOT_INIT==ERROR_STAT){
        printf("TEST 12-4 PASSED\n");
    }
    else{
       printf("TEST 12-4 FAILED\n");
    }



}


void Dummy_function(void){
}
