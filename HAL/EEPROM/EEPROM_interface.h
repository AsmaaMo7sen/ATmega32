/**********************************************************/
/*           Author  : Asmaa Mohsen                       */
/*           Layer   : HAL                                */
/*           Version : 1.00                               */
/*           SWC     : EEPROM                             */
/**********************************************************/

/*preprocessor header file guard*/
#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_


/**************************Interfacing macros*************************/

//Possible connections for A2 pin
#define HIGH           1
#define LOW            0


/**************************Functions' prototypes**************************/

/*Description   : This fucntion is to send a byte to a certain location of EEPROM */
/*Input 		: Address of target location [0:1023] 		                      */
/*				: Data byte to be sent						                      */
/*Return		: Void										                      */
void EEPROM_voidSendDataByte(u8 Copy_u8Data , u16 Copy_u16Address);

/*Description   : This fucntion is to read from a certain location of EEPROM      */
/*Input 		: Address of target location [0:1023] 		                      */
/*				: Pointer to return read byte 					                  */
/*Return		: Void											                  */
u8 EEPROM_u8ReadDataByte( u16 Copy_u16Adderss);


#endif /* EEPROM_INTERFACE_H_ */
