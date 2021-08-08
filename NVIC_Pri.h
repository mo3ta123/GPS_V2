#ifndef NVIC_PRI_H
#define NVIC_PRI_H

#define NVIC_BASE_ADDRESSE				0xE000E000

#define NVIC_SET_EN								((uint32*)(NVIC_BASE_ADDRESSE+0x100))		//0->4
#define NVIC_CLEAR_EN							((uint32*)(NVIC_BASE_ADDRESSE+0x180))		//0->4
#define NVIC_SetPend							((uint32*)(NVIC_BASE_ADDRESSE+0x200))		//0->4
#define NVIC_ClearPend						((uint32*)(NVIC_BASE_ADDRESSE+0x280))		//0->4
#define NVIC_ACTIVE								((uint32*)(NVIC_BASE_ADDRESSE+0x300))		//0->4
#define NVIC_PRI									((uint32*)(NVIC_BASE_ADDRESSE+0x400))		//0->64






#endif
