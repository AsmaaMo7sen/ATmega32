/**********************************************************/
/*           Author  : Asmaa Mohsen                       */
/*           Layer   : HAL                                */
/*           Version : 1.00                               */
/*           SWC     : CLCD                               */
/**********************************************************/

/*pre-processor file guard*/
#ifndef CLCD_INTERFACE_H_
#define CLCD_INTERFACE_H_

/*this function is to initialize clcd*/
void CLCD_voidInit(void);

/*this function is to send commands to microcontroller of clcd*/
void CLCD_voidSendCmd(u8 Copy_u8Cmd);

/*this function is to send data to clcd*/
void CLCD_voidSendData(u8 Copy_u8Data);

/*this function is to display a string on lcd*/
void CLCD_voidSendString(const char * Copy_pString);

/*this function is to write on specific location on lcd*/
void CLCD_voidGotoXY(u8 Copy_u8XPosition ,u8 Copy_u8YPosition);

/*this function is to display a special character on lcd*/
void CLCD_voidWriteSpecialChar(u8 *Copy_pu8Pattern , u8 Copy_u8PatternNumber ,u8 Copy_u8XPosition ,u8 Copy_u8YPosition);

/*this function is to display a number*/
void CLCD_voidDisplayNumber(u32 Copy_u32DisplayedNumber);

#endif /* CLCD_INTERFACE_H_ */
