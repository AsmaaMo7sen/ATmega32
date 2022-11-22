#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TIMERS_interface.h"
#include "TIMERS_registers.h"
#include "TIMERS_private.h"
#include "TIMERS_config.h"

/**************************************************************************************/
/*********************************Global variables*************************************/
/**************************************************************************************/

/*Global pointer to function to set call back*/
void(*overFlow0ptr)(void) = NULL ;          //global pointer to function for timer0 over flow ISR
void(*compareMatch0ptr)(void) = NULL ;      //global pointer to function for timer0 compare match ISR

void(*overFlow1ptr)(void) = NULL ;          //global pointer to function for timer1 over flow ISR
void(*compareMatch1Aptr)(void) = NULL ;     //global pointer to function for timer1 channel A compare match ISR
void(*compareMatch1Bptr)(void) = NULL ;     //global pointer to function for timer1 channel b compare match ISR

void(*overFlow2ptr)(void) = NULL ;          //global pointer to function for timer2 over flow ISR
void(*compareMatch2ptr)(void) = NULL ;      //global pointer to function for timer2 compare match ISR




/**************************************************************************************/
/*****************************Functions' implementation********************************/
/**************************************************************************************/


u8 TIMER0_u8Init(Timer0_t * Copy_psInitPtr)
{
	/*resetting TCCR0 register*/
	TIMER0_TCCR0 = 0 ;

	/*local variable for error checking*/
	u8 Local_u8ErrorState = OK ;

/********************************Setting mode of timer0********************************/

	/*checking for correct input of timer mode*/
	if(Copy_psInitPtr->Mode == TIMER0_NORMAL_MODE || Copy_psInitPtr->Mode == TIMER0_COMPARE_MATCH_MODE )
	{
		/*switching over timer modes*/
		switch(Copy_psInitPtr->Mode)
		{
			//in case of normal mode(over flow mode)
			case TIMER0_NORMAL_MODE :
				CLR_BIT(TIMER0_TCCR0 , TCCR0_WGM0);
				CLR_BIT(TIMER0_TCCR0 , TCCR0_WGM1);
				break ;

			//in case of compare match mode
			case TIMER0_COMPARE_MATCH_MODE:
				CLR_BIT(TIMER0_TCCR0 , TCCR0_WGM0);
				SET_BIT(TIMER0_TCCR0 , TCCR0_WGM1);
				break ;

			default :
				/*do nothing*/
				break ;
		}
	}
	/*in case of wrong input of timer mode*/
	else
	{
		Local_u8ErrorState = NOK ;
	}

/********************************Setting action of OC0 pin*****************************************/

	/*checking for correct input of OC0 action*/
	if(((Copy_psInitPtr->OC0_action)>= OC_DISCONNECTED) && ((Copy_psInitPtr->OC0_action) <=OC_SET))
	{
		TIMER0_TCCR0 &= OC0_ACTION_MASK ;                    //clearing OC0 bits to receive new values
		TIMER0_TCCR0 |= ((Copy_psInitPtr->OC0_action)<<4) ;  //setting action of OC0 pin
	}

	/*in case of wrong input of OC0 action*/
	else
	{
		Local_u8ErrorState = NOK ;
	}

/*******************************Setting interrupt****************************************/

	/*checking for correct input of interrupt status*/
	if(((Copy_psInitPtr->Interrupt_enable)>=TIMER_OVER_FLOW_INT_ENABLE) &&((Copy_psInitPtr->Interrupt_enable)<=TIMER_COMPARE_MATCH_INT_DISABLE))
	{
		/*switching over interrupt states for timer0*/
		switch(Copy_psInitPtr->Interrupt_enable)
		{
			case TIMER_OVER_FLOW_INT_ENABLE     : SET_BIT(TIMSK , TIMSK_TOIE0); break ; //enable over flow interrupt
			case TIMER_OVER_FLOW_INT_DISABLE    : CLR_BIT(TIMSK , TIMSK_TOIE0); break ; //disable over flow interrupt
			case TIMER_COMPARE_MATCH_INT_ENABLE : SET_BIT(TIMSK , TIMSK_OCIE0); break ; //enable compare match interrupt
			case TIMER_COMPARE_MATCH_INT_DISABLE: CLR_BIT(TIMSK , TIMSK_OCIE0); break ; //disable compare match interrupt
			default : /*do nothing*/                                  break ;
		}
	}

	/*in case of wrong input of interrupt status*/
	else
	{
		Local_u8ErrorState = NOK ;
	}

/********************************Setting prescaler*********************************/

	/*checking for correct input for prescaler*/
	if(((Copy_psInitPtr->prescaler) >= TIMER0_NO_PRESCALER) && ((Copy_psInitPtr->prescaler)<= TIMER0_EXT_CLK_RISING))
	{
		TIMER0_TCCR0 &= PRESCALER_MASK ;             //clearing clock select bits to receive new values
		TIMER0_TCCR0 |= Copy_psInitPtr->prescaler ;  //setting prescaler to run the timer
	}

	/*in case of wrong input of prescaler*/
	else
	{
		Local_u8ErrorState = NOK ;
	}

	/*return from this function*/
	return Local_u8ErrorState ;
}

