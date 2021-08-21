#include"MCAL/DIO/DIO.h"
#include"HAL/BUTTONS/Button.h"
#include"HAL/LED/LED.h"
#include"Mcal/DIO/DIO_REG.h"

#define INVALID_PORT  4
#define INVALID_PIN   8
#define INVALID_DIR   2
#define RANDOM_DIR    0xf0
#define RANDOM_DATA   0xaa
void TEST_RESET_PORT(uint8_t Port_ID);
void TEST_RESET_PORT(uint8_t Port_ID){
    switch (Port_ID) {
    case PORTA :
        PORTA_DIR = PORT_INPUT;
        PORTA_DATA = PORT_INPUT;
        PORTA_STAT = PORT_INPUT;
        break;
    case PORTB :
        PORTB_DIR = PORT_INPUT;
        PORTB_DATA = PORT_INPUT;
        PORTB_STAT = PORT_INPUT;
        break;
    case PORTC :
        PORTC_DIR = PORT_INPUT;
        PORTC_DATA = PORT_INPUT;
        PORTC_STAT = PORT_INPUT;
        break;
    case PORTD :
        PORTD_DIR = PORT_INPUT;
        PORTD_DATA = PORT_INPUT;
        PORTD_STAT = PORT_INPUT;
        break;
    default:
        break;
    } //END of SWITCH
}
void TEST1_DIO_setPortDirection(void);
void TEST2_DIO_setPinDirection(void);
void TEST3_DIO_writePortValue(void);
void TEST4_DIO_writePinValue(void);
void TEST5_DIO_readPort(void);
void TEST6_DIO_readPin(void);
int main(){
    printf("*********************************\n");
    printf("TEST NO.1\n");
    TEST1_DIO_setPortDirection();
    printf("*********************************\n");
    printf("TEST NO.2\n");
    TEST2_DIO_setPinDirection();
    printf("*********************************\n");
    printf("TEST NO.3\n");
    TEST3_DIO_writePortValue();
    printf("*********************************\n");
    printf("TEST NO.4\n");
    TEST4_DIO_writePinValue();
    printf("*********************************\n");
    printf("TEST NO.5\n");
    TEST5_DIO_readPort();
    printf("*********************************\n");
    printf("TEST NO.6\n");
    TEST6_DIO_readPin();
	return 0;
}

