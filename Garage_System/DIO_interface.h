/*
 * DIO_interface.h
 *
 *  Created on: Apr 8, 2022
 *      Author: mahmo
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_
/******************
 *  description : api used to set pin val to digital high/low
* inputs : u8 PorrId -> index of port number, range[portA:PortD]
*          u8 PinId ->
*          u8 val
* output : void
*/
void DIO_vidSetPinVal(u8 portId,u8 pinId,u8 val);
void DIO_vidSetPinDir(u8 portId,u8 pinId,u8 dir);
void DIO_vidSetPortVal(u8 portId,u8 portval);
void DIO_vidSetPortDir(u8 portId,u8 portdir);
u8 DIO_u8GetPinVal(u8 portId, u8 pinId , u8 *Ret_val);


// public macros
// Port definitions
#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

// Pins definitions
#define DIO_PIN0 0
#define DIO_PIN1 1
#define DIO_PIN2 2
#define DIO_PIN3 3
#define DIO_PIN4 4
#define DIO_PIN5 5
#define DIO_PIN6 6
#define DIO_PIN7 7

//Digital Values definitions
#define DIO_HIGH 1
#define DIO_LOW 0

// Pins directions
#define DIO_INPUT 0
#define DIO_OUTPUT 1



//PORT DIRECTIONS
#define DIO_PORT_OUTPUT 0xff
#define DIO_PORT_INPUT 0x00

#endif /* DIO_INTERFACE_H_ */
