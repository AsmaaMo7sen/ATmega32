#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GIE_interface.h"
#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_register.h"
#include "EXTI_config.h"

/************************Global variables*************************/

void(*EXTI_pvIsr0)(void) = NULL ;      //Pointer to function to execute call back for ISR0
void(*EXTI_pvIsr1)(void) = NULL ;		//Pointer to function to execute call back for ISR1
void(*EXTI_pvIsr2)(void) = NULL ;		//Pointer to function to execute call back for ISR2

/************************Functions' implementation************************/

u8 EXTI_u8SetSenseSignal(u8 Copy_u8InterruptNumber,u8 Copy_u8SenseSignal)
{
	u8 Local_u8ErrorState = 0 ;          //local variable for error detection


		/*switching over interrupt sources*/
		switch(Copy_u8InterruptNumber)
		{
		 	/*in case of external interrupt 0*/
			case EXTI_INT0 :

				switch(Copy_u8SenseSignal)  //switching over sense signals
				{

				case EXTI_u8FALLING_EDGE:         //in case of falling edge
					SET_BIT(EXTI_MCUCR,EXTI_ISC01);
					CLR_BIT(EXTI_MCUCR,EXTI_ISC00);
					break ;

				case EXTI_u8RISING_EDGE:         //in case of rising edge
					SET_BIT(EXTI_MCUCR,EXTI_ISC01);
					SET_BIT(EXTI_MCUCR,EXTI_ISC00);
					break ;

				case EXTI_u8LOW_LEVEL:           //in case of low level
					CLR_BIT(EXTI_MCUCR,EXTI_ISC01);
					CLR_BIT(EXTI_MCUCR,EXTI_ISC00);
					break ;

				case EXTI_u8ON_CHANGE:          //in case of high level
					CLR_BIT(EXTI_MCUCR,EXTI_ISC01);
					SET_BIT(EXTI_MCUCR,EXTI_ISC00);
					break ;

				default :
					Local_u8ErrorState = 1 ;
					break ;
				}

				break ;                 //break from external interrupt 0

		/********************************************************************/

			/*in case of external interrupt 1*/
			case EXTI_INT1 :
				switch(Copy_u8SenseSignal)  //switching over sense signals
				{

				case EXTI_u8FALLING_EDGE:         //in case of falling edge
					SET_BIT(EXTI_MCUCR,EXTI_ISC11);
					CLR_BIT(EXTI_MCUCR,EXTI_ISC10);
					break ;

				case EXTI_u8RISING_EDGE:         //in case of rising edge
					SET_BIT(EXTI_MCUCR,EXTI_ISC11);
					SET_BIT(EXTI_MCUCR,EXTI_ISC10);
					break ;

				case EXTI_u8LOW_LEVEL:           //in case of low level
					CLR_BIT(EXTI_MCUCR,EXTI_ISC11);
					CLR_BIT(EXTI_MCUCR,EXTI_ISC10);
					break ;

				case EXTI_u8ON_CHANGE:          //in case of high level
					CLR_BIT(EXTI_MCUCR,EXTI_ISC11);
					SET_BIT(EXTI_MCUCR,EXTI_ISC10);
					break ;

				default :
					Local_u8ErrorState = 1 ;
					break ;
				}

				break ;                 //break from external interrupt 1

		/********************************************************************/

			/*in case of external interrupt 2*/
			case EXTI_INT2 :
				switch(Copy_u8SenseSignal)  //switching over sense signals
				{

				case EXTI_u8FALLING_EDGE:         //in case of falling edge
					CLR_BIT(EXTI_MCUCSR,EXTI_ISC2);
					break ;

				case EXTI_u8RISING_EDGE:         //in case of rising edge
					SET_BIT(EXTI_MCUCSR,EXTI_ISC2);
					break ;


				default :
					Local_u8ErrorState = 1 ;
					break ;
				}

				break ;                 //break from external interrupt 2

		/********************************************************************/

			default :
				Local_u8ErrorState = 1 ;
				break ;
		}

	return Local_u8ErrorState ;         //return from this function
}

