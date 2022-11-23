/**********************************************************/
/*           Author  : Asmaa Mohsen                       */
/*           Layer   : MCAL                               */
/*           Version : 1.00                               */
/*           SWC     : TIMER_DELAY                        */
/**********************************************************/

/*preprocessor header file guard*/
#ifndef TMR_DELAY_INTERFACE_H_
#define TMR_DELAY_INTERFACE_H_


/******************************Interfacing macros******************************/
#define PERIODIC            1
#define NON_PERIODIC        2

/******************************Functions' prototypes******************************/

/*Description :  this function is to provide delay in ms asynchronously     */
/*Input       :  Delay period in ms	[0:8380]								*/
/*            :  pointer to function for call back							*/
/*            :  either delay is periodic or not							*/
/*Output	  :  error indicator											*/
u8 TIMER_u8DelayAsynch(u16 Copy_u16DelayInMs , void(*PtrToFunc)(void) ,u8 Copy_u8Preioicty );


/*Description :  this function is to provide delay in ms synchronously      */
/*Input       :  Delay period in ms	[0:8380]								*/
/*Output	  :  error indicator											*/
u8 TIMER_u8DelaySynch(u16 Copy_u16DelayInMs );



#endif /* TMR_DELAY_INTERFACE_H_ */
