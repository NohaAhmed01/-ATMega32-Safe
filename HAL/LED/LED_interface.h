/*
 * <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< LED_interface.h >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 * 
 *
 * Created: 10/24/2023 1:17:40 AM
 *  Author: Noha
 *  Layer: HAL
 *  SWC:LED
 */ 

#ifndef _LED_INTERFACE_H_ 
#define _LED_INTERFACE_H_

#include "../../LIB/Bit_Math.h"
#include "../../LIB/STD_types.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/DIO/DIO_private.h"


#define OUTPUT 1
#define INPUT 0

#define HIGH 1
#define LOW 0



typedef struct{
	u8 port;
	u8 pin;
	u8 active_state;
	}LED_Type;

void LED_Init(LED_Type LEDconfigs);
void LED_OnOff(LED_Type LEDconfigs);
void LED_Toggle(LED_Type LEDconfigs);



#endif