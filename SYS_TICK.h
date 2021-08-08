#ifndef SYS_TICK_H
#define SYS_TICK_H

#include "SYS_TICK_Pri.h"

#define MAX_RELOAD_VAL	0x00FFFFFF

void vTIMER_CLK_SRC_SETUP(void);
void vTIMER_ENABLE(void);
void vTIMER_DISABLE(void);
void vTIMER_Set_RELOAD(uint32 num);
uint8 u8TIMER_Count_Done(void);
void vTIMER_Count(uint32 num);
void vTIMER_Clear_Current_Load(void);
///////////////delay funs//////////////////
void wait_ms(uint32 del_ms);
void wait_sec(float32 del_s);
////////interrupt/////////////////////////////////////
void vTIMER_Interrupt_ENABLE(void);
void vTIMER_Interrupt_Disable(void);
#endif
