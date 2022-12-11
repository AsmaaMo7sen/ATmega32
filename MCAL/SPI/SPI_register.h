/**********************************************************/
/*           Author  : Asmaa Mohsen                       */
/*           Layer   : MCAL                               */
/*           Version : 1.00                               */
/*           SWC     : SPI		                          */
/**********************************************************/

/*preprocessor header file guard*/
#ifndef SPI_REGISTER_H_
#define SPI_REGISTER_H_


#define SPI_SPCR     *((volatile u8*)(0x2D))    //SPI Control Register
#define SPI_SPSR     *((volatile u8*)(0x2E))    //SPI Status Register
#define SPI_SPDR     *((volatile u8*)(0x2F))    //SPI Data Register

#endif /* SPI_REGISTER_H_ */