/***************************************************************************************************************/

u8 EXTI_voidEnableInt(u8 Copy_u8InterruptNumber)
{
	u8 Local_u8ErrorState = 0 ;          //local variable for error detection

	switch(Copy_u8InterruptNumber)       //switching over interrupts
	{
		case EXTI_INT0 :
			SET_BIT(EXTI_GICR,EXTI_INT0_ENABLE);      //enabling INT0
			break ;

		case EXTI_INT1 :
			SET_BIT(EXTI_GICR,EXTI_INT1_ENABLE);      //enabling INT1
			break ;

		case EXTI_INT2 :
			SET_BIT(EXTI_GICR,EXTI_INT2_ENABLE);      //enabling INT2
			break ;

		default :                                     //in case of wrong input argument
			Local_u8ErrorState = 1 ;
			break ;

	}
		return Local_u8ErrorState ;         //return from this function
}

/***************************************************************************************************************/

u8 EXTI_voidDisableInt(u8 Copy_u8InterruptNumber)
{
	u8 Local_u8ErrorState = 0 ;          //local variable for error detection

	switch(Copy_u8InterruptNumber)       //switching over interrupts
	{
		case EXTI_INT0 :
			CLR_BIT(EXTI_GICR,EXTI_INT0_ENABLE);      //disabling INT0
			break ;

		case EXTI_INT1 :
			CLR_BIT(EXTI_GICR,EXTI_INT1_ENABLE);      //disabling INT1
			break ;

		case EXTI_INT2 :
			CLR_BIT(EXTI_GICR,EXTI_INT2_ENABLE);      //disabling INT2
			break ;

		default :                                     //in case of wrong input argument
			Local_u8ErrorState = 1 ;
			break ;

	}		return Local_u8ErrorState ;         //return from this function
}

/***************************************************************************************************************/

u8 EXTI_u8Int0SetCallBack(void(*Copy_pvInt0Func)(void))
{
	u8 Local_u8ErrorState = 0 ;          //local variable for error detection
	if(Copy_pvInt0Func != NULL)
	{
		EXTI_pvIsr0=Copy_pvInt0Func;
	}

	else
		Local_u8ErrorState = 1 ;

	return Local_u8ErrorState ;          //return from this function
}

/***************************************************************************************************************/

u8 EXTI_u8Int1SetCallBack(void(*Copy_pvInt1Func)(void))
{
	u8 Local_u8ErrorState = 0 ;          //local variable for error detection
	if(Copy_pvInt1Func != NULL)
	{
		EXTI_pvIsr1=Copy_pvInt1Func;
	}

	else
		Local_u8ErrorState = 1 ;

	return Local_u8ErrorState ;          //return from this function
}

/***************************************************************************************************************/

u8 EXTI_u8Int2SetCallBack(void(*Copy_pvInt2Func)(void))
{
	u8 Local_u8ErrorState = 0 ;          //local variable for error detection
	if(Copy_pvInt2Func != NULL)
	{
		EXTI_pvIsr2=Copy_pvInt2Func;
	}

	else
		Local_u8ErrorState = 1 ;

	return Local_u8ErrorState ;          //return from this function
}

/***************************************************************************************************************/

