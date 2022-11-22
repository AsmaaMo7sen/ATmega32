/**********************************************************/
/*           Author  : Asmaa Mohsen                       */
/*           Layer   : MCAL                               */
/*           Version : 1.00                               */
/*           SWC     : PORT                               */
/**********************************************************/

/*preprocessor file guard*/
#ifndef PORT_CONFIG_H_
#define PORT_CONFIG_H_


/*OUTPUT+LOW_OUTPUT    ->  PIN WITH LOW OUTPUT   */
/*OUTPUT+HIGH_OUTPUT   ->  PIN WITH HIGH OUTPUT  */
/*INPUT+INPUT_PULL_UP  ->  PIN WITH INPUT PULLUP */
/*INPUT+INPUT_FLOAT    ->  PIN WITH FLOAT INPUT  */

/*pins of port A*/
#define PORTA_PIN0_DIR       OUTPUT
#define PORTA_PIN1_DIR       OUTPUT
#define PORTA_PIN2_DIR       OUTPUT
#define PORTA_PIN3_DIR       OUTPUT
#define PORTA_PIN4_DIR       OUTPUT
#define PORTA_PIN5_DIR       OUTPUT
#define PORTA_PIN6_DIR       OUTPUT
#define PORTA_PIN7_DIR       OUTPUT

/*pins of port B*/
#define PORTB_PIN0_DIR       OUTPUT
#define PORTB_PIN1_DIR       OUTPUT
#define PORTB_PIN2_DIR       OUTPUT
#define PORTB_PIN3_DIR       OUTPUT
#define PORTB_PIN4_DIR       OUTPUT
#define PORTB_PIN5_DIR       OUTPUT
#define PORTB_PIN6_DIR       OUTPUT
#define PORTB_PIN7_DIR       OUTPUT

/*pins of port C*/
#define PORTC_PIN0_DIR       OUTPUT
#define PORTC_PIN1_DIR       OUTPUT
#define PORTC_PIN2_DIR       OUTPUT
#define PORTC_PIN3_DIR       OUTPUT
#define PORTC_PIN4_DIR       OUTPUT
#define PORTC_PIN5_DIR       OUTPUT
#define PORTC_PIN6_DIR       OUTPUT
#define PORTC_PIN7_DIR       OUTPUT

/*pins of port D*/
#define PORTD_PIN0_DIR       OUTPUT
#define PORTD_PIN1_DIR       OUTPUT
#define PORTD_PIN2_DIR       OUTPUT
#define PORTD_PIN3_DIR       OUTPUT
#define PORTD_PIN4_DIR       OUTPUT
#define PORTD_PIN5_DIR       OUTPUT
#define PORTD_PIN6_DIR       OUTPUT
#define PORTD_PIN7_DIR       OUTPUT

/**********************************************************************************/
/*pins of port A*/
#define PORTA_PIN0_INIT_VAL       LOW_OUTPUT
#define PORTA_PIN1_INIT_VAL       LOW_OUTPUT
#define PORTA_PIN2_INIT_VAL       LOW_OUTPUT
#define PORTA_PIN3_INIT_VAL       LOW_OUTPUT
#define PORTA_PIN4_INIT_VAL       LOW_OUTPUT
#define PORTA_PIN5_INIT_VAL       LOW_OUTPUT
#define PORTA_PIN6_INIT_VAL       LOW_OUTPUT
#define PORTA_PIN7_INIT_VAL       LOW_OUTPUT

/*pins of port B*/
#define PORTB_PIN0_INIT_VAL       LOW_OUTPUT
#define PORTB_PIN1_INIT_VAL       LOW_OUTPUT
#define PORTB_PIN2_INIT_VAL       LOW_OUTPUT
#define PORTB_PIN3_INIT_VAL       HIGH_OUTPUT
#define PORTB_PIN4_INIT_VAL       HIGH_OUTPUT
#define PORTB_PIN5_INIT_VAL       HIGH_OUTPUT
#define PORTB_PIN6_INIT_VAL       HIGH_OUTPUT
#define PORTB_PIN7_INIT_VAL       HIGH_OUTPUT

/*pins of port C*/
#define PORTC_PIN0_INIT_VAL       LOW_OUTPUT
#define PORTC_PIN1_INIT_VAL       LOW_OUTPUT
#define PORTC_PIN2_INIT_VAL       HIGH_OUTPUT
#define PORTC_PIN3_INIT_VAL       HIGH_OUTPUT
#define PORTC_PIN4_INIT_VAL       HIGH_OUTPUT
#define PORTC_PIN5_INIT_VAL       HIGH_OUTPUT
#define PORTC_PIN6_INIT_VAL       LOW_OUTPUT
#define PORTC_PIN7_INIT_VAL       LOW_OUTPUT

/*pins of port D*/
#define PORTD_PIN0_INIT_VAL       LOW_OUTPUT
#define PORTD_PIN1_INIT_VAL       HIGH_OUTPUT
#define PORTD_PIN2_INIT_VAL       HIGH_OUTPUT
#define PORTD_PIN3_INIT_VAL       HIGH_OUTPUT
#define PORTD_PIN4_INIT_VAL       HIGH_OUTPUT
#define PORTD_PIN5_INIT_VAL       HIGH_OUTPUT
#define PORTD_PIN6_INIT_VAL       HIGH_OUTPUT
#define PORTD_PIN7_INIT_VAL       LOW_OUTPUT

#endif /* PORT_CONFIG_H_ */
