/**********************************************************/
/*           Author  : Asmaa Mohsen                       */
/*           Layer   : MCAL                               */
/*           Version : 1.00                               */
/*           SWC     : EXTI                               */
/**********************************************************/

/*preprocessor header file guard*/
#ifndef EXTI_CONFIG_H_
#define EXTI_CONFIG_H_



/*Configurations of sense signal of interrupts*/
/*Options :
 	 	 	1. LOW_LEVEL
 	 	 	2. ON_CHANGE
 	 	 	3. FALLING_EDGE
 	 	 	4. RISING_EDGE
*/
#define INT0_SENSE	FALLING_EDGE
#define INT1_SENSE	FALLING_EDGE
#define INT2_SENSE	FALLING_EDGE

/*Configurations of interrupt enable*/
/*Option  :
 	 	 	1. Enable
 	 	 	2. Disable
*/
#define INT0_ENABLE  ENABLE
#define INT1_ENABLE  DISABLE
#define INT2_ENABLE  DISABLE




#endif /* EXTI_CONFIG_H_ */
