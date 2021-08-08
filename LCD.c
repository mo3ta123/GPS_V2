#include "LCD.h"

void vLCD_E(uint8 dat);
void vLCD_RS(uint8 dat);

void vLCD_INT(void){
	vLCD_Instruction(LCD_Ins_FunctionSet);
	vLCD_Instruction(LCD_Ins_DisplayOn);
	vLCD_Instruction(LCD_Ins_ClearDisplay);
	vLCD_Instruction(LCD_Ins_EntryMode);
}

void vLCD_String(char string []){
	uint8 i=0;
	uint8 flag_newline=0;
	vLCD_Instruction(LCD_Ins_ClearDisplay);
	vLCD_Instruction(LCD_Ins_EntryMode);
	
	while((string[i])&&(i<32)){
		if(string[i]=='\n'){
			vLCD_Instruction(LCD_Ins_NewLine);
			flag_newline=1;
		}
		else{
			if((i==16)&&(flag_newline==0)){
				vLCD_Instruction(LCD_Ins_NewLine);
				flag_newline=1;
			}
			vLCD_Char(string[i]);
		}
		i++;
	}
	
}








void  vLCD_Char(uint8 ch){
	vGPIO_DATA_WRITE_ALL(GPIO_B,ch);
	vLCD_RS(HIGH);
	vLCD_E(HIGH);
	wait_ms(3);
	vLCD_E(LOW);
}

void 	vLCD_Instruction(uint8 Ins){
	vGPIO_DATA_WRITE_ALL(GPIO_B,Ins);
	vLCD_RS(LOW);
	vLCD_E(HIGH);
	wait_ms(3);
	vLCD_E(LOW);
}


void vLCD_RS(uint8 dat){		//PC6
	switch(dat){
		case 0:
			vGPIO_DATA_WRITE_RESET_ALL(GPIO_C,0x40);
			break;
		case 1:
			vGPIO_DATA_WRITE_SET_ALL(GPIO_C,0x40);
			break;
		default:
			vGPIO_DATA_WRITE_SET_ALL(GPIO_C,0x40);
			break;
	}
}

void vLCD_E(uint8 dat){			//PC7
	switch(dat){
		case 0:
			vGPIO_DATA_WRITE_RESET_ALL(GPIO_C,0x80);
			break;
		case 1:
			vGPIO_DATA_WRITE_SET_ALL(GPIO_C,0x80);
			break;
		default:
			vGPIO_DATA_WRITE_SET_ALL(GPIO_C,0x80);
			break;
	}
}

