#ifndef GPS_RX_H
#define GPS_RX_H


#include <string.h>
#include <stdio.h>
#include "STD_TYPES.h"

typedef struct{
	float lat;
	float lon;
	float time;
	uint8 time_H;
	uint8 time_M;
	uint8 time_S;
}GPGLL_Struct_t;


uint8 GPS_Rx(char string[],GPGLL_Struct_t* GPGLL,uint16 size);	//returns 0 if not succes returns 1 if success

#endif
