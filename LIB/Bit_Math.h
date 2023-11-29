/*
 * <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Bit_Math.h >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Created on: Aug 24, 2023
 *      Author: Noha
 *      Layer: LIBRARY
 */
#ifndef	BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(reg,bit)		(reg |= (1<<bit))
#define Clear_BIT(reg,bit)		(reg &= ~(1<<bit))
#define GET_BIT(reg,bit)        (reg & (1<<bit))
#define TOGGLE(reg,bit)         (reg ^= (1<<bit))     

#define ROT_R(reg,bit)			(reg = (reg>>bit)|(reg<<REG_SIZE-bit))
#define ROT_L(reg,bit)			(reg = (reg<<bit)|(reg>>REG_SIZE-bit))

#endif