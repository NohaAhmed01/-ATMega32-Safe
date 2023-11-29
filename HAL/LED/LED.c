/*
 * <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< LED.c >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 * 
 *
 * Created: 10/24/2023 1:17:40 AM
 *  Author: Noha
 *  Layer: HAL
 *  SWC:LED
 */ 

#include "../../LIB/Bit_Math.h"
#include "../../LIB/STD_types.h"

#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/DIO/DIO_private.h"
#include "LED_interface.h"

void LED_Init(LED_Type LEDconfigs)
{
	DIO_voidSetPinDirection(LEDconfigs.port,LEDconfigs.pin,OUTPUT);
}
void LED_OnOff(LED_Type LEDconfigs)
{
	if(LEDconfigs.active_state == HIGH)
	DIO_voidSetPinValue(LEDconfigs.port,LEDconfigs.pin,HIGH);
	else if(LEDconfigs.active_state == LOW)
	DIO_voidSetPinValue(LEDconfigs.port,LEDconfigs.pin,LOW);
}
void LED_Toggle(LED_Type LEDconfigs)
{
	DIO_voidTogglePinValue (LEDconfigs.port , LEDconfigs.pin);
}
