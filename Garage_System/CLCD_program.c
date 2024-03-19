/*********************************************************/
/***********		Author: Amgad Samir 	**************/
/***********		Layer: HAL			 	**************/
/***********		Component: CLCD 		**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 14-8/2020		 	**************/
/*********************************************************/

#include "types1.h"
#include <util/delay.h>

#include "DIO_interface.h"

#include "CLCD_config.h"
#include "CLCD_interface.h"
#include "CLCD_private.h"

void CLCD_voidSendCommand(u8 Copy_u8Command)
{
	/*Set RS pin to low for command*/
	DIO_vidSetPinVal(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_LOW);

	/*Set RW pin to low for write*/
	DIO_vidSetPinVal(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_LOW);

	/*Set command to data pins*/
	DIO_vidSetPortVal(CLCD_DATA_PORT,Copy_u8Command);

	/*Send enable pulse*/
	DIO_vidSetPinVal(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_HIGH);
	_delay_ms(2);
	DIO_vidSetPinVal(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_LOW);
}

void CLCD_voidSendData(u8 Copy_u8Data)
{
	/*Set RS pin to high for data*/
	DIO_vidSetPinVal(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_HIGH);

	/*Set RW pin to low for write*/
	DIO_vidSetPinVal(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_LOW);

	/*Set Data to data pins*/
	DIO_vidSetPortVal(CLCD_DATA_PORT,Copy_u8Data);

	/*Send enable pulse*/
	DIO_vidSetPinVal(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_HIGH);
	_delay_ms(2);
	DIO_vidSetPinVal(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_LOW);
}

void CLCD_voidInit(void)
{
	/*Wait for more than 30 ms*/
	_delay_ms(40);

	/*Function set command: 2 lines, 5*8 Font size*/
	CLCD_voidSendCommand(0b00111000);

	/*Display on off control: display enable, disable cursor, no blink cursor*/
	CLCD_voidSendCommand(0b00001100);

	/*Clear display*/
	CLCD_voidSendCommand(1);
}

void CLCD_vidSendString(const char *Copy_u8String)
{
	u8 Local_u8Iterator = 0 ;
	while(Copy_u8String[Local_u8Iterator] != '\0')
	{
		CLCD_voidSendData(Copy_u8String[Local_u8Iterator]) ;
		Local_u8Iterator ++ ;
	}
}

void CLCD_GoToXY(u8 xPos , u8 yPos)
{
	u8 Local_u8DDRAMaddress = 0 ;
	if (xPos == 0)
	{
		Local_u8DDRAMaddress = yPos;
	}
	else if (xPos == 1)
	{
		Local_u8DDRAMaddress =yPos + 0x40 ;
	}

	CLCD_voidSendCommand(Local_u8DDRAMaddress + 128);

}

void CLCD_voidWriteSpecialCharacter(u8 *Copy_u8Pattern , u8 Copy_u8PatternNumber , u8 xPos , u8 yPos)
{
	u8 Local_u8CGRAMaddress = 0  , Local_u8Iterator ;

	/*Calculate CGRAM Address whose each location is 8 bytes*/
	Local_u8CGRAMaddress = Copy_u8PatternNumber * 8 ;

	/*Send CGRAM address command to LCD*/
	CLCD_voidSendCommand(Local_u8CGRAMaddress + 64);

	/*Write the Pattern into CGRAM*/
	for (Local_u8Iterator = 0 ; Local_u8Iterator < 8 ; Local_u8Iterator ++)
	{
		CLCD_voidSendData(Copy_u8Pattern[Local_u8Iterator]);
	}

	/*go back to DDRAM to Display the pattern*/
	CLCD_GoToXY(xPos , yPos);

	/*Display data written in CGRAM*/
	CLCD_voidSendData(Copy_u8PatternNumber);
}

/*void LCD_vidPrintInt(u16 u16dec)
{
	u16 arr[4],ASCII,mod;
	if ((u16dec>9) && (u16dec<9999))
	{
		for (u8 i=0 ; i<4 ; i++)
		{
			mod=u16dec%10 ;
			ASCII=mod+'0';
			arr[i]=ASCII;
			u16dec/=10;

			if(mod==0)
			{
				ASCII=u16dec+'0';
				arr[i]=ASCII;
			}
		}
		CLCD_voidSendCommand(0x80);
		CLCD_voidSendData(arr[3]);

		CLCD_voidSendCommand(0x81);
		CLCD_voidSendData(arr[2]);

		CLCD_voidSendCommand(0x82);
		CLCD_voidSendData(arr[1]);

		CLCD_voidSendCommand(0x83);
		CLCD_voidSendData(arr[0]);
	}
	else if ((u16dec<=9)&&(u16dec>=0))
	{
		ASCII=u16dec+'0';
		CLCD_voidSendCommand(0x80);
		CLCD_voidSendData(ASCII);
	}

	/*else
	{
		LCD_vidsendCMD(0x80);
		LCD_vidsendCHAR('E');

		LCD_vidsendCMD(0x81);
		LCD_vidsendCHAR('R');

		LCD_vidsendCMD(0x82);
		LCD_vidsendCHAR('R');

		LCD_vidsendCMD(0x83);
		LCD_vidsendCHAR('O');

		LCD_vidsendCMD(0x84);
		LCD_vidsendCHAR('R');
	}*/

//}

void CLCD_write_Number(u16 Copy_u16DecNum)
{
	static u8 arr_Two_Digits[2] ;
	static u8 arr_Three_Digits[3] ;
	static u8 arr_Four_Digits[4] ;
	u8 index = 0 ;
	u8 mod ;

	if (Copy_u16DecNum >9 && Copy_u16DecNum <= 99)
	{
		while (Copy_u16DecNum > 0)
		{
			mod = Copy_u16DecNum  % 10 ;
			arr_Two_Digits[index] = mod ;
			Copy_u16DecNum /=10 ;
			index ++ ;
		}

		CLCD_voidSendData(arr_Two_Digits[1] + '0') ;
		CLCD_voidSendData(arr_Two_Digits[0] + '0') ;
	}
	else if (Copy_u16DecNum > 99 && Copy_u16DecNum <= 999)
	{
		while (Copy_u16DecNum > 0)
		{
			mod = Copy_u16DecNum  % 10 ;
			arr_Three_Digits[index] = mod ;
			Copy_u16DecNum /=10 ;
			index ++ ;
		}

		CLCD_voidSendData(arr_Three_Digits[2] + '0') ;
		CLCD_voidSendData(arr_Three_Digits[1] + '0') ;
		CLCD_voidSendData(arr_Three_Digits[0] + '0') ;
	}
	else if (Copy_u16DecNum > 999 && Copy_u16DecNum <= 9999)
	{
		while (Copy_u16DecNum > 0)
		{
			mod = Copy_u16DecNum  % 10 ;
			arr_Four_Digits[index] = mod ;
			Copy_u16DecNum /=10 ;
			index ++ ;
		}

		CLCD_voidSendData(arr_Four_Digits[3] + '0') ;
		CLCD_voidSendData(arr_Four_Digits[2] + '0') ;
		CLCD_voidSendData(arr_Four_Digits[1] + '0') ;
		CLCD_voidSendData(arr_Four_Digits[0] + '0') ;
	}
	else if (Copy_u16DecNum >= 0 && Copy_u16DecNum <= 9)
	{
		CLCD_voidSendData(Copy_u16DecNum + '0') ;
	}
}
