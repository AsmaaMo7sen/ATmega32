/**********************************************************/
/*           Author  : Asmaa Mohsen                       */
/*           Layer   : MCAL                               */
/*           Version : 1.00                               */
/*           SWC     : ADC                                */
/**********************************************************/

/*preprocessor header file guard*/
#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_
/************************************************************************************/
/*********************************Interfacing macros*********************************/
/************************************************************************************/

/***********MASKS***********/
#define PRESCALER_MASK                   (0b11111000)
#define AUTO_TRIGGER_MASK                (0b11111000)
#define CHANNEL_MASK                     (0b11100000)


/***********ADC channels**************/
#define ADC_SINGLE_ENDED_ADC0       (0b00000000)
#define ADC_SINGLE_ENDED_ADC1       (0b00000001)
#define ADC_SINGLE_ENDED_ADC2       (0b00000010)
#define ADC_SINGLE_ENDED_ADC3       (0b00000011)
#define ADC_SINGLE_ENDED_ADC4       (0b00000100)
#define ADC_SINGLE_ENDED_ADC5       (0b00000101)
#define ADC_SINGLE_ENDED_ADC6       (0b00000110)
#define ADC_SINGLE_ENDED_ADC7       (0b00000111)

/***********ADC reference voltage***********/
#define ADC_VREF_AREF               (1)
#define ADC_VREF_AVCC               (2)
#define ADC_VREF_INTERNAL_2_56V     (3)

/***********ADC bits adjustment***********/
#define ADC_LEFT_ADJUST             (1)
#define ADC_RIGHT_ADJUST            (0)

/***********ADC peripheral state***********/
#define ADC_ENABLE                  (1)
#define ADC_DISABLE                 (0)

/***********ADC auto trigger***********/
#define ADC_AUTO_TRIGGER_ENABLE     (1)
#define ADC_AUTO_TRIGGER_DISABLE    (0)

/***********ADC conversion complete interrupt***********/
#define ADC_INTERRUPT_ENABLE        (1)
#define ADC_INTERRUPT_DISABLE       (0)

/***********ADC clock prescaler***********/
#define ADC_PRESCALER_2             (0b00000001)
#define ADC_PRESCALER_4				(0b00000010)
#define ADC_PRESCALER_8				(0b00000011)
#define ADC_PRESCALER_16			(0b00000100)
#define ADC_PRESCALER_32			(0b00000101)
#define ADC_PRESCALER_64			(0b00000110)
#define ADC_PRESCALER_128			(0b00000111)

/***********Auto trigger source***********/
#define FREE_RUNNING_MODE               (0b00000000)
#define ANALOG_COMPARATOR               (0b00000001)
#define EXTERNAL_INTERRUPT_REQUEST_0    (0b00000010)
#define TIMER_0_COMPARE_MATCH           (0b00000011)
#define TIMER_0_OVERFLOW                (0b00000100)
#define TIMER_COMPARE_MATCH_B           (0b00000101)
#define TIMER_1_OVERFLOW                (0b00000110)
#define TIMER_1_CAPTURE_EVENT           (0b00000111)


/*A new data type for chain characteristics*/
typedef struct
{
	u8 * channel ;                   //channels required to convert
	u16 * result ;                   //array to store readings of chain
	u8 chainSize ;                   //number of channels at chain
	void (*notificationFunc)(void);  //notification of end of chain
}Chain_t;

/*****************************************************************************/
/*****************************Functions' Prototypes***************************/
/*****************************************************************************/

/*Description  :  this function is to initialize ADC peripheral       */
/*Input        :  void												  */
/*Output       :  void			                                      */
/*Configuration:  pre-build 									      */
void ADC_voidInit(void);

/*Description  :  this function is to get the reading of ADC channel with concept of polling */
/*Input        :  ADC channel number                                                         */
/*Output       :  channel digital reading                                                    */
/*             :  channel analog value                                                       */
/*             :  error statement                                                            */
u8 ADC_u16StartConversionSych(u8 Copy_u8Channel , u16* Copy_pu16DigitalReading , u16* Copy_pu16AnalogReading);

/*Description  :  this function is to get the reading of ADC channel with interrupt  */
/*Input        :  ADC channel number                                                 */
/*             :  pointer to notification function                                   */
/*Output       :  channel digital reading                                            */
/*             :  error statement                                                    */
/*******make sure to enable global interrupt*************/
u8 ADC_voidStartConversionAsync(u8 Copy_u8Channel , u16* Copy_pu16DigitalReading ,
								  void(*Copy_pvNotificationFunc)(void));

/*Description  :  this function is to get the reading of ADC chain  */
/*Input        :  pointer to struct of chain characteristics        */
/*Output       :  error state                                       */
u8 ADC_u8StartChainAsync(Chain_t * Copy_chain);



#endif /* ADC_INTERFACE_H_ */
