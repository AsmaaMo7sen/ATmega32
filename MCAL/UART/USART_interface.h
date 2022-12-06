/**********************************************************/
/*           Author  : Asmaa Mohsen                       */
/*           Layer   : MCAL                               */
/*           Version : 1.00                               */
/*           SWC     : USART                              */
/**********************************************************/

/*preprocessor header file guard*/
#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_

/********************************************************************************************************/
/*****************************************Interfacing macros*********************************************/
/********************************************************************************************************/

/*Running microcontroller as a transmitter or receiver or both*/
#define TRANSMITTER                      1
#define RECEIVER                         2
#define TRANS_AND_REC                    3

/*Speed of transmission either doubled or not*/
#define DOUBLE_SPEED_ENABLED             1
#define DOUBLE_SPEED_DISABLED            2

/*Different interrupt sources*/
#define NO_INTERRUPT                     1
#define TRANSMISSION_INTERRUPT_ENABLE    2
#define RECEIVE_INTERRUPT_ENABLE         3

/*Possible sizes of exchanged data*/
#define CHAR_SIZE_5                      1
#define CHAR_SIZE_6                      2
#define CHAR_SIZE_7                      3
#define CHAR_SIZE_8                      4
#define CHAR_SIZE_9                      5

/*Mode of operation*/
#define ASYNCHRONOUS                     0
#define SYNCHRONOUS                      1

/*Parity bits*/
#define NO_PARITY                        0
#define EVEN_PARITY                      2
#define ODD_PARITY                       3

/*Number of stop bits*/
#define ONE_STOP_BIT                     0
#define TWO_STOP_BITS                    1

typedef struct
{
	u8 Node     ;            //transmitter or receiver or both
 	u8 CharSize ;            //range of [5:9] bits
	u8 Mode     ;            //synchronous or asynchronous mode
	u8 Parity   ;            //no parity or even or odd parity bit
	u8 StopBits ;            //either 1 or 2 bits
	u8 Interrupt;            //transmission or receive interrupt enabled or disabled
}USART_t;

/********************************************************************************************************/
/****************************************Functions' prototypes*******************************************/
/********************************************************************************************************/

u8 USART_u8Init(USART_t * Copy_pxUart);

void USART_voidSent(u16 Copy_u16Data);
u16 USART_u16Receive();
#endif /* USART_INTERFACE_H_ */
