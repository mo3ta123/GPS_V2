#include "NVIC.h"

void 	vNVIC_ENABLE(uint8 Interrupt_num){
	if(Interrupt_num <=138){
	uint8 index=Interrupt_num/32;
	setBit(NVIC_SET_EN[index],Interrupt_num%32);
	}
}
void 	vNVIC_DISABLE(uint8 Interrupt_num){
	if(Interrupt_num <=138){
		uint8 index=Interrupt_num/32;
		setBit(NVIC_CLEAR_EN[index],Interrupt_num%32);
	}
}
void 	vNVIC_SetPending(uint8 Interrupt_num){
	if(Interrupt_num <=138){
	uint8 index=Interrupt_num/32;
	setBit(NVIC_SetPend[index],Interrupt_num%32);
	}
}
void 	vNVIC_ClearPending(uint8 Interrupt_num){
	if(Interrupt_num <=138){
	uint8 index=Interrupt_num/32;
	setBit(NVIC_ClearPend[index],Interrupt_num%32);
	}
}
uint8 u8NVIC_ACTIVE_Flag(uint8 Interrupt_num){
	uint8 index=Interrupt_num/32;
	return checkBit(NVIC_ACTIVE[index],Interrupt_num%32);
}
void 	vNVIC_SET_PRI(uint8 Interrupt_num,uint8 pri){
	uint8 shift=(Interrupt_num%4)*8+5;
	if(Interrupt_num <=138){
	uint8 index=Interrupt_num/4;
	NVIC_PRI[index]|=(pri<<shift);
	}
}
