/**********************************************************/
/*           Author  : Asmaa Mohsen                       */
/*           Layer   : HAL                                */
/*           Version : 1.00                               */
/*           SWC     : CLCD                               */
/**********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>

#include "DIO_interface.h"
#include "CLCD_interface.h"
#include "CLCD_config.h"
#include "CLCD_private.h"



void CLCD_voidInit(void)
{
	/*1)delay for more than 30ms till voltage rises from 0v to 4.5v*/
	_delay_ms(40);

	/*2)function set command -> 0011NFXX*/
	//2 lines and 5*8 size
	CLCD_voidSendCmd(0b00111000);

	/*3)delay for more than 39us but its included in SendCmd function*/

	/*4)Display enable*/
	// cursor enable with blinking
	CLCD_voidSendCmd(0b00001111);

	/*5)delay for more than 39us but its included in SendCmd function*/

	/*6)Display clear*/
	CLCD_voidSendCmd(0b00000001);

	/*7)delay for more than 1.53ms but its included in SendCmd function*/
}

/****************************************************************************************************/

void CLCD_voidSendCmd(u8 Copy_u8Cmd)
{
	/*1)setting pin direction of RS to be 0 for command*/
	DIO_u8SetPinValue(CLCD_u8CTRL_PORT , CLCD_u8RS_PIN , DIO_u8PIN_LOW);

	/*2)setting pin direction of R/W to be 0 for write*/
	DIO_u8SetPinValue(CLCD_u8CTRL_PORT , CLCD_u8R_W_PIN , DIO_u8PIN_LOW);

	/*3)sending command through data pins*/
	DIO_u8SetPortValue(CLCD_u8DATA_PORT , Copy_u8Cmd);

	/*4)enable data transfer by enable pulse*/
	DIO_u8SetPinValue(CLCD_u8CTRL_PORT , CLCD_u8EN_PIN , DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_u8CTRL_PORT , CLCD_u8EN_PIN , DIO_u8PIN_LOW);
}

/****************************************************************************************************/

void CLCD_voidSendData(u8 Copy_u8Data)
{
		/*1)setting pin direction of RS to be 1 for data*/
		DIO_u8SetPinValue(CLCD_u8CTRL_PORT , CLCD_u8RS_PIN , DIO_u8PIN_HIGH);

		/*2)setting pin direction of R/W to be 0 for write*/
		DIO_u8SetPinValue(CLCD_u8CTRL_PORT , CLCD_u8R_W_PIN , DIO_u8PIN_LOW);

		/*3)sending data through data pins*/
		DIO_u8SetPortValue(CLCD_u8DATA_PORT , Copy_u8Data);

		/*4)enable data transfer by enable pulse*/
		DIO_u8SetPinValue(CLCD_u8CTRL_PORT , CLCD_u8EN_PIN , DIO_u8PIN_HIGH);
		_delay_ms(2);
		DIO_u8SetPinValue(CLCD_u8CTRL_PORT , CLCD_u8EN_PIN , DIO_u8PIN_LOW);
}

/****************************************************************************************************/

void CLCD_voidSendString(const char * Copy_pString)
{
	u8 Local_u8Counter ;   //local variable for looping
	while(Copy_pString[Local_u8Counter] != '\0') //unless the character isn't \0
	{
		   CLCD_voidSendData(Copy_pString[Local_u8Counter]); //sending character to get displayed
		   Local_u8Counter++ ;
	}
}

/****************************************************************************************************/

void CLCD_voidGotoXY(u8 Copy_u8XPosition ,u8 Copy_u8YPosition)
{
	u8 Local_u8Address ;    //local variable for address after calculation

	if(Copy_u8XPosition == 0)      //in case of existence in first row
	    Local_u8Address = Copy_u8YPosition ;

	else if(Copy_u8XPosition == 1)      //in case of existence in second row
	    Local_u8Address = Copy_u8YPosition + 0x40 ;

	//a command to set the location of start
	CLCD_voidSendCmd(Local_u8Address | (1<<7));
}

/****************************************************************************************************/

void CLCD_voidWriteSpecialChar(u8 *Copy_pu8Pattern , u8 Copy_u8PatternNumber ,u8 Copy_u8XPosition ,u8 Copy_u8YPosition)
{
	u8 Local_u8Iterator ;           //local variable for looping over CGRAM locations
	u8 Local_u8CGRAMadress ;        //local variable for calculations of CGRAM address
	Local_u8CGRAMadress = Copy_u8PatternNumber * 8 ;   //each block is 8Bytes

	CLCD_voidSendCmd(Local_u8CGRAMadress + 64) ; //sending CGRAM address command to lcd with bit no6 =1

	/*looping over all 8 bytes of the chosen location*/
	for(Local_u8Iterator = 0 ; Local_u8Iterator <8 ; Local_u8Iterator++)
	{
		 CLCD_voidSendData(Copy_pu8Pattern[Local_u8Iterator]); //sending pattern of each byte to CGRAM
	}

	CLCD_voidGotoXY(Copy_u8XPosition , Copy_u8YPosition);  //returning back to DDRAM to display the pattern

	CLCD_voidSendData(Copy_u8PatternNumber);      //displaying pattern written on CGRAM (block access)
}

/****************************************************************************************************/

void CLCD_voidDisplayNumber(u32 Copy_u32DisplayedNumber)
{
	u32 Local_u32Reserved = 1 ;

	while(Copy_u32DisplayedNumber != 0)
	{
		Local_u32Reserved=Local_u32Reserved*10 + Copy_u32DisplayedNumber%10 ;
		Copy_u32DisplayedNumber/=10;
	}
	do
	{
		CLCD_voidSendData((Local_u32Reserved%10)+'0');
		Local_u32Reserved/=10;
	}
	while(Local_u32Reserved!=1);
}
