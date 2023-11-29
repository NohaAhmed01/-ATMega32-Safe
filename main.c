/*
 * GccApplication1.c
 *
 * Created: 8/28/2023 2:23:50 AM
 * Author : Noha
 */ 

#define F_CPU 8000000UL
#include <util/delay.h>
#include "MCAL/DIO/DIO_config.h"
#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/DIO/DIO_private.h"
#include "LIB/Bit_Math.h"
#include "LIB/STD_types.h"
#include "HAL/LED/LED_interface.h"
#include "HAL/LCD/LCD_config.h"
#include "HAL/LCD/LCD_interface.h"
#include "HAL/LCD/LCD_private.h"
#include "HAL/KPD/KPD_config.h"
#include "HAL/KPD/KPD_interface.h"



#include <stdlib.h>


#include <util/delay.h>
//#include <avr/io.h>

int main(void)
{	
	LCD_Init();
	KPD_Init();
	DIO_voidSetPinDirection(PORT_A,PIN0,DIO_Pin_Output);
	const u8 * intro = "hello ya niho";
	LCD_SendptrString(intro);
	_delay_ms(100);	
	LCD_CLEAR();
	const u8 * outro = "enter password:";
	LCD_SendptrString(outro);
	set_cursor_position(1,0);
	u8 butn;
	u8 pass[4] = {'1','2','3','4'};
	u8 buff[4];
	int i=0;
	
    /* Replace with your application code */
    while (1) 
    {	
		butn = KPD_GetPressed();
		if(butn != NOTPRESSED && i<4)
		{	
			LCD_SendData(butn);		
			buff[i++]=butn;
		}
		if(i==4){
			if(pass[0]==buff[0]&&pass[1]==buff[1]&&pass[2]==buff[2]&&pass[3]==buff[3])
				{ i=5;
				 LCD_CLEAR();
				 set_cursor_position(0,0);
				 LCD_SendptrString("correct!!");
				 DIO_voidSetPinValue(PORT_A,PIN0,DIO_Pin_HIGH);
				 }				 
			else{
				i=0;
				LCD_CLEAR();
				set_cursor_position(0,0);
				LCD_SendptrString("wrong :(");
				_delay_ms(100);
				LCD_CLEAR();
				LCD_SendptrString("try again:");
				set_cursor_position(1,0);
				}		 
		}
    }
}

