/*
 *  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< LCD_config.h >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 * 
 *
 * Created: 10/28/2023 2:17:18 AM
 *  Author: Noha
 *  Layer: HAL
 *  SWC:LCD
 */ 

#ifndef _LCD_CONFIG_H_
#define _LCD_CONFIG_H_

//the user redefines this file according to the hardware connections pre-build configurations

/***************************************************************************************/
/* LCD Mode */

	/* Choose 8 for 8_bit connection, 4 for 4_bit connection */

/* $ Options :-

	1- 4
	2- 8
	
 */

#define LCD_mode 4

/***************************************************************************************/

/* D0 ------> D7 */

/*
  Options:-
 	 1-PORT_A
 	 2-PORT_B
 	 3-PORT_C
 	 4-PORT_D

 */
/**************************************************************************************/
#define LCD_Data_Port PORT_A
#define LCD_Command_Port PORT_C

/***************************************************************************************/

/*
 Options:-
 	 1-PIN0
 	 2-PIN1
 	 3-PIN2
 	 4-PIN3
 	 5-PIN4
 	 6-PIN5
 	 7-PIN6
 	 8-PIN7

 */
#define LCD_RS    PIN1
#define LCD_RW    PIN2
#define LCD_EN    PIN3

/***************************************************************************************/


#endif
