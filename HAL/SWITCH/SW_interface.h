/**********************************************************/
/*           Author  : Asmaa Mohsen                       */
/*           Layer   : HAL                                */
/*           Version : 1.00                               */
/*           SWC     : SWITCH                             */
/**********************************************************/

#ifndef SW_INTERFACE_H_
#define SW_INTERFACE_H_

typedef struct
{
	u8 SW_u8Port ;       //port including the terminal of switch
	u8 SW_u8Pin ;        //pin connected to the terminal of switch
	u8 SW_u8PullState ;  //connection state either pull up or pull down
}SWITCH_t;

/*ports for connecting switches*/
#define SW_u8PORTA       DIO_u8PORTA
#define SW_u8PORTB       DIO_u8PORTB
#define SW_u8PORTC       DIO_u8PORTC
#define SW_u8PORTD       DIO_u8PORTD

/*pins to connect switches*/
#define SW_u8PIN0       DIO_u8PIN0
#define SW_u8PIN1       DIO_u8PIN1
#define SW_u8PIN2       DIO_u8PIN2
#define SW_u8PIN3       DIO_u8PIN3
#define SW_u8PIN4       DIO_u8PIN4
#define SW_u8PIN5       DIO_u8PIN5
#define SW_u8PIN6       DIO_u8PIN6
#define SW_u8PIN7       DIO_u8PIN7

/*pull condition*/
#define SW_u8PULL_UP    (0)
#define SW_u8PULL_DOWN  (1)

/*pull up results*/
#define SW_u8PRESSED_PULL_UP       (0)
#define SW_u8NOT_PRESSED_PULL_UP   (1)

/*pull down results*/
#define SW_u8PRESSED_PULL_DOWN     (1)
#define SW_u8NOT_PRESSED_PULL_DOWN (0)

/***************************************************************************************/
/*this function is to return the state of the switch either pressed or not*/
u8 SW_u8GetState(SWITCH_t * Copy_pSwitchInit , u8 * Copy_u8State);

#endif /* SW_INTERFACE_H_ */
