/*
 * <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< DIO_interface.h >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Created on: Aug 27, 2023
 *      Author: Noha
 *      Layer: MCAL
 *      SWC:DIO/GPIO 
 */

#ifndef _DIO_INTERFACE_H_
#define _DIO_INTERFACE_H_

#include "../../LIB/STD_types.h"
#include "../../LIB/Bit_Math.h"
#include "DIO_private.h"

#define DIO_Pin_Output 1
#define DIO_Pin_Input 0

#define DIO_Pin_HIGH 1
#define DIO_Pin_LOW 0

#define DIO_PORT_Output 0xFF
#define DIO_PORT_Input 0

#define DIO_PORT_HIGH 0xFF
#define DIO_PORT_LOW 0

#define PORT_A 0
#define PORT_B 1
#define PORT_C 2
#define PORT_D 3

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

void DIO_voidSetPinDirection (u8 copy_u8PORT, u8 copy_u8PIN, u8 copy_u8DIRECTION);
void DIO_voidSetPinValue (u8 copy_u8PORT, u8 copy_u8PIN, u8 copy_u8VALUE);
u8 DIO_u8GetPinValue (u8 copy_u8PORT, u8 copy_u8PIN);
void DIO_voidTogglePinValue (u8 copy_u8PORT, u8 copy_u8PIN);

void DIO_voidSetPortDirection (u8 copy_u8PORT, u8 PortDirection);
void DIO_voidSetPortValue (u8 copy_u8PORT, u8 PortValue);

//LCD function to use in 4bit mode
void DIO_WriteHighNibbles(u8 copy_u8PORT , u8 value);

#endif