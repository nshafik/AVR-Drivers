/*
 * HLCD_prog.c
 *
 *  Created on: May 19, 2022
 *      Author: Ahmed Magdy
 */
#include "../LIB/STD_TYPES.h"
#include "../MCAL/MDIO_int.h"
#include "HLCD_int.h"
#include "util/delay.h"

void HLCD_VidsendCommand(u8 A_u8Command) {
	/*RS LOW*/
	MDIO_vidSetPinValue(LCD_CONTROL_PORT, LCD_RS , LOW);
	/*RW LOW*/
	MDIO_vidSetPinValue(LCD_CONTROL_PORT, LCD_RW , LOW);
	/*Send Command*/
	MDIO_vidSetPortValue(LCD_DATA_PORT, A_u8Command);
	/*Send Enable pulse*/
	MDIO_vidSetPinValue(LCD_CONTROL_PORT, LCD_E , HIGH );
	_delay_ms(2) ;
	MDIO_vidSetPinValue(LCD_CONTROL_PORT, LCD_E , LOW);
}
void HLCD_VidsendData(u8 A_u8Data) {
	/*RS LOW*/
	MDIO_vidSetPinValue(LCD_CONTROL_PORT, LCD_RS , HIGH);
	/*RW LOW*/
	MDIO_vidSetPinValue(LCD_CONTROL_PORT, LCD_RW , LOW);
	/*Send Data*/
	MDIO_vidSetPortValue(LCD_DATA_PORT, A_u8Data);
	/*Send Enable pulse*/
	MDIO_vidSetPinValue(LCD_CONTROL_PORT, LCD_E , HIGH);
	_delay_ms(2) ;
	MDIO_vidSetPinValue(LCD_CONTROL_PORT, LCD_E , LOW);
}
void HLCD_VidInit(){

	MDIO_vidSetPortDirection(LCD_DATA_PORT,OUTPUT);
	MDIO_vidSetPinDirection(LCD_CONTROL_PORT, LCD_RS, OUTPUT);
	MDIO_vidSetPinDirection(LCD_CONTROL_PORT, LCD_RW, OUTPUT);
	MDIO_vidSetPinDirection(LCD_CONTROL_PORT,  LCD_E, OUTPUT);

	/*LCD intialization sequence*/

	_delay_ms(50) ;
	HLCD_VidsendCommand(0b00111000) ;
	_delay_ms(1) ;
	HLCD_VidsendCommand(0b00001100) ;
	_delay_ms(1) ;
	HLCD_VidsendCommand(0b00000001) ;
	_delay_ms(4) ;
}
