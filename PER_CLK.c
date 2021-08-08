#include "PER_CLK.h"

void vEnable_CLK_TIMER(uint8 num){
	setBit(RCGCTIMER,num);
}
void vEnable_CLK_GPIO(GPIO_CLK_SEL_t num){
	setBit(RCGCGPIO,num);
}
void vEnable_CLK_DMA(){
	setBit(RCGCDMA,0);
}
void vEnable_CLK_UART(uint8 num){
	setBit(RCGCUART,num);
}


void vDisable_CLK_TIMER(uint8 num){
	resetBit(RCGCTIMER,num);
}
void vDisable_CLK_GPIO(GPIO_CLK_SEL_t num){
	resetBit(RCGCGPIO,num);
}
void vDisable_CLK_DMA(){
	resetBit(RCGCDMA,0);
}
void vDisable_CLK_UART(uint8 num){
	resetBit(RCGCUART,num);
}



uint8 u8Check_CLK_TIMER(uint8 num){
	return checkBit(PRTIMER,num);
}
uint8 u8Check_CLK_GPIO(GPIO_CLK_SEL_t num){
	return checkBit(PRGPIO,num);
}
uint8 u8Check_CLK_DMA(){
	return checkBit(PRDMA,0);
}
uint8 u8Check_CLK_UART(uint8 num){
	return checkBit(PRUART,num);
}



void vActive_CLK_TIMER(uint8 num){
	vEnable_CLK_TIMER(num);
	while(!u8Check_CLK_TIMER(num));
}
void vActive_CLK_GPIO(GPIO_CLK_SEL_t num){
	vEnable_CLK_GPIO(num);
	while(!u8Check_CLK_GPIO(num));
}
void vActive_CLK_DMA(){
	vEnable_CLK_DMA();
	while(!u8Check_CLK_DMA());
}
void vActive_CLK_UART(uint8 num){
	vEnable_CLK_UART(num);
	while(!u8Check_CLK_UART(num));
}
