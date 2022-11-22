/**********************************************************/
/*           Author  : Asmaa Mohsen                       */
/*           Layer   : MCAL                               */
/*           Version : 1.00                               */
/*           SWC     : TIMERS                             */
/**********************************************************/

/*preprocessor header file guard*/
#ifndef TIMERS_INTERFACE_H_
#define TIMERS_INTERFACE_H_



/*struct for timer0 initialization configurations*/
typedef struct
{
	u8 Mode ;             //mode of TIMER0
	u8 OC0_action ;       //action of OC0 pin on interrupt
	u8 prescaler  ;       //prescaler value
	u8 Interrupt_enable ; //interrupt of timer0
}Timer0_t;

/*struct for timer1 initialization configurations*/
typedef struct
{
	u8 Mode ;             //mode of TIMER0
	u8 Channel ;          //channel A or B
	u8 OC1_action ;       //action of OC2 pin on interrupt
	u8 prescaler  ;       //prescaler value
	u8 Interrupt_enable ; //interrupt of timer2
}Timer1_t;


/*struct for timer2 initialization configurations*/
typedef struct
{
	u8 Mode ;             //mode of TIMER0
	u8 OC2_action ;       //action of OC2 pin on interrupt
	u8 prescaler  ;       //prescaler value
	u8 Interrupt_enable ; //interrupt of timer2
}Timer2_t;



/**********************************************************************************/
/*****************************Interfacing macros***********************************/
/**********************************************************************************/


//timer channels
//Set compare match function
#define TIMER0                          1
#define TIMER1                          2
#define TIMER2                          3

//timer1 channels
#define CHANNEL_A                       1
#define CHANNEL_B                       2

//action on OC0|OC1A|OC1B|OC2 pins on over flow or compare match
#define OC_DISCONNECTED         0      //OC pin disconnected
#define OC_TOGGLE               1      //toggle on compare match or over flow
#define OC_CLEAR                2      //clear on compare match or over flow
#define OC_SET                  3      //set on compare match or over flow

//timer0|2 interrupt sources state
#define TIMER_OVER_FLOW_INT_ENABLE                1   //enable over flow interrupt
#define TIMER_OVER_FLOW_INT_DISABLE               2   //disable over flow interrupt
#define TIMER_COMPARE_MATCH_INT_ENABLE            3   //enable compare match interrupt
#define TIMER_COMPARE_MATCH_INT_DISABLE           4   //disable compare match interrupt


//timer1 interrupt sources state
#define TIMER1_OVER_FLOW_INT_ENABLE                  1   //enable over flow interrupt
#define TIMER1_OVER_FLOW_INT_DISABLE                 2   //disable over flow interrupt
#define TIMER1_COMPARE_MATCH_A_INT_ENABLE            3   //enable compare match on channel A interrupt
#define TIMER1_COMPARE_MATCH_A_INT_DISABLE           4   //disable compare match on channel A interrupt
#define TIMER1_COMPARE_MATCH_B_INT_ENABLE            5   //enable compare match on channel B interrupt
#define TIMER1_COMPARE_MATCH_B_INT_DISABLE           6   //disable compare match on channel B interrupt

//timer 0 modes
//used in timer0 struct
#define TIMER0_NORMAL_MODE              1
#define TIMER0_COMPARE_MATCH_MODE       2

//timer 1 modes
//used in timer1 struct
#define TIMER1_NORMAL_MODE              1
#define TIMER1_COMPARE_MATCH_MODE       2

//timer 2 modes
//used in timer2 struct
#define TIMER2_NORMAL_MODE              1
#define TIMER2_COMPARE_MATCH_MODE       2


//timer0 clock prescaler values
//used in timer0 struct
#define TIMER0_NO_CLOCK                 0   //no input clock(stop peripheral)
#define TIMER0_NO_PRESCALER             1   //tick time = 1/8 us
#define TIMER0_PRESCALER_8              2   //tick time = 1 us
#define TIMER0_PRESCALER_64             3   //tick time = 8 us
#define TIMER0_PRESCALER_256            4   //tick time = 32 us
#define TIMER0_PRESCALER_1024           5   //tick time = 128 us
#define TIMER0_EXT_CLK_FALLING          6   //external clock on T0 pin , clock on falling edge
#define TIMER0_EXT_CLK_RISING           7   //external clock on T0 pin , clock on rising edge


