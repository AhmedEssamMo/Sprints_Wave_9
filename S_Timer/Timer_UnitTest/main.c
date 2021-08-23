#include <stdio.h>
#include <stdlib.h>
#include "MCAL/TIMER/TIMER.h"
#include "LIB/STD_TYPES.h"
#define INVALID_TIMER_CH  (uint8_t)3
#define INVALID_INT_TYPE  (uint8_t)0xff
#define INVALID_PIN       (uint8_t)4
#define INVALID_REG       (uint8_t)4
#define DUMMY_VAL         (uint16_t)0xAA
static void Dummy_Function(void);
static void Dummy_Function(void){
}
void TEST1_TIMER_init(void);
void TEST2_TIMER_start(void);
void TEST3_TIMER_stop(void);
void TEST4_TIMER_EN_Interrupt(void);
void TEST5_TIMER_DIS_Interrupt(void);
void TEST6_TIMER_callBackFunc(void);
void TEST7_TIMER_pinConnect(void);
void TEST8_TIMER_pinDisconnect(void);
void TEST9_TIMER_preload(void);
void TEST10_TIMER_cmprValue(void);
int main()
{
    printf("***************************\n");
    printf("TEST NO.1\n");
    TEST1_TIMER_init();
    printf("***************************\n");
    printf("TEST NO.2\n");
    TEST2_TIMER_start();
    printf("***************************\n");
    printf("TEST NO.3\n");
    TEST3_TIMER_stop();
    printf("***************************\n");
    printf("TEST NO.4\n");
    TEST4_TIMER_EN_Interrupt();
    printf("***************************\n");
    printf("TEST NO.5\n");
    TEST5_TIMER_DIS_Interrupt();
    printf("***************************\n");
    printf("TEST NO.6\n");
    TEST6_TIMER_callBackFunc();
    printf("***************************\n");
    printf("TEST NO.7\n");
    TEST7_TIMER_pinConnect();
    printf("***************************\n");
    printf("TEST NO.8\n");
    TEST8_TIMER_pinDisconnect();
    printf("***************************\n");
    printf("TEST NO.9\n");
    TEST9_TIMER_preload();
    printf("***************************\n");
    printf("TEST NO.10\n");
    TEST10_TIMER_cmprValue();
    return 0;
}
void TEST1_TIMER_init(void){
    uint8_t au8_StoredData = ERROR_OK;
    ERROR_STATE_t au8_ERROR_STAT = ERROR_OK;
    au8_ERROR_STAT=TIMER_init(INVALID_TIMER_CH);
    if(ERROR_NOK==au8_ERROR_STAT){
        printf("TEST 1-1 PASSED\n");
    }
    else{
        printf("TEST 1-1 FAILED\n");
    }
    TCCR0=0;
    au8_ERROR_STAT=TIMER_init(TIMER0);
    au8_StoredData=TCCR0;

    if(ERROR_OK==au8_ERROR_STAT&&(TIMER0_MODE==TCCR0)){
        printf("TEST 1-2 PASSED\n");
    }
    else{
        printf("TEST 1-2 FAILED\n");
    }
}
void TEST2_TIMER_start(void){
    uint8_t au8_StoredData = ERROR_OK;
    ERROR_STATE_t au8_ERROR_STAT = ERROR_OK;
    au8_ERROR_STAT=TIMER_start(INVALID_TIMER_CH);
    if(ERROR_NOK==au8_ERROR_STAT){
        printf("TEST 2-1 PASSED\n");
    }
    else{
        printf("TEST 2-1 FAILED\n");
    }
    TCCR0=0;
    au8_ERROR_STAT=TIMER_start(TIMER0);
    au8_StoredData=TCCR0;

    if(ERROR_OK==au8_ERROR_STAT&&(TIMER0_PRESCALER==TCCR0)){
        printf("TEST 2-2 PASSED\n");
    }
    else{
        printf("TEST 2-2 FAILED\n");
    }
}
void TEST3_TIMER_stop(void){
    uint8_t au8_StoredData = ERROR_OK;
    ERROR_STATE_t au8_ERROR_STAT = ERROR_OK;
    au8_ERROR_STAT=TIMER_stop(INVALID_TIMER_CH);
    if(ERROR_NOK==au8_ERROR_STAT){
        printf("TEST 3-1 PASSED\n");
    }
    else{
        printf("TEST 3-1 FAILED\n");
    }
    TCCR0=255;

    au8_ERROR_STAT=TIMER_stop(TIMER0);
    au8_StoredData=TCCR0;

    if(ERROR_OK==au8_ERROR_STAT&&(!Get_Bit(TCCR0,CS01)))
    {
        printf("TEST 3-2 PASSED\n");
    }
    else{
        printf("TEST 3-2 FAILED\n");
    }
    TCCR0=0;
}
void TEST4_TIMER_EN_Interrupt(void){
    uint8_t au8_StoredData = ERROR_OK;
    ERROR_STATE_t au8_ERROR_STAT = ERROR_OK;
    au8_ERROR_STAT=TIMER_EN_Interrupt(INVALID_INT_TYPE);
    if(ERROR_NOK==au8_ERROR_STAT){
        printf("TEST 4-1 PASSED\n");
    }
    else{
        printf("TEST 4-1 FAILED\n");
    }
    TIMSK=0;
    au8_ERROR_STAT=TIMER_EN_Interrupt(CTC0_INTERRUPT);
    au8_StoredData=TIMSK;

    if(ERROR_OK==au8_ERROR_STAT&&(CTC0_INTERRUPT==au8_StoredData))
    {
        printf("TEST 4-2 PASSED\n");
    }
    else{
        printf("TEST 4-2 FAILED\n");
    }
}
void TEST5_TIMER_DIS_Interrupt(void){
     uint8_t au8_StoredData = ERROR_OK;
    ERROR_STATE_t au8_ERROR_STAT = ERROR_OK;
    au8_ERROR_STAT=TIMER_DIS_Interrupt(INVALID_INT_TYPE);
    if(ERROR_NOK==au8_ERROR_STAT){
        printf("TEST 5-1 PASSED\n");
    }
    else{
        printf("TEST 5-1 FAILED\n");
    }
    TIMSK=255;

    au8_ERROR_STAT=TIMER_DIS_Interrupt(CTC0_INTERRUPT);
    if(ERROR_OK==au8_ERROR_STAT&&(0==Get_Bit(TIMSK,OCIE0)))
    {
        printf("TEST 5-2 PASSED\n");
    }
    else{
        printf("TEST 5-2 FAILED\n");
    }
    TIMSK=0;
}
void TEST6_TIMER_callBackFunc(void){
    ERROR_STATE_t au8_ERROR_STAT = ERROR_OK;
    au8_ERROR_STAT=TIMER_callBackFunc(INVALID_INT_TYPE,Dummy_Function);
    if(ERROR_NOK==au8_ERROR_STAT){
        printf("TEST 6-1 PASSED\n");
    }
    else
    {
        printf("TEST 6-1 FAILED\n");
    }
    au8_ERROR_STAT=TIMER_callBackFunc(CTC0_INTERRUPT,NULL_PTR);
    if(ERROR_NOK==au8_ERROR_STAT){
        printf("TEST 6-2 PASSED\n");
    }
    else
    {
        printf("TEST 6-2 FAILED\n");
    }
    au8_ERROR_STAT=TIMER_callBackFunc(CTC0_INTERRUPT,Dummy_Function);
    if(ERROR_OK==au8_ERROR_STAT)
    {
        printf("TEST 6-3 PASSED\n");
    }
    else{
        printf("TEST 6-3 FAILED\n");
    }
}
void TEST7_TIMER_pinConnect(void){
    uint8_t au8_StoredData = ERROR_OK;
    ERROR_STATE_t au8_ERROR_STAT = ERROR_OK;
    au8_ERROR_STAT=TIMER_pinConnect(INVALID_PIN);
    if(ERROR_NOK==au8_ERROR_STAT){
        printf("TEST 7-1 PASSED\n");
    }
    else{
        printf("TEST 7-1 FAILED\n");
    }
    TCCR0=0;
    au8_ERROR_STAT=TIMER_pinConnect(TIMER0_OC0);
    au8_StoredData=TCCR0;
    if(ERROR_OK==au8_ERROR_STAT&&(OC0_OUTPUT==au8_StoredData))
    {
        printf("TEST 7-2 PASSED\n");
    }
    else{
        printf("TEST 7-2 FAILED\n");
    }
    TCCR0=0;
}
void TEST8_TIMER_pinDisconnect(void){
    uint8_t au8_StoredData = ERROR_OK;
    ERROR_STATE_t au8_ERROR_STAT = ERROR_OK;
    au8_ERROR_STAT=TIMER_pinDisconnect(INVALID_PIN);
    if(ERROR_NOK==au8_ERROR_STAT){
        printf("TEST 8-1 PASSED\n");
    }
    else{
        printf("TEST 8-1 FAILED\n");
    }
    TCCR0=255;

    au8_ERROR_STAT=TIMER_pinDisconnect(TIMER0_OC0);
    if(ERROR_OK==au8_ERROR_STAT&&(0==Get_Bit(TIMSK,OCIE0)))
    {
        printf("TEST 8-2 PASSED\n");
    }
    else{
        printf("TEST 8-2 FAILED\n");
    }
    TCCR0=0;
}
void TEST9_TIMER_preload(void){
    uint16_t au16_StoredData = ERROR_OK;
    ERROR_STATE_t au8_ERROR_STAT = ERROR_OK;
    au8_ERROR_STAT=TIMER_preload(INVALID_TIMER_CH,DUMMY_VAL);
    if(ERROR_NOK==au8_ERROR_STAT){
        printf("TEST 9-1 PASSED\n");
    }
    else{
        printf("TEST 9-1 FAILED\n");
    }
    TCNT0=0;
    au8_ERROR_STAT=TIMER_preload(TIMER0,DUMMY_VAL);
    au16_StoredData=TCNT0;

    if(ERROR_OK==au8_ERROR_STAT&&(DUMMY_VAL==au16_StoredData)){
        printf("TEST 9-2 PASSED\n");
    }
    else{
        printf("TEST 9-2 FAILED\n");
    }
}
void TEST10_TIMER_cmprValue(void){
    uint16_t au16_StoredData = ERROR_OK;
    ERROR_STATE_t au8_ERROR_STAT = ERROR_OK;
    au8_ERROR_STAT=TIMER_cmprValue(INVALID_REG,DUMMY_VAL);
    if(ERROR_NOK==au8_ERROR_STAT){
        printf("TEST 10-1 PASSED\n");
    }
    else{
        printf("TEST 10-1 FAILED\n");
    }
    OCR0=0;
    au8_ERROR_STAT=TIMER_cmprValue(TIMER0,DUMMY_VAL);
    au16_StoredData=OCR0;

    if(ERROR_OK==au8_ERROR_STAT&&(DUMMY_VAL==au16_StoredData)){
        printf("TEST 10-2 PASSED\n");
    }
    else{
        printf("TEST10-2 FAILED\n");
    }
}

