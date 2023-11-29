/*
 * <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< KPD_config.h >>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 * Created: 11/27/2023 10:00:20 PM
 * 		Author: Noha
 *      Layer: HAL
 *      SWC:KPD
 */ 

#ifndef KPD_CONFIG_H_
#define KPD_CONFIG_H_

/******** configure 1st and last row and column pins ***********/
#define KPD_row_1st		PIN0
#define KPD_row_last	PIN3

#define KPD_col_1st		PIN4
#define KPD_col_last	PIN7
									//col0 col1 col2 col3
static const u8 KPD_buttons[4][4] = {{'7','8','9','/'}, //row0
									 {'4','5','6','*'}, //row1
									 {'1','2','3','-'}, //row2
									 {'?','0','=','+'}  //row3
									 };
						
/*********** choose KPD Port ************/
/*
		options:
			1-PORT_A
			2-PORT_B
			3-PORT_C
			4-PORT_D
 */
#define KPD_Port PORT_D

/*
		options:
			1-PIN0
			2-PIN1
			3-PIN2
			4-PIN3
			5-PIN4
			6-PIN5
			7-PIN6
			8-PIN7
*/
#define KPD_ROW0	 PIN0
#define KPD_ROW1	 PIN1
#define KPD_ROW2	 PIN2
#define KPD_ROW3	 PIN3
#define KPD_COL0	 PIN4
#define KPD_COL1	 PIN5
#define KPD_COL2	 PIN6
#define KPD_COL3	 PIN7


#endif