#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TMR_DELAY_interface.h"
#include "TIMER_DELAY_register.h"
#include "TIMER_DELAY_private.h"
#include "TIMER_DELAY_config.h"

/*global pointer to function for call back*/
void (*GlobalPtrToFunc)(void) = NULL ;

/*global variable for periodicity*/
u8 Global_u8Periodicity = 0 ;
/*****************************************************************************************************/

u8 TIMER_u8DelayAsynch(u16 Copy_u16DelayInMs , void(*PtrToFunc)(void) ,u8 Copy_u8Preioicty )
{
	/*local variable for error checking*/
	u8 Local_u8ErrorState ;

	/*Both OC1A and OC1B pins are disconnected*/
	CLR_BIT(TIMER1_TCCR1A , TCCR1A_COM1A0) ;
	CLR_BIT(TIMER1_TCCR1A , TCCR1A_COM1A1) ;
	CLR_BIT(TIMER1_TCCR1A , TCCR1A_COM1B0) ;
	CLR_BIT(TIMER1_TCCR1A , TCCR1A_COM1B1) ;

	/*Setting Timer1 in compare match mode*/
	CLR_BIT(TIMER1_TCCR1A,TCCR1A_WGM10);
	CLR_BIT(TIMER1_TCCR1A,TCCR1A_WGM11);
	CLR_BIT(TIMER1_TCCR1B,TCCR1B_WGM13);
	SET_BIT(TIMER1_TCCR1B,TCCR1B_WGM12);

	/*assign value of OCR to get target delay*/
	TIMER1_OCR1A = ((u32)Copy_u16DelayInMs * 1000) / 128 ;

	/*valid range for input delay*/
	if(Copy_u16DelayInMs>=0 && Copy_u16DelayInMs<=8380)
	{
		 /*assign value of OCR to get target delay*/
		 TIMER1_OCR1A = ((u32)Copy_u16DelayInMs * 1000) / 128 ;
	}
	else
	{
		Local_u8ErrorState = OUT_OF_RANGE ;
	}

	/*assign periodicity configuration to the global variable*/
	Global_u8Periodicity = Copy_u8Preioicty ;

	/*Setting call back*/
	if(PtrToFunc != NULL)
	{
		GlobalPtrToFunc = PtrToFunc ;
	}
	else
	{
		Local_u8ErrorState = NULL_POINTER ;
	}


	/*setting prescaler to run timer1 with tick time = 128 us*/
	TIMER1_TCCR1B &= CLK_MASK ;
	TIMER1_TCCR1B |= PRESCALER_1024 ;

	/*return from this function*/
	return Local_u8ErrorState ;
}



u8 TIMER_u8DelaySynch(u16 Copy_u16DelayInMs )
{
	/*local variable for error checking*/
	u8 Local_u8ErrorState ;

	/*Both OC1A and OC1B pins are disconnected*/
	CLR_BIT(TIMER1_TCCR1A , TCCR1A_COM1A0) ;
	CLR_BIT(TIMER1_TCCR1A , TCCR1A_COM1A1) ;
	CLR_BIT(TIMER1_TCCR1A , TCCR1A_COM1B0) ;
	CLR_BIT(TIMER1_TCCR1A , TCCR1A_COM1B1) ;

	/*Setting Timer1 in compare match mode*/
	CLR_BIT(TIMER1_TCCR1A,TCCR1A_WGM10);
	CLR_BIT(TIMER1_TCCR1A,TCCR1A_WGM11);
	CLR_BIT(TIMER1_TCCR1B,TCCR1B_WGM13);
	SET_BIT(TIMER1_TCCR1B,TCCR1B_WGM12);

	/*enable compare match interrupt*/
	CLR_BIT(TIMSK , TIMSK_OCIE1A) ;

	/*valid range for input delay*/
	if(Copy_u16DelayInMs>=0 && Copy_u16DelayInMs<=8380)
	{
		 /*assign value of OCR to get target delay*/
		 TIMER1_OCR1A = ((u32)Copy_u16DelayInMs * 1000) / 128 ;
	}
	else
	{
		Local_u8ErrorState = OUT_OF_RANGE ;
	}

	/*setting prescaler to run timer1 with tick time = 128 us*/
	TIMER1_TCCR1B &= CLK_MASK ;
	TIMER1_TCCR1B |= PRESCALER_1024 ;

	/*polling till end of delay period*/
	while((GET_BIT(TIFR , TIFR_OCF1A))==0);

	/*clearing compare match flag*/
	SET_BIT(TIFR , TIFR_OCF1A);

	/*stopping timer*/
	TIMER1_TCCR1B &= CLK_MASK ;
	TIMER1_TCCR1B |= NO_CLK ;


	/*return from this function*/
	return Local_u8ErrorState ;
}

/*ISR for compare match on timer 1 channel A*/
void __vector_7 (void) __attribute__((signal));
void __vector_7 (void)
{
	if(Global_u8Periodicity == PERIODIC)
	{
		/*running target application*/
		GlobalPtrToFunc();
		/*do nothing as prescaler value didn't change*/
	}
	else if(Global_u8Periodicity == NON_PERIODIC)
	{
		/*running target application*/
		GlobalPtrToFunc();

		/*stopping timer*/
		TIMER1_TCCR1B &= CLK_MASK ;
		TIMER1_TCCR1B |= NO_CLK ;
	}
}
