/**********************************************************/
/*           Author  : Asmaa Mohsen                       */
/*           Layer   : MCAL                               */
/*           Version : 1.00                               */
/*           SWC     : PWM                                */
/**********************************************************/

/*preprocessor header file guard*/
#ifndef PWM_INTERFACE_H_
#define PWM_INTERFACE_H_

/********************************************************************************/
/****************************Interfacing macros**********************************/
/********************************************************************************/

/**************************TIMER0 configurations*************************/
/*possible frequencies represented by value of prescaler to be set in clock select bits*/
#define FREQUENCY_31250      1      //T=32 us
#define FREQUENCY_3906       2		//T=256 us
#define FREQUENCY_488        3		//T=2048 us
#define FREQUENCY_122        4      //T=8129 us
#define FREQUENCY_30         5		//T=32768 us

/**************************TIMER1 configurations*************************/
/*possible channels*/
#define CHANNEL_A            1      //activating action of OC1A
#define CHANNEL_B            2      //activating action of OC1B

/*possible frequencies represented by values to be set on ICR1 register*/
#define FREQUENCY_1000       1000
#define FREQUENCY_500        2000
#define FREQUENCY_250        4000
#define FREQUENCY_200        5000
#define FREQUENCY_125        8000
#define FREQUENCY_100        10000
#define FREQUENCY_50         20000
#define FREQUENCY_40		 25000
#define FREQUENCY_25		 40000
#define FREQUENCY_20		 50000

/********************************************************************************/
/**************************Functions' prototype**********************************/
/********************************************************************************/

/*Description  :  this function is to initialize FAST PWM on TIMER/COUNTER0       */
/*Input        :  frequency of output signal					                  */
/*             :  Duty cycle for setting ON timer                                 */
/*Output       :  error indicator                                     			  */
/*Configuration:  post-build    								                  */
u8 PWM_u8InitTimer0( u16 Copy_u8Frequency , u8 Copy_u8DutyCycle);


/*Description  :  this function is to initialize FAST PWM on TIMER/COUNTER1       */
/*Input        :  output channel [channelA or channelB]			                  */
/*             :  frequency of output signal									  */
/*             :  Duty cycle for setting ON timer                                 */
/*Output       :  error indicator                                     			  */
/*Configuration:  post-build    								                  */
u8 PWM_u8InitTimer1(u8 Copy_u8Channel , u16 Copy_u8Frequency , u8 Copy_u8DutyCycle);


#endif /* PWM_INTERFACE_H_ */
