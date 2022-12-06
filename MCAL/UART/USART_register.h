/**********************************************************/
/*           Author  : Asmaa Mohsen                       */
/*           Layer   : MCAL                               */
/*           Version : 1.00                               */
/*           SWC     : USART                              */
/**********************************************************/

/*preprocessor header file guard*/
#ifndef USART_REGISTER_H_
#define USART_REGISTER_H_

#define USART_UDR      *((volatile u8 *)(0x2C))    //USART I/O date register
#define USART_UCSRA    *((volatile u8 *)(0x2B))	   //USART control and status register A
#define USART_UCSRB    *((volatile u8 *)(0x2A))    //USART control and status regisetr B

#define USART_UCSRC    *((volatile u8 *)(0x40))    //USART control and status register C sharing same address with UBRRH
#define USART_UBBRH    *((volatile u8 *)(0x40))    //USART baud rate register high

#define USART_UBBRL    *((volatile u8 *)(0x29))    //USART baud rate register low


#endif /* USART_REGISTER_H_ */
