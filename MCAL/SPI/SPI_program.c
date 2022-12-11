#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SPI_interface.h"
#include "SPI_register.h"
#include "SPI_private.h"
#include "SPI_config.h"

	u8 Interrupt     ;
	u8 DataOrder     ;
	u8 ClockPolarity ;
	u8 ClockPhase    ;

u8 SPI_u8MasterInit(MASTER_t * Copy_xpMasterPtr)
{
	/*local varaible for error checking*/
	u8 Local_u8ErrorState = OK ;

	/*Setting the node to be a MASTER*/
	SET_BIT(SPI_SPCR , SPCR_MSTR) ;

	/*switching over interrupt sources*/
	switch(Copy_xpMasterPtr->Interrupt)
	{
		case INTERRUPT_ENABLE  : SET_BIT(SPI_SPCR , SPCR_SPIE) ; break ;
		case INTERRUPT_DISABLE : CLR_BIT(SPI_SPCR , SPCR_SPIE) ; break ;
		default :  Local_u8ErrorState = NOK ;                    break ;
	}

	/*switching over data transfer order*/
	switch(Copy_xpMasterPtr->DataOrder)
	{
		case LSB_FIRST : SET_BIT(SPI_SPCR , SPCR_DORD) ; break ;
		case MSB_FIRST : CLR_BIT(SPI_SPCR , SPCR_DORD) ; break ;
		default :  Local_u8ErrorState = NOK ;            break ;
	}

	/*switching over clock polarity options*/
	switch(Copy_xpMasterPtr->ClockPolarity)
	{
		case LEADING_RISING : CLR_BIT(SPI_SPCR , SPCR_CPOL) ; break ;
		case LEADING_FALLING: SET_BIT(SPI_SPCR , SPCR_CPOL) ; break ;
		default :  Local_u8ErrorState = NOK ;                 break ;
	}

	/*switching over clock phase options*/
	switch(Copy_xpMasterPtr->ClockPhase)
	{
		case SAMPLE_AT_LEAD : CLR_BIT(SPI_SPCR , SPCR_CPHA) ;     break ;
		case SETUPT_AT_LEAD : SET_BIT(SPI_SPCR , SPCR_CPHA) ;     break ;
		default :  Local_u8ErrorState = NOK ;                     break ;
	}

	/*switching over prescaler values*/
	switch(Copy_xpMasterPtr->Prescaler)
	{
		case CLK_DIV_BY_2 :
			CLR_BIT(SPI_SPCR , SPCR_SPR0) ;
			CLR_BIT(SPI_SPCR , SPCR_SPR1) ;
			SET_BIT(SPI_SPSR , SPSR_SPI2X);
			break ;

		case CLK_DIV_BY_4 :
			CLR_BIT(SPI_SPCR , SPCR_SPR0) ;
			CLR_BIT(SPI_SPCR , SPCR_SPR1) ;
			CLR_BIT(SPI_SPSR , SPSR_SPI2X);
			break ;

		case CLK_DIV_BY_8 :
			SET_BIT(SPI_SPCR , SPCR_SPR0) ;
			CLR_BIT(SPI_SPCR , SPCR_SPR1) ;
			SET_BIT(SPI_SPSR , SPSR_SPI2X);
			break ;

		case CLK_DIV_BY_16 :
			SET_BIT(SPI_SPCR , SPCR_SPR0) ;
			CLR_BIT(SPI_SPCR , SPCR_SPR1) ;
			CLR_BIT(SPI_SPSR , SPSR_SPI2X);
			break ;

		case CLK_DIV_BY_32 :
			CLR_BIT(SPI_SPCR , SPCR_SPR0) ;
			SET_BIT(SPI_SPCR , SPCR_SPR1) ;
			SET_BIT(SPI_SPSR , SPSR_SPI2X);
			break ;

		case CLK_DIV_BY_64 :
			SET_BIT(SPI_SPCR , SPCR_SPR0) ;
			SET_BIT(SPI_SPCR , SPCR_SPR1) ;
			SET_BIT(SPI_SPSR , SPSR_SPI2X);
			break ;

		case CLK_DIV_BY_128 :
			SET_BIT(SPI_SPCR , SPCR_SPR0) ;
			SET_BIT(SPI_SPCR , SPCR_SPR1) ;
			CLR_BIT(SPI_SPSR , SPSR_SPI2X);
			break ;

		default :
			Local_u8ErrorState = NOK ;
			break ;
	}

	/*Enabling SPI peripheral*/
	SET_BIT(SPI_SPCR , SPCR_SPE) ;

	/*return from this function*/
	return Local_u8ErrorState ;
}

u8 SPI_u8SlaveInit(SLAVE_t * Copy_xpSlavePtr)
{
	/*local varaible for error checking*/
	u8 Local_u8ErrorState = OK ;

	/*Setting the node to be a SLAVE*/
	CLR_BIT(SPI_SPCR , SPCR_MSTR) ;


	/*switching over interrupt sources*/
	switch(Copy_xpSlavePtr->Interrupt)
	{
		case INTERRUPT_ENABLE  : SET_BIT(SPI_SPCR , SPCR_SPIE) ; break ;
		case INTERRUPT_DISABLE : CLR_BIT(SPI_SPCR , SPCR_SPIE) ; break ;
		default :  Local_u8ErrorState = NOK ;                    break ;
	}

	/*switching over data transfer order*/
	switch(Copy_xpSlavePtr->DataOrder)
	{
		case LSB_FIRST : SET_BIT(SPI_SPCR , SPCR_DORD) ; break ;
		case MSB_FIRST : CLR_BIT(SPI_SPCR , SPCR_DORD) ; break ;
		default :  Local_u8ErrorState = NOK ;            break ;
	}

	/*switching over clock polarity options*/
	switch(Copy_xpSlavePtr->ClockPolarity)
	{
		case LEADING_RISING : CLR_BIT(SPI_SPCR , SPCR_CPOL) ; break ;
		case LEADING_FALLING: SET_BIT(SPI_SPCR , SPCR_CPOL) ; break ;
		default :  Local_u8ErrorState = NOK ;                 break ;
	}

	/*switching over clock phase options*/
	switch(Copy_xpSlavePtr->ClockPhase)
	{
		case SAMPLE_AT_LEAD : CLR_BIT(SPI_SPCR , SPCR_CPHA) ;     break ;
		case SETUPT_AT_LEAD : SET_BIT(SPI_SPCR , SPCR_CPHA) ;     break ;
		default :  Local_u8ErrorState = NOK ;                     break ;
	}

	/*Enabling SPI peripheral*/
	SET_BIT(SPI_SPCR , SPCR_SPE) ;

	/*return from this function*/
	return Local_u8ErrorState ;

}

u8 SPI_u8Trasceive(u8 Copy_u8Data)
{

	/*setting data to be sent*/
	SPI_SPDR = Copy_u8Data ;

	/*polling til end of data transfer*/
	while((GET_BIT(SPI_SPSR , SPSR_SPIF)) == 0) ;

    /*getting received data*/
	return SPI_SPDR ;
}
