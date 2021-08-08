#ifndef UART_H
#define UART_H

#include "UART_Pri.h"
#ifndef CPU_CLK
#define CPU_CLK	(16*1000000)
#endif

#define div			16		//used in BR

UART_Struct_t* UART_SELECT_BASE_ADD(UART_SEL_t uart);
////////////////UART en/dis//////////////////////
void vUART_ENABLE(UART_SEL_t num);
void vUART_DISABLE(UART_SEL_t num);

////////////////UART Baud rate//////////////////
void vUART_BAUD_RATE_SETUP(UART_SEL_t num,uint32 BR);

///////////////UART Tx/Rx //////////////////////
void vUART_MODE_SETUP(UART_SEL_t num,UART_MODE_t mod);

///////////////UART DATA  //////////////////////
uint8 u8UART_READ_DATA(UART_SEL_t num);
void vUART_WRITE_DATA(UART_SEL_t num,uint8 data);

//////////////UART setting/////////////////////////
void vUART_DATA_WLEN(UART_SEL_t num,uint8 len);

void vUART_FIFO_ENABLE(UART_SEL_t num);
void vUART_FIFO_DISABLE(UART_SEL_t num);

uint8 u8UART_FIFO_EN_READ(UART_SEL_t num);

//////////////uart flags//////////////////////////////
uint8 u8UART_TX_FIFO_FULL(UART_SEL_t num);
uint8 u8UART_RX_FIFO_Empty(UART_SEL_t num);

//////////////////////DMA	Control /////////////////////////
void vUART_DMA_SETUP(UART_SEL_t num,UART_MODE_t dma,uint8 DMA_Error_disable_handle);
void vUART_DMA_DISABLE(UART_SEL_t num);
#endif
