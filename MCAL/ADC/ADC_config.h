/**********************************************************/
/*           Author  : Asmaa Mohsen                       */
/*           Layer   : MCAL                               */
/*           Version : 1.00                               */
/*           SWC     : ADC                                */
/**********************************************************/

/*preprocessor header file guard*/
#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_

/**************************************Configurable parameters**************************************/

/*Setting reference voltage :
 	 	 	 	 	 	   [ ADC_VREF_AREF || ADC_VREF_AVCC || ADC_VREF_INTERNAL_2_56V ] */
#define ADC_VREF         ADC_VREF_AVCC

/*Presentation of the ADC conversion result in the ADC Data Register :
 	 	 	 	 	 	   [ ADC_LEFT_ADJUST  (for 8 bit resolution) ||
 	 	 	 	 	 	     ADC_RIGHT_ADJUST (for 10 bit resolution)   ]*/
#define ADC_ADJUST       ADC_LEFT_ADJUST


/*Auto trigger of ADC peripheral :
 	 	 	 	 	 	   [ ADC_AUTO_TRIGGER_ENABLE || ADC_AUTO_TRIGGER_DISABLE(single conversion) ]*/
#define ADC_AUTO_TRIGGER ADC_AUTO_TRIGGER_DISABLE


/*End of conversion interrupt enable:
 	 	 	 	 	 	   [ ADC_INTERRUPT_ENABLE  || ADC_INTERRUPT_DISABLE ] */
#define ADC_INTERRUPT    ADC_INTERRUPT_DISABLE


/*Prescaler of ADC clock :
 	 	 	 	 	 	   [ADC_PRESCALER_2    || ADC_PRESCALER_4  ||
 	 	 	 	 	 	    ADC_PRESCALER_8    || ADC_PRESCALER_16 ||
 	 	 	 	 	 	    ADC_PRESCALER_32   || ADC_PRESCALER_64 ||
 	 	 	 	 	 	               ADC_PRESCALER_128 ] */
#define ADC_PRESCALER    ADC_PRESCALER_128


/*Time out for ADC conversion complete*/
#define ADC_u32TIME_OUT     500000


/*Auto trigger source for ADC :
 	 	 	 	 	 	   [ FREE_RUNNING_MODE || ANALOG_COMPARATOR ||
								  EXTERNAL_INTERRUPT_REQUEST_0 ||
                             TIMER_0_COMPARE_MATCH  || TIMER_0_OVERFLOW ||
							 TIMER_COMPARE_MATCH_B  || TIMER_1_OVERFLOW ||
                                        TIMER_1_CAPTURE_EVENT    ]   */
#define ADC_AUTO_TRIG_SRC FREE_RUNNING_MODE


#endif /* ADC_CONFIG_H_ */
