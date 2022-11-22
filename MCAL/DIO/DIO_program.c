/**********************************************************/
/*           Author  : Asmaa Mohsen                       */
/*           Layer   : MCAL                               */
/*           Version : 1.00                               */
/*           SWC     : DIO                                */
/**********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "DIO_register.h"
#include "DIO_private.h"
#include "DIO_config.h"


u8 DIO_u8SetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Value)
{
	u8 Local_u8ErrorState = 0 ;    //local variable for error state check

	/*checking for inputs in right range*/
	if(Copy_u8Pin<=DIO_u8PIN7)
	{
		/*switching over ports*/
		switch(Copy_u8Port)
		{
		/*in case of port A*/
		case DIO_u8PORTA :
			/*switching over values*/
			switch(Copy_u8Value)
			{
			case DIO_u8PIN_HIGH :  //in case of high level of pin in port A
				SET_BIT(PORTA,Copy_u8Pin);
				break ;

			case DIO_u8PIN_LOW :  //in case of low level of pin in port A
				CLR_BIT(PORTA,Copy_u8Pin);
				break ;

			/*for any other input argument of pin value*/
			default :
				Local_u8ErrorState = 1 ; //indicator for error
				break ;
			}
			break ;  //breaking from port A case

		/*in case of port B*/
		case DIO_u8PORTB :
			/*switching over values*/
			switch(Copy_u8Value)
			{
			case DIO_u8PIN_HIGH :  //in case of high level of pin in port B
				SET_BIT(PORTB,Copy_u8Pin);
				break ;

			case DIO_u8PIN_LOW :  //in case of low level of pin in port B
				CLR_BIT(PORTB,Copy_u8Pin);
				break ;

			/*for any other input argument of pin value*/
			default :
				Local_u8ErrorState = 1 ; //indicator for error
				break ;
			}
			break ;  //breaking from port B case


		/*in case of port C*/
		case DIO_u8PORTC :
			/*switching over values*/
			switch(Copy_u8Value)
			{
			case DIO_u8PIN_HIGH :  //in case of high level of pin in port C
				SET_BIT(PORTC,Copy_u8Pin);
				break ;

			case DIO_u8PIN_LOW :  //in case of low level of pin in port C
				CLR_BIT(PORTC,Copy_u8Pin);
				break ;

			/*for any other input argument of pin value*/
			default :
				Local_u8ErrorState = 1 ; //indicator for error
				break ;
			}
			break ;  //breaking from port C case

		/*in case of port D*/
		case DIO_u8PORTD :
			/*switching over values*/
			switch(Copy_u8Value)
			{
			case DIO_u8PIN_HIGH :  //in case of high level of pin in port D
				SET_BIT(PORTD,Copy_u8Pin);
				break ;

			case DIO_u8PIN_LOW :  //in case of low level of pin in port D
				CLR_BIT(PORTD,Copy_u8Pin);
				break ;

			/*for any other input argument of pin value*/
			default :
				Local_u8ErrorState = 1 ; //indicator for error
				break ;
			}

			break ;  //breaking from port D case

		/*for any other input argument of port value*/
		default :
			Local_u8ErrorState = 1 ; //indicator for error
			break ;
		}
	}

	/*in case of wrong input argument in pin value*/
	else
		Local_u8ErrorState = 1 ;   //indicator for error

	return Local_u8ErrorState ;    //return from this function
}

/******************************************************************************/

u8 DIO_u8SetPortValue(u8 Copy_u8Port , u8 Copy_u8Value)
{
	u8 Local_u8ErrorState = 0 ;    //local variable for error state check

	/*checking for right port range of values*/
	if (Copy_u8Port<=DIO_u8PORTD)
	{
		/*switching over ports*/
		switch(Copy_u8Port)
		{
		case DIO_u8PORTA :   //in case of port A
			PORTA=Copy_u8Value ; //setting target output value to port A
			break ;          //break from port A case

		case DIO_u8PORTB :   //in case of port B
			PORTB=Copy_u8Value ; //setting target output value to port B
			break ;          //break from port B case

		case DIO_u8PORTC :   //in case of port C
			PORTC=Copy_u8Value ; //setting target output value to port C
			break ;          //break from port C case

		case DIO_u8PORTD :   //in case of port D
			PORTD=Copy_u8Value ; //setting target output value to port D
			break ;          //break from port D case

		/*for any other input argument of port value*/
		default :
			Local_u8ErrorState = 1 ; //indicator for error
			break ;
		}
	}

	/*in case of wrong input argument in port value*/
	else
		Local_u8ErrorState = 1 ;  //indicator for error

	return Local_u8ErrorState ;    //return from this function
}

u8 DIO_u8GetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin , u8 * Copy_p8Value)
{
	u8 Local_u8ErrorState = 0 ;    //local variable for error state check


    /*checking for the right range of pins value*/
    if((Copy_p8Value != NULL) && Copy_u8Pin<=DIO_u8PIN7)
    {
    	/*switching over ports*/
		switch(Copy_u8Port)
		{
		case DIO_u8PORTA :    //in case of port A
			*Copy_p8Value=GET_BIT(PINA,Copy_u8Pin);   //assigning pin value to the addressee location
			break ;           //break from case of port A

		case DIO_u8PORTB :    //in case of port B
			*Copy_p8Value=GET_BIT(PINB,Copy_u8Pin);   //assigning pin value to the addressee location
			break ;           //break from case of port B

		case DIO_u8PORTC :    //in case of port C
			*Copy_p8Value=GET_BIT(PINC,Copy_u8Pin);   //assigning pin value to the addressee location
			break ;           //break from case of port C

		case DIO_u8PORTD :    //in case of port D
			*Copy_p8Value=GET_BIT(PIND,Copy_u8Pin);   //assigning pin value to the addressee location
			break ;           //break from case of port D

		/*for any other input argument of port value*/
		default :
			Local_u8ErrorState = 1 ; //indicator for error
			break ;
		}
    }
    /*in case of wrong input argument of pin value*/
    else
    	Local_u8ErrorState = 1 ;

	return Local_u8ErrorState ;    //return from this function	}
}