/*********************************************************************************************************/
/*********************************************************************************************************/

u8 TIMER1_u8Init(Timer1_t * Copy_psInitPtr)
{
	TIMER1_TCCR1A = 0;
	TIMER1_TCCR1B = 0;

	/*local variable for error checking*/
	u8 Local_u8ErrorState =OK ;

	/********************************Setting mode of timer1********************************/

	/*checking for correct input of timer mode*/
	if(Copy_psInitPtr->Mode == TIMER1_NORMAL_MODE || Copy_psInitPtr->Mode == TIMER1_COMPARE_MATCH_MODE)
	{
		switch(Copy_psInitPtr->Mode)
		{
			/*in case of normal(over flow)mode*/
			case TIMER1_NORMAL_MODE :
				CLR_BIT(TIMER1_TCCR1A,TCCR1A_WGM10);
				CLR_BIT(TIMER1_TCCR1A,TCCR1A_WGM11);
				CLR_BIT(TIMER1_TCCR1B,TCCR1B_WGM13);
				CLR_BIT(TIMER1_TCCR1B,TCCR1B_WGM12);
				break ;

			/*in case of compare match mode*/
			case TIMER1_COMPARE_MATCH_MODE :
				CLR_BIT(TIMER1_TCCR1A,TCCR1A_WGM10);
				CLR_BIT(TIMER1_TCCR1A,TCCR1A_WGM11);
				CLR_BIT(TIMER1_TCCR1B,TCCR1B_WGM13);
				SET_BIT(TIMER1_TCCR1B,TCCR1B_WGM12);
				break ;

			default :
				/*do nothing*/
				break ;
		}
	}

	/*in case of wrong input of timer mode*/
	else
	{
		Local_u8ErrorState = NOK ;
	}

	/********************************Setting action of OC1 pin*****************************************/

	if(Copy_psInitPtr->Channel == CHANNEL_A || Copy_psInitPtr->Channel == CHANNEL_B)
	{
		/*switching over channels*/
		switch(Copy_psInitPtr->Channel)
		{
		case CHANNEL_A :

			/*switching over actions of OC1 A */
			switch(Copy_psInitPtr->OC1_action)
			{
				case OC_DISCONNECTED :                       //OC1A disconnected
					CLR_BIT(TIMER1_TCCR1A,TCCR1A_COM1A0);
					CLR_BIT(TIMER1_TCCR1A,TCCR1A_COM1A1);
						break ;
				case OC_TOGGLE :                             //OC1A toggle on over flow or compare match
					SET_BIT(TIMER1_TCCR1A,TCCR1A_COM1A0);
					CLR_BIT(TIMER1_TCCR1A,TCCR1A_COM1A1);
						break ;

				case OC_CLEAR :                             //OC1A clear on over flow or compare match
					SET_BIT(TIMER1_TCCR1A,TCCR1A_COM1A1);
					CLR_BIT(TIMER1_TCCR1A,TCCR1A_COM1A0);
						break ;

				case OC_SET :                               //OC1A set on over flow or compare match
					SET_BIT(TIMER1_TCCR1A,TCCR1A_COM1A1);
					SET_BIT(TIMER1_TCCR1A,TCCR1A_COM1A0);
						break ;

				default :
					Local_u8ErrorState = NOK ;
					break ;

			}
			/*breaking from case of channel A*/
			break ;

	  case CHANNEL_B :

			/*switching over actions of OC1 A */
			switch(Copy_psInitPtr->OC1_action)
			{
				case OC_DISCONNECTED :                       //OC1A disconnected
					CLR_BIT(TIMER1_TCCR1A,TCCR1A_COM1B0);
					CLR_BIT(TIMER1_TCCR1A,TCCR1A_COM1B1);
						break ;
				case OC_TOGGLE :                             //OC1A toggle on over flow or compare match
					SET_BIT(TIMER1_TCCR1A,TCCR1A_COM1B0);
					CLR_BIT(TIMER1_TCCR1A,TCCR1A_COM1B1);
						break ;

				case OC_CLEAR :                             //OC1A clear on over flow or compare match
					SET_BIT(TIMER1_TCCR1A,TCCR1A_COM1B1);
					CLR_BIT(TIMER1_TCCR1A,TCCR1A_COM1B0);
						break ;

				case OC_SET :                               //OC1A set on over flow or compare match
					SET_BIT(TIMER1_TCCR1A,TCCR1A_COM1B1);
					SET_BIT(TIMER1_TCCR1A,TCCR1A_COM1B0);
						break ;

				default :
					Local_u8ErrorState = NOK ;
					break ;

			}
			/*breaking from case of channel B*/
			break ;

			default :
				/*do nothing*/
				break ;
		}
	}

	/*in case of wrong input for timer1 channel*/
	else
	{
		Local_u8ErrorState = NOK ;
	}

	/*******************************Setting interrupt****************************************/

	/*checking for correct input of interrupt state*/
	if(Copy_psInitPtr->Interrupt_enable >= TIMER1_OVER_FLOW_INT_ENABLE && Copy_psInitPtr->Interrupt_enable <=TIMER1_COMPARE_MATCH_B_INT_DISABLE)
	{
		/*switching over interrupt states*/
		switch(Copy_psInitPtr->Interrupt_enable)
		{
			case TIMER1_OVER_FLOW_INT_ENABLE        : SET_BIT(TIMSK , TIMSK_TOIE1); break ;
			case TIMER1_OVER_FLOW_INT_DISABLE       : CLR_BIT(TIMSK , TIMSK_TOIE1); break ;
			case TIMER1_COMPARE_MATCH_A_INT_ENABLE  : SET_BIT(TIMSK , TIMSK_OCIE1A); break ;
			case TIMER1_COMPARE_MATCH_A_INT_DISABLE : CLR_BIT(TIMSK , TIMSK_OCIE1A); break ;
			case TIMER1_COMPARE_MATCH_B_INT_ENABLE  : SET_BIT(TIMSK , TIMSK_OCIE1B); break ;
			case TIMER1_COMPARE_MATCH_B_INT_DISABLE : CLR_BIT(TIMSK , TIMSK_OCIE1B); break ;
			default : /*do nothing*/                                  break ;
		}
	}

	/*in case of wrong input for timer1 interrupt state*/
	else
	{
		Local_u8ErrorState = NOK ;
	}

	/********************************Setting prescaler*********************************/

	/*checking for correct input of timer1 prescaler*/
	if(Copy_psInitPtr->prescaler >=TIMER1_NO_CLOCK && Copy_psInitPtr->prescaler<=TIMER1_EXT_CLK_RISING)
	{
		TIMER1_TCCR1B &= PRESCALER_MASK ;                     //clearing clock select bits to receive new values
		TIMER1_TCCR1B |= (Copy_psInitPtr->prescaler) ;        //setting prescaler to run the timer
	}

	/*in case of wrong input for timer1 prescaler*/
	else
	{
		Local_u8ErrorState = NOK ;
	}

	/*****************************End Of Initialization******************************/

	/*return from this function*/
	return Local_u8ErrorState ;
}


