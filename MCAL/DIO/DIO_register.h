/**********************************************************/
/*           Author  : Asmaa Mohsen                       */
/*           Layer   : MCAL                               */
/*           Version : 1.00                               */
/*           SWC     : DIO                                */
/**********************************************************/

#ifndef DIO_REGISTER_H_
#define DIO_REGISTER_H_

//PORT A registers
#define PORTA   *((volatile u8*)(0x3B))
#define PINA    *((volatile u8*)(0x39))

//PORT B registers
#define PORTB   *((volatile u8*)(0x38))
#define PINB    *((volatile u8*)(0x36))

//PORT C registers
#define PORTC   *((volatile u8*)(0x35))
#define PINC    *((volatile u8*)(0x33))

//PORT D registers
#define PORTD   *((volatile u8*)(0x32))
#define PIND    *((volatile u8*)(0x30))


#endif /* DIO_REGISTER_H_ */
