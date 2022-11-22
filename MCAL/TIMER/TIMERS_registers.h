/**********************************************************/
/*           Author  : Asmaa Mohsen                       */
/*           Layer   : MCAL                               */
/*           Version : 1.00                               */
/*           SWC     : TIMERS                             */
/**********************************************************/

/*preprocessor header file guard*/
#ifndef TIMERS_REGISTERS_H_
#define TIMERS_REGISTERS_H_

/*****************TIMER/COUNTER0 registers*****************/
#define TIMER0_TCCR0      *((volatile u8*)(0x53))
#define TIMER0_TCNT0      *((volatile u8*)(0x52))
#define TIMER0_OCR0       *((volatile u8*)(0x5C))

/*****************TIMER/COUNTER1 registers*****************/
#define TIMER1_TCCR1A     *((volatile u8*)(0x4F))
#define TIMER1_TCCR1B     *((volatile u8*)(0x4E))
#define TIMER1_TCNT1      *((volatile u16*)(0x4C))
#define TIMER1_OCR1A      *((volatile u16*)(0x5A))
#define TIMER1_OCR1B      *((volatile u16*)(0x48))
#define TIMER1_ICR1       *((volatile u16*)(0x46))


/*****************TIMER/COUNTER2 registers*****************/
#define TIMER2_TCCR2      *((volatile u8*)(0x45))
#define TIMER2_TCNT2      *((volatile u8*)(0x44))
#define TIMER2_OCR2       *((volatile u8*)(0x43))


/*****************Shared registers*************************/
#define TIMSK             *((volatile u8*)(0x59))
#define TIFR	          *((volatile u8*)(0x58))

#endif /* TIMERS_REGISTERS_H_ */
