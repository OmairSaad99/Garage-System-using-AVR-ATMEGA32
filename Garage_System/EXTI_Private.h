/*
 * EXTI_Private.h
 *
 *  Created on: Sep 13, 2022
 *      Author: HP
 */

#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_



#define    GICR  *((volatile u8*)0x5B)
#define    INT_1   7
#define    INT_0   6
#define    INT_2   5

#define   GIFR   *((volatile u8*)0x5A)
#define   MCUCR   *((volatile u8*)0x55)
#define   ISC11  3
#define   ISC10  2
#define   ISC01  1
#define   ISC00  0



#define MCUCSR   *((volatile u8*)0x54)
#define INT2   6
#define ISC2 6




#endif /* EXTI_PRIVATE_H_ */
