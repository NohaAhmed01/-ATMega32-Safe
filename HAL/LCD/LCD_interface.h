/*
 *  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< LCD_interface.h >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 * 
 *
 * Created: 10/28/2023 2:17:18 AM
 *  Author: Noha
 *  Layer: HAL
 *  SWC:LCD
 */ 

#ifndef _LCD_INTERFACE_H_
#define _LCD_INTERFACE_H_

//#if LCD_mode == 4
//#define FOUR_BIT 0x28
//#elif LCD_mode == 8
//#define EIGHT_BIT 0x38
//#endif

/*********** datasheet instructions ***********/
#define displayOn_cursorOn				 0x0e
#define diplayOn_cursorOff				 0x0c
#define displayOn_cursorOn_Blink		 0x0f
#define displayOff						 0x08
#define clear							 0x01
#define entryMode						 0x06   //write from left to right
#define arabic_entryMode				 0x04   //write from write to left
#define lcd_home						 0x02
#define lcd_CGRAM						 0x40   //first address at CGRAM when we want to write a custom char
#define setCursor						 0x80   //set cursor position at 1st row 1st column i.e. first address of DDRAM||if u want 2nd row 1st column add 64 = 0xc0
#define lcd_reset						 0x30 

/************ Rows & Columns **************/
#define row1 0
#define row2 1

#define col1 0
#define col2 1
#define col3 2
#define col4 3
#define col5 4
#define col6 5
#define col7 6
#define col8 7
#define col9 8
#define col10 9
#define col11 10
#define col12 11
#define col13 12
#define col14 13
#define col15 14
#define col16 15




void LCD_Init(void);
void LCD_SendData(u8 data);
void LCD_SendCommand(u8 command);
void LCD_SendptrString(const u8 * ptrString);

void SendExtraChar( u8 copyRow, u8 copyCol);
void set_cursor_position(u8 copyRow, u8 copyCol);
void LCD_CLEAR(void);


#endif
