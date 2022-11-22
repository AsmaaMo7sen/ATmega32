/**********************************************************/
/*           Author  : Asmaa Mohsen                       */
/*           Layer   : MCAL                               */
/*           Version : 1.00                               */
/*           SWC     : EXTI                               */
/**********************************************************/

/*preprocessor header file guard*/
#ifndef EXTI_REGISTER_H_
#define EXTI_REGISTER_H_

/**********************************EXTI registers**********************************/

#define EXTI_MCUCR   *((volatile u8 *)(0x55))
#define EXTI_MCUCSR  *((volatile u8 *)(0x54))
#define EXTI_GICR    *((volatile u8 *)(0x5B))
#define EXTI_GIFR    *((volatile u8 *)(0x5A))


#endif /* EXTI_REGISTER_H_ */
