/**********************************************************/
/*           Author  : Asmaa Mohsen                       */
/*           Layer   : MCAL                               */
/*           Version : 1.00                               */
/*           SWC     : TIMER_DELAY                        */
/**********************************************************/

/*preprocessor header file guard*/
#ifndef TIMER_DELAY_REGISTER_H_
#define TIMER_DELAY_REGISTER_H_

/*****************TIMER/COUNTER1 registers*****************/
#define TIMER1_TCCR1A     *((volatile u8*)(0x4F))
#define TIMER1_TCCR1B     *((volatile u8*)(0x4E))
#define TIMER1_TCNT1      *((volatile u16*)(0x4C))
#define TIMER1_OCR1A      *((volatile u16*)(0x4A))
#define TIMER1_OCR1B      *((volatile u16*)(0x48))
#define TIMER1_ICR1       *((volatile u16*)(0x46))

#define TIMSK             *((volatile u8*)(0x59))
#define TIFR	          *((volatile u8*)(0x58))

#endif /* TIMER_DELAY_REGISTER_H_ */
