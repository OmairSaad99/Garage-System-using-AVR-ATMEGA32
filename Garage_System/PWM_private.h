/*
 * private.h
 *
 *  Created on: May 13, 2022
 *      Author: HP
 */

#ifndef TIMERS_PRIVATE_H_
#define TIMERS_PRIVATE_H_

#define TCCR0    *((volatile u8*)(0x53))
#define F0C0    7
#define WGM00   6
#define COM01   5
#define COM00   4
#define WGM01   3
#define CS02    2
#define CS01    1
#define CS00    0

#define OCR0    *((volatile u8*)(0x5C))
#define TCNT0    *((volatile u8*)(0x52))
#define SREG    *((volatile u8*)(0x5F))
#define I      7
/************************************************************/

/*ICU Registers*/
#define TCCR1A    *((volatile u8*)(0x4f))
#define COM1A1   7
#define COM1A0   6
#define COM1B1   5
#define COM1B0   4
#define FOC1A    3
#define FOC1B    2
#define WGM11    1
#define WGM10    0

/**********************************************************/
#define TCCR1B    *((volatile u8*)(0x4E))
#define ICNC1   7
#define ICES1   6
#define WGM13   4
#define WGM12   3
#define CS12    2
#define CS11    1
#define CS10    0

/**********************************************************/
#define TCNT1L   *((volatile u16*)(0x4C))
#define OCR1AL   *((volatile u16*)(0x4A))
#define ICR1L    *((volatile u16*)(0x46))

#define TIMSK     *((volatile u16*)(0x59))
#define OCIE0      1
#define TICIE1     5
#define OCIE1A     6

#define OCR1BL   *((volatile u16*)(0x48))
#define OCR1AL   *((volatile u16*)(0x4A))



#define Divison_Factor_Mask 0b11111000
#define Divison_By_8   2
#define Divison_By_64   3
#endif /* PRIVATE_H_ */
