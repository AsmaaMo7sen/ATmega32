#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TWI_interface.h"
#include "TWI_register.h"
#include "TWI_private.h"
#include "TWI_config.h"


/*PASS 0 AS INPUT ARGUMENT IF THE MASTER WILL NOT BE A RECEIVER*/
void TWI_voidMasterInit(u8 Copy_u8Address)
{
	/*Enable master to send ACK bit after receiving data*/
	SET_BIT(TWI_TWCR , TWCR_TWEA) ;


	/* 1) Setting clock frequency to 400kbps */
	CLR_BIT(TWI_TWSR , TWSR_TWPS0);
	CLR_BIT(TWI_TWSR , TWSR_TWPS1);
	TWI_TWBR = 2 ;

	/* 2) Setting address of the node */
	if(Copy_u8Address != 0)          //if the master will be a receiver
	{
		/*setting the target address to 7 MSB of the register */
		TWI_TWAR = Copy_u8Address<<1 ;
	}

	/* 3) Enable TWI peripheral */
	SET_BIT(TWI_TWCR , TWCR_TWEN);

}

/****************************************************************************/

void TWI_voidSlaveInit(u8 Copy_u8Address)
{
	/* 1) Setting the target address to 7 MSB of the register */
	TWI_TWAR = Copy_u8Address<<1 ;

	/* 2) Enable TWI peripheral */
	SET_BIT(TWI_TWCR , TWCR_TWEN);

}

/****************************************************************************/

TWI_ErrState TWI_SendStartCondition(void)
{
	/*local enum object for error checking*/
	TWI_ErrState Local_ErrorState = NO_ERROR ;

	/* 1) Send Start Condition on the bus*/
	SET_BIT(TWI_TWCR , TWCR_TWSTA) ;

	/* 2) Clearing flag to perform the required action*/
	SET_BIT(TWI_TWCR , TWCR_TWINT) ;

	/* 3) Polling till interrupt flag is raised again (end of action)*/
	while((GET_BIT(TWI_TWCR , TWCR_TWINT)) == 0);

	/* 4) Checking for action ID*/
	if((TWI_TWSR & STATUS_MASK) != START_ACK)
	{
		Local_ErrorState = START_CONDITION_ERROR;
	}
	else
	{
		/*Do nothing*/
	}

	/*return from this function*/
	return Local_ErrorState ;
}

/****************************************************************************/

TWI_ErrState TWI_SendRepeatedStart(void)
{
	/*local enum object for error checking*/
	TWI_ErrState Local_ErrorState = NO_ERROR ;

	/* 1) Send Start Condition on the bus*/
	SET_BIT(TWI_TWCR , TWCR_TWSTA) ;

	/* 2) Clearing flag to perform the required action*/
	SET_BIT(TWI_TWCR , TWCR_TWINT) ;

	/* 3) Polling till interrupt flag is raised again (end of action)*/
	while((GET_BIT(TWI_TWCR , TWCR_TWINT)) == 0);

	/* 4) Checking for action ID*/
	if((TWI_TWSR & STATUS_MASK) != REP_START_ACK)
	{
		Local_ErrorState = REPEATED_START_CONDITION_ERROR ;
	}
	else
	{
		/*Do nothing*/
	}

	/*return from this function*/
	return Local_ErrorState ;
}

/****************************************************************************/

TWI_ErrState TWI_SendSlaveAddressWithWriteCmd(u8 Copy_u8SlaveAddress)
{
	/*local enum object for error checking*/
	TWI_ErrState Local_ErrorState = NO_ERROR ;

	/*local variable to adjust slave address and write bit into one byte*/
	//slave address in bits[1-7] and write request bit in bit [0]
	u8 Local_u8AdderssPacket = ((Copy_u8SlaveAddress<<1) | (0x00));


	/* 1) Setting address packet to data register to be sent*/
	TWI_TWDR = Local_u8AdderssPacket ;

	/* 2) Clear start condition bit*/
	CLR_BIT(TWI_TWCR , TWCR_TWSTA) ;

	/* 3) Clearing flag to perform the required action*/
	SET_BIT(TWI_TWCR , TWCR_TWINT) ;

	/* 4) Polling till interrupt flag is raised again (end of action)*/
	while((GET_BIT(TWI_TWCR , TWCR_TWINT)) == 0);

	/* 5) Checking for action ID*/
	if((TWI_TWSR & STATUS_MASK) != SLAVE_ADD_AND_WR_ACK)
	{
		Local_ErrorState = ADDRESS_WITH_WRITE_ERROR ;
	}
	else
	{
		/*Do nothing*/
	}

	/*return from this function*/
	return Local_ErrorState ;
}

