#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "USART_interface.h"
#include "USART_register.h"
#include "USART_private.h"
#include "USART_config.h"

/*Global pointer to function for end of transmission ISR*/
void (*EndOfTransmission)(void) = NULL ;

/*Global pointer to function for end of receive ISR*/
void (*EndOfReceive)(void) = NULL ;

/*global pointer to set received data asynchronously*/
u8 * GlobalPtrToRecChar = NULL ;

/*global string to send string asynchronously */
char * GlobalString  = NULL;

/*global variable used as a flag of interrupt source of transmission [either a string or a character]*/
u8 TRAN_INTERRUPT_SRC = IDLE ;


/********************************************************************************************************/
/**************************************Functions' implementation*****************************************/
/********************************************************************************************************/
u8 USART_u8Init(USART_t * Copy_pxUart)
{
	/*local variable for error checking*/
	u8 Local_u8ErrorState = OK ;

	/*local variable to assign value of UCSRC register*/
	u8 Local_u8UCSRC_value  = 0 ;

	/*Switching over modes of USART*/
	switch(Copy_pxUart->Node)
	{
		/*in case of running as a transmitter*/
		case TRANSMITTER:
			SET_BIT(USART_UCSRB , UCSRB_TXEN);
			break ;

		/*in case of running as a receiver*/
		case RECEIVER :
			SET_BIT(USART_UCSRB , UCSRB_RXEN);
			break ;

		case TRANS_AND_REC :
			SET_BIT(USART_UCSRB , UCSRB_TXEN);
			SET_BIT(USART_UCSRB , UCSRB_RXEN);
			break ;

		/*in case of wrong input*/
		default :
			Local_u8ErrorState = NOK ;
			break;
	}


	/*Switching over different options of exchanged data size*/
	switch(Copy_pxUart->CharSize)
	{
		case CHAR_SIZE_5 :
			Local_u8UCSRC_value = (1<<UCSRC_URSEL) | ((Copy_pxUart->Mode)<<UCSRC_UMSEL) | ((Copy_pxUart->Parity)<<UCSRC_UPM0) |
			              ((Copy_pxUart->StopBits)<<UCSRC_USBS) | (0<<UCSRC_UCSZ1) | (0<<UCSRC_UCSZ0) ;
			USART_UCSRC = Local_u8UCSRC_value ;
			CLR_BIT(USART_UCSRB , UCSRB_UCSZ2) ;
			break ;

		case CHAR_SIZE_6 :
			Local_u8UCSRC_value = (1<<UCSRC_URSEL) | ((Copy_pxUart->Mode)<<UCSRC_UMSEL) | ((Copy_pxUart->Parity)<<UCSRC_UPM0) |
					      ((Copy_pxUart->StopBits)<<UCSRC_USBS) | (0<<UCSRC_UCSZ1) | (1<<UCSRC_UCSZ0) ;
			USART_UCSRC = Local_u8UCSRC_value ;
			CLR_BIT(USART_UCSRB , UCSRB_UCSZ2) ;
			break ;

		case CHAR_SIZE_7 :
			Local_u8UCSRC_value = (1<<UCSRC_URSEL) | ((Copy_pxUart->Mode)<<UCSRC_UMSEL) | ((Copy_pxUart->Parity)<<UCSRC_UPM0) |
						  ((Copy_pxUart->StopBits)<<UCSRC_USBS) | (1<<UCSRC_UCSZ1) | (0<<UCSRC_UCSZ0) ;
			USART_UCSRC = Local_u8UCSRC_value ;
			CLR_BIT(USART_UCSRB , UCSRB_UCSZ2) ;
			break ;

		case CHAR_SIZE_8 :
			Local_u8UCSRC_value = (1<<UCSRC_URSEL) | ((Copy_pxUart->Mode)<<UCSRC_UMSEL) | ((Copy_pxUart->Parity)<<UCSRC_UPM0) |
						  ((Copy_pxUart->StopBits)<<UCSRC_USBS) | (1<<UCSRC_UCSZ1) | (1<<UCSRC_UCSZ0) ;
			USART_UCSRC = Local_u8UCSRC_value ;
			CLR_BIT(USART_UCSRB , UCSRB_UCSZ2) ;
			break ;

		case CHAR_SIZE_9 :
			Local_u8UCSRC_value = (1<<UCSRC_URSEL) | ((Copy_pxUart->Mode)<<UCSRC_UMSEL) | ((Copy_pxUart->Parity)<<UCSRC_UPM0) |
						  ((Copy_pxUart->StopBits)<<UCSRC_USBS) | (1<<UCSRC_UCSZ1) | (1<<UCSRC_UCSZ0) ;
			SET_BIT(USART_UCSRB , UCSRB_UCSZ2) ;
			break ;

		/*in case of wrong input*/
		default :
			Local_u8ErrorState = NOK ;
			break;
	}


	/*baud rate  = 9600*/
	USART_UBBRL = 51 ;

	/*return from this function*/
	return Local_u8ErrorState ;
}

