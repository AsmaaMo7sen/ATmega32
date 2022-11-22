/**********************************************************/
/*           Author  : Asmaa Mohsen                       */
/*           Layer   : HAL                                */
/*           Version : 1.00                               */
/*           SWC     : CLCD                               */
/**********************************************************/

/*per-processor file guard*/
#ifndef CLCD_CONFIG_H_
#define CLCD_CONFIG_H_

/*port of data pins*/
#define CLCD_u8DATA_PORT         DIO_u8PORTA

/*port of control pins*/
#define CLCD_u8CTRL_PORT         DIO_u8PORTB

/*control pins*/
#define CLCD_u8RS_PIN            DIO_u8PIN0    //register select pin
#define CLCD_u8R_W_PIN           DIO_u8PIN1    //read write pin
#define CLCD_u8EN_PIN            DIO_u8PIN2    //enable pin


#endif /* CLCD_CONFIG_H_ */
