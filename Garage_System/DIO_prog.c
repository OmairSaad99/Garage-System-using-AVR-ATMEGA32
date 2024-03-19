/*
 * DIO_prog.c

 *
 *  Created on: Apr 8, 2022
 *      Author: mahmo
 */

#include "types1.h"
#include "Bit_Math.h"
#include "DIO_Private.h"
#include "DIO_Interface.h"
/**************FUNCTION IMPLEMENTATION************/
void DIO_vidSetPinVal(u8 portId, u8 pinId, u8 val)
{
	if ((portId <= DIO_PORTD) && (pinId <= DIO_PIN7))//the range is right
	{ if (val == DIO_HIGH)
	{
		switch(portId)
		{
		case DIO_PORTA: SET_BIT(pinId,PORTA_REG);break;
		case DIO_PORTB: SET_BIT(pinId,PORTB_REG);break;
		case DIO_PORTC: SET_BIT(pinId,PORTC_REG);break;
		case DIO_PORTD: SET_BIT(pinId,PORTD_REG);break;
		}
	}
	else if (val == DIO_LOW)
	{
		switch(portId)
		{
		case DIO_PORTA: CLR_BIT(pinId,PORTA_REG);break;
		case DIO_PORTB: CLR_BIT(pinId,PORTB_REG);break;
		case DIO_PORTC: CLR_BIT(pinId,PORTC_REG);break;
		case DIO_PORTD: CLR_BIT(pinId,PORTD_REG);break;
		}
	}
	else //for future development

	{
		//Report Error
	}

	}
	else//for future development
	{
		// Report Error
	}

}
void DIO_vidSetPinDir(u8 portId, u8 pinId, u8 dir)
{
	if ((portId <= DIO_PORTD) && (pinId <= DIO_PIN7))
	{ if (dir == DIO_OUTPUT)
	{
		switch(portId)
		{
		case DIO_PORTA: SET_BIT(pinId,DDRA_REG);break;
		case DIO_PORTB: SET_BIT(pinId,DDRB_REG);break;
		case DIO_PORTC: SET_BIT(pinId,DDRC_REG);break;
		case DIO_PORTD: SET_BIT(pinId,DDRD_REG);break;
		}
	}
	else if (dir == DIO_INPUT)
	{
		switch(portId)
		{
		case DIO_PORTA: CLR_BIT(pinId,DDRA_REG);break;
		case DIO_PORTB: CLR_BIT(pinId,DDRB_REG);break;
		case DIO_PORTC: CLR_BIT(pinId,DDRC_REG);break;
		case DIO_PORTD: CLR_BIT(pinId,DDRD_REG);break;
		}
	}
	else
	{
		//Report Error
	}

	}
	else
	{
		// Report Error
	}

}
void DIO_vidSetPortVal(u8 portId, u8 portval)
{
	if (portId <= DIO_PORTD)
	{
		switch(portId)
		{
		case DIO_PORTA: PORTA_REG = portval;break;
		case DIO_PORTB: PORTB_REG = portval;break;
		case DIO_PORTC: PORTC_REG = portval;break;
		case DIO_PORTD: PORTD_REG = portval;break;
		}
	}
}

void DIO_vidSetPortDir(u8 portId, u8 portdir)
{
	if (portId <= DIO_PORTD)
	{
		switch(portId)
		{
		case DIO_PORTA: DDRA_REG = portdir;break;
		case DIO_PORTB: DDRB_REG = portdir;break;
		case DIO_PORTC: DDRC_REG = portdir;break;
		case DIO_PORTD: DDRD_REG = portdir;break;
		}
	}
}

u8 DIO_u8GetPinVal(u8 portId, u8 pinId , u8 *Ret_val)
{
	u8 Local_u8ErrorState = 0 ;

	if ((Ret_val != NULL) && (pinId <= DIO_PIN7))
	{
		switch(portId)
		{
		case DIO_PORTA: *Ret_val = GET_BIT(pinId,PINA_REG);break;
		case DIO_PORTB: *Ret_val = GET_BIT(pinId,PINB_REG);break;
		case DIO_PORTC: *Ret_val = GET_BIT(pinId,PINC_REG);break;
		case DIO_PORTD: *Ret_val = GET_BIT(pinId,PIND_REG);break;
		default : Local_u8ErrorState = 1 ;

		}
	}
	else
	{
		Local_u8ErrorState = 1;
	}
	return Local_u8ErrorState;
}
