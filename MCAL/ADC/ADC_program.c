/**********************************************************/
/*           Author  : Asmaa Mohsen                       */
/*           Layer   : MCAL                               */
/*           Version : 1.00                               */
/*           SWC     : ADC                                */
/**********************************************************/

#include "BIT_MATH.h"
#include "STD_TYPES.h"


#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"
#include "ADC_register.h"

/****************************************************************************************/
/************************************Global Variables************************************/
/****************************************************************************************/

/*global variable to store digital reading of Asynchronous function*/
static u16* ADC_pu16Reading = NULL ;

/*global variable to store address of notification function*/
static void (*notificationPtr)(void) = NULL ;

/*global variable to set the state of ADC peripheral*/
u8 ADC_u8BusyState = IDLE ;

/*global variable to carry chain array*/
static u8 * ADC_p8ChainChannelArray = NULL ;

/*global variable to carry the chain size*/
static u8  ADC_u8ChainSize = 0 ;

/*global variable to carry result of chain conversions*/
static u16 * ADC_p16ChainReading = NULL ;

/*global variable to carry the current channel index in chain*/
static u8 ADC_u8ChannelIndex = 0 ;

/*global variable as an indicator for interrupt source*/
static u8 ADC_u8IsrSource  ;

/***********************************************************************************************/
/***********************************Functions' Implementation***********************************/
/***********************************************************************************************/

void ADC_voidInit(void)
{
/***************Setting reference voltage***************/

	/*In case of Vref = voltage on Aref pin*/
	#if ADC_VREF == ADC_VREF_AREF
		CLR_BIT(ADC_ADMUX,ADMUX_REFS0);
		CLR_BIT(ADC_ADMUX,ADMUX_REFS1);

	/*In case of Vref = Avcc*/
	#elif ADC_VREF == ADC_VREF_AVCC
		CLR_BIT(ADC_ADMUX,ADMUX_REFS0);
		SET_BIT(ADC_ADMUX,ADMUX_REFS1);

	/*In case of Vref = internal 2.56 volt*/
	#elif ADC_VREF == ADC_VREF_INTERNAL_2_56V
		SET_BIT(ADC_ADMUX,ADMUX_REFS0);
		SET_BIT(ADC_ADMUX,ADMUX_REFS1);

	#else
		#error "wrong reference voltage configuration"

	#endif

/***************Setting bit adjust***************/

	/*In case of left adjust -> 8-bit resolution*/
	#if ADC_ADJUST == ADC_LEFT_ADJUST
			SET_BIT(ADC_ADMUX,ADMUX_ADLAR);

	/*In case of right adjust -> 10-bit resolution*/
	#elif ADC_ADJUST == ADC_RIGHT_ADJUST
			CLR_BIT(ADC_ADMUX,ADMUX_ADLAR);

	#else
		#error "wrong bits adjust configuration"


	#endif

/***************Setting ADC clock prescaler***************/

	ADC_ADCSRA &= PRESCALER_MASK ;    //placing mask over prescaler bits
	ADC_ADCSRA |= ADC_PRESCALER  ;    //setting value of configured prescaler over target bits

/***************Setting ADC interrupt***************/

	/*in case of enabling end of conversion interrupt*/
	#if ADC_INTERRUPT == ADC_INTERRUPT_ENABLE
		SET_BIT(ADC_ADCSRA,ADCSRA_ADIE) ;

	/*in case of disabling end of conversion interrupt*/
	#elif ADC_INTERRUPT == ADC_INTERRUPT_DISABLE
		CLR_BIT(ADC_ADCSRA,ADCSRA_ADIE) ;

	#else
		#error "wrong interrupt enable configuration"

	#endif

/***************Setting Auto Trigger***************/

	/*in case of disabling auto trigger*/
	#if ADC_AUTO_TRIGGER == ADC_AUTO_TRIGGER_DISABLE
			CLR_BIT(ADC_ADCSRA,ADCSRA_ADATE);

	/*in case of enabling auto trigger*/
	#elif ADC_AUTO_TRIGGER == ADC_AUTO_TRIGGER_ENABLE
			SET_BIT(ADC_ADCSRA,ADCSRA_ADATE);

			/*setting trigger source*/
			ADC_SFIOR &= AUTO_TRIGGER_MASK ;
			ADC_SFIOR |= ADC_AUTO_TRIG_SRC ;
	#else
		#error "wrong auto trigger configuration"

	#endif

/***************Enabling ADC peripheral***************/

	SET_BIT(ADC_ADCSRA,ADCSRA_ADEN) ;

}


