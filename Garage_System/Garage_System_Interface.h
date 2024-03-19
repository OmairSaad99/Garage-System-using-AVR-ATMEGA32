/*
 * Garage_System_Interface.h
 *
 *  Created on: Aug 12, 2023
 *      Author: HP
 */

#ifndef GARAGE_SYSTEM_INTERFACE_H_
#define GARAGE_SYSTEM_INTERFACE_H_

#define PINB_REG	*((volatile u8*) 0x36)
#define PIND_REG	*((volatile u8*) 0x30)

void Garage_System_Init(void) ;

void Garage_System_Start(void);

#endif /* GARAGE_SYSTEM_INTERFACE_H_ */
