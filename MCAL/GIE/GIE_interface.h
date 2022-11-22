/**********************************************************/
/*           Author  : Asmaa Mohsen                       */
/*           Layer   : MCAL                               */
/*           Version : 1.00                               */
/*           SWC     : GIE                                */
/**********************************************************/

/*preprocessor header file guard*/
#ifndef GIE_INTERFACE_H_
#define GIE_INTERFACE_H_

/*Description :  this function is to enable global interrupt */
/*Input       :  void										 */
/*Output      :  void										 */
void GIE_voidEnableGlobalInterrupt(void);


/*Description :  this function is to disable global interrupt*/
/*Input       :  void					  					 */
/*Output      :  void										 */
void GIE_voidDisableGlobalInterrupt(void);

#endif /* GIE_INTERFACE_H_ */
