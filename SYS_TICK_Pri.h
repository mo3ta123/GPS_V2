#ifndef SYS_TICK_PRI
#define SYS_TICK_PRI
#include "STD_TYPES.h"


#define SYS_TICK_BASE_ADD				0xE000E000

#define SYS_TICL_STCTRL					(*((volatile uint32*)(SYS_TICK_BASE_ADD+0x010)))
#define SYS_TICL_STRELOAD				(*((volatile uint32*)(SYS_TICK_BASE_ADD+0x014)))
#define SYS_TICL_STCURRENT			(*((volatile uint32*)(SYS_TICK_BASE_ADD+0x018)))
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////CLK SETUP///////////////////////////////////////////////////
#define System_CLK							16//MHz

#define TIMER_CLK							(System_CLK)	//MHz






#endif
