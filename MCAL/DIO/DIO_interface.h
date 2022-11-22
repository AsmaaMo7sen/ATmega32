/**********************************************************/
/*           Author  : Asmaa Mohsen                       */
/*           Layer   : MCAL                               */
/*           Version : 1.00                               */
/*           SWC     : DIO                                */
/**********************************************************/

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

//macros for ports
#define DIO_u8PORTA         (1)
#define DIO_u8PORTB         (2)
#define DIO_u8PORTC         (3)
#define DIO_u8PORTD         (4)

//macros for pins
#define DIO_u8PIN0          (0)
#define DIO_u8PIN1          (1)
#define DIO_u8PIN2          (2)
#define DIO_u8PIN3          (3)
#define DIO_u8PIN4          (4)
#define DIO_u8PIN5          (5)
#define DIO_u8PIN6          (6)
#define DIO_u8PIN7          (7)

//macros for possible output pin values
#define DIO_u8PIN_HIGH          (1)
#define DIO_u8PIN_LOW           (0)


//macros for high and low port values
#define DIO_u8HIGH_PORT     (0xFF)
#define DIO_u8LOW_PORT      (0X00)



//this function is to set the output value of a pin in a certain port [high | low]
u8 DIO_u8SetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Value);

//this function is to set the value of output port [0:255]
u8 DIO_u8SetPortValue(u8 Copy_u8Port , u8 Copy_u8Value);

//this function is to read the input of a certain pin
u8 DIO_u8GetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin , u8 * Copy_p8Value);


#endif /* DIO_INTERFACE_H_ */
