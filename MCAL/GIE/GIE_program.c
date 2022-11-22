#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GIE_interface.h"
#include "GIE_register.h"

void GIE_voidEnableGlobalInterrupt(void)
{
	SET_BIT(SREG,7);    //enable global interrupt
}
void GIE_voidDisableGlobalInterrupt(void)
{
	CLR_BIT(SREG,7);    //disable global interrupt
}
