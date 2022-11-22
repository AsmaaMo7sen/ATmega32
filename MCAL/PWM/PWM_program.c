#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "PWM_interface.h"
#include "PWM_register.h"
#include "PWM_private.h"
#include "PWM_config.h"

u8 PWM_u8InitTimer0( u16 Copy_u8Frequency , u8 Copy_u8DutyCycle)
{
	/*local variable for error checking*/
	u8 Local_u8ErrorState = OK ;

	/* 1- setting mode of TIMER/COUNTER0 to be fast pwm*/
	SET_BIT(TCCR0 , TCCR0_WGM00);
	SET_BIT(TCCR0 , TCCR0_WGM01);

	/* 2- setting inverted mode of OC0 pin*/
	CLR_BIT(TCCR0 , TCCR0_COM00);
	SET_BIT(TCCR0 , TCCR0_COM01);

	/* 3- setting value of OCR0 to adjust duty cycle*/
	OCR0 = ((u16)Copy_u8DutyCycle * 256) / 100 ;

	/* 4-disable all interrupts*/
	TIMSK = 0 ;

	/* 5- setting prescaler to run TIMER/COUNTER0*/
	TCCR0 &= CLK_MASK ;
	TCCR0 |= Copy_u8Frequency ;


	/*return from this function*/
	return Local_u8ErrorState ;
}


u8 PWM_u8InitTimer1(u8 Copy_u8Channel , u16 Copy_u8Frequency , u8 Copy_u8DutyCycle)
{
	/*local variable for error checking*/
	u8 Local_u8ErrorState = OK ;

	/* 1- setting mode of TIMER/COUNTER1 to be fast PWM (mode no.14)*/
	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	SET_BIT(TCCR1A,TCCR1A_WGM11);
	SET_BIT(TCCR1B,TCCR1B_WGM12);
	SET_BIT(TCCR1B,TCCR1B_WGM13);

	/* 2-setting non inverted mode on OC1A | OC1B pins */
	/*switching over channels*/
	switch(Copy_u8Channel)
		{
			/*choosing Channel A*/
			case CHANNEL_A :
				CLR_BIT(TCCR1A ,TCCR1A_COM1A0);
				SET_BIT(TCCR1A ,TCCR1A_COM1A1);
				break ;

			/*choosing Channel B*/
			case CHANNEL_B :
				CLR_BIT(TCCR1A ,TCCR1A_COM1B0);
				SET_BIT(TCCR1A ,TCCR1A_COM1B1);
				break ;

			default :
				Local_u8ErrorState = WRONG_CHANNEL ;
				break ;
		}


	/* 3- Setting value of ICR register to set frequency*/
	/*checking for right configuration of frequency*/
	if(Copy_u8Frequency >= FREQUENCY_1000 || Copy_u8Frequency <= FREQUENCY_20)
	{
		ICR1 = Copy_u8Frequency ;
	}
	else
	{
		Local_u8ErrorState = WRONG_FREQ ;
	}


	/* 4-setting value of OCR to set duty cycle*/
	/*checking for valid value of duty cycle*/
	if(Copy_u8DutyCycle >= 0 && Copy_u8DutyCycle <=100)
	{
		/*switching over channels*/
		switch(Copy_u8Channel)
			{
				/*choosing Channel A*/
				case CHANNEL_A :
					OCR1A = ((u32)Copy_u8DutyCycle * Copy_u8Frequency) / 100  ;
					break ;

				/*choosing Channel B*/
				case CHANNEL_B :
					OCR1B = ((u32)Copy_u8DutyCycle * Copy_u8Frequency) / 100  ;
					break ;

				default :
					Local_u8ErrorState = WRONG_CHANNEL ;
					break ;
			}
	}
	else
	{
		Local_u8ErrorState = NOK ;
	}

	/* 5-disable all interrupts*/
	TIMSK = 0 ;

	/* 6- setting prescaler to run TIMER/COUNTER1*/
	/*setting prescaler=8 to get tick time = 1us*/
	TCCR1B &= CLK_MASK ;
	TCCR1B |= PRESCALER_8 ;

	/*return from this function*/
	return Local_u8ErrorState ;
}

