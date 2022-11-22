/**********************************************************/
/*           Author  : Asmaa Mohsen                       */
/*           Layer   : HAL                                */
/*           Version : 1.00                               */
/*           SWC     : SERVO                              */
/**********************************************************/

/*preprocessor header file guard*/
#ifndef SERVO_INTERFACE_H_
#define SERVO_INTERFACE_H_

/********************************************************************************/
/****************************Interfacing macros**********************************/
/********************************************************************************/

/*possible channels*/
#define CHANNEL_A            1      //activating action of OC1A
#define CHANNEL_B            2      //activating action of OC1B

/********************************************************************************/
/**************************Functions' prototype**********************************/
/********************************************************************************/


/*Description  :  this function is to rotate servo motor in certain angle         */
/*Input        :  output channel [channelA or channelB]			                  */
/*             :  rotation angle												  */
/*Output       :  error indicator                                     			  */
/*Configuration:  post-build    								                  */
u8 SERVO_u8Rotate(u8 Copy_u8Channel , u8 Copy_u8Angle);

#endif /* SERVO_INTERFACE_H_ */
