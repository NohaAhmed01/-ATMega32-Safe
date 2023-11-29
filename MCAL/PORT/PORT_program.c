/*
 * <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< PORT_program.c >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 * Created: 11/27/2023 8:26:27 PM
 *		Author: Noha
 *      Layer: MCAL
 *      SWC:PORT
 */ 
#include "../../LIB/STD_types.h"
#include "PORT_config.h"
#include "PORT_interface.h"
#include "PORT_private.h"

void init_PORT(void)
{
	DDRA_Reg=DDRA_Dir;
	DDRB_Reg=DDRB_Dir;
	DDRC_Reg=DDRC_Dir;
	DDRD_Reg=DDRD_Dir;
}
