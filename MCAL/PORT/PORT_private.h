/**********************************************************/
/*           Author  : Asmaa Mohsen                       */
/*           Layer   : MCAL                               */
/*           Version : 1.00                               */
/*           SWC     : PORT                               */
/**********************************************************/

/*preprocessor file guard*/
#ifndef PORT_PRIVATE_H_
#define PORT_PRIVATE_H_


/*macros for directions of pins*/
#define OUTPUT               1
#define INPUT                0

/*macros for values of output pins*/
#define HIGH_OUTPUT          1
#define LOW_OUTPUT           0

/*macros for values of input pins*/
#define INPUT_FLOAT          0
#define INPUT_PULL_UP        1


#define  CONC(b7,b6,b5,b4,b3,b2,b1,b0)   CONC_HELPER(b7,b6,b5,b4,b3,b2,b1,b0)

#define  CONC_HELPER(b7,b6,b5,b4,b3,b2,b1,b0)  0b##b7##b6##b5##b4##b3##b2##b1##b0

/*value to be sent to DDR register*/
#define  PORTA_DIR   CONC(PORTA_PIN7_DIR,PORTA_PIN6_DIR,PORTA_PIN5_DIR,PORTA_PIN4_DIR,PORTA_PIN3_DIR,PORTA_PIN2_DIR,PORTA_PIN1_DIR,PORTA_PIN0_DIR)
#define  PORTB_DIR   CONC(PORTB_PIN7_DIR,PORTB_PIN6_DIR,PORTB_PIN5_DIR,PORTB_PIN4_DIR,PORTB_PIN3_DIR,PORTB_PIN2_DIR,PORTB_PIN1_DIR,PORTB_PIN0_DIR)
#define  PORTC_DIR   CONC(PORTC_PIN7_DIR,PORTC_PIN6_DIR,PORTC_PIN5_DIR,PORTC_PIN4_DIR,PORTC_PIN3_DIR,PORTC_PIN2_DIR,PORTC_PIN1_DIR,PORTC_PIN0_DIR)
#define  PORTD_DIR   CONC(PORTD_PIN7_DIR,PORTD_PIN6_DIR,PORTD_PIN5_DIR,PORTD_PIN4_DIR,PORTD_PIN3_DIR,PORTD_PIN2_DIR,PORTD_PIN1_DIR,PORTD_PIN0_DIR)

/*value to be sent to PORT register*/
#define  PORTA_VAL   CONC(PORTA_PIN7_INIT_VAL,PORTA_PIN6_INIT_VAL,PORTA_PIN5_INIT_VAL,PORTA_PIN4_INIT_VAL,PORTA_PIN3_INIT_VAL,PORTA_PIN2_INIT_VAL,PORTA_PIN1_INIT_VAL,PORTA_PIN0_INIT_VAL)
#define  PORTB_VAL   CONC(PORTB_PIN7_INIT_VAL,PORTB_PIN6_INIT_VAL,PORTB_PIN5_INIT_VAL,PORTB_PIN4_INIT_VAL,PORTB_PIN3_INIT_VAL,PORTB_PIN2_INIT_VAL,PORTB_PIN1_INIT_VAL,PORTB_PIN0_INIT_VAL)
#define  PORTC_VAL   CONC(PORTC_PIN7_INIT_VAL,PORTC_PIN6_INIT_VAL,PORTC_PIN5_INIT_VAL,PORTC_PIN4_INIT_VAL,PORTC_PIN3_INIT_VAL,PORTC_PIN2_INIT_VAL,PORTC_PIN1_INIT_VAL,PORTC_PIN0_INIT_VAL)
#define  PORTD_VAL   CONC(PORTD_PIN7_INIT_VAL,PORTD_PIN6_INIT_VAL,PORTD_PIN5_INIT_VAL,PORTD_PIN4_INIT_VAL,PORTD_PIN3_INIT_VAL,PORTD_PIN2_INIT_VAL,PORTD_PIN1_INIT_VAL,PORTD_PIN0_INIT_VAL)


#endif /* PORT_PRIVATE_H_ */
