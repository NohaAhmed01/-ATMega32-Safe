/*
 * <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< KPD.c >>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 * Created: 11/27/2023 10:00:20 PM
 * 		Author: Noha
 *      Layer: HAL
 *      SWC:KPD
 */ 
#define F_CPU 8000000UL
#include <util/delay.h>
#include "../../MCAL/DIO/DIO_interface.h"
#include "KPD_config.h"
#include "KPD_interface.h"
#include "../../LIB/STD_types.h"


void KPD_Init(void)
{
	//set rows direction and value as input pullup (i.e. input high)
	DIO_voidSetPinDirection(KPD_Port,KPD_ROW0,DIO_Pin_Input);	
	DIO_voidSetPinDirection(KPD_Port,KPD_ROW1,DIO_Pin_Input);
	DIO_voidSetPinDirection(KPD_Port,KPD_ROW2,DIO_Pin_Input);
	DIO_voidSetPinDirection(KPD_Port,KPD_ROW3,DIO_Pin_Input);
	
	DIO_voidSetPinValue(KPD_Port,KPD_ROW0,DIO_Pin_HIGH);
	DIO_voidSetPinValue(KPD_Port,KPD_ROW1,DIO_Pin_HIGH);
	DIO_voidSetPinValue(KPD_Port,KPD_ROW2,DIO_Pin_HIGH);
	DIO_voidSetPinValue(KPD_Port,KPD_ROW3,DIO_Pin_HIGH);
	
	//set columns direction and value as output high
	DIO_voidSetPinDirection(KPD_Port,KPD_COL0,DIO_Pin_Output);
	DIO_voidSetPinDirection(KPD_Port,KPD_COL1,DIO_Pin_Output);
	DIO_voidSetPinDirection(KPD_Port,KPD_COL2,DIO_Pin_Output);
	DIO_voidSetPinDirection(KPD_Port,KPD_COL3,DIO_Pin_Output);
	
	DIO_voidSetPinValue(KPD_Port,KPD_COL0,DIO_Pin_HIGH);
	DIO_voidSetPinValue(KPD_Port,KPD_COL1,DIO_Pin_HIGH);
	DIO_voidSetPinValue(KPD_Port,KPD_COL2,DIO_Pin_HIGH);
	DIO_voidSetPinValue(KPD_Port,KPD_COL3,DIO_Pin_HIGH);
		
}
u8 KPD_GetPressed(void)
{
	u8 pressedBtn = NOTPRESSED;
	u8 LOC_btn;
	/*variables for iterating rows & cols*/
	u8 LOC_col;
	u8 LOC_row;
	
	/*nested for loop to iterate all rows in each column*/
	for(LOC_col=4;LOC_col<8;LOC_col++)
	{
		//set the col that is iterating its rows to low
		DIO_voidSetPinValue(KPD_Port,LOC_col,DIO_Pin_LOW);
		for(LOC_row=0;LOC_row<4;LOC_row++)
		{
			LOC_btn = DIO_u8GetPinValue(KPD_Port,LOC_row);
			if(LOC_btn == 0)
			{
					pressedBtn = KPD_buttons[LOC_row-1][LOC_col];
				/*to avoid mistaking a long press of a button-or any HW error- to be multiple presses of same btn
					two options: 
					1-use delay for 200ms
					2-use a while loop where the pressed btn will not get out of unless its value returns back to 1
				*/
				//option 1 
				//_delay_ms(200);
				//option 2
				LOC_btn = DIO_u8GetPinValue(KPD_Port,LOC_row);
				while(DIO_Pin_LOW == LOC_btn)
				{
					LOC_btn = DIO_u8GetPinValue(KPD_Port,LOC_row);
				}break;
			
			}
		}
		DIO_voidSetPinValue(KPD_Port,LOC_col,DIO_Pin_HIGH);
	}
	return pressedBtn;
}
