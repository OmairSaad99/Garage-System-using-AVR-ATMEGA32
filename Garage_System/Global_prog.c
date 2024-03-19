/*
 * Global_prog.c
 *
 *  Created on: Sep 21, 2022
 *      Author: HP
 */


#include "types1.h"
#include "Bit_Math.h"
#include "Global_interface.h"
#include "Global_private.h"
#include "Global_CFG.h"


#include "avr/delay.h"


void GLOBAL_Init(void)
{
#if Status == ENABLED
	SET_BIT(I,SREG);
#elif Status == DISABLED
	CLR_BIT(I,SREG);
#endif
}


void Enable_Global_Interrupt()
{

	SET_BIT(I,SREG);

}


void Disable_Global_Interrupt()
{
	CLR_BIT(I,SREG);
}
