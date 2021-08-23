#ifndef TIMER_REG_H_
#define TIMER_REG_H_

//Timer0 Registers
#if 0
#define TCNT0     *( ( volatile uint8_t* ) 0x52 )
#define OCR0      *( ( volatile uint8_t* ) 0x5C )
#define TCCR0     *( ( volatile uint8_t* ) 0x53 )

//Timer1 Registers
#define TCNT1     *( ( volatile uint16_t* ) 0x4C )
#define OCR1A     *( ( volatile uint16_t* ) 0x4A )
#define OCR1B     *( ( volatile uint16_t* ) 0x48 )
#define ICR1      *( ( volatile uint16_t* ) 0x46 )
#define TCCR1A    *( ( volatile uint8_t* )  0x4F )
#define TCCR1B    *( ( volatile uint8_t* )  0x4E )

//Timer2 Registers
#define TCCR2     *( ( volatile uint8_t* ) 0x45 )
#define TCNT2     *( ( volatile uint8_t* ) 0x44 )
#define OCR2      *( ( volatile uint8_t* ) 0x43 )
#define ASSR      *( ( volatile uint8_t* ) 0x42 )

//Timers interrupt registers
#define TIMSK     *( ( volatile uint8_t* ) 0x59 )
#define TIFR      *( ( volatile uint8_t* ) 0x58 )
#endif // 0
extern uint8_t TCNT0;
extern uint8_t OCR0;
extern uint8_t TCCR0;

extern uint16_t TCNT1;
extern uint16_t OCR1A;
extern uint16_t OCR1B;
extern uint16_t ICR1;
extern uint8_t TCCR1A;
extern uint8_t TCCR1B;

extern uint8_t TCCR2;
extern uint8_t TCNT2;
extern uint8_t OCR2;
extern uint8_t ASSR;
extern uint8_t TIMSK;
extern uint8_t TIFR;
#endif /*TIMER_REG_H_*/