/*********************************************************************************************************/
/*********************************************************************************************************/

void USART_voidSendCharSync(u8 Copy_u8Data)
{
	/*polling till UDR register is ready to receive new data*/
	while((GET_BIT(USART_UCSRA , UCSRA_UDRE))== 0 );

	/*assigning data to UDR to get transmitted*/
	USART_UDR = Copy_u8Data ;

	/*polling till end of transmission*/
	while((GET_BIT(USART_UCSRA , UCSRA_TXC)) == 0 );

	/*clearing end of transmission flag*/
	CLR_BIT(USART_UCSRA , UCSRA_TXC);
}

/*********************************************************************************************************/
/*********************************************************************************************************/

u8 USART_u8SendCharAsync(u8 Copy_u8Data , void(*CopyPtrToFunc)(void))
{
	/*local variable for error checking*/
	u8 Local_u8ErrorState = OK ;

	/*setting flag of source of interrupt to be a single character*/
	TRAN_INTERRUPT_SRC = CHAR ;

	/*polling till UDR register is ready to receive new data*/
	while((GET_BIT(USART_UCSRA , UCSRA_UDRE))== 0 );

	/*assigning data to UDR to get transmitted*/
	USART_UDR = Copy_u8Data ;

	/*enable end of transmission interrupt*/
	SET_BIT(USART_UCSRB, UCSRB_TXCIE);

	/*checking for notification function*/
	if(CopyPtrToFunc != NULL)
	{
		EndOfTransmission = CopyPtrToFunc ;
	}
	else
	{
		Local_u8ErrorState = NULL_POINTER ;
	}

	/*return from this function*/
	return Local_u8ErrorState ;
}

/*********************************************************************************************************/
/*********************************************************************************************************/

u8 USART_u8ReceiveCharSync(void)
{
	/*polling till data is completely received*/
	while((GET_BIT(USART_UCSRA , UCSRA_RXC))==0);

	/*clearing flag and getting received data*/
	return USART_UDR ;
}

/*********************************************************************************************************/
/*********************************************************************************************************/

u8 USART_u8ReceiveCharAsync(u8 * Copy_pu8ReceivedData , void(*CopyPtrToFunc)(void) )
{
	/*local variable for error checking*/
	u8 Local_u8ErrorState = OK ;

	/*enable end of receive interrupt*/
	SET_BIT(USART_UCSRB, UCSRB_RXCIE);

	/*Setting global pointer to access the same address*/
	GlobalPtrToRecChar = Copy_pu8ReceivedData ;

	/*checking for notification function*/
	if(CopyPtrToFunc != NULL)
	{
		EndOfReceive = CopyPtrToFunc ;
	}
	else
	{
		Local_u8ErrorState = NULL_POINTER ;
	}

	/*return from this function*/
	return Local_u8ErrorState ;

}

