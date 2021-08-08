#include "DMA.h"
#if defined(ewarm)
#pragma data_alignment=1024
Channel_Struct_t Channel_Control[64];
#elif defined(ccs)
#pragma DATA_ALIGN(ui8ControlTable, 1024)
Channel_Struct_t Channel_Control[64];
#else
Channel_Struct_t Channel_Control[64] __attribute__ ((aligned(1024)));
#endif


/////////DMA en/dis/////////////////
void vDMA_ENABLE(void){
	setBit(DMACFG,0);
}

void vDMA_DISABLE(void){
	resetBit(DMACFG,0);
}
//////////////choosing pointer for channels///////////////////
void vDMA_Channel_BASE_Pointer(void){
	DMACTLBASE=(uint32)Channel_Control;
}

/////////////////// settings //////////////////////
void vDMA_Priority(uint8 channel,DMA_Priority_t Priority){
	if(Priority==0)
		resetBit(DMAPRIOSET,channel);
	else
		setBit(DMAPRIOSET,channel);
}

void vDMA_Primary_alternate_sel(uint8 channel ,DMA_Primary_sel_t num){
	switch(num){
		case DMA_primary:
			resetBit(DMAALTSET,channel);
			break;
		case DMA_alternate:
			setBit(DMAALTSET,channel);
			break;
	}
}
void vDMA_SB_Req_Modes(uint8 channel ,Brust_Single_mode_t mod){
	switch(mod){
		case DMA_Brust_only:
			setBit(DMAUSEBURSTSET,channel);
		break;
		case DMA_Brust_Single:
			setBit(DMAUSEBURSTCLR,channel);
		break;
	}
}

void vDMA_Channel_Alow_Req(uint8 channel){
	setBit(DMAREQMASKCLR,channel);
}
void vDMA_Channel_Mask_Req(uint8 channel){
	setBit(DMAREQMASKSET,channel);
}

////////////src dst channel add ///////////////////////////////////////////////
void vDMA_Channel_SrcDst(uint8 channel,void* SRC,void* DST,uint16 datasize ,uint8 inc_option){
	//src and dst addresse
	switch(inc_option){
		case Byte:
			Channel_Control[channel].DMASRC=(uint32)(((uint8*)SRC)+datasize-1);
			Channel_Control[channel].DMADST=(uint32)(((uint8*)DST)+datasize-1);
			break;
		case Half_word:
			Channel_Control[channel].DMASRC=(uint32)(((uint16*)SRC)+datasize-1);
			Channel_Control[channel].DMADST=(uint32)(((uint16*)DST)+datasize-1);
			break;
		case Word:
			Channel_Control[channel].DMASRC=(uint32)(((uint32*)SRC)+datasize-1);
			Channel_Control[channel].DMADST=(uint32)(((uint32*)DST)+datasize-1);
			break;
	}
	//data_size
	if(datasize >1024)datasize=1023;
	else datasize--;
	Channel_Control[channel].DMACHCTL=((Channel_Control[channel].DMACHCTL)&(0xFFFFC00F))| (datasize<<4);
	//options in src and dst
	vDMA_Channel_Increment_DST(channel,inc_option);
	vDMA_Channel_Increment_SRC(channel,inc_option);
	vDMA_Channel_DATA_SIZE_DST(channel,inc_option);
	vDMA_Channel_DATA_SIZE_SRC(channel,inc_option);
}

void vDMA_Channel_SrcDst_General(uint8 channel,void* SRC,void* DST,uint16 datasize,uint8 DATA_Byte_size,uint8 inc_SRC,uint8 inc_DST){
	//src and dst addresses
	switch(inc_SRC){
		case Byte:
			Channel_Control[channel].DMASRC=(uint32)(((uint8*)SRC)+datasize-1);
			break;
		case Half_word:
			Channel_Control[channel].DMASRC=(uint32)(((uint16*)SRC)+datasize-1);
			break;
		case Word:
			Channel_Control[channel].DMASRC=(uint32)(((uint32*)SRC)+datasize-1);
			break;
		case No_increment:
			Channel_Control[channel].DMASRC=(uint32)SRC;
		break;
	}
	
	switch(inc_DST){
		case Byte:
			Channel_Control[channel].DMADST=(uint32)(((uint8*)DST)+datasize-1);
			break;                      
		case Half_word:               
			Channel_Control[channel].DMADST=(uint32)(((uint16*)DST)+datasize-1);
			break;                      
		case Word:                    
			Channel_Control[channel].DMADST=(uint32)(((uint32*)DST)+datasize-1);
			break;                      
		case No_increment:            
			Channel_Control[channel].DMADST=(uint32)DST;
		break;
	}
	if(datasize >1024)datasize=1023;
	else datasize--;
	Channel_Control[channel].DMACHCTL=((Channel_Control[channel].DMACHCTL)&(0xFFFFC00F))| (datasize<<4);
	
	vDMA_Channel_Increment_DST(channel,inc_DST);
	vDMA_Channel_Increment_SRC(channel,inc_SRC);
	vDMA_Channel_DATA_SIZE_DST(channel,DATA_Byte_size);
	vDMA_Channel_DATA_SIZE_SRC(channel,DATA_Byte_size);
	
}
///////// dma channel ////////////////////////////////
void vDMA_Channel_Increment_DST(uint8 channel,uint8 inc_option){
	Channel_Control[channel].DMACHCTL=((Channel_Control[channel].DMACHCTL)&(0x3FFFFFFF))| (inc_option<<30);
}

void vDMA_Channel_Increment_SRC(uint8 channel,uint8 inc_option){
	Channel_Control[channel].DMACHCTL=((Channel_Control[channel].DMACHCTL)&(0xF3FFFFFF))| (inc_option<<26);
}

void vDMA_Channel_DATA_SIZE_DST(uint8 channel,uint8 inc_option){
	Channel_Control[channel].DMACHCTL=((Channel_Control[channel].DMACHCTL)&(0xCFFFFFFF))| (inc_option<<28);
}

void vDMA_Channel_DATA_SIZE_SRC(uint8 channel,uint8 inc_option){
	Channel_Control[channel].DMACHCTL=((Channel_Control[channel].DMACHCTL)&(0xFCFFFFFF))| (inc_option<<24);
}


void vDMA_Channel_Transfer_Mode(uint8 channel,uint8 mode){
	Channel_Control[channel].DMACHCTL=((Channel_Control[channel].DMACHCTL)&(0xFFFFFFFC))| mode;
}

/////////////////////// dma channel enable ////////////////////////////////
void vDMA_Channel_ENABLE(uint8 channel ){
	setBit(DMAENASET,channel);
}

void vDMA_Channel_DISABLE(uint8 channel ){
	resetBit(DMAENASET,channel);
}

//////Channel Software Request /////////////////
void vDMA_Channel_SW_Transfer_REQ(uint8 channel){
	setBit(DMASWREQ,channel);
}


////////////////////////DMA Channel MAP Select /////////////////
void vDMA_Channel_MAP(uint8 channel,uint8 Map){
	uint8 index=(channel%8)*4;
	if(channel<8){
		DMACHMAP0&=~(0xF<<index);
		DMACHMAP0|=(Map<<index);
	}
	else if(channel<16){
		DMACHMAP1&=~(0xF<<index);
		DMACHMAP1|=(Map<<index);
	}
	else if(channel<24){
		DMACHMAP2&=~(0xF<<index);
		DMACHMAP2|=(Map<<index);
	}
	else if(channel<32){
		DMACHMAP3&=~(0xF<<index);
		DMACHMAP3|=(Map<<index);
	}
}
