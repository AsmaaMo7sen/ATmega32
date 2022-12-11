/**********************************************************/
/*           Author  : Asmaa Mohsen                       */
/*           Layer   : MCAL                               */
/*           Version : 1.00                               */
/*           SWC     : SPI		                          */
/**********************************************************/

/*preprocessor header file guard*/
#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

/*****************************************************************************************/
/*****************************************************************************************/

/*struct to initialize SPI Master characteristics*/
typedef struct
{
	u8 Interrupt     ;
	u8 DataOrder     ;
	u8 ClockPolarity ;
	u8 ClockPhase    ;
	u8 Prescaler     ;
}MASTER_t;

/*struct to initialize SPI Slave characteristics*/
typedef struct
{
	u8 Interrupt     ;
	u8 DataOrder     ;
	u8 ClockPolarity ;
	u8 ClockPhase    ;
}SLAVE_t;

/*****************************************************************************************/
/**********************************Interfacing macros*************************************/
/*****************************************************************************************/

/*Node status*/
#define MASTER                        1      //Node as a master
#define SLAVE                         2      //Node as a slave

/*Interrupt state*/
#define INTERRUPT_ENABLE              1      //enable end of data transfer interrupt
#define INTERRUPT_DISABLE             2      //disable end of data transfer interrupt

/*Data order*/
#define LSB_FIRST                     1      //sending LSB first
#define MSB_FIRST                     2      //sending MSB first

/*Clock Polarity*/
#define LEADING_RISING                1      //leading edge is rising & trailing edge is falling
#define LEADING_FALLING               2      //leading edge is falling & trailing edge is rising

/*Clock Phase*/
#define SAMPLE_AT_LEAD                1      //sample(receive) at leading edge and setup(send) at trailing edge
#define SETUPT_AT_LEAD                2      //setup(send) at leading edge and sample(receive) at trailing edge

/*Clock prescaler*/
#define CLK_DIV_BY_2                  1
#define CLK_DIV_BY_4                  2
#define CLK_DIV_BY_8                  3
#define CLK_DIV_BY_16                 4
#define CLK_DIV_BY_32                 5
#define CLK_DIV_BY_64                 6
#define CLK_DIV_BY_128                7


/*****************************************************************************************/
/*********************************Functions' prototype************************************/
/*****************************************************************************************/

/*Description :  this function is to initialize the node as a master        */
/*Input       :  pointer to struct of node characteristics    			    */
/*Output	  :  error indicator											*/
u8 SPI_u8MasterInit(MASTER_t * Copy_xpMasterPtr);


/*Description :  this function is to initialize the node as a slave         */
/*Input       :  pointer to struct of node characteristics    			    */
/*Output	  :  error indicator											*/
u8 SPI_u8SlaveInit(SLAVE_t * Copy_xpSlavePtr);

/*Description :  this function is to transfer data between nodes            */
/*Input       :  data to be sent 			    	 			   			*/
/*Output	  :  received data  											*/
u8 SPI_u8Trasceive(u8 Copy_u8Data);

#endif /* SPI_INTERFACE_H_ */
