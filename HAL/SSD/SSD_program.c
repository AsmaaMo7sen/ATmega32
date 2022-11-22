/**********************************************************/
/*           Author  : Asmaa Mohsen                       */
/*           Layer   : HAL                                */
/*           Version : 1.00                               */
/*           SWC     : SSD                                */
/**********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "PORT_interface.h"
#include "TIMER_interface.h"
#include "GIE_interface.h"

#include "SSD_interface.h"

#include "SSD_config.h"
#include "SSD_private.h"


u8 SSD_u8SetNumber(SSD_t * Copy_pStructInit ,u8 Copy_u8Number)
{
	/*local variable for error checking*/
	u8 LocalErrorState = 0;

	   //in case of common anode ssd
	   if(Copy_pStructInit->SSD_u8Type ==SSD_COMMON_ANODE)
		  //setting target number to be displayed on ssd
		  DIO_u8SetPortValue(Copy_pStructInit->SSD_u8PORT , ~SSD_u8ArrayOfNumbers[Copy_u8Number]);

	   //in case of common cathode ssd
	   else if (Copy_pStructInit->SSD_u8Type ==SSD_COMMON_CATHODE)
		  //setting target number to be displayed on ssd
		  DIO_u8SetPortValue(Copy_pStructInit->SSD_u8PORT , SSD_u8ArrayOfNumbers[Copy_u8Number]);

	   /*in case of wrong input value of ssd type*/
	   else
	      LocalErrorState = 1 ; //indicator for error

 		/*return from this function*/
		return LocalErrorState ;
}
/*********************************************************************************/
u8 SSD_u8EnableSSD(SSD_t * Copy_pStructInit)
{
	/*local variable for error checking*/
	u8 LocalErrorState = 0;

	   //in case of common anode ssd
	   if(Copy_pStructInit->SSD_u8Type ==SSD_COMMON_ANODE)
		  //setting common pin to high to enable SSD
		  DIO_u8SetPinValue(Copy_pStructInit->SSD_u8EnablePort , Copy_pStructInit->SSD_u8EnablePin,DIO_u8PIN_HIGH);

	   //in case of common cathode ssd
	   else if (Copy_pStructInit->SSD_u8Type ==SSD_COMMON_CATHODE)
		  //setting common pin to low to enable SSD
		  DIO_u8SetPinValue(Copy_pStructInit->SSD_u8EnablePort , Copy_pStructInit->SSD_u8EnablePin,DIO_u8PIN_LOW);

		 /*in case of wrong input value of ssd type*/
		 else
		   LocalErrorState = 1 ; //indicator for error

	/*return from this function*/
	return LocalErrorState ;
}
/*********************************************************************************/
u8 SSD_u8DisableSSD(SSD_t * Copy_pStructInit)
{
	/*local variable for error checking*/
	u8 LocalErrorState = 0;

	   //in case of common anode ssd
	   if(Copy_pStructInit->SSD_u8Type ==SSD_COMMON_ANODE)
		  //setting common pin to be low output to deactivate common anode ssd
		  DIO_u8SetPinValue(Copy_pStructInit->SSD_u8EnablePort , Copy_pStructInit->SSD_u8EnablePin,DIO_u8PIN_LOW);

	   //in case of common cathode ssd
	   else if (Copy_pStructInit->SSD_u8Type ==SSD_COMMON_CATHODE)
		  //setting common pin to be high output to deactivate common cathode ssd
		  DIO_u8SetPinValue(Copy_pStructInit->SSD_u8EnablePort , Copy_pStructInit->SSD_u8EnablePin,DIO_u8PIN_HIGH);

	   /*in case of wrong input value of ssd type*/
	   else
	      LocalErrorState = 1 ; //indicator for error

	/*return from this function*/
	return LocalErrorState ;
}


