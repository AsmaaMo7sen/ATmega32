/**********************************************************/
/*           Author  : Asmaa Mohsen                       */
/*           Layer   : HAL                                */
/*           Version : 1.00                               */
/*           SWC     : KEYPAD                             */
/**********************************************************/

/*preprocessor file guard*/
#ifndef KPD_CONFIG_H_
#define KPD_CONFIG_H_


#define KPD_u8PORT                DIO_u8PORTA

#define KPD_u8COL0_PIN            DIO_u8PIN0
#define KPD_u8COL1_PIN            DIO_u8PIN1
#define KPD_u8COL2_PIN            DIO_u8PIN2
#define KPD_u8COL3_PIN            DIO_u8PIN3

#define KPD_u8ROW0_PIN            DIO_u8PIN4
#define KPD_u8ROW1_PIN            DIO_u8PIN5
#define KPD_u8ROW2_PIN            DIO_u8PIN6
#define KPD_u8ROW3_PIN            DIO_u8PIN7


/*set a value to return in case of no pressed keys , out of range of[0-15]*/
#define NO_PRESSED_KEY_STATE          0xFF

/*a configurable array to set values of button*/
#define KPD_ARRAY     {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}}


#endif /* KPD_CONFIG_H_ */