/*********************************************************************************************************/
/*********************************************************************************************************/

u8 TIMER2_u8Init(Timer2_t * Copy_psInitPtr)
{
	/*resetting TCCR0 register*/
		TIMER2_TCCR2 = 0 ;

		/*local variable for error checking*/
		u8 Local_u8ErrorState = OK ;

	/********************************Setting mode of timer2********************************/

		/*checking for correct input of timer mode*/
		if(Copy_psInitPtr->Mode == TIMER2_NORMAL_MODE || Copy_psInitPtr->Mode == TIMER2_COMPARE_MATCH_MODE )
		{
			/*switching over timer modes*/
			switch(Copy_psInitPtr->Mode)
			{
				//in case of normal mode(over flow mode)
				case TIMER2_NORMAL_MODE :
					CLR_BIT(TIMER2_TCCR2 , TCCR2_WGM0);
					CLR_BIT(TIMER2_TCCR2 , TCCR2_WGM1);
					break ;

				//in case of compare match mode
				case TIMER2_COMPARE_MATCH_MODE:
					CLR_BIT(TIMER2_TCCR2 , TCCR2_WGM0);
					SET_BIT(TIMER2_TCCR2 , TCCR2_WGM1);
					break ;

				default :
					/*do nothing*/
					break ;
			}
		}
		/*in case of wrong input of timer mode*/
		else
		{
			Local_u8ErrorState = NOK ;
		}

	/********************************Setting action of OC0 pin*****************************************/

		/*checking for correct input of OC0 action*/
		if(((Copy_psInitPtr->OC2_action)>= OC_DISCONNECTED) && ((Copy_psInitPtr->OC2_action) <=OC_SET))
		{
			TIMER2_TCCR2 &= OC0_ACTION_MASK ;                    //clearing OC0 bits to receive new values
			TIMER2_TCCR2 |= ((Copy_psInitPtr->OC2_action)<<4) ;  //setting action of OC0 pin
		}

		/*in case of wrong input of OC0 action*/
		else
		{
			Local_u8ErrorState = NOK ;
		}

	/*******************************Setting interrupt****************************************/

		/*checking for correct input of interrupt status*/
		if(((Copy_psInitPtr->Interrupt_enable)>=TIMER_OVER_FLOW_INT_ENABLE) &&((Copy_psInitPtr->Interrupt_enable)<=TIMER_COMPARE_MATCH_INT_DISABLE))
		{
			/*switching over interrupt states for timer0*/
			switch(Copy_psInitPtr->Interrupt_enable)
			{
				case TIMER_OVER_FLOW_INT_ENABLE     : SET_BIT(TIMSK , TIMSK_TOIE2); break ; //enable over flow interrupt
				case TIMER_OVER_FLOW_INT_DISABLE    : CLR_BIT(TIMSK , TIMSK_TOIE2); break ; //disable over flow interrupt
				case TIMER_COMPARE_MATCH_INT_ENABLE : SET_BIT(TIMSK , TIMSK_OCIE2); break ; //enable compare match interrupt
				case TIMER_COMPARE_MATCH_INT_DISABLE: CLR_BIT(TIMSK , TIMSK_OCIE2); break ; //disable compare match interrupt
				default : /*do nothing*/                                  break ;
			}
		}

		/*in case of wrong input of interrupt status*/
		else
		{
			Local_u8ErrorState = NOK ;
		}

	/********************************Setting prescaler*********************************/

		/*checking for correct input for prescaler*/
		if(((Copy_psInitPtr->prescaler) >= TIMER2_NO_PRESCALER) && ((Copy_psInitPtr->prescaler)<= TIMER2_PRESCALER_1024))
		{
			TIMER2_TCCR2 &= PRESCALER_MASK ;             //clearing clock select bits to receive new values
			TIMER2_TCCR2 |= Copy_psInitPtr->prescaler ;  //setting prescaler to run the timer
		}

		/*in case of wrong input of prescaler*/
		else
		{
			Local_u8ErrorState = NOK ;
		}

		/*return from this function*/
		return Local_u8ErrorState ;

}

