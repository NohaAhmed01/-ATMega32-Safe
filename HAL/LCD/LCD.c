/*
 *  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< LCD.c >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 * 
 *
 * Created: 10/28/2023 2:17:18 AM
 *  Author: Noha
 *  Layer: HAL
 *  SWC:LCD
 */ 
#define F_CPU 8000000UL
#include <util/delay.h>

#include "../../MCAL/DIO/DIO_interface.h"
#include "LCD_interface.h"
#include "LCD_config.h"
#include "LCD_private.h"
#include "extraChar.h"

void LCD_Init(void)
{
	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<      8 Bits Mode       >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	#if LCD_mode == 8
	_delay_ms(50);
	DIO_voidSetPortDirection(LCD_Data_Port,DIO_PORT_Output);
	DIO_voidSetPinDirection(LCD_Command_Port,LCD_RS,DIO_Pin_Output);
	DIO_voidSetPinDirection(LCD_Command_Port,LCD_RW,DIO_Pin_Output);
	DIO_voidSetPinDirection(LCD_Command_Port,LCD_EN,DIO_Pin_Output);
	
	LCD_SendCommand(lcd_home);
	_delay_ms(1);
	
	LCD_SendCommand(0x38);
	_delay_ms(1);
	
	LCD_SendCommand(displayOn_cursorOn_Blink);
	_delay_ms(1);
	
	LCD_CLEAR();
	
	LCD_SendCommand(entryMode);
	_delay_ms(1);
	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<      4 Bits Mode       >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	#elif LCD_mode == 4 
	_delay_ms(50);
	DIO_voidSetPinDirection(LCD_Data_Port,PIN4,DIO_Pin_Output);
	DIO_voidSetPinDirection(LCD_Data_Port,PIN5,DIO_Pin_Output);
	DIO_voidSetPinDirection(LCD_Data_Port,PIN6,DIO_Pin_Output);
	DIO_voidSetPinDirection(LCD_Data_Port,PIN7,DIO_Pin_Output);
	DIO_voidSetPinDirection(LCD_Command_Port,LCD_RS,DIO_Pin_Output);
	DIO_voidSetPinDirection(LCD_Command_Port,LCD_RW,DIO_Pin_Output);
	DIO_voidSetPinDirection(LCD_Command_Port,LCD_EN,DIO_Pin_Output);
	
	LCD_SendCommand(lcd_home);
	_delay_ms(1);
	
	LCD_SendCommand(0x28);
	_delay_ms(1);
	
	LCD_SendCommand(displayOn_cursorOn_Blink);
	_delay_ms(1);
	
	LCD_CLEAR();
	
	LCD_SendCommand(entryMode);
	_delay_ms(1);
	#endif
}

void LCD_SendptrString(const u8 * ptrString)
{
	u8 i = 0;
	while(ptrString[i] != '\0')
	{
		LCD_SendData(ptrString[i]);
		i++;
	}
}

void LCD_SendData(u8 data)
{
	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<      8 Bits Mode       >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	#if LCD_mode == 8
	
	DIO_voidSetPortValue(LCD_Data_Port,data);
	DIO_voidSetPinValue(LCD_Command_Port,LCD_RS,DIO_Pin_HIGH);
	DIO_voidSetPinValue(LCD_Command_Port,LCD_RW,DIO_Pin_LOW);
	Enable();
	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<      4 Bits Mode       >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	#elif LCD_mode == 4
	DIO_voidSetPinValue(LCD_Command_Port,LCD_RS,DIO_Pin_HIGH);
	DIO_voidSetPinValue(LCD_Command_Port,LCD_RW,DIO_Pin_LOW);
	DIO_WriteHighNibbles(LCD_Data_Port,(data)>>4);
	Enable();
	DIO_WriteHighNibbles(LCD_Data_Port,data);
	Enable();
	
	#endif
	_delay_ms(1);
}
void LCD_SendCommand(u8 command)
{
	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<      8 Bits Mode       >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	#if LCD_mode == 8
	
	DIO_voidSetPortValue(LCD_Data_Port,command);
	DIO_voidSetPinValue(LCD_Command_Port,LCD_RS,DIO_Pin_LOW);
	DIO_voidSetPinValue(LCD_Command_Port,LCD_RW,DIO_Pin_LOW);
	Enable();
	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<      4 Bits Mode       >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	#elif LCD_mode == 4
	DIO_voidSetPinValue(LCD_Command_Port,LCD_RS,DIO_Pin_LOW);
	DIO_voidSetPinValue(LCD_Command_Port,LCD_RW,DIO_Pin_LOW);
	DIO_WriteHighNibbles(LCD_Data_Port,(command)>>4);
	Enable();
	DIO_WriteHighNibbles(LCD_Data_Port,command);
	Enable();
	#endif
	_delay_ms(1);
}
void set_cursor_position(u8 copyRow, u8 copyCol)
{
	u8 position;
	if(copyRow>1||copyRow<0||copyCol>15||copyCol<0)
	{
		position = setCursor;
	}
	else if(copyRow == row1)
	{
		position = (setCursor) + (copyCol);
	}
	else if(copyRow == row2)
	{
		position = (setCursor) + 64 + (copyCol);
	}
	LCD_SendCommand(position);
	_delay_ms(1);
}
void SendExtraChar( u8 copyRow, u8 copyCol)
{
	u8 c = 0;
	//1-goto CGRAM 
	LCD_SendCommand(lcd_CGRAM);
	
	//2-draw character in CGRAM
	for(c=0;c<sizeof(extraChar)/sizeof(extraChar[0]);c++)
	{
		LCD_SendData(extraChar[c]);
	}
	//3-go back to DDRAM
	set_cursor_position(copyRow,copyCol);
	//4-send char address
	for(c=0;c<8;c++)
	{
		LCD_SendData(c);
	}
}

void LCD_CLEAR(void)
{
	LCD_SendCommand(clear);
	_delay_ms(10);
}
static void Enable(void)
{
	DIO_voidSetPinValue(LCD_Command_Port,LCD_EN,DIO_Pin_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(LCD_Command_Port,LCD_EN,DIO_Pin_LOW);
	_delay_ms(1);
	
}