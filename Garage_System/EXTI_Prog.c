/*
 * EXTI_Prog.c
 *
 *  Created on: Sep 13, 2022
 *      Author: HP
 */


#include "Bit_Math.h"
#include "types1.h"

#include "EXTI_Interface.h"
#include "EXTI_Private.h"
#include "EXTI_CFG.h"




void (*EXTI_PvINT0Func)(void) = NULL_Pointer;
void (*EXTI_PvINT2Func)(void) = NULL_Pointer;

#if EXTI_Int_Src == INT_0
void EXTI_Int0_Inti(void)
{
	/*Check Sense Control*/
#if INT0_sense == Low_Level
	CLR_BIT(ISC00,MCUCR);
	CLR_BIT(ISC01,MCUCR);

#elif INT0_sense == On_change
	SET_BIT(ISC00,MCUCR);
	CLR_BIT(ISC01,MCUCR);

#elif INT0_sense == Falling_Edge
	CLR_BIT(ISC00,MCUCR);
	SET_BIT(ISC01,MCUCR);

#elif INT0_sense == Rising_Edge
	SET_BIT(ISC00,MCUCR);
	SET_BIT(ISC01,MCUCR);

#endif

  /*INT0 Enable*/
#if INT0_State == ENABLED
	SET_BIT(INT_0,GICR);
#elif INT0_State == DISABLED
	CLR_BIT(INT_0,GICR);
#else
#error "Wrong State"
#endif
}

u8 INT0_Interrupt_State(u8 Copy_State)
{
	u8 Local_ErrorState = OK;
	switch(Copy_State)
	{
	case ENABLED :
		SET_BIT(INT_0,GICR);
		break;
	case DISABLED :
		CLR_BIT(INT_0,GICR);
		break;
	default :
		Local_ErrorState = NOK;
	}
	return Local_ErrorState ;
}

u8 INT0_Sense_Control(u8 Copy_Sense_Control)
{
	u8 Local_ErrorState = OK;
	switch(Copy_Sense_Control)
	{
	case Low_Level :
		CLR_BIT(ISC00,MCUCR);
		CLR_BIT(ISC01,MCUCR);
		break;
	case On_change :
		SET_BIT(ISC00,MCUCR);
		CLR_BIT(ISC01,MCUCR);
		break;
	case Falling_Edge :
		CLR_BIT(ISC00,MCUCR);
		SET_BIT(ISC01,MCUCR);
		break;
	case Rising_Edge :
		SET_BIT(ISC00,MCUCR);
		SET_BIT(ISC01,MCUCR);
		break;
	default :
		Local_ErrorState = NOK;
	}

	return Local_ErrorState ;
}
#elif EXTI_Int_Src == INT_2
void EXTI_Int2_Inti(void)
{

#if INT2_sense == Falling_Edge
	CLR_BIT(ISC2 , MCUCSR);

#elif INT2_sense == Rising_Edge
	SET_BIT(ISC2,MCUCSR);

#endif

	/*INT2 Enable*/
#if INT2_State == ENABLED
	SET_BIT(INT_2,GICR);
#elif INT2_State == DISABLED
	CLR_BIT(INT_2,GICR);
#else
#error "Wrong State"
#endif
}
#endif

u8 EXTI_INT0SetCallBack(void (*Copy_PvINT0Func)(void))
{
	u8 Local_ErrorState = OK;
	if (Copy_PvINT0Func != NULL_Pointer)
	{
		EXTI_PvINT0Func = Copy_PvINT0Func;
	}
	else
	{
		Local_ErrorState = NULL_Pointer ;
	}
	return Local_ErrorState ;
}


u8 EXTI_INT2SetCallBack(void (*Copy_PvINT2Func)(void))
{
	u8 Local_ErrorState = OK;
	if (Copy_PvINT2Func != NULL_Pointer)
	{
		EXTI_PvINT2Func = Copy_PvINT2Func;
	}
	else
	{
		Local_ErrorState = NULL_Pointer ;
	}
	return Local_ErrorState ;
}


void __vector_1 (void) __attribute__((signal));
void __vector_1 (void)
{
	if (EXTI_PvINT0Func != NULL_Pointer)
	{
		EXTI_PvINT0Func();
	}
	else
	{
		/*Do no thing*/
	}
}

void __vector_3 (void) __attribute__((signal));
void __vector_3 (void)
{
	if (EXTI_PvINT2Func != NULL_Pointer)
	{
		EXTI_PvINT2Func();
	}
	else
	{
		/*Do no thing*/
	}
}