/*********************************************************************************************************/
/*********************************************************************************************************/

u8 TIMER_u8TimerSetCallBack(u8 Copy_u8Event , void(*ptrToFunc)(void))
{
	/*local variable for error checking*/
	u8 Local_u8ErrorState = OK ;

	if(ptrToFunc != NULL)
	{
		switch(Copy_u8Event)
			{
			case TIMER0_OVER_FLOW       : overFlow0ptr = ptrToFunc ; break ;
			case TIMER0_COMPARE_MATCH   : compareMatch0ptr = ptrToFunc ; break ;
			case TIMER1_OVER_FLOW       : overFlow1ptr = ptrToFunc ; break ;
			case TIMER1_COMPARE_MATCH_A : compareMatch1Aptr = ptrToFunc ; break ;
			case TIMER1_COMPARE_MATCH_B : compareMatch1Bptr = ptrToFunc ; break ;
			case TIMER2_OVER_FLOW       : overFlow2ptr = ptrToFunc ; break ;
			case TIMER2_COMPARE_MATCH   : compareMatch2ptr = ptrToFunc ; break ;
			}
	}
	else
	{
		Local_u8ErrorState = NULL_POINTER ;
	}
	/*return from this function*/
	return Local_u8ErrorState ;
}

/*********************************************************************************************************/
/*********************************************************************************************************/

