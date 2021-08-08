#ifndef PER_CLK_H
#define PER_CLK_H

#include "PER_CLK_Pri.h"


//enable per clk
void vEnable_CLK_TIMER(uint8 num);
void vEnable_CLK_GPIO(GPIO_CLK_SEL_t num);
void vEnable_CLK_DMA(void);
void vEnable_CLK_UART(uint8 num);

//dis per clk
void vDisable_CLK_TIMER(uint8 num);
void vDisable_CLK_GPIO(GPIO_CLK_SEL_t num);
void vDisable_CLK_DMA(void);
void vDisable_CLK_UART(uint8 num);

//check if ready
uint8 u8Check_CLK_TIMER(uint8 num);
uint8 u8Check_CLK_GPIO(GPIO_CLK_SEL_t num);
uint8 u8Check_CLK_DMA(void);
uint8 u8Check_CLK_UART(uint8 num);

//activate clk
void vActive_CLK_TIMER(uint8 num);
void vActive_CLK_GPIO(GPIO_CLK_SEL_t num);
void vActive_CLK_DMA(void);
void vActive_CLK_UART(uint8 num);


#endif

