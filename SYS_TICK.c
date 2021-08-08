#include "SYS_TICK.h"


void vTIMER_CLK_SRC_SETUP(void){
	setBit(SYS_TICL_STCTRL,2); 		//clk is cpu clk
}

void vTIMER_ENABLE(void){
	setBit(SYS_TICL_STCTRL,0);
}

void vTIMER_DISABLE(void){
	resetBit(SYS_TICL_STCTRL,0);
}

void vTIMER_Set_RELOAD(uint32 num){//from 0 to 16777215
	SYS_TICL_STRELOAD =(MAX_RELOAD_VAL&num);
}

uint8 u8TIMER_Count_Done(void){
	return checkBit(SYS_TICL_STCTRL,16);
}

void vTIMER_Count(uint32 num){
	vTIMER_DISABLE();
	vTIMER_Set_RELOAD(num);
	vTIMER_Clear_Current_Load();
	vTIMER_ENABLE();
	while(u8TIMER_Count_Done()==0);
	vTIMER_DISABLE();
	
}

void vTIMER_Clear_Current_Load(void){
	SYS_TICL_STCURRENT =MAX_RELOAD_VAL;  //to clear current load
}

void wait_ms(uint32 del_ms){
	uint32 Total_count;
	double period=1.0/TIMER_CLK; 						//in micro sec
	double del_micro=del_ms*1000;				
	Total_count=(uint32)(del_micro/period);
	
	while(Total_count>0){
		if(Total_count>=MAX_RELOAD_VAL){
			vTIMER_Count(MAX_RELOAD_VAL);
			Total_count-=MAX_RELOAD_VAL;
	}
		else{
			vTIMER_Count(Total_count);
			Total_count=0;
		}
	}
	
}

void wait_sec(float32 del_s){
	wait_ms(del_s*1000);
}

void vTIMER_Interrupt_ENABLE(void){
	setBit(SYS_TICL_STCTRL,1);
}
void vTIMER_Interrupt_Disable(void){
	resetBit(SYS_TICL_STCTRL,1);
}