u8 TIMER_u8SetCompareMatchVal(u8 Copy_u8TimerID , u8 Copy_u8CompareMatchValue)
{
	/*local variable for error checking*/
	u8 Local_u8ErrorState = OK ;
if(Copy_u8TimerID == TIMER0 || Copy_u8TimerID == TIMER2)
{
	/*possible input range*/
	if(Copy_u8CompareMatchValue>=0 && Copy_u8CompareMatchValue<=255)
	{
		switch(Copy_u8TimerID)
			{
				case TIMER0 :  TIMER0_OCR0 = Copy_u8CompareMatchValue ;  break ;
				case TIMER2 :  TIMER2_OCR2 = Copy_u8CompareMatchValue ;  break ;
				default     :  /*do nothing */                           break ;
			}
	}

	/*in case of input value out of OCR0 register*/
	else
	{
		Local_u8ErrorState = OUT_OF_RANGE ;
	}
}
//in case of wrong input of timer ID
else
{
	Local_u8ErrorState= WRONG_ID;
}
	/*return from this function*/
	return Local_u8ErrorState ;
}

/*********************************************************************************************************/
/*********************************************************************************************************/

u8 TIMER1_u8SetCompareMatch(u8 Copy_u8ChannelID , u16 Copy_u16CompareMatchValue)
{
	/*local variable for error checking*/
	u8 Local_u8ErrorState = OK ;

	/*checking for valid range of compare match value*/
	if((Copy_u16CompareMatchValue>=0) && (Copy_u16CompareMatchValue<=65536) )
	{
		switch(Copy_u8ChannelID)
		{
			case CHANNEL_A : TIMER1_OCR1A = Copy_u16CompareMatchValue ; break ;
			case CHANNEL_B : TIMER1_OCR1B = Copy_u16CompareMatchValue ; break ;
			default : Local_u8ErrorState= WRONG_ID ; break ;
		}
	}

	else
	{
		Local_u8ErrorState= OUT_OF_RANGE ;
	}

	/*return from this function*/
	return Local_u8ErrorState ;
}


/*********************************************************************************************************/
/*********************************************************************************************************/

void TIMER0_voidStopTimer(void)
{
	TIMER0_TCNT0 = 0 ;
	TIMER0_OCR0  = 0 ;
	TIMER0_TCCR0 = 0 ;  //clearing prescaler bits
}

/*********************************************************************************************************/
/*********************************************************************************************************/

u8 Timer1_u8SetValue(u16 Copy_u16Value)
{
	/*local variable for error checking*/
	u8 Local_u8ErrorState = OK ;

	/*checking for valid input value*/
	if(Copy_u16Value>=0&&Copy_u16Value<=65536)
	{
		TIMER1_TCNT1 = Copy_u16Value ;
	}
	else
	{
		Local_u8ErrorState = NOK ;
	}

	/*return from this function*/
	return Local_u8ErrorState ;
	}

/*********************************************************************************************************/
/*********************************************************************************************************/

u16 TIMER1_u16GetValue(void)
{
	return TIMER1_TCNT1 ;
}


/*********************************************************************************************************/
/*********************************************************************************************************/

/*ISR for compare match event on timer0*/
void __vector_10 (void) __attribute__((signal));
void __vector_10 (void)
{
	compareMatch0ptr();
}

/*********************************************************************************************************/
/*********************************************************************************************************/

/*ISR for over flow event on timer0*/
void __vector_11 (void) __attribute__((signal));
void __vector_11 (void)
{
	overFlow0ptr();
}

/*********************************************************************************************************/
/*********************************************************************************************************/

/*ISR for compare match event on timer2*/
void __vector_4 (void) __attribute__((signal));
void __vector_4 (void)
{
	compareMatch2ptr();
}

/*********************************************************************************************************/
/*********************************************************************************************************/

/*ISR for over flow event on timer2*/
void __vector_5 (void) __attribute__((signal));
void __vector_5 (void)
{
	overFlow2ptr();
}

/*********************************************************************************************************/
/*********************************************************************************************************/

/*ISR for compare match on timer 1 channel A*/
void __vector_7 (void) __attribute__((signal));
void __vector_7 (void)
{
	compareMatch1Aptr();
}

/*********************************************************************************************************/
/*********************************************************************************************************/

/*ISR for compare match on timer 1 channel B*/
void __vector_8 (void) __attribute__((signal));
void __vector_8 (void)
{
	compareMatch1Bptr();
}

/*********************************************************************************************************/
/*********************************************************************************************************/

/*ISR for over flow on timer 1 */
void __vector_9 (void) __attribute__((signal));
void __vector_9 (void)
{
	overFlow1ptr();
}






