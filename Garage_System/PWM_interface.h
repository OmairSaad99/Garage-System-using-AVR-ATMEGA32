/*
 * PWM_interface.h
 *
 *  Created on: Sep 21, 2022
 *      Author: HP
 */

#ifndef PWM_INTERFACE_H_
#define PWM_INTERFACE_H_



void Timer0_FastPWM_Mode();
void TIMR0_VidSetCompMatchVal(u8 Copy_u8CompVal);
void Timer1_FastPWM_Mode() ;
void SetTimer1_ICRval(u16 Copy_ICRVal);
void TIMR1_VidSetOCACompMatchVal(u16 Copy_u16CompVal) ;
void TIMR1_VidSetOCBCompMatchVal(u16 Copy_u16CompVal) ;



#endif /* PWM_INTERFACE_H_ */
