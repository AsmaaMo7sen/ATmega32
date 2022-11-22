#include "STD_TYPES.h"

#include "PWM_interface.h"
#include "SERVO_interface.h"
#include "SERVO_private.h"
#include "SERVO_config.h"

u8 SERVO_u8Rotate(u8 Copy_u8Channel , u8 Copy_u8Angle)
{
	/*local variable for error checking*/
	u8 Local_u8ErrorState = OK ;

	/*local variable for value of OCR register to get target angle*/
	u16 Local_u16MappedAngle = ((u16)Copy_u8Angle * 10) + 750 ;

	/*checking for valid range of rotation angle*/
	if(Copy_u8Angle>=0 && Copy_u8Angle<=180)
	{
		switch(Copy_u8Channel)
		{
		case CHANNEL_A :
			PWM_u8Init(CHANNEL_A , FREQUENCY_50 , Local_u16MappedAngle);
			break ;

		case CHANNEL_B :
			PWM_u8Init(CHANNEL_B , FREQUENCY_50 , Local_u16MappedAngle);
			break ;

		default :
			break ;
		}
	}

	/*in case of input angle out of possible range*/
	else
	{
		Local_u8ErrorState = OUT_OF_RANGE ;
	}

	/*return from this function*/
	return Local_u8ErrorState ;
}
