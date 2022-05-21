/*
 * DIO.c
 *
 *  Created on: May 17, 2022
 *      Author: Nourhan
 */

#include <util/delay.h>
#include "../LIB/typedef.h"
#include "../MCAL/MDIO_int.h"
#include "../HAL/HSSD_int.h"


#define HLED	0
#define HSSD	1

#define code	HSSD
int main(){

#if code == 0
	/* Define pin as output */
	MDIO_VidSetPinDirection(PORT_A, PIN_1, OUTPUT);

	/* Set pin as high */

	while(1){
		MDIO_VidSetPinValue(PORT_A, PIN_1, HIGH);

	_delay_ms(500);

	/* Set pin as low */
	MDIO_VidSetPinValue(PORT_A, PIN_1, LOW );
	_delay_ms(500);
	}
#elif code == 1
	HSSD_VidInit(SSD_ID0 , SSD_COM_ANODE);
	HSSD_VidInit(SSD_ID1 , SSD_COM_ANODE);

	while (1){
		for(int i = 0 ; i < 6 ; i++){
			HSSD_VidDisplayNumber(SSD_ID1,i);
			for(int j = 0 ; j < 10 ; j++){
				HSSD_VidDisplayNumber(SSD_ID0,j);
				_delay_ms(1000);
			}

		}
	}
#endif
}
