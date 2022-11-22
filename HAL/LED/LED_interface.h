/**********************************************************/
/*           Author  : Asmaa Mohsen                       */
/*           Layer   : HAL                                */
/*           Version : 1.00                               */
/*           SWC     : LED                                */
/**********************************************************/

#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

/*a struct to define characteristics of a led*/
typedef struct
	{
		u8 LED_u8Port ;       //to define port connection
		u8 LED_u8Pin ;        //to define pin connection
		u8 LED_u8Connection ; //to define either sink or source connection
	}LED_t;

/****************************************************************************/

/*ports to connect a led*/
#define LED_u8PORTA       DIO_u8PORTA
#define LED_u8PORTB       DIO_u8PORTB
#define LED_u8PORTC       DIO_u8PORTC
#define LED_u8PORTD       DIO_u8PORTD

/*pins to connect a led*/
#define LED_u8PIN0       DIO_u8PIN0
#define LED_u8PIN1       DIO_u8PIN1
#define LED_u8PIN2       DIO_u8PIN2
#define LED_u8PIN3       DIO_u8PIN3
#define LED_u8PIN4       DIO_u8PIN4
#define LED_u8PIN5       DIO_u8PIN5
#define LED_u8PIN6       DIO_u8PIN6
#define LED_u8PIN7       DIO_u8PIN7

/*possible methods of led connection*/
#define LED_u8SOURCE     (0)
#define LED_u8SINK       (1)

/****************************************************************************/

/*this function is to turn a led on*/
u8 LED_u8TurnLedOn(LED_t * Local_pLedInit);

/*this function is to turn a led off*/
u8 LED_u8TurnLedOff(LED_t * Local_pLedInit);


#endif /* LED_INTERFACE_H_ */
