/**********************************************************/
/*           Author  : Asmaa Mohsen                       */
/*           Layer   : MCAL                               */
/*           Version : 1.00                               */
/*           SWC     : ADC                                */
/**********************************************************/

/*preprocessor header file guard*/
#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

/******************************************special bits******************************************/

#define ADMUX_REFS1                   7         //for reference voltage selection bit1
#define ADMUX_REFS0                   6         //for reference voltage selection bit0
#define ADMUX_ADLAR                   5         //for left adjustment


#define ADCSRA_ADEN                   7         //for ADC enable
#define ADCSRA_ADSC                   6         //for ADC start conversion
#define ADCSRA_ADATE                  5         //for ADC auto trigger enable
#define ADCSRA_ADIF                   4         //for ADC interrupt flag
#define ADCSRA_ADIE                   3         //for ADC interrupt enable
#define ADCSRA_ADP2                   2         //for ADC clock prescaler bit 2
#define ADCSRA_ADP1                   1         //for ADC clock prescaler bit 1
#define ADCSRA_ADP0                   0         //for ADC clock prescaler bit 0

/*******************************private macros*******************************/
#define IDLE                   0
#define BUSY                   1

#define SINGLE_CHANNEL_ISR     1
#define CHAIN_ISR              2



#endif /* ADC_PRIVATE_H_ */
