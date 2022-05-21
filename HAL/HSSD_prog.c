/*
 * HSSD_prog.c
 *
 *  Created on: May 17, 2022
 *      Author: Nourhan
 */
#include "../LIB/BIT_MATH.h"
#include "../LIB/typedef.h"
#include "../MCAL/MDIO_int.h"
#include "HSSD_int.h"

/*SSD common Anode */
u8 GR_u8SSDCommAnodeArray []= {
		~0b00111111,   /* 0 */
        ~0b00000110,   /* 1 */
        ~0b01011011,   /* 2 */
        ~0b01001111,   /* 3 */
        ~0b01100110,   /* 4 */
        ~0b01101101,   /* 5 */
        ~0b01111101,   /* 6 */
        ~0b00000111,   /* 7 */
        ~0b01111111,   /* 8 */
        ~0b01101111    /* 9 */
		  };
u8 GR_u8SSDCommCathodeArray[] = {
		0b00111111,   /* 0 */
        0b00000110,   /* 1 */
        0b01011011,   /* 2 */
        0b01001111,   /* 3 */
        0b01100110,   /* 4 */
        0b01101101,   /* 5 */
        0b01111101,   /* 6 */
        0b00000111,   /* 7 */
        0b01111111,   /* 8 */
        0b01101111    /* 9 */
		  };

