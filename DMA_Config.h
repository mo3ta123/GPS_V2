#ifndef DMA_CONFIG_H
#define DMA_CONFIG_H

#include "DMA.h"
#include "PER_CLK.h"
#include "UART.h"
/////////////////////mem to mem/////////////////////////////////////
void vDMA_MemToMem_SETUP(void);
void vDMA_MemToMem_Begin(void* SRC,void* DST,uint16 datasize ,uint8 inc_option);
uint8 u8DMA_MemToMem_isDone(void);
/////////////////////UART 7///////////////////////////////////////////////
void vDMA_UART7_Rx_SETUP(void);
void vDMA_UART7_Rx_Begin(void* DST,uint16 datasize);
uint8 u8DMA_UART7_Rx_isDone(void);
#endif