u8 ADC_u16StartConversionSych(u8 Copy_u8Channel ,u16* Copy_pu16DigitalReading ,u16* Copy_pu16AnalogReading)
{
	u8 Local_u8ErrorState = OK ;           //local variable for error checking
	u32 Local_u32Counter=0 ;               //local variable to handle time out mechanism

/*making sure not to be interrupted*/
if(ADC_u8BusyState == IDLE)
{
	ADC_u8BusyState = BUSY ;		//making ADC busy till its free to work

	/*choosing target channel*/
	ADC_ADMUX &= CHANNEL_MASK ;
	ADC_ADMUX |= Copy_u8Channel ;

/***************Starting Conversion***************/

	/*in case of disabling auto trigger (single conversion)*/
	#if ADC_AUTO_TRIGGER == ADC_AUTO_TRIGGER_DISABLE
		/*starting conversion*/
		SET_BIT(ADC_ADCSRA,ADCSRA_ADSC);

		/*polling until end of conversion OR time runs out*/
		while(((GET_BIT(ADC_ADCSRA,ADCSRA_ADIF))==0)&&(Local_u32Counter!=ADC_u32TIME_OUT))
		{
			Local_u32Counter ++ ;  //incrementing counter
		}

		/*In case of breaking the loop as a result of reaching time out value*/
		if(Local_u32Counter == ADC_u32TIME_OUT)
		{
			Local_u8ErrorState = NOK ;
		}
		/*loop is broken because flag is raised due to conversion complete*/
		else
		{
			/*clearing flag after end of conversion*/
			SET_BIT(ADC_ADCSRA,ADCSRA_ADIF);

			/***************Getting Digital Readings***************/

		    /*in case of 8 bit resolution*/
			#if ADC_ADJUST == ADC_LEFT_ADJUST
				/*getting channel reading*/
			    *Copy_pu16DigitalReading = ADC_ADCH ;

			/*in case of 10 bit resolution*/
			#elif ADC_ADJUST == ADC_RIGHT_ADJUST
				/*getting channel reading*/
			    *Copy_pu16DigitalReading = ADC_ADCR ;
			#endif
		}

	#endif

/***************Calculating Analog voltage in millivolt***************/

	/*in case of 10-bit resolution*/
	#if ADC_ADJUST == ADC_RIGHT_ADJUST
		/*calculating analog voltage in mvolt*/
		*Copy_pu16AnalogReading =(u16) ((u32)Copy_pu16DigitalReading * 5000UL)/1024UL ;

	/*in case of 8-bit resolution*/
	#elif ADC_ADJUST == ADC_LEFT_ADJUST
		/*calculating analog voltage in mvolt*/
		*Copy_pu16AnalogReading =(u16) ((u32)Copy_pu16DigitalReading * 5000UL)/256UL ;
	#endif

		ADC_u8BusyState = IDLE ;   //releasing ADC peripheral
}

else
{
	Local_u8ErrorState = NOK ;
}
		/*return from this function*/
		return Local_u8ErrorState;
}



u8 ADC_voidStartConversionAsync(u8 Copy_u8Channel,u16* Copy_pu16DigitalReading,void(*Copy_pvNotificationFunc)(void))
{
	u8 Local_u8ErrorState = OK ;              //local variable for error checking

/*Making sure that the peripheral is free to work*/
if(ADC_u8BusyState == IDLE)
{
	if(Copy_pvNotificationFunc == NULL ||Copy_pu16DigitalReading== NULL )
	{
		Local_u8ErrorState = NOK ;
	}
	else
	{
		ADC_u8BusyState = BUSY ; 					  //making ADC busy till its free to work
		ADC_u8IsrSource = SINGLE_CHANNEL_ISR ;        //setting source of interrupt

		ADC_pu16Reading = Copy_pu16DigitalReading ;   //assigning address of reading to the global pointer
		notificationPtr = Copy_pvNotificationFunc ;   //assigning address of notification to the global pointer

		/*choosing target channel*/
		ADC_ADMUX &= CHANNEL_MASK ;
		ADC_ADMUX |= Copy_u8Channel ;

		/*starting conversion*/
		SET_BIT(ADC_ADCSRA,ADCSRA_ADSC);

		/*enabling conversion complete interrupt*/
		SET_BIT(ADC_ADCSRA , ADCSRA_ADIE);

	}
}

else
{
	Local_u8ErrorState = NOK ;     //the peripheral is busy
}
	/*return from this function*/
	return Local_u8ErrorState ;
}

