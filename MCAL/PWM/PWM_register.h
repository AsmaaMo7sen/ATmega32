/**********************************************************/
/*           Author  : Asmaa Mohsen                       */
/*           Layer   : MCAL                               */
/*           Version : 1.00                               */
/*           SWC     : PWM                                */
/**********************************************************/

/*preprocessor header file guard*/
#ifndef PWM_REGISTER_H_
#define PWM_REGISTER_H_


/*****************TIMER/COUNTER0 registers*****************/
#define TCCR0             *((volatile u8*)(0x53))
#define TCNT0             *((volatile u8*)(0x52))
#define OCR0              *((volatile u8*)(0x5C))


/*****************TIMER/COUNTER1 registers*****************/
#define TCCR1A            *((volatile u8*)(0x4F))
#define TCCR1B            *((volatile u8*)(0x4E))
#define TCNT1             *((volatile u16*)(0x4C))
#define OCR1A             *((volatile u16*)(0x4A))
#define OCR1B             *((volatile u16*)(0x48))
#define ICR1              *((volatile u16*)(0x46))
#define TIMSK             *((volatile u8*)(0x59))

#endif /* PWM_REGISTER_H_ */