/*********************************************************************************************************/
/*********************************************************************************************************/

void USART_voidSendStringSync(char * Copy_pcharSentString)
{
	/*local variable to loop over characters of the string*/
	u8 Local_u8Counter = 0 ;

	/*looping over string characters*/
	while(Copy_pcharSentString[Local_u8Counter] != '\0')
	{
		/*sending characters one by one*/
		USART_voidSendCharSync(Copy_pcharSentString[Local_u8Counter]);

		Local_u8Counter ++ ;
	}
}

/*********************************************************************************************************/
/*********************************************************************************************************/

u8 USART_u8SendStringAsync(char * Copy_pcharSentString , void(*CopyPtrToFunc)(void) )
{
	/*local variable for error checking*/
	u8 Local_u8ErrorState = OK ;

	/*setting flag of source of interrupt to be a string*/
	TRAN_INTERRUPT_SRC = STRING ;

	/*set global pointer to access the same address*/
	GlobalString = Copy_pcharSentString ;

	/*polling till UDR register is ready to receive new data*/
	while((GET_BIT(USART_UCSRA , UCSRA_UDRE))== 0 );

	if((Copy_pcharSentString != NULL) && (Copy_pcharSentString[0] != '\0'))
	{
		/*assigning data to UDR to get transmitted*/
		USART_UDR = Copy_pcharSentString[0] ;
	}
	else
	{
		Local_u8ErrorState = NOK ;
	}


	/*enable end of transmission interrupt*/
	SET_BIT(USART_UCSRB, UCSRB_TXCIE);


 	/*checking for notification function*/
	if(CopyPtrToFunc != NULL)
	{
		EndOfTransmission = CopyPtrToFunc ;
	}
	else
	{
		Local_u8ErrorState = NULL_POINTER ;
	}


	/*return from this function*/
	return Local_u8ErrorState ;
}

/*********************************************************************************************************/
/*********************************************************************************************************/

void USART_voidReceiveBufferSync(char * Copy_pcharReceivedBuffer , u8 Copy_u8BufferSize)
{
	/*local variable to loop over buffer elements*/
	u8 Local_u8Counter = 0 ;

	/*looping over buffer elemetns*/
	for(Local_u8Counter = 0 ; Local_u8Counter<= Copy_u8BufferSize ; Local_u8Counter++)
	{
		/*getting received character*/
		Copy_pcharReceivedBuffer[Local_u8Counter] = USART_u8ReceiveCharSync() ;
	}

}

/*********************************************************************************************************/
/*********************************************************************************************************/

void USART_voidDisableInterrupt(void)
{
	/*Disable end of transmission interrupt*/
	CLR_BIT(USART_UCSRB, UCSRB_TXCIE);

	/*Disable end of receive interrupt*/
	CLR_BIT(USART_UCSRB, UCSRB_RXCIE);

}

/*********************************************************************************************************/
/*********************************************************************************************************/

/*ISR for USART end of transmission*/
void __vector_15 (void) __attribute__((signal));
void __vector_15 (void)
{
	/*in case end of transmission of a single character*/
	if(TRAN_INTERRUPT_SRC == CHAR)
	{
		/*calling notification function*/
		EndOfTransmission ();
	}
	else if(TRAN_INTERRUPT_SRC == STRING)
	{
		u8 i = 1 ;

		/*sending remaining characters*/
		while(GlobalString[i] != '\0')
		{
			USART_voidSendCharSync(GlobalString[i]);
			i ++ ;
		}

		/*calling notification function*/
		EndOfTransmission();
	}
	else
	{
		//do nothing
	}
}

/*ISR for USART end of receive*/
void __vector_13 (void) __attribute__((signal));
void __vector_13 (void)
{
	/*getting received character*/
	*GlobalPtrToRecChar = USART_UDR ;

	/*calling notification function*/
	EndOfReceive ();
}

