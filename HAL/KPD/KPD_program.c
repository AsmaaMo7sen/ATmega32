/**********************************************************/
/*           Author  : Asmaa Mohsen                       */
/*           Layer   : HAL                                */
/*           Version : 1.00                               */
/*           SWC     : KEYPAD                             */
/**********************************************************/

#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "KPD_interface.h"
#include "KPD_private.h"
#include "KPD_config.h"


u8 KPD_u8GetPressedKey(void)
{
	 u8 Local_u8PressedKey = NO_PRESSED_KEY_STATE;   						   //local variable to store value of pressed key
	 u8 Local_u8ColIndex ;                       			    			   //a local variable for column iterator
	 u8 Local_u8RowIndex ;							 						   //a local variable for rows iterator
	 u8 Local_u8PinState ;													   //a local variable for reading current row

	 static u8 Local_u8KeypadArray[KPD_NO_OF_ROWS][KPD_NO_OF_COLS] = KPD_ARRAY;       //an array of buttons values
	 static u8 Local_u8ColArr[KPD_NO_OF_COLS] = {KPD_u8COL0_PIN,KPD_u8COL1_PIN,KPD_u8COL2_PIN,KPD_u8COL3_PIN};
	 static u8 Local_u8RowArr[KPD_NO_OF_ROWS] = {KPD_u8ROW0_PIN,KPD_u8ROW1_PIN,KPD_u8ROW2_PIN,KPD_u8ROW3_PIN};

	 /*looping over columns*/
	 for (Local_u8ColIndex=0 ; Local_u8ColIndex<KPD_NO_OF_COLS ; Local_u8ColIndex++)
	 {
		 /*Activating current column*/
		 DIO_u8SetPinValue(KPD_u8PORT,Local_u8ColArr[Local_u8ColIndex], DIO_u8PIN_LOW);

		 /*looping over rows to search for pressed key*/
		 for(Local_u8RowIndex=0 ; Local_u8RowIndex<KPD_NO_OF_ROWS ; Local_u8RowIndex++)
		 {
			 /*Read the current row*/
			 DIO_u8GetPinValue(KPD_u8PORT,Local_u8RowArr[Local_u8RowIndex] , &Local_u8PinState);

			 /*checking if switch is pressed*/
			 if(Local_u8PinState==DIO_u8PIN_LOW)
				 {
					 Local_u8PressedKey =Local_u8KeypadArray[Local_u8RowIndex][Local_u8ColIndex] ;

				 	 while(Local_u8PinState==DIO_u8PIN_LOW)          //polling(busy waiting) till key is released
				 	 {
				 		DIO_u8GetPinValue(KPD_u8PORT,Local_u8RowArr[Local_u8RowIndex] , &Local_u8PinState);
				 	 }

					 return Local_u8PressedKey ;
				 }
		 }

		 /*Deactivating current column*/
		 DIO_u8SetPinValue(KPD_u8PORT,Local_u8ColArr[Local_u8ColIndex], DIO_u8PIN_HIGH);
	 }

	 /*return from this function*/
	 return Local_u8PressedKey ;
}
