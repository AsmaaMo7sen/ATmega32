/**********************************************************/
/*           Author  : Asmaa Mohsen                       */
/*           Layer   : MCAL                               */
/*           Version : 1.00                               */
/*           SWC     : EXTI                               */
/**********************************************************/

/*preprocessor header file guard*/
#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_

/*********************************Configuration macros*********************************/

/*options of sense signal configurations*/
#define  LOW_LEVEL                	1
#define  ON_CHANGE    				2
#define  FALLING_EDGE 				3
#define  RISING_EDGE				4

/*options of enable or disable interrupt*/
#define ENABLE                      2
#define DISABLE                     1


/********************************Important bits**********************************/

/*interrupts enable bits */
//at GICR
#define EXTI_INT1_ENABLE           7
#define EXTI_INT0_ENABLE           6
#define EXTI_INT2_ENABLE           5

/*interrupt source control bits for INT1*/
//at MCUCR
#define EXTI_ISC11                 3
#define EXTI_ISC10                 2

/*interrupt source control bits for INT0*/
//at MCUCR
#define EXTI_ISC01                 1
#define EXTI_ISC00                 0

/*interrupt source control bit for INT2*/
//at MCUCSR
#define EXTI_ISC2                  6



#endif /* EXTI_PRIVATE_H_ */
