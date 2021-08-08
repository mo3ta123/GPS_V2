#include "DMA_Config.h"

#include <stdio.h>

/////////////////////mem to mem/////////////////////////////////////
void vDMA_MemToMem_SETUP(void){
	vActive_CLK_DMA();
	vDMA_Channel_BASE_Pointer();
	vDMA_ENABLE();
	vDMA_Priority(30,DMA_High_pri);
	vDMA_Primary_alternate_sel(30,DMA_primary);
	vDMA_SB_Req_Modes(30,DMA_Brust_Single);
	vDMA_Channel_Alow_Req(30);
	
	
}

void vDMA_MemToMem_Begin(void* SRC,void* DST,uint16 datasize ,uint8 inc_option){
	vDMA_Channel_SrcDst(30,SRC,DST,datasize,inc_option);
	vDMA_Channel_Transfer_Mode(30,Auto_Request);
	vDMA_Channel_ENABLE(30);
	vDMA_Channel_SW_Transfer_REQ(30);
}

uint8 u8DMA_MemToMem_isDone(void){
	if (checkBit(DMAENASET,30)==0)
		return 1;
	else 
		return 0;
}

//////////////////uart ////////////////////////////////////////////////////////
void vDMA_UART7_Rx_SETUP(void){
	
	vActive_CLK_DMA();
	vDMA_Channel_BASE_Pointer();
	vDMA_ENABLE();
	vDMA_Priority(20,DMA_High_pri);
	vDMA_Primary_alternate_sel(20,DMA_primary);
	vDMA_SB_Req_Modes(20,DMA_Brust_Single);
	vDMA_Channel_Alow_Req(20);
	vDMA_Channel_MAP(20,2);// choosing uart7 rx
	
	vActive_CLK_UART(UART_7);
	vUART_DMA_SETUP(UART_7,Rx_only,0);
}

void vDMA_UART7_Rx_Begin(void* DST,uint16 datasize){
	vDMA_Channel_SrcDst_General(20,UART7_BASE_ADD,DST,datasize,Byte,No_increment,Byte);//no increment for src only dst
	vDMA_Channel_Transfer_Mode(20,Basic_Transfer_mode);
	vDMA_Channel_ENABLE(20);
}

uint8 u8DMA_UART7_Rx_isDone(void){
	if (checkBit(DMAENASET,20)==0)
		return 1;
	else 
		return 0;
}