/****************************************************************************/

TWI_ErrState TWI_SendSlaveAddressWithReadCmd(u8 Copy_u8SlaveAddress)
{
	/*local enum object for error checking*/
	TWI_ErrState Local_ErrorState = NO_ERROR ;

	/*local variable to adjust slave address and read bit into one byte*/
	//slave address in bits[1-7] and read request bit in bit [0]
	u8 Local_u8AdderssPacket = ((Copy_u8SlaveAddress<<1) | (0x01));


	/* 1) Setting address packet to data register to be sent*/
	TWI_TWDR = Local_u8AdderssPacket ;

	/* 2) Clear start condition bit*/
	CLR_BIT(TWI_TWCR , TWCR_TWSTA) ;

	/* 3) Clearing flag to perform the required action*/
	SET_BIT(TWI_TWCR , TWCR_TWINT) ;

	/* 4) Polling till interrupt flag is raised again (end of action)*/
	while((GET_BIT(TWI_TWCR , TWCR_TWINT)) == 0);

	/* 5) Checking for action ID*/
	if((TWI_TWSR & STATUS_MASK) != SLAVE_ADD_AND_RD_ACK)
	{
		Local_ErrorState = ADDRESS_WITH_READ_ERROR ;
	}
	else
	{
		/*Do nothing*/
	}

	/*return from this function*/
	return Local_ErrorState ;
}

/****************************************************************************/

TWI_ErrState TWI_MasterWriteDataByte(u8 Copy_u8DataByte)
{
	/*local enum object for error checking*/
	TWI_ErrState Local_ErrorState = NO_ERROR ;

	/* 1) Setting data byte to get transmitter*/
	TWI_TWDR = Copy_u8DataByte ;

	/* 2) Clearing flag to perform the required action*/
	SET_BIT(TWI_TWCR , TWCR_TWINT) ;

	/* 3) Polling till interrupt flag is raised again (end of action)*/
	while((GET_BIT(TWI_TWCR , TWCR_TWINT)) == 0);

	/* 4) Checking for action ID*/
	if((TWI_TWSR & STATUS_MASK) != MSTR_WR_BYTE_ACK)
	{
		Local_ErrorState = MSTR_WRITE_DATA_ERROR ;
	}
	else
	{
		/*Do nothing*/
	}

	/*return from this function*/
	return Local_ErrorState ;
}

/****************************************************************************/

TWI_ErrState TWI_MasterReadDataByte(u8 * Copy_pu8ReceivedDataByte)
{
	/*local enum object for error checking*/
	TWI_ErrState Local_ErrorState = NO_ERROR ;

	/* 1) Clearing flag to allow slave sending data*/
	SET_BIT(TWI_TWCR , TWCR_TWINT) ;

	/* 2) Polling till interrupt flag is raised again (end of action)*/
	while((GET_BIT(TWI_TWCR , TWCR_TWINT)) == 0);

	/* 3) Checking for action ID*/
	if((TWI_TWSR & STATUS_MASK) != MSTR_RD_BYTE_WITH_ACK)
	{
		Local_ErrorState = MSTR_READ_DATA_ERROR ;
	}
	else
	{
		/* 4) Getting received data*/
		* Copy_pu8ReceivedDataByte = TWI_TWDR  ;
	}

	/*return from this function*/
	return Local_ErrorState ;
}

/****************************************************************************/

void TWI_voidSendStopCondition(void)
{
	/* 1) Generating stop condition on the bus*/
	SET_BIT(TWI_TWCR , TWCR_TWSTO);

	/* 2) Clearing flag to perform the required action*/
	SET_BIT(TWI_TWCR , TWCR_TWINT) ;
}

/****************************************************************************/
