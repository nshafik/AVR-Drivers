/*
 * MDIO_int.h
 *
 *  Created on: May 17, 2022
 *      Author: Nourhan
 */

#ifndef MCAL_MDIO_INT_H_
#define MCAL_MDIO_INT_H_
#include "../LIB/typedef.h"
/* DIO Ports */
#define PORT_A	0
#define PORT_B	1
#define PORT_C	2
#define PORT_D	3

/* DIO Pins */
#define PIN_0	0
#define PIN_1	1
#define PIN_2	2
#define PIN_3	3
#define PIN_4	4
#define PIN_5	5
#define PIN_6	6
#define PIN_7	7

/* DIO Directions */
#define INPUT	0
#define OUTPUT	1

/* Pin State */
#define LOW		0
#define HIGH	1

/* Set pin direction */
void MDIO_VidSetPinDirection(u8 A_u8Port , u8  A_u8Pin, u8 A_u8PinDir);

/* Set pin value */
void MDIO_VidSetPinValue(u8 A_u8Port, u8 A_u8Pin, u8 A_u8PinValue);

/* Set pin value */
void MDIO_VidGetPinValue(u8 A_u8Port, u8 A_u8Pin, u8 *AP_u8PinValue);


/* Set port direction */
void MDIO_VidSetPortDirection(u8 A_u8Port,  u8 A_u8PortDir);

/* Set port value */
void MDIO_VidSetPortValue(u8 A_u8Port, u8 AP_u8PortValue);

/* Set port value */
void MDIO_VidGetPortValue(u8 A_u8Port, u8 *AP_u8Value);

#endif /* MCAL_MDIO_INT_H_ */
