#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "USART_interface.h"
#include "USART_register.h"
#include "USART_private.h"
#include "USART_config.h"


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

	/*Switching over interrupts */
	switch(Copy_pxUart->Interrupt)
	{
		case NO_INTERRUPT :
			CLR_BIT(USART_UCSRB, UCSRB_TXCIE);
			CLR_BIT(USART_UCSRB, UCSRB_RXCIE);
			break;

		case TRANSMISSION_INTERRUPT_ENABLE :
			SET_BIT(USART_UCSRB, UCSRB_TXCIE);
			break ;

		case RECEIVE_INTERRUPT_ENABLE :
			SET_BIT(USART_UCSRB, UCSRB_RXCIE);
			break;

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


void USART_voidSent(u16 Copy_u16Data)
{
	while((GET_BIT(USART_UCSRA , UCSRA_UDRE))==0);
	USART_UDR = Copy_u16Data ;
}

u16 USART_u16Receive()
{
	while((GET_BIT(USART_UCSRA , UCSRA_RXC))==0);
	return USART_UDR ;
}
