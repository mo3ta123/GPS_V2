#ifndef DMA_H
#define DMA_H

#include "DMA_Pri.h"

/////////DMA en/dis/////////////////
void vDMA_ENABLE(void);
void vDMA_DISABLE(void);

/////////DMA Channel Add selection//////////
void vDMA_Channel_BASE_Pointer(void);

////////DMA channel  setting////////////////////////
void vDMA_Priority(uint8 channel,DMA_Priority_t Priority);
void vDMA_Primary_alternate_sel(uint8 channel ,DMA_Primary_sel_t num);
void vDMA_SB_Req_Modes(uint8 channel ,Brust_Single_mode_t mod);
void vDMA_Channel_Alow_Req(uint8 channel);
void vDMA_Channel_Mask_Req(uint8 channel);

//////// channel src and dst add //////////////////
void vDMA_Channel_SrcDst(uint8 channel,void* SRC,void* DST,uint16 datasize ,uint8 inc_option);
void vDMA_Channel_SrcDst_General(uint8 channel,void* SRC,void* DST,uint16 datasize,uint8 DATA_Byte_size,uint8 inc_SRC,uint8 inc_DST);
///////// dma channel ////////////////////////////////
void vDMA_Channel_Increment_DST(uint8 channel,uint8 inc_option);
void vDMA_Channel_Increment_SRC(uint8 channel,uint8 inc_option);

void vDMA_Channel_DATA_SIZE_DST(uint8 channel,uint8 inc_option);
void vDMA_Channel_DATA_SIZE_SRC(uint8 channel,uint8 inc_option);



void vDMA_Channel_Transfer_Mode(uint8 channel,uint8 mode);

//////////enable transfer channel //////////////
void vDMA_Channel_ENABLE(uint8 channel );
void vDMA_Channel_DISABLE(uint8 channel );

//////Channel Software Request /////////////////
void vDMA_Channel_SW_Transfer_REQ(uint8 channel);

////////////////////////DMA Channel MAP Select /////////////////
void vDMA_Channel_MAP(uint8 channel,uint8 Map);
	
#endif
