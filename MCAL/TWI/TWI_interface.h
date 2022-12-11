/**********************************************************/
/*           Author  : Asmaa Mohsen                       */
/*           Layer   : MCAL                               */
/*           Version : 1.00                               */
/*           SWC     : TWI                                */
/**********************************************************/

/*Preprocessor Header File Guard*/
#ifndef TWI_INTERFACE_H_
#define TWI_INTERFACE_H_


typedef enum
{
	NO_ERROR ,
	START_CONDITION_ERROR ,
	REPEATED_START_CONDITION_ERROR,
	ADDRESS_WITH_WRITE_ERROR,
	ADDRESS_WITH_READ_ERROR,
	MSTR_WRITE_DATA_ERROR,
	MSTR_READ_DATA_ERROR,
}TWI_ErrState;


/*Description   : This fucntion is to initialize TWI as a master */
/*Input 		: Address of the node							 */
/*Return		: Void											 */
/*NOTE !!!      : PASS 0 AS INPUT IF THE NODE IS A MASTER ONLY   */
void TWI_voidMasterInit(u8 Copy_u8Address);


/*Description   : This fucntion is to initialize TWI as a slave   */
/*Input 		: Address of the node							  */
/*Return		: Void											  */
void TWI_voidSlaveInit(u8 Copy_u8Address);


/*Description   : This fucntion is send a start condition         */
/*Input 		: Void											  */
/*Return		: Error State									  */
TWI_ErrState TWI_SendStartCondition(void);


/*Description   : This fucntion is send a repeated start 	      */
/*Input 		: Void											  */
/*Return		: Error State									  */
TWI_ErrState TWI_SendRepeatedStart(void);


/*Description   : This fucntion is to write to a certain slave    */
/*Input 		: Target Slave Address							  */
/*Return		: Error State									  */
TWI_ErrState TWI_SendSlaveAddressWithWriteCmd(u8 Copy_u8SlaveAddress);


/*Description   : This fucntion is to write a data byte on the bus*/
/*Input 		: Data to be sent   							  */
/*Return		: Error State									  */
TWI_ErrState TWI_MasterWriteDataByte(u8 Copy_u8DataByte);


/*Description   : This fucntion is to read from a certain slave   */
/*Input 		: Target Slave Address							  */
/*Return		: Error State									   */
TWI_ErrState TWI_SendSlaveAddressWithReadCmd(u8 Copy_u8SlaveAddress);


/*Description   : This fucntion is to receive a data byte         */
/*Input 		: Pointer to received data 						  */
/*Return		: Error State									  */
TWI_ErrState TWI_MasterReadDataByte(u8 * Copy_pu8ReceivedDataByte);


/*Description   : This fucntion is send a stop condition		  */
/*Input 		: Void											  */
/*Return		: Void											  */
void TWI_voidSendStopCondition(void);



#endif /* TWI_INTERFACE_H_ */
