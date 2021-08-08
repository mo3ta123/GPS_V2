#ifndef PER_CLK_PRI_H
#define PER_CLK_PRI_H
#include "STD_TYPES.h"

#define SYS_CTRL_BASE_ADD		0x400FE000

#define RCGCTIMER 					(*((volatile uint32*)(SYS_CTRL_BASE_ADD+0x604)))
#define RCGCGPIO						(*((volatile uint32*)(SYS_CTRL_BASE_ADD+0x608)))
#define RCGCDMA						  (*((volatile uint32*)(SYS_CTRL_BASE_ADD+0x60C)))
#define RCGCUART						(*((volatile uint32*)(SYS_CTRL_BASE_ADD+0x618)))
                                                                          
#define PRTIMER							(*((volatile uint32*)(SYS_CTRL_BASE_ADD+0xA04)))
#define PRGPIO							(*((volatile uint32*)(SYS_CTRL_BASE_ADD+0xA08)))
#define	PRDMA								(*((volatile uint32*)(SYS_CTRL_BASE_ADD+0xA0C)))
#define PRUART							(*((volatile uint32*)(SYS_CTRL_BASE_ADD+0xA18)))

typedef enum{
	GPIO_CLK_A=0,
	GPIO_CLK_B,
	GPIO_CLK_C,
	GPIO_CLK_D,
	GPIO_CLK_E,
	GPIO_CLK_F
}GPIO_CLK_SEL_t;






#endif

