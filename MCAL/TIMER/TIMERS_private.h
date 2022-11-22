/**********************************************************/
/*           Author  : Asmaa Mohsen                       */
/*           Layer   : MCAL                               */
/*           Version : 1.00                               */
/*           SWC     : TIMERS                             */
/**********************************************************/

/*preprocessor header file guard*/
#ifndef TIMERS_PRIVATE_H_
#define TIMERS_PRIVATE_H_


/******************Bit masks*******************/
#define OC0_ACTION_MASK     0b11001111
#define PRESCALER_MASK      0b11111000

/*****************Private bits*****************/
//TIMER-COUNTER0
#define TCCR0_WGM0                 6  //two bits for mode of timer0
#define TCCR0_WGM1                 3
#define TCCR0_COM1                 5  //two bits for behavior of OC0 pin
#define TCCR0_COM0                 4

#define TIMSK_TOIE0                0  //timer0 over flow interrupt enable
#define TIMSK_OCIE0                1  //timer0 compare match interrupt enable

#define TIFR_TOV0                  0  //timer0 over flow interrupt flag
#define TIFR_OCF0                  1  //timer0 compare match interrupt flag

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


//TIMER-COUNTER2
#define TCCR2_WGM0                 6  //two bits for mode of timer2
#define TCCR2_WGM1                 3
#define TCCR2_COM0                 4  //two bits for behavior of OC2 pin
#define TCCR2_COM1                 5

#define TIMSK_OCIE2                7  //timer2 compare match interrupt enable
#define TIMSK_TOIE2                6  //timer2 over flow interrupt enable

#define TIFR_OCF2                  7  //timer2 output compare match flag
#define TIFR_TOV2                  6  //timer2 over flow flag



#endif /* TIMERS_PRIVATE_H_ */
