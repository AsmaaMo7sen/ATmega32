/**********************************************************/
/*           Author  : Asmaa Mohsen                       */
/*           Layer   : MCAL                               */
/*           Version : 1.00                               */
/*           SWC     : ADC                                */
/**********************************************************/

/*preprocessor header file guard*/
#ifndef ADC_REGISTER_H_
#define ADC_REGISTER_H_

/******************************************ADC registers******************************************/

#define ADC_ADMUX    *((volatile u8 *)(0x27))      //ADC multiplexer selection register
#define ADC_ADCSRA   *((volatile u8 *)(0x26))      //ADC control and status registerA
#define ADC_ADCH     *((volatile u8 *)(0x25))      //ADC high register
#define ADC_ADCL     *((volatile u8 *)(0x24))      //ADC low register

#define ADC_SFIOR    *((volatile u8 *)(0x50))      //ADC special function IO register
#define ADC_ADCR     *((volatile u16*)(0x24))      //ADC data register for 10 bit resolution


#endif /* ADC_REGISTER_H_ */
