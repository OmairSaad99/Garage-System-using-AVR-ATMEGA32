/*
 * EXTI_Interface.h
 *
 *  Created on: Sep 13, 2022
 *      Author: HP
 */

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_
//#include "types.h"
//#include "bitMath.h"

#define Falling_Edge 1
#define Rising_Edge  2
#define Low_Level    3
#define On_change    4

#define ENABLED    1
#define DISABLED   0

void EXTI_Int0_Inti(void);
u8 INT0_Sense_Control(u8 Copy_Sense_Control);
u8 INT0_Interrupt_State(u8 Copy_State);

void EXTI_Int1_Inti(void);
u8 INT1_Sense_Control(u8 Copy_Sense_Control);
u8 INT1_Interrupt_State(u8 Copy_State);


void EXTI_Int2_Inti(void);
u8 INT2_Sense_Control(u8 Copy_Sense_Control);
u8 INT2_Interrupt_State(u8 Copy_State);

u8 EXTI_INT0SetCallBack(void (*Copy_PvINT0Func)(void));
u8 EXTI_INT2SetCallBack(void (*Copy_PvINT0Func)(void));
#endif /* EXTI_INTERFACE_H_ */
