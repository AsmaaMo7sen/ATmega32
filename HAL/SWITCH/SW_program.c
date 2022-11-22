/**********************************************************/
/*           Author  : Asmaa Mohsen                       */
/*           Layer   : HAL                                */
/*           Version : 1.00                               */
/*           SWC     : SWITCH                             */
/**********************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "SW_interface.h"
#include "SW_private.h"
#include "SW_config.h"




u8 SW_u8GetState(SWITCH_t * Copy_pSwitchInit , u8 * Copy_u8State)
{
	u8 LocalErrorState = 0 ; //local variable for error detection
	u8 Local_u8Value ;       //local variable to store value of switch

	DIO_u8SetPinDirection(Copy_pSwitchInit->SW_u8Port,Copy_pSwitchInit->SW_u8Pin,DIO_u8PIN_INPUT_PULL_UP);

	/*in case of pull up connection*/
	if(Copy_pSwitchInit->SW_u8PullState == SW_u8PULL_UP)
	{
	  DIO_u8GetPinValue(Copy_pSwitchInit->SW_u8Port,Copy_pSwitchInit->SW_u8Pin,&Local_u8Value);

	  if(Local_u8Value==0)
		  *Copy_u8State = SW_u8PRESSED_PULL_UP ;

	  else if(Local_u8Value==1)
		  *Copy_u8State = SW_u8NOT_PRESSED_PULL_UP ;

	  else
		   LocalErrorState = 1 ;
	}

	/*in case of pull down*/
	else if(Copy_pSwitchInit->SW_u8PullState == SW_u8PULL_DOWN)
	{
	   DIO_u8GetPinValue(Copy_pSwitchInit->SW_u8Port,Copy_pSwitchInit->SW_u8Pin,&Local_u8Value);

	   if(Local_u8Value==0)
		   *Copy_u8State = SW_u8NOT_PRESSED_PULL_DOWN ;

	   else if(Local_u8Value==1)
	       *Copy_u8State = SW_u8PRESSED_PULL_DOWN ;

	     LocalErrorState = 1 ;

	}

	/*in case of wrong input of pull state*/
	else
		LocalErrorState = 0 ; //indicator for error

	return LocalErrorState ; //return from this function
}


