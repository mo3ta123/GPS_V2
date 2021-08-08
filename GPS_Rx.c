#include "GPS_Rx.h"
#include "LCD.h"
uint8 GPS_Rx(char string[],GPGLL_Struct_t* GPGLL,uint16 size){
	uint16 i=0;uint16 temp_int;float temp_float;
	while(i<size){
		for(;i<size;i++)if(string[i]=='$')break;
		
		if(strncmp(&string[i],"$GPGLL",6)==0){
			if(sscanf(&string[i],"$GPGLL,%f,%*c,%f,%*c,%f,",&(GPGLL->lat),&(GPGLL->lon),&(GPGLL->time))){
				temp_int=(GPGLL->lat/100);//degrees
				temp_float=(GPGLL->lat)-temp_int*100;//minutes
				temp_float=temp_float/60;//converted to degrees
				GPGLL->lat=temp_int+temp_float;
				
				temp_int=(GPGLL->lon/100);//degrees
				temp_float=(GPGLL->lon)-temp_int*100;//minutes
				temp_float=temp_float/60;//converted to degrees
				GPGLL->lon=temp_int+temp_float;
				
				GPGLL->time_H=(GPGLL->time)/10000;																							//hhmmss.ss/10000=hh.mmssss == hh
				GPGLL->time_M=((GPGLL->time)/100)-((GPGLL->time_H)*100);												//hhmmss.ss/100 - hh*100 = hhmm.ssss-hh00 = mm.ssss == mm
				GPGLL->time_S=(GPGLL->time)-(((GPGLL->time_H)*10000)+((GPGLL->time_M)*100));		//hhmmss.ss - (hh*10000 + mm*100)=hhmmss.ss - hhmm00=ss.ss == ss
				
				//for egypt time
				GPGLL->time_H -=2;
				return 1;	
			}
			else return 0;
		}
		i++;
	}
	return 0;
}
