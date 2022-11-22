/**********************************************************/
/*           Author  : Asmaa Mohsen                       */
/*           Layer   : MCAL                               */
/*           Version : 1.00                               */
/*           SWC     : PORT                               */
/**********************************************************/

/*preprocessor file guard*/
#ifndef PORT_REGISTER_H_
#define PORT_REGISTER_H_

/*registers of pins direction*/
#define DDRA   *((volatile u8 *)(0x3A))
#define DDRB   *((volatile u8 *)(0x37))
#define DDRC   *((volatile u8 *)(0x34))
#define DDRD   *((volatile u8 *)(0x31))

/*registers of output pins value*/
#define PORTA   *((volatile u8*)(0x3B))
#define PORTB   *((volatile u8*)(0x38))
#define PORTC   *((volatile u8*)(0x35))
#define PORTD   *((volatile u8*)(0x32))


#endif /* PORT_REGISTER_H_ */
