/**********************************************************/
/*           Author  : Asmaa Mohsen                       */
/*           Layer   : MCAL                               */
/*           Version : 1.00                               */
/*           SWC     : TWI                                */
/**********************************************************/

/*Preprocessor Header File Guard*/
#ifndef TWI_REGISTER_H_
#define TWI_REGISTER_H_


/************TWI registers*************/

#define TWI_TWCR    *((volatile u8*)(0x56))    //TWI Control Register
#define TWI_TWDR    *((volatile u8*)(0x23))    //TWI Data Register
#define TWI_TWAR    *((volatile u8*)(0x22))    //TWI Slave Address Register
#define TWI_TWSR    *((volatile u8*)(0x21))    //TWI Status Register
#define TWI_TWBR    *((volatile u8*)(0x20))    //TWI Bit rate Register




#endif /* TWI_REGISTER_H_ */
