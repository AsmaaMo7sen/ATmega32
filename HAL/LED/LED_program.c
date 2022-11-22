/**********************************************************/
/*           Author  : Asmaa Mohsen                       */
/*           Layer   : HAL                                */
/*           Version : 1.00                               */
/*           SWC     : LED                                */
/**********************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "LED_interface.h"
#include "LED_private.h"
#include "LED_config.h"


u8 LED_u8TurnLedOn(LED_t * Local_pLedInit)
{
	u8 LocalErrorState = 0 ;   //local variable for error detection

	//in case of sink connection
	if(Local_pLedInit->LED_u8Connection == LED_u8SINK)
		//setting its direction to low
		DIO_u8SetPinValue(Local_pLedInit->LED_u8Port ,Local_pLedInit->LED_u8Pin , DIO_u8PIN_LOW);

	//in case of source connection
	else if(Local_pLedInit->LED_u8Connection == LED_u8SOURCE)
		//setting its direction to high
		DIO_u8SetPinValue(Local_pLedInit->LED_u8Port ,Local_pLedInit->LED_u8Pin , DIO_u8PIN_HIGH);

	else                                                     //in case of wrong argument
		LocalErrorState = 1 ;   //indication of error


	return LocalErrorState ;  //return from this function
}


u8 LED_u8TurnLedOff(LED_t * Local_pLedInit)
{
	u8 LocalErrorState = 0 ;   //local variable for error detection

	//in case of sink connection
	if(Local_pLedInit->LED_u8Connection == LED_u8SINK)
		//setting its direction to high
		DIO_u8SetPinValue(Local_pLedInit->LED_u8Port ,Local_pLedInit->LED_u8Pin , DIO_u8PIN_HIGH);

	//in case of source connection
	else if(Local_pLedInit->LED_u8Connection == LED_u8SOURCE)
		//setting its direction to low
		DIO_u8SetPinValue(Local_pLedInit->LED_u8Port ,Local_pLedInit->LED_u8Pin , DIO_u8PIN_LOW);

	else                                                     //in case of wrong argument
		LocalErrorState = 1 ;   //indication of error


	return LocalErrorState ;  //return from this function
}
