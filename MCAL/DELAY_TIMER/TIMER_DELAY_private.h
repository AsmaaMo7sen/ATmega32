/**********************************************************/
/*           Author  : Asmaa Mohsen                       */
/*           Layer   : MCAL                               */
/*           Version : 1.00                               */
/*           SWC     : TIMER_DELAY                        */
/**********************************************************/

/*preprocessor header file guard*/
#ifndef TIMER_DELAY_PRIVATE_H_
#define TIMER_DELAY_PRIVATE_H_

#define CLK_MASK                   0b11111000
#define NO_CLK                     0
#define PRESCALER_1024             5

//TIMER-COUNTER1
#define TCCR1A_COM1A1              7  //two bits for behavior of OC1A pin
#define TCCR1A_COM1A0              6

#define TCCR1A_COM1B1              5  //two bits for behavior of OC1B pin
#define TCCR1A_COM1B0              4

#define TCCR1A_WGM11               1  //for bits for mode of timer1
#define TCCR1A_WGM10               0
#define TCCR1B_WGM13               4
#define TCCR1B_WGM12               3

#define TIMSK_OCIE1A               4  //timer1 output compare channel A interrupt enable
#define TIMSK_OCIE1B               3  //timer1 output compare channel B interrupt enable
#define TIMSK_TOIE1                2  //timer1 over flow interrupt enable

#define TIFR_OCF1A                 4  //compare match channelA flag

#endif /* TIMER_DELAY_PRIVATE_H_ */
