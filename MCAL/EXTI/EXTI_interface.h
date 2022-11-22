/**********************************************************/
/*           Author  : Asmaa Mohsen                       */
/*           Layer   : MCAL                               */
/*           Version : 1.00                               */
/*           SWC     : EXTI                               */
/**********************************************************/

/*preprocessor header file guard*/
#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

/**********************************Interfacing macros**********************************/

/*macros for interrupts*/
#define EXTI_INT0                1
#define EXTI_INT1                2
#define EXTI_INT2                3


/*macros for sense signals*/
#define EXTI_u8FALLING_EDGE               1
#define EXTI_u8RISING_EDGE                2
#define EXTI_u8LOW_LEVEL                  3
#define EXTI_u8ON_CHANGE                  4


/**********************************Functions' prototypes**********************************/

/*Description  :  this function is to initialize an external interrupt*/
/*Input        :  interrupt number                                    */
/*			      Sense signal of interrupt                           */
/*Output       :  error indicator                                     */
/*Configuration:  post build									      */
u8 EXTI_u8SetSenseSignal(u8 Copy_u8InterruptNumber , u8 Copy_u8SenseSignal);


/*Description  :  this function is to enable a specific interrupt */
/*Input        :  interrupt number[INT0 | INT1 | INT2]            */
/*Output       :  error indicator								  */
/*Configuration:  post build									   */
u8 EXTI_voidEnableInt(u8 Copy_u8InterruptNumber);

/*Description  :  this function is to disable a specific interrupt */
/*Input        :  interrupt number[INT0 | INT1 | INT2]             */
/*Output       :  error indicator		    				       */
/*Configuration:  post build									   */
u8 EXTI_voidEnableInt(u8 Copy_u8InterruptNumber);


/*Description  :  this function is to set call back for interrupt 0 */
/*Input        :  pointer to function takes void and returns void   */
/*Output       :  error indicator                                   */
/*Configuration:  post build                                        */
u8 EXTI_u8Int0SetCallBack(void(*Copy_pvInt0Func)(void));

/*Description  :  this function is to set call back for interrupt 1 */
/*Input        :  pointer to function takes void and returns void   */
/*Output       :  error indicator                                   */
/*Configuration:  post build                                        */
u8 EXTI_u8Int1SetCallBack(void(*Copy_pvInt1Func)(void));

/*Description  :  this function is to set call back for interrupt 2 */
/*Input        :  pointer to function takes void and returns void   */
/*Output       :  error indicator                                   */
/*Configuration:  post build                                        */
u8 EXTI_u8Int2SetCallBack(void(*Copy_pvInt2Func)(void));



/*Description  :  this function is to initialize interrupt 0 with specific sense signal*/
/*Input        :  void 																   */
/*Output       :  void																   */
/*Configuration:  pre-build													           */
void EXTI_voidInt0Init(void);


/*Description  :  this function is to initialize interrupt 1 with specific sense signal*/
/*Input        :  void 																   */
/*Output       :  void																   */
/*Configuration:  pre-build													           */
void EXTI_voidInt1Init(void);


/*Description  :  this function is to initialize interrupt 2 with specific sense signal*/
/*Input        :  void 																   */
/*Output       :  void																   */
/*Configuration:  pre-build													           */
void EXTI_voidInt2Init(void);




#endif /* EXTI_INTERFACE_H_ */
