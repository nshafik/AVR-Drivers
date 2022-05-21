/*
 * HLCD_int.h
 *
 *  Created on: May 19, 2022
 *      Author: Ahmed Magdy
 */

#ifndef HAL_HLCD_INT_H_
#define HAL_HLCD_INT_H_

#define LCD_DATA_PORT     PORT_B

#define LCD_CONTROL_PORT  PORT_A
#define LCD_RS            PIN_0
#define LCD_RW            PIN_1
#define LCD_E             PIN_2

void HLCD_VidsendCommand(u8 A_u8Command) ;
void HLCD_VidsendData(u8 A_u8Data) ;
void HLCD_VidInit();
void HLCD_VidGotXY(u8 A_u8X ,u8 A_u8Y  ) ;



#endif /* HAL_HLCD_INT_H_ */
