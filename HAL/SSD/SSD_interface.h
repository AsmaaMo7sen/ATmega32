/**********************************************************/
/*           Author  : Asmaa Mohsen                       */
/*           Layer   : HAL                                */
/*           Version : 1.00                               */
/*           SWC     : SSD                                */
/**********************************************************/

#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_

/*a struct to initialize parameters of ssd*/
typedef struct
{
	u8 SSD_u8PORT ;        //port connected to ssd
	u8 SSD_u8Type ;        //ssd type [common anode or common cathode]
	u8 SSD_u8EnablePin ;   //pin connected to common of ssd
	u8 SSD_u8EnablePort ;  //port including pin connected to common of ssd
}SSD_t;

/*array includes numbers to be displayed on ssd*/
static u8 SSD_u8ArrayOfNumbers[10]=
						{
							0b00111111, //0
							0b00000110, //1
							0b01011011, //2
							0b01001111, //3
							0b01100110, //4
							0b01101101, //5
							0b01111101, //6
							0b00000111, //7
							0b01111111, //8
							0b01100111, //9
						};

/*macros for SSD type*/
#define SSD_COMMON_ANODE      (0)
#define SSD_COMMON_CATHODE    (1)


/*macros for enable pin*/
#define SSD_u8ENABLE_PIN0        DIO_u8PIN0
#define SSD_u8ENABLE_PIN1        DIO_u8PIN1
#define SSD_u8ENABLE_PIN2        DIO_u8PIN2
#define SSD_u8ENABLE_PIN3        DIO_u8PIN3
#define SSD_u8ENABLE_PIN4        DIO_u8PIN4
#define SSD_u8ENABLE_PIN5        DIO_u8PIN5
#define SSD_u8ENABLE_PIN6        DIO_u8PIN6
#define SSD_u8ENABLE_PIN7        DIO_u8PIN7

/*macros for enable port*/
#define SSD_u8ENABLE_PORTA       DIO_u8PORTA
#define SSD_u8ENABLE_PORTB       DIO_u8PORTB
#define SSD_u8ENABLE_PORTC       DIO_u8PORTC
#define SSD_u8ENABLE_PORTD       DIO_u8PORTD

/*macros for ssd port*/
#define SSD_u8PORTA              DIO_u8PORTA
#define SSD_u8PORTB              DIO_u8PORTB
#define SSD_u8PORTC              DIO_u8PORTC
#define SSD_u8PORTD              DIO_u8PORTD


/*this function is to display a number on a ssd*/
/*input arguments are a pointer to struct that set characteristics of ssd
   && number to get displayed*/
u8 SSD_u8SetNumber(SSD_t * Copy_pStructInit ,u8 Copy_u8Number);

/*this function is to enable a ssd*/
u8 SSD_u8EnableSSD(SSD_t * Copy_pStructInit);

/*this function is to disable a ssd*/
u8 SSD_u8DisableSSD(SSD_t * Copy_pStructInit);

#endif /* SSD_INTERFACE_H_ */
