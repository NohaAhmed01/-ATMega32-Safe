/*
 * <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< DIO_program.c >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Created on: Aug 27, 2023
 *      Author: Noha
 *      Layer: MCAL
 *      SWC:DIO/GPIO 
 */

#include "../../LIB/STD_types.h"
#include "../../LIB/Bit_Math.h"

#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"


void DIO_voidSetPinDirection (u8 copy_u8PORT, u8 copy_u8PIN, u8 copy_u8DIRECTION)
{
	if(copy_u8DIRECTION == DIO_Pin_Output)
	{
		switch(copy_u8PORT){
			case PORT_A : SET_BIT(DDRA,copy_u8PIN);break;
			case PORT_B : SET_BIT(DDRB,copy_u8PIN);break;
			case PORT_C : SET_BIT(DDRC,copy_u8PIN);break;
			case PORT_D : SET_BIT(DDRD,copy_u8PIN);break;
		}
	}
	else if(copy_u8DIRECTION == DIO_Pin_Input)
	{
			switch(copy_u8PORT){
				case PORT_A : Clear_BIT(DDRA,copy_u8PIN);break;
				case PORT_B : Clear_BIT(DDRB,copy_u8PIN);break;
				case PORT_C : Clear_BIT(DDRC,copy_u8PIN);break;
				case PORT_D : Clear_BIT(DDRD,copy_u8PIN);break;
			}
		
	}
}


void DIO_voidSetPinValue (u8 copy_u8PORT, u8 copy_u8PIN, u8 copy_u8VALUE)
{
	if(copy_u8VALUE == DIO_Pin_HIGH)
	{
		switch(copy_u8PORT){
			case PORT_A : SET_BIT(PORTA,copy_u8PIN);break;
			case PORT_B : SET_BIT(PORTB,copy_u8PIN);break;
			case PORT_C : SET_BIT(PORTC,copy_u8PIN);break;
			case PORT_D : SET_BIT(PORTD,copy_u8PIN);break;
		}
	}
	else if(copy_u8VALUE == DIO_Pin_LOW)
	{
		switch(copy_u8PORT){
			case PORT_A : Clear_BIT(PORTA,copy_u8PIN);break;
			case PORT_B : Clear_BIT(PORTB,copy_u8PIN);break;
			case PORT_C : Clear_BIT(PORTC,copy_u8PIN);break;
			case PORT_D : Clear_BIT(PORTD,copy_u8PIN);break;
		}
    }
}


u8 DIO_u8GetPinValue (u8 copy_u8PORT, u8 copy_u8PIN)
{
	u8 local_u8Status=0; 
	switch(copy_u8PORT){
		case PORT_A : local_u8Status=GET_BIT(PINA,copy_u8PIN);break;
		case PORT_B : local_u8Status=GET_BIT(PINB,copy_u8PIN);break;
		case PORT_C : local_u8Status=GET_BIT(PINC,copy_u8PIN);break;
		case PORT_D : local_u8Status=GET_BIT(PIND,copy_u8PIN);break;
	}
	return local_u8Status;
}
void DIO_voidTogglePinValue (u8 copy_u8PORT, u8 copy_u8PIN)
{
		switch(copy_u8PORT){
			case PORT_A : TOGGLE(PORTA,copy_u8PIN);break;
			case PORT_B : TOGGLE(PORTB,copy_u8PIN);break;
			case PORT_C : TOGGLE(PORTC,copy_u8PIN);break;
			case PORT_D : TOGGLE(PORTD,copy_u8PIN);break;
		}
}


void DIO_voidSetPortDirection (u8 copy_u8PORT, u8 PortDirection)
{
	if(PortDirection == DIO_PORT_Output)
	{
		switch(copy_u8PORT)
		{
			case PORT_A : DDRA = PortDirection; break; 
			case PORT_B : DDRB = PortDirection; break;
			case PORT_C : DDRC = PortDirection; break;
			case PORT_D : DDRD = PortDirection; break;
		}
	}else if(PortDirection == DIO_PORT_Input)
	{
		switch(copy_u8PORT)
		{
			case PORT_A : DDRA = PortDirection; break;
			case PORT_B : DDRB = PortDirection; break;
			case PORT_C : DDRC = PortDirection; break;
			case PORT_D : DDRD = PortDirection; break;
		}
	}
}
void DIO_voidSetPortValue (u8 copy_u8PORT, u8 PortValue)
{
	if(PortValue == DIO_PORT_HIGH)
	{
		switch(copy_u8PORT)
		{
			case PORT_A : PORTA = PortValue; break;
			case PORT_B : PORTB = PortValue; break;
			case PORT_C : PORTC = PortValue; break;
			case PORT_D : PORTD = PortValue; break;
		}
	}else if(PortValue == DIO_PORT_LOW)
	{
		switch(copy_u8PORT)
		{
			case PORT_A : PORTA = PortValue; break;
			case PORT_B : PORTB = PortValue; break;
			case PORT_C : PORTC = PortValue; break;
			case PORT_D : PORTD = PortValue; break;
		}
	}
}
void DIO_WriteHighNibbles(u8 copy_u8PORT , u8 value)
{
	value = (value<<4) ;
	switch(copy_u8PORT)
	{
		case PORT_A :
		PORTA&=0x0f;                   // make sure the high bits = 0000
		PORTA|=value;				 //Set only the high nibble of the port A by the given value
		break ;
		case PORT_B:
		PORTB&=0x0f;                 //Set only the high nibble of the port B by the given value
		PORTB|=value;
		break ;
		case PORT_C :
		PORTC&=0x0f;                 //Set only the high nibble of the port C by the given value
		PORTC|=value;
		break ;
		case PORT_D:
		PORTD&=0x0f;                 //Set only the high nibble of the port D by the given value
		PORTD|=value;
		break ;
		default: break ;

	}
}