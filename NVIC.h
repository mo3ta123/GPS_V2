#ifndef NVIC_H
#define NVIC_H

#include "NVIC_Pri.h"
#include "STD_TYPES.h"
void 	vNVIC_ENABLE(uint8 Interrupt_num);
void 	vNVIC_DISABLE(uint8 Interrupt_num);
void 	vNVIC_SetPending(uint8 Interrupt_num);
void 	vNVIC_ClearPending(uint8 Interrupt_num);
uint8 u8NVIC_ACTIVE_Flag(uint8 Interrupt_num);
void 	vNVIC_SET_PRI(uint8 Interrupt_num,uint8 pri);


#endif