void EXTI_voidInt0Init(void)
{
	/* 1. checking for sense signal*/

	#if INT0_SENSE == FALLING_EDGE 							//in case of sense signal on falling edge
		SET_BIT(EXTI_MCUCR,EXTI_ISC01);
		CLR_BIT(EXTI_MCUCR,EXTI_ISC00);

	#elif INT0_SENSE == RISING_EDGE 						//in case of sense signal on rising edge
		SET_BIT(EXTI_MCUCR,EXTI_ISC01);
		SET_BIT(EXTI_MCUCR,EXTI_ISC00);

	#elif INT0_SENSE == LOW_LEVEL							//in case of sense signal on low level
		CLR_BIT(EXTI_MCUCR,EXTI_ISC01);
		CLR_BIT(EXTI_MCUCR,EXTI_ISC00);

	#elif INT0_SENSE == ON_CHANGE							//in case of sense signal on any change
		CLR_BIT(EXTI_MCUCR,EXTI_ISC01);
		SET_BIT(EXTI_MCUCR,EXTI_ISC00);


	#else 													//in case of wrong configuration
	#error "Wrong configuration for sense signal"

	#endif

	/* 2. Enable or disable interrupt*/

	#if INT0_ENABLE == ENABLE
		SET_BIT(EXTI_GICR,EXTI_INT0_ENABLE);

	#elif INT0_ENABLE == DISABLE
		CLR_BIT(EXTI_GICR,EXTI_INT0_ENABLE);

	#else 													//in case of wrong configuration
	#error "Wrong configuration for enable state"

	#endif

}

/***************************************************************************************************************/

void EXTI_voidInt1Init(void)
{
	/* 1. checking for sense signal*/

	#if INT1_SENSE == FALLING_EDGE 							//in case of sense signal on falling edge
		SET_BIT(EXTI_MCUCR,EXTI_ISC11);
		CLR_BIT(EXTI_MCUCR,EXTI_ISC10);

	#elif INT1_SENSE == RISING_EDGE 						//in case of sense signal on rising edge
		SET_BIT(EXTI_MCUCR,EXTI_ISC11);
		SET_BIT(EXTI_MCUCR,EXTI_ISC10);

	#elif INT1_SENSE == LOW_LEVEL							//in case of sense signal on low level
		CLR_BIT(EXTI_MCUCR,EXTI_ISC11);
		CLR_BIT(EXTI_MCUCR,EXTI_ISC10);

	#elif INT1_SENSE == ON_CHANGE							//in case of sense signal on any change
		CLR_BIT(EXTI_MCUCR,EXTI_ISC11);
		SET_BIT(EXTI_MCUCR,EXTI_ISC10);


	#else 													//in case of wrong configuration
	#error "Wrong configuration for sense signal"

	#endif

	/* 2. Enable or disable interrupt*/

	#if INT1_ENABLE == ENABLE
		SET_BIT(EXTI_GICR,EXTI_INT1_ENABLE);

	#elif INT1_ENABLE == DISABLE
		CLR_BIT(EXTI_GICR,EXTI_INT1_ENABLE);

	#else 													//in case of wrong configuration
	#error "Wrong configuration for enable state"

	#endif
}

/***************************************************************************************************************/

void EXTI_voidInt2Init(void)
{
	/* 1. checking for sense signal*/

	#if INT2_SENSE == FALLING_EDGE 							//in case of sense signal on falling edge
		CLR_BIT(EXTI_MCUCSR,EXTI_ISC2);

	#elif INT2_SENSE == RISING_EDGE 						//in case of sense signal on rising edge
		SET_BIT(EXTI_MCUCSR,EXTI_ISC2);

	#else 													//in case of wrong configuration
	#error "Wrong configuration for sense signal"

	#endif


	/* 2. Enable or disable interrupt*/

	#if INT2_ENABLE == ENABLE
		SET_BIT(EXTI_GICR,EXTI_INT2_ENABLE);

	#elif INT2_ENABLE == DISABLE
		CLR_BIT(EXTI_GICR,EXTI_INT2_ENABLE);

	#else 													//in case of wrong configuration
	#error "Wrong configuration for enable state"

	#endif

}

/***************************************************************************************************************/

void __vector_1 (void) __attribute__((signal));         //ISR of interrupt 0
void __vector_1(void)
{
	EXTI_pvIsr0();
}


void __vector_2 (void) __attribute__((signal));			//ISR of interrupt 1
void __vector_2(void)
{
	EXTI_pvIsr1();
}


void __vector_3 (void) __attribute__((signal));			//ISR of interrupt 2
void __vector_3(void)
{
	EXTI_pvIsr2();
}