void HSSD_VidInit(u8 A_u8Id , u8 A_u8Type){


	if (A_u8Id == SSD_ID0){
		MDIO_VidSetPinDirection(SSD_ID0, SSD1_SEGA , OUTPUT);
		MDIO_VidSetPinDirection(SSD_ID0, SSD1_SEGB , OUTPUT);
		MDIO_VidSetPinDirection(SSD_ID0, SSD1_SEGC , OUTPUT);
		MDIO_VidSetPinDirection(SSD_ID0, SSD1_SEGD , OUTPUT);
		MDIO_VidSetPinDirection(SSD_ID0, SSD1_SEGE , OUTPUT);
		MDIO_VidSetPinDirection(SSD_ID0, SSD1_SEGF , OUTPUT);
		MDIO_VidSetPinDirection(SSD_ID0, SSD1_SEGG , OUTPUT);

		switch(A_u8Type){
		case SSD_COM_CATHODE:
			MDIO_VidSetPinValue(SSD_ID0, SSD1_SEGA , LOW) ;
			MDIO_VidSetPinValue(SSD_ID0, SSD1_SEGB , LOW) ;
			MDIO_VidSetPinValue(SSD_ID0, SSD1_SEGC , LOW) ;
			MDIO_VidSetPinValue(SSD_ID0, SSD1_SEGD , LOW) ;
			MDIO_VidSetPinValue(SSD_ID0, SSD1_SEGE , LOW) ;
			MDIO_VidSetPinValue(SSD_ID0, SSD1_SEGF , LOW) ;
			MDIO_VidSetPinValue(SSD_ID0, SSD1_SEGG , LOW) ;
		break;
		case SSD_COM_ANODE:
			MDIO_VidSetPinValue(SSD_ID0, SSD1_SEGA , HIGH) ;
			MDIO_VidSetPinValue(SSD_ID0, SSD1_SEGB , HIGH) ;
			MDIO_VidSetPinValue(SSD_ID0, SSD1_SEGC , HIGH) ;
			MDIO_VidSetPinValue(SSD_ID0, SSD1_SEGD , HIGH) ;
			MDIO_VidSetPinValue(SSD_ID0, SSD1_SEGE , HIGH) ;
			MDIO_VidSetPinValue(SSD_ID0, SSD1_SEGF , HIGH) ;
			MDIO_VidSetPinValue(SSD_ID0, SSD1_SEGG , HIGH) ;
		break;
		}
	}
	else if (A_u8Id == SSD_ID1){
		MDIO_VidSetPinDirection(SSD_ID1, SSD1_SEGA , OUTPUT);
		MDIO_VidSetPinDirection(SSD_ID1, SSD1_SEGB , OUTPUT);
		MDIO_VidSetPinDirection(SSD_ID1, SSD1_SEGC , OUTPUT);
		MDIO_VidSetPinDirection(SSD_ID1, SSD1_SEGD , OUTPUT);
		MDIO_VidSetPinDirection(SSD_ID1, SSD1_SEGE , OUTPUT);
		MDIO_VidSetPinDirection(SSD_ID1, SSD1_SEGF , OUTPUT);
		MDIO_VidSetPinDirection(SSD_ID1, SSD1_SEGG , OUTPUT);

	}
	switch(A_u8Type){
	case SSD_COM_CATHODE:
		MDIO_VidSetPinValue(SSD_ID1, SSD1_SEGA , LOW) ;
		MDIO_VidSetPinValue(SSD_ID1, SSD1_SEGB , LOW) ;
		MDIO_VidSetPinValue(SSD_ID1, SSD1_SEGC , LOW) ;
		MDIO_VidSetPinValue(SSD_ID1, SSD1_SEGD , LOW) ;
		MDIO_VidSetPinValue(SSD_ID1, SSD1_SEGE , LOW) ;
		MDIO_VidSetPinValue(SSD_ID1, SSD1_SEGF , LOW) ;
		MDIO_VidSetPinValue(SSD_ID1, SSD1_SEGG , LOW) ;
	break;
	case SSD_COM_ANODE:
		MDIO_VidSetPinValue(SSD_ID1, SSD1_SEGA , HIGH) ;
		MDIO_VidSetPinValue(SSD_ID1, SSD1_SEGB , HIGH) ;
		MDIO_VidSetPinValue(SSD_ID1, SSD1_SEGC , HIGH) ;
		MDIO_VidSetPinValue(SSD_ID1, SSD1_SEGD , HIGH) ;
		MDIO_VidSetPinValue(SSD_ID1, SSD1_SEGE , HIGH) ;
		MDIO_VidSetPinValue(SSD_ID1, SSD1_SEGF , HIGH) ;
		MDIO_VidSetPinValue(SSD_ID1, SSD1_SEGG , HIGH) ;
	break;
	}
}
void HSSD_VidDisplayNumber(u8 A_u8Id, u8 A_u8Number){
	if (A_u8Id == SSD_ID0) {
#if SSD0_TYPE == SSD_COM_ANODE
	/*clear SSD0 */
		MDIO_VidSetPinValue(SSD0_PORT , SSD0_SEGA ,HIGH) ;
		MDIO_VidSetPinValue(SSD0_PORT , SSD0_SEGB ,HIGH);
		MDIO_VidSetPinValue(SSD0_PORT , SSD0_SEGC ,HIGH);
		MDIO_VidSetPinValue(SSD0_PORT , SSD0_SEGD ,HIGH);
		MDIO_VidSetPinValue(SSD0_PORT , SSD0_SEGE ,HIGH);
		MDIO_VidSetPinValue(SSD0_PORT , SSD0_SEGF ,HIGH);
		MDIO_VidSetPinValue(SSD0_PORT , SSD0_SEGG ,HIGH);
	/*Set SSD number */
	MDIO_VidSetPortValue( SSD0_PORT , GR_u8SSDCommAnodeArray[A_u8Number]) ;
	#elif SSD0_TYPE == SSD_COM_CATHOD
			/*clear SSD0 */

						MDIO_VidSetPinValue(SSD0_PORT , SSD0_SEGA ,LOW) ;
						MDIO_VidSetPinValue(SSD0_PORT , SSD0_SEGB ,LOW) ;
						MDIO_VidSetPinValue(SSD0_PORT , SSD0_SEGC ,LOW) ;
						MDIO_VidSetPinValue(SSD0_PORT , SSD0_SEGD ,LOW) ;
						MDIO_VidSetPinValue(SSD0_PORT , SSD0_SEGE ,LOW) ;
						MDIO_VidSetPinValue(SSD0_PORT , SSD0_SEGF ,LOW) ;
						MDIO_VidSetPinValue(SSD0_PORT , SSD0_SEGG ,LOW) ;

	MDIO_VidSetPortValue( SSD0_PORT , GR_u8SSDCommCathodeArray[A_u8Number]) ;
	#endif

	}
	else if (A_u8Id == SSD_ID1){
#if SSD1_TYPE == SSD_COM_ANODE
		/*clear SSD0 */
			MDIO_VidSetPinValue(SSD1_PORT , SSD1_SEGA ,HIGH) ;
			MDIO_VidSetPinValue(SSD1_PORT , SSD1_SEGB ,HIGH);
			MDIO_VidSetPinValue(SSD1_PORT , SSD1_SEGC ,HIGH);
			MDIO_VidSetPinValue(SSD1_PORT , SSD1_SEGD ,HIGH);
			MDIO_VidSetPinValue(SSD1_PORT , SSD1_SEGE ,HIGH);
			MDIO_VidSetPinValue(SSD1_PORT , SSD1_SEGF ,HIGH);
			MDIO_VidSetPinValue(SSD1_PORT , SSD1_SEGG ,HIGH);
		/*Set SSD number */
		MDIO_VidSetPortValue( SSD1_PORT , GR_u8SSDCommAnodeArray[A_u8Number]) ;
		#elif SSD1_TYPE == SSD_COM_CATHOD
				/*clear SSD0 */

							MDIO_VidSetPinValue(SSD1_PORT , SSD1_SEGA ,LOW) ;
							MDIO_VidSetPinValue(SSD1_PORT , SSD1_SEGB ,LOW) ;
							MDIO_VidSetPinValue(SSD1_PORT , SSD1_SEGC ,LOW) ;
							MDIO_VidSetPinValue(SSD1_PORT , SSD1_SEGD ,LOW) ;
							MDIO_VidSetPinValue(SSD1_PORT , SSD1_SEGE ,LOW) ;
							MDIO_VidSetPinValue(SSD1_PORT , SSD1_SEGF ,LOW) ;
							MDIO_VidSetPinValue(SSD1_PORT , SSD1_SEGG ,LOW) ;

		MDIO_VidSetPortValue( SSD1_PORT , GR_u8SSDCommCathodeArray[A_u8Number]) ;
		#endif
	}

}


