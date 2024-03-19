/*
 * PWM_prog.c
 *
 *  Created on: Sep 21, 2022
 *      Author: HP
 */
#include "Bit_Math.h"
#include "types1.h"
#include "PWM_interface.h"
#include "PWM_CFG.h"
#include "PWM_private.h"

void Timer0_FastPWM_Mode()
{

	/*Select FPWM*/
	SET_BIT(WGM00 , TCCR0);
	SET_BIT(WGM01 , TCCR0);




	/*Select Non Interval Mode*/
	SET_BIT( COM01 , TCCR0);
	CLR_BIT( COM00 , TCCR0 );

#if Prescaller_Select == Divison_By_8  /*Select Prescaller 8*/
	TCCR0&=Divison_Factor_Mask;
	TCCR0|=Prescaller_Select;
#elif Prescaller_Select == Divison_By_64  /*Select Prescaller 64*/
	TCCR0&=Divison_Factor_Mask;
	TCCR0|=Prescaller_Select;
#endif


}
void TIMR0_VidSetCompMatchVal(u8 Copy_u8CompVal)
{
	OCR0 = Copy_u8CompVal;
}

void Timer1_FastPWM_Mode()
{
	/*Select WaveForm Mode FPWM*/
	SET_BIT(WGM13 , TCCR1B);
	SET_BIT(WGM12 , TCCR1B);
	SET_BIT(WGM11 , TCCR1A);
	CLR_BIT(WGM10 , TCCR1A);


	/*Select FPWM OCA Non Inverted Mode*/
	SET_BIT(COM1A1 , TCCR1A) ;
	CLR_BIT(COM1A0 , TCCR1A) ;

	/*Select FPWM OCB Non Inverted Mode*/
	SET_BIT(COM1B1 , TCCR1A) ;
	CLR_BIT(COM1B0 , TCCR1A) ;


	/*Prescaller*/
#if Prescaller_Select == Divison_By_8
	TCCR1B &=Divison_Factor_Mask ;
	TCCR1B |=Prescaller_Select ;
#elif Prescaller_Select == Divison_By_64
	TCCR1B &=Divison_Factor_Mask ;
	TCCR1B |=Prescaller_Select ;
#endif
}

void SetTimer1_ICRval(u16 Copy_ICRVal)
{
	ICR1L = Copy_ICRVal ;
}

void TIMR1_VidSetOCACompMatchVal(u16 Copy_u16CompVal)
{
	OCR1AL = Copy_u16CompVal;
}

void TIMR1_VidSetOCBCompMatchVal(u16 Copy_u16CompVal)
{
	OCR1BL = Copy_u16CompVal;
}
