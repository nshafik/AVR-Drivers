/*
--- * HSSD_int.h
 *
 *  Created on: May 17, 2022
 *      Author: Nourhan
 */

#ifndef HAL_HSSD_INT_H_
#define HAL_HSSD_INT_H_
#include "../MCAL/MDIO_int.h"

/*Define Ids*/
#define SSD_ID0	0
#define SSD_ID1	1

/* SSD Type */
#define SSD_COM_CATHODE	0
#define SSD_COM_ANODE	1

/* SSD0 PINS */
#define SSD0_PORT	PORT_A
#define SSD0_SEGA	PIN_0
#define SSD0_SEGB	PIN_1
#define SSD0_SEGC	PIN_2
#define SSD0_SEGD	PIN_3
#define SSD0_SEGE	PIN_4
#define SSD0_SEGF	PIN_5
#define SSD0_SEGG	PIN_6

/* SSD1 PINS */
#define SSD1_PORT	PORT_B
#define SSD1_SEGA	PIN_0
#define SSD1_SEGB	PIN_1
#define SSD1_SEGC	PIN_2
#define SSD1_SEGD	PIN_3
#define SSD1_SEGE	PIN_4
#define SSD1_SEGF	PIN_5
#define SSD1_SEGG	PIN_6


#define SSD0_TYPE	SSD_COM_ANODE
#define SSD1_TYPE	SSD_COM_ANODE

void HSSD_VidInit(u8 A_u8Id , u8 A_u8Type);

void HSSD_VidDisplayNumber(u8 A_u8Id, u8 A_u8Number);

void HSSD_VidTurnOff(u8 A_u8Id);

#endif /* HAL_HSSD_INT_H_ */
