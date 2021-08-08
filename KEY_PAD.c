#include "KEY_PAD.h"

const char Key_Matrix[]={'1'	,'2', '3' ,F1
												,'4'	,'5', '6' ,F2
												,'7'	,'8', '9' ,F3
												,Start,'0',Stop ,F4};

												
char Read_Key(void){
	uint8 Row=0,Col=0,i,Pd=0;
	//waiting for key to be pressed 
	while((u8GPIO_DATA_READ_ALL(GPIO_D)&(0xCC))==0);
	
	//determine column
	if(u8GPIO_DATA_READ_PIN(GPIO_D,2)==1){Col=0;Pd=2;}
	else if(u8GPIO_DATA_READ_PIN(GPIO_D,3)==1){Col=1;Pd=3;}
	else if(u8GPIO_DATA_READ_PIN(GPIO_D,6)==1){Col=2;Pd=6;}
	else if(u8GPIO_DATA_READ_PIN(GPIO_D,7)==1){Col=3;Pd=7;}
	
	//determine row
	for(i=0;i<4;i++){
		vGPIO_DATA_WRITE_RESET_ALL(GPIO_A,0xF0);
		vGPIO_DATA_WRITE_SET_ALL(GPIO_A,((0x10)<<i));
		
		if(u8GPIO_DATA_READ_PIN(GPIO_D,Pd)==1){
			Row=i;
			break;
		}
		
	}
	
	vGPIO_DATA_WRITE_SET_ALL(GPIO_A,0xF0);
	
	while(u8GPIO_DATA_READ_PIN(GPIO_D,Pd)==1);
	return Key_Matrix[Col+Row*4];
}