void TEST1_DIO_setPortDirection(void){
    /*DEFINE AN VARIABLE TO STORRE THE ERROR*/
    ERROR_STATE_t u8_ERROR_STATE=ERROR_OK;
    /*CALL THE FUNCTION WITH INVALID PORT*/
    u8_ERROR_STATE=DIO_setPortDirection(INVALID_PORT,PORT_OUTPUT);
    if(ERROR_NOK==u8_ERROR_STATE){
        printf("TEST 1-1 PASSED\n");
    }
    else{
        printf("TEST 1-1 FAILED\n");
    }
    /*SET PORT A DIRECTION OUTPUT*/
    /*RESET PORT A*/
    TEST_RESET_PORT(PORTA);
    u8_ERROR_STATE=DIO_setPortDirection(PORTA,PORT_OUTPUT);
    if((ERROR_OK==u8_ERROR_STATE) && (PORT_OUTPUT==PORTA_DIR)){
        printf("TEST 1-2 PASSED\n");
    }
    else{
        printf("TEST 1-2 FAILED\n");
    }
    TEST_RESET_PORT(PORTB);
    u8_ERROR_STATE=DIO_setPortDirection(PORTB,RANDOM_DIR);
    if((ERROR_OK==u8_ERROR_STATE) && (RANDOM_DIR==PORTB_DIR)){
        printf("TEST 1-3 PASSED\n");
    }
    else{
        printf("TEST 1-3 FAILED\n");
    }
    TEST_RESET_PORT(PORTC);
    u8_ERROR_STATE=DIO_setPortDirection(PORTC,PORT_INPUT);
    if((ERROR_OK==u8_ERROR_STATE) && (PORT_INPUT==PORTC_DIR)){
        printf("TEST 1-4 PASSED\n");
    }
    else{
        printf("TEST 1-4 FAILED\n");
    }
}
void TEST2_DIO_setPinDirection(void){
    /*DEFINE AN VARIABLE TO STORRE THE ERROR*/
    ERROR_STATE_t u8_ERROR_STATE=ERROR_OK;
    /*CALL THE FUNCTION WITH INVALID PORT*/
    u8_ERROR_STATE=DIO_setPinDirection(INVALID_PORT,PIN0,PIN_OUTPUT);
    if(ERROR_NOK==u8_ERROR_STATE){
        printf("TEST 2-1 PASSED\n");
    }
    else{
        printf("TEST 2-1 FAILED\n");
    }
     /*CALL THE FUNCTION WITH INVALID PIN*/
    /*RESET PORT A*/
    TEST_RESET_PORT(PORTA);
    u8_ERROR_STATE=DIO_setPinDirection(PORTA,INVALID_PIN,PORT_OUTPUT);
    if(ERROR_NOK==u8_ERROR_STATE){
        printf("TEST 2-2 PASSED\n");
    }
    else{
        printf("TEST 2-2 FAILED\n");
    }
    /*CALL THE FUNCTION WITH INVALID DIRECTION*/
    TEST_RESET_PORT(PORTB);
    u8_ERROR_STATE=DIO_setPinDirection(PORTB,PIN7,INVALID_DIR);
    if(ERROR_NOK==u8_ERROR_STATE){
        printf("TEST 2-3 PASSED\n");
    }
    else{
        printf("TEST 2-3 FAILED\n");
    }
    /*SET PIN DIRRECTION SELECT RANDOM PINs AND PORTs*/
    TEST_RESET_PORT(PORTA);
    u8_ERROR_STATE=DIO_setPinDirection(PORTA,PIN0,PIN_OUTPUT);
    if((ERROR_OK==u8_ERROR_STATE) && (PIN_OUTPUT==(Get_Bit(PORTA_DIR,PIN0)))){
        printf("TEST 2-4 PASSED\n");
    }
    else{
        printf("TEST 2-4 FAILED\n");
    }
    TEST_RESET_PORT(PORTA);
    u8_ERROR_STATE=DIO_setPinDirection(PORTA,PIN7,PIN_OUTPUT);
    if((ERROR_OK==u8_ERROR_STATE) && (PIN_OUTPUT==(Get_Bit(PORTA_DIR,PIN7)))){
        printf("TEST 2-5 PASSED\n");
    }
    else{
        printf("TEST 2-5 FAILED\n");
    }
    TEST_RESET_PORT(PORTA);
    u8_ERROR_STATE=DIO_setPinDirection(PORTA,PIN3,PIN_INPUT);
    if((ERROR_OK==u8_ERROR_STATE) && (PIN_INPUT==(Get_Bit(PORTA_DIR,PIN3)))){
        printf("TEST 2-6 PASSED\n");
    }
    else{
        printf("TEST 2-6 FAILED\n");
    }
    TEST_RESET_PORT(PORTA);
    u8_ERROR_STATE=DIO_setPinDirection(PORTA,PIN0,PIN_OUTPUT);
    if((ERROR_OK==u8_ERROR_STATE) && (PIN_OUTPUT==(Get_Bit(PORTA_DIR,PIN0)))){
        printf("TEST 2-7 PASSED\n");
    }
    else{
        printf("TEST 2-7 FAILED\n");
    }
    TEST_RESET_PORT(PORTA);
    u8_ERROR_STATE=DIO_setPinDirection(PORTA,PIN7,PIN_OUTPUT);
    if((ERROR_OK==u8_ERROR_STATE) && (PIN_OUTPUT==(Get_Bit(PORTA_DIR,PIN7)))){
        printf("TEST 2-8 PASSED\n");
    }
    else{
        printf("TEST 2-8 FAILED\n");
    }
    TEST_RESET_PORT(PORTB);
    u8_ERROR_STATE=DIO_setPinDirection(PORTB,PIN3,PIN_INPUT);
    if((ERROR_OK==u8_ERROR_STATE) && (PIN_INPUT==(Get_Bit(PORTB_DIR,PIN3)))){
        printf("TEST 2-9 PASSED\n");
    }
    else{
        printf("TEST 2-9 FAILED\n");
    }
        TEST_RESET_PORT(PORTC);
    u8_ERROR_STATE=DIO_setPinDirection(PORTC,PIN0,PIN_OUTPUT);
    if((ERROR_OK==u8_ERROR_STATE) && (PIN_OUTPUT==(Get_Bit(PORTC_DIR,PIN0)))){
        printf("TEST 2-10 PASSED\n");
    }
    else{
        printf("TEST 2-10 FAILED\n");
    }
    TEST_RESET_PORT(PORTC);
    u8_ERROR_STATE=DIO_setPinDirection(PORTC,PIN7,PIN_OUTPUT);
    if((ERROR_OK==u8_ERROR_STATE) && (PIN_OUTPUT==(Get_Bit(PORTC_DIR,PIN7)))){
        printf("TEST 2-11 PASSED\n");
    }
    else{
        printf("TEST 2-11 FAILED\n");
    }
    TEST_RESET_PORT(PORTC);
    u8_ERROR_STATE=DIO_setPinDirection(PORTC,PIN6,PIN_INPUT);
    if((ERROR_OK==u8_ERROR_STATE) && (PIN_INPUT==(Get_Bit(PORTC_DIR,PIN6)))){
        printf("TEST 2-12 PASSED\n");
    }
    else{
        printf("TEST 2-12 FAILED\n");
    }
        TEST_RESET_PORT(PORTD);
    u8_ERROR_STATE=DIO_setPinDirection(PORTD,PIN0,PIN_OUTPUT);
    if((ERROR_OK==u8_ERROR_STATE) && (PIN_OUTPUT==(Get_Bit(PORTD_DIR,PIN0)))){
        printf("TEST 2-13 PASSED\n");
    }
    else{
        printf("TEST 2-13 FAILED\n");
    }
    TEST_RESET_PORT(PORTD);
    u8_ERROR_STATE=DIO_setPinDirection(PORTD,PIN7,PIN_INPUT);
    if((ERROR_OK==u8_ERROR_STATE) && (PIN_INPUT==(Get_Bit(PORTD_DIR,PIN7)))){
        printf("TEST 2-14 PASSED\n");
    }
    else{
        printf("TEST 2-14 FAILED\n");
    }
    TEST_RESET_PORT(PORTD);
    u8_ERROR_STATE=DIO_setPinDirection(PORTD,PIN5,PIN_INPUT);
    if((ERROR_OK==u8_ERROR_STATE) && (PIN_INPUT==(Get_Bit(PORTD_DIR,PIN5)))){
        printf("TEST 2-15 PASSED\n");
    }
    else{
        printf("TEST 2-15 FAILED\n");
    }
}
void TEST3_DIO_writePortValue(void){
 /*DEFINE AN VARIABLE TO STORRE THE ERROR*/
    ERROR_STATE_t u8_ERROR_STATE=ERROR_OK;
    /*CALL THE FUNCTION WITH INVALID PORT*/
    u8_ERROR_STATE=DIO_writePortValue(INVALID_PORT,PORT_OUTPUT);
    if(ERROR_NOK==u8_ERROR_STATE){
        printf("TEST 3-1 PASSED\n");
    }
    else{
        printf("TEST 3-1 FAILED\n");
    }
    /*SET PORT A DIRECTION OUTPUT*/
    /*RESET PORT A*/
    TEST_RESET_PORT(PORTA);
    u8_ERROR_STATE=DIO_writePortValue(PORTA,PORT_OUTPUT);
    if((ERROR_OK==u8_ERROR_STATE) && (PORT_OUTPUT==PORTA_DATA)){
        printf("TEST 3-2 PASSED\n");
    }
    else{
        printf("TEST 3-2 FAILED\n");
    }
    TEST_RESET_PORT(PORTB);
    u8_ERROR_STATE=DIO_writePortValue(PORTB,RANDOM_DIR);
    if((ERROR_OK==u8_ERROR_STATE) && (RANDOM_DIR==PORTB_DATA)){
        printf("TEST 3-3 PASSED\n");
    }
    else{
        printf("TEST 3-3 FAILED\n");
    }
    TEST_RESET_PORT(PORTC);
    u8_ERROR_STATE=DIO_writePortValue(PORTC,PORT_INPUT);
    if((ERROR_OK==u8_ERROR_STATE) && (PORT_INPUT==PORTC_DATA)){
        printf("TEST 3-4 PASSED\n");
    }
    else{
        printf("TEST 3-4 FAILED\n");
    }
}
void TEST4_DIO_writePinValue(void){
     /*DEFINE AN VARIABLE TO STORRE THE ERROR*/
    ERROR_STATE_t u8_ERROR_STATE=ERROR_OK;
    /*CALL THE FUNCTION WITH INVALID PORT*/
    u8_ERROR_STATE=DIO_writePinValue(INVALID_PORT,PIN0,PIN_HIGH);
    if(ERROR_NOK==u8_ERROR_STATE){
        printf("TEST 4-1 PASSED\n");
    }
    else{
        printf("TEST 4-1 FAILED\n");
    }
     /*CALL THE FUNCTION WITH INVALID PIN*/
    /*RESET PORT A*/
    TEST_RESET_PORT(PORTA);
    u8_ERROR_STATE=DIO_writePinValue(PORTA,INVALID_PIN,PORT_OUTPUT);
    if(ERROR_NOK==u8_ERROR_STATE){
        printf("TEST 4-2 PASSED\n");
    }
    else{
        printf("TEST 4-2 FAILED\n");
    }
    /*CALL THE FUNCTION WITH INVALID DIRECTION*/
    TEST_RESET_PORT(PORTB);
    u8_ERROR_STATE=DIO_writePinValue(PORTB,PIN7,INVALID_DIR);
    if(ERROR_NOK==u8_ERROR_STATE){
        printf("TEST 4-3 PASSED\n");
    }
    else{
        printf("TEST 4-3 FAILED\n");
    }
    /*SET PIN DIRRECTION SELECT RANDOM PINs AND PORTs*/
    TEST_RESET_PORT(PORTA);
    u8_ERROR_STATE=DIO_writePinValue(PORTA,PIN0,PIN_HIGH);
    if((ERROR_OK==u8_ERROR_STATE) && (PIN_HIGH==(Get_Bit(PORTA_DATA,PIN0)))){
        printf("TEST 4-4 PASSED\n");
    }
    else{
        printf("TEST 4-4 FAILED\n");
    }
    TEST_RESET_PORT(PORTA);
    u8_ERROR_STATE=DIO_writePinValue(PORTA,PIN7,PIN_HIGH);
    if((ERROR_OK==u8_ERROR_STATE) && (PIN_HIGH==(Get_Bit(PORTA_DATA,PIN7)))){
        printf("TEST 4-5 PASSED\n");
    }
    else{
        printf("TEST 4-5 FAILED\n");
    }
    TEST_RESET_PORT(PORTA);
    u8_ERROR_STATE=DIO_writePinValue(PORTA,PIN3,PIN_LOW);
    if((ERROR_OK==u8_ERROR_STATE) && (PIN_LOW==(Get_Bit(PORTA_DATA,PIN3)))){
        printf("TEST 4-6 PASSED\n");
    }
    else{
        printf("TEST 4-6 FAILED\n");
    }
    TEST_RESET_PORT(PORTA);
    u8_ERROR_STATE=DIO_writePinValue(PORTA,PIN0,PIN_HIGH);
    if((ERROR_OK==u8_ERROR_STATE) && (PIN_HIGH==(Get_Bit(PORTA_DATA,PIN0)))){
        printf("TEST 4-7 PASSED\n");
    }
    else{
        printf("TEST 4-7 FAILED\n");
    }
    TEST_RESET_PORT(PORTA);
    u8_ERROR_STATE=DIO_writePinValue(PORTA,PIN7,PIN_HIGH);
    if((ERROR_OK==u8_ERROR_STATE) && (PIN_HIGH==(Get_Bit(PORTA_DATA,PIN7)))){
        printf("TEST 4-8 PASSED\n");
    }
    else{
        printf("TEST 4-8 FAILED\n");
    }
    TEST_RESET_PORT(PORTB);
    u8_ERROR_STATE=DIO_writePinValue(PORTB,PIN3,PIN_LOW);
    if((ERROR_OK==u8_ERROR_STATE) && (PIN_LOW==(Get_Bit(PORTB_DATA,PIN3)))){
        printf("TEST 4-9 PASSED\n");
    }
    else{
        printf("TEST 4-9 FAILED\n");
    }
        TEST_RESET_PORT(PORTC);
    u8_ERROR_STATE=DIO_writePinValue(PORTC,PIN0,PIN_HIGH);
    if((ERROR_OK==u8_ERROR_STATE) && (PIN_HIGH==(Get_Bit(PORTC_DATA,PIN0)))){
        printf("TEST 4-10 PASSED\n");
    }
    else{
        printf("TEST 4-10 FAILED\n");
    }
    TEST_RESET_PORT(PORTC);
    u8_ERROR_STATE=DIO_writePinValue(PORTC,PIN7,PIN_HIGH);
    if((ERROR_OK==u8_ERROR_STATE) && (PIN_HIGH==(Get_Bit(PORTC_DATA,PIN7)))){
        printf("TEST 4-11 PASSED\n");
    }
    else{
        printf("TEST 4-11 FAILED\n");
    }
    TEST_RESET_PORT(PORTC);
    u8_ERROR_STATE=DIO_writePinValue(PORTC,PIN6,PIN_LOW);
    if((ERROR_OK==u8_ERROR_STATE) && (PIN_LOW==(Get_Bit(PORTC_DATA,PIN6)))){
        printf("TEST 4-12 PASSED\n");
    }
    else{
        printf("TEST 4-12 FAILED\n");
    }
        TEST_RESET_PORT(PORTD);
    u8_ERROR_STATE=DIO_writePinValue(PORTD,PIN0,PIN_HIGH);
    if((ERROR_OK==u8_ERROR_STATE) && (PIN_HIGH==(Get_Bit(PORTD_DATA,PIN0)))){
        printf("TEST 4-13 PASSED\n");
    }
    else{
        printf("TEST 4-13 FAILED\n");
    }
    TEST_RESET_PORT(PORTD);
    u8_ERROR_STATE=DIO_writePinValue(PORTD,PIN7,PIN_LOW);
    if((ERROR_OK==u8_ERROR_STATE) && (PIN_LOW==(Get_Bit(PORTD_DATA,PIN7)))){
        printf("TEST 4-14 PASSED\n");
    }
    else{
        printf("TEST 4-14 FAILED\n");
    }
    TEST_RESET_PORT(PORTD);
    u8_ERROR_STATE=DIO_writePinValue(PORTD,PIN5,PIN_LOW);
    if((ERROR_OK==u8_ERROR_STATE) && (PIN_LOW==(Get_Bit(PORTD_DATA,PIN5)))){
        printf("TEST 4-15 PASSED\n");
    }
    else{
        printf("TEST 4-15 FAILED\n");
    }
}
void TEST5_DIO_readPort(void){
 /*DEFINE AN VARIABLE TO STORRE THE ERROR*/
    ERROR_STATE_t u8_ERROR_STATE=ERROR_OK;
    uint8_t  u8_DummyVar=0;
    /*CALL THE FUNCTION WITH INVALID PORT*/
    u8_ERROR_STATE=DIO_readPort(INVALID_PORT,&u8_DummyVar);
    if(ERROR_NOK==u8_ERROR_STATE){
        printf("TEST 5-1 PASSED\n");
    }
    else{
        printf("TEST 5-1 FAILED\n");
    }
    u8_ERROR_STATE=DIO_readPort(PORTA,NULL_PTR);
    if(ERROR_NOK==u8_ERROR_STATE){
        printf("TEST 5-2 PASSED\n");
    }
    else{
        printf("TEST 5-2 FAILED\n");
    }
    /*SET PORT A DIRECTION OUTPUT*/
    /*RESET PORT A*/
    TEST_RESET_PORT(PORTA);
    PORTA_STAT=RANDOM_DATA;
    u8_ERROR_STATE=DIO_readPort(PORTA,&u8_DummyVar);
    if((ERROR_OK==u8_ERROR_STATE) && (RANDOM_DATA==u8_DummyVar)){
        printf("TEST 5-3 PASSED\n");
    }
    else{
        printf("TEST 5-3 FAILED\n");
    }
    TEST_RESET_PORT(PORTB);
    PORTB_STAT=RANDOM_DATA;
    u8_ERROR_STATE=DIO_readPort(PORTB,&u8_DummyVar);
    if((ERROR_OK==u8_ERROR_STATE) && (RANDOM_DATA==u8_DummyVar)){
        printf("TEST 5-4 PASSED\n");
    }
    else{
        printf("TEST 5-4 FAILED\n");
    }
    TEST_RESET_PORT(PORTC);
    PORTC_STAT=RANDOM_DATA;
    u8_ERROR_STATE=DIO_readPort(PORTC,&u8_DummyVar);
    if((ERROR_OK==u8_ERROR_STATE) && (RANDOM_DATA==u8_DummyVar)){
        printf("TEST 5-5 PASSED\n");
    }
    else{
        printf("TEST 5-5 FAILED\n");
    }
}
void TEST6_DIO_readPin(void){
    /*DEFINE AN VARIABLE TO STORRE THE ERROR*/
    ERROR_STATE_t u8_ERROR_STATE=ERROR_OK;
    uint8_t  u8_DummyVar=0;
    /*CALL THE FUNCTION WITH INVALID PORT*/
    u8_ERROR_STATE=DIO_readPin(INVALID_PORT,PIN0,&u8_DummyVar);
    if(ERROR_NOK==u8_ERROR_STATE){
        printf("TEST 6-1 PASSED\n");
    }
    else{
        printf("TEST 6-1 FAILED\n");
    }
     /*CALL THE FUNCTION WITH INVALID PIN*/
    /*RESET PORT A*/
    TEST_RESET_PORT(PORTA);
    u8_ERROR_STATE=DIO_readPin(PORTA,INVALID_PIN,&u8_DummyVar);
    if(ERROR_NOK==u8_ERROR_STATE){
        printf("TEST 6-2 PASSED\n");
    }
    else{
        printf("TEST 6-2 FAILED\n");
    }
    u8_ERROR_STATE=DIO_readPin(PORTA,PIN0,NULL_PTR);
    if(ERROR_NOK==u8_ERROR_STATE){
        printf("TEST 6-3 PASSED\n");
    }
    else{
        printf("TEST 6-3 FAILED\n");
    }
    /*SET PIN DIRRECTION SELECT RANDOM PINs AND PORTs*/
    TEST_RESET_PORT(PORTA);
    Set_Bit(PORTA_STAT, PIN0);
    u8_ERROR_STATE=DIO_readPin(PORTA,PIN0,&u8_DummyVar);
    if((ERROR_OK==u8_ERROR_STATE) && (PIN_HIGH==u8_DummyVar)){
        printf("TEST 6-4 PASSED\n");
    }
    else{
        printf("TEST 6-4 FAILED\n");
    }
    TEST_RESET_PORT(PORTA);
    Set_Bit(PORTA_STAT, PIN7);
    u8_ERROR_STATE=DIO_readPin(PORTA,PIN7,&u8_DummyVar);
    if((ERROR_OK==u8_ERROR_STATE) && (PIN_HIGH==u8_DummyVar)){
        printf("TEST 6-5 PASSED\n");
    }
    else{
        printf("TEST 6-5 FAILED\n");
    }
    TEST_RESET_PORT(PORTA);
    Clr_Bit(PORTA_STAT, PIN3);
    u8_ERROR_STATE=DIO_readPin(PORTA,PIN3,&u8_DummyVar);
    if((ERROR_OK==u8_ERROR_STATE) && (PIN_LOW==u8_DummyVar)){
        printf("TEST 6-6 PASSED\n");
    }
    else{
        printf("TEST 6-6 FAILED\n");
    }
    TEST_RESET_PORT(PORTB);
    Clr_Bit(PORTB_STAT, PIN0);
    u8_ERROR_STATE=DIO_readPin(PORTB,PIN0,&u8_DummyVar);
    if((ERROR_OK==u8_ERROR_STATE) && (PIN_LOW==u8_DummyVar)){
        printf("TEST 6-7 PASSED\n");
    }
    else{
        printf("TEST 6-7 FAILED\n");
    }
    TEST_RESET_PORT(PORTB);
    Clr_Bit(PORTB_STAT, PIN7);
    u8_ERROR_STATE=DIO_readPin(PORTB,PIN7,&u8_DummyVar);
    if((ERROR_OK==u8_ERROR_STATE) && (PIN_LOW==u8_DummyVar)){
        printf("TEST 6-8 PASSED\n");
    }
    else{
        printf("TEST 6-8 FAILED\n");
    }
    TEST_RESET_PORT(PORTB);
    Set_Bit(PORTB_STAT, PIN3);
    u8_ERROR_STATE=DIO_readPin(PORTB,PIN3,&u8_DummyVar);
    if((ERROR_OK==u8_ERROR_STATE) && (PIN_HIGH==u8_DummyVar)){
        printf("TEST 6-9 PASSED\n");
    }
    else{
        printf("TEST 6-9 FAILED\n");
    }
    TEST_RESET_PORT(PORTC);
    Set_Bit(PORTC_STAT, PIN0);
    u8_ERROR_STATE=DIO_readPin(PORTC,PIN0,&u8_DummyVar);
    if((ERROR_OK==u8_ERROR_STATE) && (PIN_HIGH==u8_DummyVar)){
        printf("TEST 6-10 PASSED\n");
    }
    else{
        printf("TEST 6-10 FAILED\n");
    }
    TEST_RESET_PORT(PORTC);
    Set_Bit(PORTC_STAT, PIN7);
    u8_ERROR_STATE=DIO_readPin(PORTC,PIN7,&u8_DummyVar);
    if((ERROR_OK==u8_ERROR_STATE) && (PIN_HIGH==u8_DummyVar)){
        printf("TEST 6-11 PASSED\n");
    }
    else{
        printf("TEST 6-11 FAILED\n");
    }
    TEST_RESET_PORT(PORTC);
    Clr_Bit(PORTC_STAT, PIN4);
    u8_ERROR_STATE=DIO_readPin(PORTC,PIN4,&u8_DummyVar);
    if((ERROR_OK==u8_ERROR_STATE) && (PIN_LOW==u8_DummyVar)){
        printf("TEST 6-12 PASSED\n");
    }
    else{
        printf("TEST 6-12 FAILED\n");
    }
    TEST_RESET_PORT(PORTD);
    Set_Bit(PORTD_STAT, PIN0);
    u8_ERROR_STATE=DIO_readPin(PORTD,PIN0,&u8_DummyVar);
    if((ERROR_OK==u8_ERROR_STATE) && (PIN_HIGH==u8_DummyVar)){
        printf("TEST 6-13 PASSED\n");
    }
    else{
        printf("TEST 6-13 FAILED\n");
    }
    TEST_RESET_PORT(PORTD);
    Clr_Bit(PORTD_STAT, PIN4);
    u8_ERROR_STATE=DIO_readPin(PORTD,PIN6,&u8_DummyVar);
    if((ERROR_OK==u8_ERROR_STATE) && (PIN_LOW==u8_DummyVar)){
        printf("TEST 6-14 PASSED\n");
    }
    else{
        printf("TEST 6-14 FAILED\n");
    }
    TEST_RESET_PORT(PORTD);
    Set_Bit(PORTD_STAT, PIN5);
    u8_ERROR_STATE=DIO_readPin(PORTD,PIN5,&u8_DummyVar);
    if((ERROR_OK==u8_ERROR_STATE) && (PIN_HIGH==u8_DummyVar)){
        printf("TEST 6-15 PASSED\n");
    }
    else{
        printf("TEST 6-15 FAILED\n");
    }

}

