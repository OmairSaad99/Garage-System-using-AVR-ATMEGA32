/*
 * Servo_prog.c
 *
 *  Created on: Dec 27, 2022
 *      Author: HP
 */
#include "types1.h"
#include "Bit_Math.h"

#include "DIO_interface.h"
#include "PWM_interface.h"
#include "PWM_private.h"
#include "Servo_Interface.h"



u8 Servo_Rotete(u8 Copy_ChannelId , u8 Copy_Degree)
{
	u8 Local_ErrorState = OK ;
	if (Copy_Degree == 0 && Copy_ChannelId == OCA)
	{
		DIO_vidSetPinDir(DIO_PORTD , DIO_PIN5 , DIO_OUTPUT);
		TIMR1_VidSetOCACompMatchVal(750) ;
	}
	else if (Copy_Degree == 0 && Copy_ChannelId == OCB)
	{
		DIO_vidSetPinDir(DIO_PORTD , DIO_PIN4 , DIO_OUTPUT);
		OCR1BL =  750 ;
	}
	else if (Copy_Degree == 180 && Copy_ChannelId == OCA)
	{
		DIO_vidSetPinDir(DIO_PORTD , DIO_PIN5 , DIO_OUTPUT);
		TIMR1_VidSetOCACompMatchVal(2500) ;
	}
	else if (Copy_Degree == 180 && Copy_ChannelId == OCB)
	{
		DIO_vidSetPinDir(DIO_PORTD , DIO_PIN4 , DIO_OUTPUT);
		OCR1BL =  2500 ;
	}
	else if (Copy_Degree >0 && Copy_Degree < 180)
	{
		if (Copy_ChannelId == OCA)
		{
			DIO_vidSetPinDir(DIO_PORTD , DIO_PIN5 , DIO_OUTPUT);
			TIMR1_VidSetOCACompMatchVal(((u32)Copy_Degree * 2500) / 180) ;
		}
		else if (Copy_ChannelId == OCB)
		{
			DIO_vidSetPinDir(DIO_PORTD , DIO_PIN4 , DIO_OUTPUT);
			OCR1BL =  ((u32)Copy_Degree * 2500) / 180 ;
		}
	}
	else
	{
		Local_ErrorState = NOK ;
	}

	return Local_ErrorState ;
}