//timer1 clock prescaler values
//used in timer1 struct
#define TIMER1_NO_CLOCK                 0   //no input clock(stop peripheral)
#define TIMER1_NO_PRESCALER             1   //tick time = 1/8 us
#define TIMER1_PRESCALER_8              2   //tick time = 1 us
#define TIMER1_PRESCALER_64             3   //tick time = 8 us
#define TIMER1_PRESCALER_256            4   //tick time = 32 us
#define TIMER1_PRESCALER_1024           5   //tick time = 128 us
#define TIMER1_EXT_CLK_FALLING          6   //external clock on T1 pin , clock on falling edge
#define TIMER1_EXT_CLK_RISING           7   //external clock on T1 pin , clock on rising edge


//timer2 clock prescaler values
//used in timer2 struct
#define TIMER2_NO_CLOCK                 0   //no input clock(stop peripheral)
#define TIMER2_NO_PRESCALER             1   //tick time = 1/8 us
#define TIMER2_PRESCALER_8              2   //tick time = 1 us
#define TIMER2_PRESCALER_32             3   //tick time = 4 us
#define TIMER2_PRESCALER_64             4   //tick time = 8 us
#define TIMER2_PRESCALER_128            5   //tick time = 16 us
#define TIMER2_PRESCALER_256            6   //tick time = 32 us
#define TIMER2_PRESCALER_1024           7   //tick time = 128 us


//interrupt sources of timer0
//used in set call back function
#define TIMER0_OVER_FLOW                  1
#define TIMER0_COMPARE_MATCH              2

//interrupt sources of timer1
//used in set call back function
#define TIMER1_OVER_FLOW                  3
#define TIMER1_COMPARE_MATCH_A            4
#define TIMER1_COMPARE_MATCH_B            5

//interrupt sources of timer2
//used in set call back function
#define TIMER2_OVER_FLOW                  6
#define TIMER2_COMPARE_MATCH              7


/**********************************************************************************/
/**************************Functions' prototypes***********************************/
/**********************************************************************************/


/*Description  :  this function is to initialize TIMER/COUNTER0       */
/*Input        :  pointer to struct of initialization configurations  */
/*Output       :  error indicator                                     */
/*Configuration:  post build	   		   				              */
u8 TIMER0_u8Init(Timer0_t * Copy_psInitPtr);

/*Description  :  this function is to initialize TIMER/COUNTER1       */
/*Input        :  pointer to struct of initialization configurations  */
/*Output       :  error indicator                                     */
/*Configuration:  post build	   		   				              */
u8 TIMER1_u8Init(Timer1_t * Copy_psInitPtr);

/*Description  :  this function is to initialize TIMER/COUNTER2       */
/*Input        :  pointer to struct of initialization configurations  */
/*Output       :  error indicator                                     */
/*Configuration:  post build	   		   				              */
u8 TIMER2_u8Init(Timer2_t * Copy_psInitPtr);


/*Description  :  this function is to stop TIMER/COUNTER0             */
/*Input        :  void												  */
/*Output       :  void				                                  */
void TIMER0_voidStopTimer(void);

/*Description  :  this function is to get counted value in TCNT1      */
/*Input        :  void												  */
/*Output       :  counted value in TCNT                               */
u16 TIMER1_u16GetValue(void);


/*Description  :  this function is to set compare match value         */
/*Input        :  compare match value to be set at OCR(0|2) register  */
/*             :  timer ID (timer0 | timer1 | timer2)                 */
/*Output       :  error indicator (value out of register range[0:255])*/
/*                                (wrong ID number)                   */
u8 TIMER_u8SetCompareMatchVal(u8 Copy_u8TimerID , u8 Copy_u8CompareMatchValue);

/*Description  :  this function is to set compare match value of timer1*/
/*Input        :  compare match value to be set at OCR1(A|B) register  */
/*             :  channel ID (channelA | channelB)                     */
/*Output       :  error indicator(value out of register range[0:65536])*/
/*                                (wrong ID number)                    */
u8 TIMER1_u8SetCompareMatch(u8 Copy_u8ChannelID , u16 Copy_u16CompareMatchValue);

/*Description  :  this function is to set call back		              */
/*Input        :  pointer to function  								  */
/*             :  interrupt source                                    */
/*Output       :  error indicator	                                  */
u8 TIMER_u8TimerSetCallBack(u8 Copy_u8Event , void(*ptrToFunc)(void));

/*Description  :  this function is to set a value in TCNT1            */
/*Input        :  value to be set   								  */
/*Output       :  error indicator	                                  */
u8 Timer1_u8SetValue(u16 Copy_u16Value);

#endif /* TIMERS_INTERFACE_H_ */