void HSSD_VidTurnOff(u8 A_u8Id){
	if (A_u8Id == SSD_ID0) {
	#if SSD0_TYPE == SSD_COM_ANODE
	/*clear SSD0 */
		MDIO_VidSetPinValue(SSD0_PORT , SSD0_SEGA ,HIGH) ;
		MDIO_VidSetPinValue(SSD0_PORT , SSD0_SEGB ,HIGH);
		MDIO_VidSetPinValue(SSD0_PORT , SSD0_SEGC ,HIGH);
		MDIO_VidSetPinValue(SSD0_PORT , SSD0_SEGD ,HIGH);
		MDIO_VidSetPinValue(SSD0_PORT , SSD0_SEGE ,HIGH);
		MDIO_VidSetPinValue(SSD0_PORT , SSD0_SEGF ,HIGH);
		MDIO_VidSetPinValue(SSD0_PORT , SSD0_SEGG ,HIGH);
	#elif SSD0_TYPE == SSD_COM_CATHOD
			/*clear SSD0 */

						MDIO_VidSetPinValue(SSD0_PORT , SSD0_SEGA ,LOW) ;
						MDIO_VidSetPinValue(SSD0_PORT , SSD0_SEGB ,LOW) ;
						MDIO_VidSetPinValue(SSD0_PORT , SSD0_SEGC ,LOW) ;
						MDIO_VidSetPinValue(SSD0_PORT , SSD0_SEGD ,LOW) ;
						MDIO_VidSetPinValue(SSD0_PORT , SSD0_SEGE ,LOW) ;
						MDIO_VidSetPinValue(SSD0_PORT , SSD0_SEGF ,LOW) ;
						MDIO_VidSetPinValue(SSD0_PORT , SSD0_SEGG ,LOW) ;

	#endif

	}
	else if (A_u8Id == SSD_ID1){
#if SSD1_TYPE == SSD_COM_ANODE
		/*clear SSD1 */
			MDIO_VidSetPinValue(SSD1_PORT , SSD1_SEGA ,HIGH) ;
			MDIO_VidSetPinValue(SSD1_PORT , SSD1_SEGB ,HIGH);
			MDIO_VidSetPinValue(SSD1_PORT , SSD1_SEGC ,HIGH);
			MDIO_VidSetPinValue(SSD1_PORT , SSD1_SEGD ,HIGH);
			MDIO_VidSetPinValue(SSD1_PORT , SSD1_SEGE ,HIGH);
			MDIO_VidSetPinValue(SSD1_PORT , SSD1_SEGF ,HIGH);
			MDIO_VidSetPinValue(SSD1_PORT , SSD1_SEGG ,HIGH);
#elif SSD1_TYPE == SSD_COM_CATHOD
		/*clear SSD0 */

			MDIO_VidSetPinValue(SSD1_PORT , SSD1_SEGA ,LOW) ;
			MDIO_VidSetPinValue(SSD1_PORT , SSD1_SEGB ,LOW) ;
			MDIO_VidSetPinValue(SSD1_PORT , SSD1_SEGC ,LOW) ;
			MDIO_VidSetPinValue(SSD1_PORT , SSD1_SEGD ,LOW) ;
			MDIO_VidSetPinValue(SSD1_PORT , SSD1_SEGE ,LOW) ;
			MDIO_VidSetPinValue(SSD1_PORT , SSD1_SEGF ,LOW) ;
			MDIO_VidSetPinValue(SSD1_PORT , SSD1_SEGG ,LOW) ;

#endif
	}
}

