/*
 * Garage_System.c
 *
 *  Created on: Aug 12, 2023
 *      Author: HP
 */



#include "types1.h"
#include "Bit_Math.h"
#include "DIO_interface.h"
#include "CLCD_interface.h"
#include "PWM_interface.h"
#include "Servo_Interface.h"
#include "EXTI_Interface.h"
#include "Global_interface.h"
#include "Garage_System_Interface.h"

#include "avr/delay.h"

void ISR(void);

void Garage_System_Init(void)
{
	/*Set Data Port As Output*/
	DIO_vidSetPortDir(DIO_PORTC , 0b11111111);
	/*Set Control Port As Output*/
	DIO_vidSetPinDir(DIO_PORTA , DIO_PIN2 , DIO_OUTPUT);
	DIO_vidSetPinDir(DIO_PORTA , DIO_PIN3 , DIO_OUTPUT);
	DIO_vidSetPinDir(DIO_PORTA , DIO_PIN4 , DIO_OUTPUT);

	/*Make Entry Push Button Pin PINB2 as Input*/
	DIO_vidSetPinDir(DIO_PORTB, DIO_PIN2 , DIO_INPUT);
	/*Enable Pull Up Resistor*/
	DIO_vidSetPinVal(DIO_PORTB, DIO_PIN2 , DIO_HIGH);

	/*Make Exit Push Button Pin PIND2 as Input*/
	DIO_vidSetPinDir(DIO_PORTD, DIO_PIN2 , DIO_INPUT);
	/*Enable Pull Up Resistor*/
	DIO_vidSetPinVal(DIO_PORTD, DIO_PIN2 , DIO_HIGH);

	CLCD_voidInit();
	Timer1_FastPWM_Mode();
	SetTimer1_ICRval(20000);
	//EXTI_Int2_Inti();
	//EXTI_INT2SetCallBack(&ISR);
	//Enable_Global_Interrupt();
}


void Garage_System_Start(void)
{
	u8 Local_u8EntryPinVal ; /*Status For Entry Pin*/
	u8 Local_u8ExitPinVal ; /*Status For Exit Pin*/
	static u8 Local_u8NumberOfCars = 0 ;  /*Number OF Cars*/

	CLCD_vidSendString("There Are 0 Cars");
	CLCD_GoToXY(1,0);
	CLCD_vidSendString("Garage Has Space");

	while (1)
	{
		DIO_u8GetPinVal(DIO_PORTD , DIO_PIN2 ,&Local_u8EntryPinVal) ; /*For Entry Gate*/

		DIO_u8GetPinVal(DIO_PORTB , DIO_PIN2 ,&Local_u8ExitPinVal) ; /*For Close Gate*/

		if (Local_u8EntryPinVal == 0 && Local_u8NumberOfCars <3) /*Pin Of Entry Gate*/
		{
			Local_u8NumberOfCars ++ ; /*Number OF Cars*/

			CLCD_voidSendCommand(1) ;
			CLCD_vidSendString("There Are ") ;
			CLCD_GoToXY(0,10) ;
			CLCD_write_Number(Local_u8NumberOfCars);
			CLCD_GoToXY(0,11);
			CLCD_vidSendString(" Cars") ;
			if (Local_u8NumberOfCars == 3)
			{
				CLCD_GoToXY(1,0);
				CLCD_vidSendString("Garage Is Full");
				for(u8 i=0 ; i<=90 ; i++) /*Open Entry Gate*/
				{
					Servo_Rotete(OCB , i);
					_delay_ms(10);
				}
				_delay_ms(1000);  /*Waiting The Car To Enter*/
				for(u8 i=89 ; i>0 ; i--) /*Close Entry Gate*/
				{
					Servo_Rotete(OCB , i);
					_delay_ms(10);
				}
			}
			else
			{
				CLCD_GoToXY(1,0);
				CLCD_vidSendString("Garage Has Space");
				for(u8 i=0 ; i<=90 ; i++) /*Open Entry Gate*/
				{
					Servo_Rotete(OCB , i);
					_delay_ms(10);
				}
				_delay_ms(1000);  /*Waiting The Car To Enter*/
				for(u8 i=89 ; i>0 ; i--) /*Close Entry Gate*/
				{
					Servo_Rotete(OCB , i);
					_delay_ms(10);
				}

			}

		}
		if (Local_u8ExitPinVal == 0 && Local_u8NumberOfCars != 0)/*Pin Of Exit Gate*/
		{
			Local_u8NumberOfCars -- ;

			CLCD_voidSendCommand(1) ;
			CLCD_vidSendString("There Are ") ;
			CLCD_GoToXY(0,10) ;
			CLCD_write_Number(Local_u8NumberOfCars);
			CLCD_GoToXY(0,11);
			CLCD_vidSendString(" Cars") ;

			if (Local_u8NumberOfCars == 0)
			{
				CLCD_GoToXY(1,0);
				CLCD_vidSendString("Garage Has Space");
				for(u8 i=0 ; i<=90 ; i++) /*Open Exit Gate*/
				{
					Servo_Rotete(OCA , i);
					_delay_ms(10);
				}
				_delay_ms(1000);  /*Waiting The Car To Exit*/
				for(u8 i=89 ; i>0 ; i--) /*Close Exit Gate*/
				{
					Servo_Rotete(OCA , i);
					_delay_ms(10);
				}
				continue ;
			}

			CLCD_GoToXY(1,0);
			CLCD_vidSendString("Garage Has Space");
			for(u8 i=0 ; i<=90 ; i++) /*Open Exit Gate*/
			{
				Servo_Rotete(OCA , i);
				_delay_ms(10);
			}
			_delay_ms(1000); /*Waiting The Car To Exit*/
			for(u8 i=89 ; i>0 ; i--) /*Close Exit Gate*/
			{
				Servo_Rotete(OCA , i);
				_delay_ms(10);
			}
		}
	}
}

void ISR (void)
{
	static u8 Local_u8NumberOfCars = 0 ;

	Local_u8NumberOfCars ++ ;

	CLCD_voidSendCommand(1) ;
	CLCD_vidSendString("There Are ") ;
	CLCD_GoToXY(0,9) ;
	CLCD_write_Number(Local_u8NumberOfCars);
	CLCD_GoToXY(0,10);
	CLCD_vidSendString(" Cars") ;
	if (Local_u8NumberOfCars == 3)
	{
		CLCD_GoToXY(1,0);
		CLCD_vidSendString("Garage Is Full");
		Disable_Global_Interrupt();
	}
	else
	{
		CLCD_GoToXY(1,0);
		CLCD_vidSendString("Garage Has Space");
	}
}
