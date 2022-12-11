
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TWI_interface.h"
#include "EEPROM_interface.h"
#include "EEPROM_private.h"
#include "EEPROM_config.h"



void EEPROM_voidSendDataByte(u8 Copy_u8Data , u16 Copy_u16Address)
{

	/*local variable for EEPROM address*/
	//1010 fixed
	//A2 pin configurable (either high or low)
	//last two bits is for page access
	u8 Local_u8Address = ((1010) | (A2_PIN<<2) | (u16)(Copy_u16Address>>8));

	/* 1) Sending start condition on the bus*/
	TWI_SendStartCondition();

	/* 2) Sending address of EEPROM with target page and write command*/
	TWI_SendSlaveAddressWithWriteCmd(Local_u8Address) ;

	/* 3) Sending target location of the EEPROM*/
	TWI_MasterWriteDataByte((u8)Copy_u16Address) ;

	/* 4) Sending target data to the specified location*/
	TWI_MasterWriteDataByte(Copy_u8Data);

	/* 5) Sending stop condition*/
	TWI_voidSendStopCondition() ;

}


u8 EEPROM_u8ReadDataByte( u16 Copy_u16Address)
{

	/*local variable to get read data*/
	u8 Local_u8Data ;

	/*local variable for EEPROM address*/
	//1010 fixed
	//A2 pin configurable (either high or low)
	//last two bits is for page access
	u8 Local_u8Address = ((1010) | (A2_PIN<<2) | (u8)(Copy_u16Address>>8));


	/* 1) Sending start condition on the bus*/
	TWI_SendStartCondition();

	/* 2) Sending address of EEPROM with target page and write command*/
	TWI_SendSlaveAddressWithWriteCmd(Local_u8Address) ;

	/* 3) Sending target location of the EEPROM*/
	TWI_MasterWriteDataByte((u8)Copy_u16Address) ;

	/* 4) Sending repeated start condition*/
	TWI_SendRepeatedStart() ;

	/* 5) Sending read request from EEPROM*/
	TWI_SendSlaveAddressWithReadCmd(Local_u8Address);

	/* 6) Reading from target location*/
	TWI_MasterReadDataByte(&Local_u8Data);

	/* 7) Sending stop condition*/
	TWI_voidSendStopCondition();

	return Local_u8Data ;
}
