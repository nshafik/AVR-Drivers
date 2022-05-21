/*
 * MDIO_prog.c
 *
 *  Created on: May 17, 2022
 *      Author: Nourhan
 */
#include <avr/io.h>

#include "MDIO_int.h"
#include "../LIB/BIT_MATH.h"
#include "../LIB/typedef.h"
#include "MDIO_int.h"

/* Set pin direction */
void MDIO_VidSetPinDirection(u8 A_u8Port , u8  A_u8Pin, u8 A_u8PinDir){

	if(A_u8PinDir == INPUT){
		switch (A_u8Port){
			case PORT_A: CLEAR_BIT(DDRA, A_u8Pin); break;
			case PORT_B: CLEAR_BIT(DDRB, A_u8Pin); break;
			case PORT_C: CLEAR_BIT(DDRC, A_u8Pin); break;
			case PORT_D: CLEAR_BIT(DDRD, A_u8Pin); break;

		}
	}

	else if(A_u8PinDir == OUTPUT){
		switch (A_u8Port){
				case PORT_A: SET_BIT(DDRA, A_u8Pin); break;
				case PORT_B: SET_BIT(DDRB, A_u8Pin); break;
				case PORT_C: SET_BIT(DDRC, A_u8Pin); break;
				case PORT_D: SET_BIT(DDRD, A_u8Pin); break;

		}
	}
}

/* Set pin value */
void MDIO_VidSetPinValue(u8 A_u8Port, u8 A_u8Pin, u8 A_u8PinValue){
	if(A_u8PinValue == HIGH){
		switch (A_u8Port){
				case PORT_A: SET_BIT(PORTA, A_u8Pin); break;
				case PORT_B: SET_BIT(PORTB, A_u8Pin); break;
				case PORT_C: SET_BIT(PORTC, A_u8Pin); break;
				case PORT_D: SET_BIT(PORTD, A_u8Pin); break;
		}
	}
	else if(A_u8PinValue == LOW){
		switch (A_u8Port){
			case PORT_A: CLEAR_BIT(PORTA, A_u8Pin); break;
			case PORT_B: CLEAR_BIT(PORTB, A_u8Pin); break;
			case PORT_C: CLEAR_BIT(PORTC, A_u8Pin); break;
			case PORT_D: CLEAR_BIT(PORTD, A_u8Pin); break;

		}
	}
}

/* Set pin value */
void MDIO_VidGetPinValue(u8 A_u8Port, u8 A_u8Pin, u8 *AP_u8PinValue){
	switch (A_u8Port){
			case PORT_A: *AP_u8PinValue = GET_BIT(PINA, A_u8Pin); break;
			case PORT_B: *AP_u8PinValue = GET_BIT(PINB, A_u8Pin); break;
			case PORT_C: *AP_u8PinValue = GET_BIT(PINC, A_u8Pin); break;
			case PORT_D: *AP_u8PinValue = GET_BIT(PIND, A_u8Pin); break;
	}
}

/* Set port direction */
void MDIO_VidSetPortDirection(u8 A_u8Port , u8 A_u8PortDir){

	if(A_u8PortDir == INPUT){
		switch (A_u8Port){
			case PORT_A: DDRA = 0x00; break;
			case PORT_B: DDRB = 0x00; break;
			case PORT_C: DDRC = 0x00; break;
			case PORT_D: DDRD = 0x00; break;

		}
	}

	else if(A_u8PortDir == OUTPUT){
		switch (A_u8Port){
			case PORT_A: DDRA = 0xff; break;
			case PORT_B: DDRB = 0xff; break;
			case PORT_C: DDRC = 0xff; break;
			case PORT_D: DDRD = 0xff; break;

		}
	}
}

/* Set port value */
void MDIO_VidSetPortValue (u8 A_u8Port ,  u8 A_u8PortVal)  {
	switch(A_u8Port) {
	case PORT_A :PORTA =A_u8PortVal ; break ;
	case PORT_B :PORTB =A_u8PortVal ; break ;
	case PORT_C :PORTC =A_u8PortVal ; break ;
	case PORT_D :PORTD =A_u8PortVal ; break ;
	}


}
/*Get PORT value */
void MDIO_VidGetPortValue (u8 A_u8Port , u8 *AP_u8Val) {
	switch(A_u8Port) {
	case PORT_A :*AP_u8Val = PINA  ; break ;
	case PORT_B :*AP_u8Val = PINB  ; break ;
	case PORT_C :*AP_u8Val = PINC  ; break ;
	case PORT_D :*AP_u8Val = PIND  ; break ;
	}
}