u8 ADC_u8StartChainAsync(Chain_t * Copy_chain)
{
	u8 Local_u8ErrorState = OK ;	//local variable for error checking

	/*checking NULL pointers*/
	if(Copy_chain != NULL)
	{
		/*checking for ADC state either free to run or not*/
		if(ADC_u8BusyState == IDLE)
		{
			/*Making ADC busy*/
			ADC_u8BusyState = BUSY ;

			/*setting source of ISR*/
			ADC_u8IsrSource = CHAIN_ISR ;

			/*converting local chain parameters to global to be accessible by ISR*/
			ADC_p8ChainChannelArray = Copy_chain ->channel ;
			ADC_p16ChainReading = Copy_chain -> result ;
			ADC_u8ChainSize = Copy_chain -> chainSize ;
			notificationPtr = Copy_chain -> notificationFunc ;

			/*making sure to start converting the first channel*/
			ADC_u8ChannelIndex = 0 ;

			/*Setting first channel*/
			ADC_ADMUX &= CHANNEL_MASK ;
			ADC_ADMUX |= ADC_p8ChainChannelArray[ADC_u8ChannelIndex];

			/*Starting conversion*/
			SET_BIT(ADC_ADCSRA,ADCSRA_ADSC);

			/*Enable interrupt of conversion complete*/
			SET_BIT(ADC_ADCSRA,ADCSRA_ADIE);

		}
		else
		{
			Local_u8ErrorState = BUSY_STATE ;
		}
	}

	else
	{
		Local_u8ErrorState = NULL_POINTER ;
	}

	/*return from this function*/
	return Local_u8ErrorState ;
}


void __vector_16 (void) __attribute__((signal));
void __vector_16 (void)
{
	/*in case of interrupt as a result of single channel conversion asynchronous*/
	if(ADC_u8IsrSource == SINGLE_CHANNEL_ISR)
	{
		/*1)reading ADC results*/
		#if ADC_ADJUST == ADC_LEFT_ADJUST			/*in case of 8-bit resolution*/
			*ADC_pu16Reading = ADC_ADCH ;

		#elif ADC_ADJUST == ADC_RIGHT_ADJUST		/*in case of 10-bit resolution*/
			*ADC_pu16Reading = ADC_ADCR ;

		#else
			#error "wrong adjust configuration"
		#endif

		/*2)Releasing ADC peripheral*/
		ADC_u8BusyState = IDLE ;

		/*3)Calling call back notification pointer to function*/
		notificationPtr();

		/*4)Disable conversion complete interrupt*/
		CLR_BIT(ADC_ADCSRA,ADCSRA_ADIE);
		}


	/*in case of interrupt as a result of end of conversion of first channel of a chain*/
	else if(ADC_u8IsrSource == CHAIN_ISR)
	{
		/*1)reading result of first conversion*/
		#if ADC_ADJUST == ADC_LEFT_ADJUST			/*in case of 8-bit resolution*/
			ADC_p16ChainReading[ADC_u8ChannelIndex] = ADC_ADCH ;

		#elif ADC_ADJUST == ADC_RIGHT_ADJUST		/*in case of 10-bit resolution*/
			ADC_p16ChainReading[ADC_u8ChannelIndex] = ADC_ADCR ;

		#else
			#error "wrong adjust configuration"
		#endif

		/*2)incrementing ADC chain index to the following channel*/
		ADC_u8ChannelIndex ++ ;

		/*3)checking end of chain*/
		if(ADC_u8ChannelIndex==ADC_u8ChainSize)   //chain finished
		{
			/*Releasing ADC peripheral*/
			ADC_u8BusyState = IDLE ;

			/*calling notification function*/
			notificationPtr();

			/*disable ADC conversion interrupt*/
			CLR_BIT(ADC_ADCSRA,ADCSRA_ADIE);
		}
		else                                      //chain isn't over
		{
			/*Setting the new channel*/
			ADC_ADMUX &= CHANNEL_MASK ;
			ADC_ADMUX |= ADC_p8ChainChannelArray[ADC_u8ChannelIndex];

			/*Starting conversion*/
			SET_BIT(ADC_ADCSRA,ADCSRA_ADSC);
		}
	}

}
