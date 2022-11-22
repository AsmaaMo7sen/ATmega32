/**********************************************************/
/*           Author  : Asmaa Mohsen                       */
/*           Layer   : MCAL                               */
/*           Version : 1.00                               */
/*           SWC     : PWM                                */
/**********************************************************/

/*preprocessor header file guard*/
#ifndef PWM_PRIVATE_H_
#define PWM_PRIVATE_H_

/******************private macros******************/
#define CLK_MASK     0b11111000
#define PRESCALER_8  2

/******************Private bits******************/

/************TIMER0**************/
#define TCCR0_WGM00                 6    //two bits for setting mode of TIMER/COUNTER0 to be FAST PWM
#define TCCR0_WGM01                 3

#define TCCR0_COM01                 5    //two bits for setting behavior of OC0 pin
#define TCCR0_COM00                 4

/************TIMER1**************/
#define TCCR1A_COM1A1               7    //two bits for setting behavior of OC1A pin
#define TCCR1A_COM1A0               6

#define TCCR1A_COM1B1               5    //two bits for setting behavior of OC1B pin
#define TCCR1A_COM1B0               4

#define TCCR1A_WGM11                1    //four bits for setting mode of TIMER/COUNTER1 to be PWM (mode no.14)
#define TCCR1A_WGM10                0

#define TCCR1B_WGM13                4
#define TCCR1B_WGM12                3




#endif /* PWM_PRIVATE_H_ */
