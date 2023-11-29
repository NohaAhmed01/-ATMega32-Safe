/*
 * <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< KPD_interface.h >>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 * Created: 11/27/2023 10:00:20 PM
 * 		Author: Noha
 *      Layer: HAL
 *      SWC:KPD
 */ 

#ifndef	_KPD_INTERFACE_H_
#define _KPD_INTERFACE_H_

#define NOTPRESSED 0xff

void KPD_Init(void);
u8 KPD_GetPressed(void);
#endif