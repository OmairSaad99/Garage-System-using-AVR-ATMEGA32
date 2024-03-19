/*********************************************************/
/***********		Author: Amgad Samir 	**************/
/***********		Layer: HAL			 	**************/
/***********		Component: CLCD 		**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 14-8/2020		 	**************/
/*********************************************************/


/*Preprocessor file guard*/
#ifndef CLCD_INTERFACE_H_
#define CLCD_INTERFACE_H_

void CLCD_voidSendCommand(u8 Copy_u8Command);

void CLCD_voidSendData(u8 Copy_u8Data);

void CLCD_voidInit(void);

void CLCD_vidSendString(const char *Copy_u8String);

void CLCD_GoToXY(u8 xPos , u8 yPos);

void CLCD_voidWriteSpecialCharacter(u8 *Copy_u8Pattern , u8 Copy_u8PatternNumber , u8 xPos , u8 yPos);

void CLCD_write_Number (u16 Copy_u16DecNum) ;
#endif
