/*
 * <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< PORT_private.h >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 * Created: 11/27/2023 8:26:27 PM
 *		Author: Noha
 *      Layer: MCAL
 *      SWC:PORT
 */ 

#ifndef _PORT_PRIVATE_H_
#define _PORT_PRIVATE_H_

#include "PORT_config.h"

/********** defining the DDR and PORT registers for ports (A,B,C,D) *************/
 #define DDRA_Reg  *((volatile u8*)0x3A)
 #define DDRB_Reg  *((volatile u8*)0x37)
 #define DDRC_Reg  *((volatile u8*)0x34)
 #define DDRD_Reg  *((volatile u8*)0x31)
 
 #define  PORTA_Reg		*((volatile u8*)0x3B)
 #define  PORTB_Reg		*((volatile u8*)0x38)
 #define  PORTC_Reg		*((volatile u8*)0x35)
 #define  PORTD_Reg		*((volatile u8*)0x32)
 
 /****************** Concatenate pin values together to put into DDR value ***********/
 #define conc(b7,b6,b5,b4,b3,b2,b1,b0)				conc_help(b7,b6,b5,b4,b3,b2,b1,b0)
 #define conc_help(b7,b6,b5,b4,b3,b2,b1,b0)			0b##b7##b6##b5##b4##b3##b2##b1##b0
 
 #define DDRA_Dir	conc(PORT_A_PIN7_Dir,PORT_A_PIN6_Dir,PORT_A_PIN5_Dir,PORT_A_PIN4_Dir,PORT_A_PIN3_Dir,PORT_A_PIN2_Dir,PORT_A_PIN1_Dir,PORT_A_PIN0_Dir)
 #define DDRB_Dir	conc(PORT_B_PIN7_Dir,PORT_B_PIN6_Dir,PORT_B_PIN5_Dir,PORT_B_PIN4_Dir,PORT_B_PIN3_Dir,PORT_B_PIN2_Dir,PORT_B_PIN1_Dir,PORT_B_PIN0_Dir)
 #define DDRC_Dir	conc(PORT_C_PIN7_Dir,PORT_C_PIN6_Dir,PORT_C_PIN5_Dir,PORT_C_PIN4_Dir,PORT_C_PIN3_Dir,PORT_C_PIN2_Dir,PORT_C_PIN1_Dir,PORT_C_PIN0_Dir)
 #define DDRD_Dir	conc(PORT_D_PIN7_Dir,PORT_D_PIN6_Dir,PORT_D_PIN5_Dir,PORT_D_PIN4_Dir,PORT_D_PIN3_Dir,PORT_D_PIN2_Dir,PORT_D_PIN1_Dir,PORT_D_PIN0_Dir)
 
 
 

#endif