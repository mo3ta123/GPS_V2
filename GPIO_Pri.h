#ifndef GPIO_PRI_H
#define GPIO_PRI_H
#include "STD_TYPES.h"
//base addresses
#define GPIO_PORT_A_BASE_ADD  ((GPIO_struct_t*)0x40004000)
#define GPIO_PORT_B_BASE_ADD	((GPIO_struct_t*)0x40005000)
#define GPIO_PORT_C_BASE_ADD	((GPIO_struct_t*)0x40006000)
#define GPIO_PORT_D_BASE_ADD	((GPIO_struct_t*)0x40007000)
#define GPIO_PORT_E_BASE_ADD	((GPIO_struct_t*)0x40024000)
#define GPIO_PORT_F_BASE_ADD	((GPIO_struct_t*)0x40025000)

//
#define GPIO_UNLOCK_KEY 0x4C4F434B    


//to get arraysize discarded: n2-n1/4 +1
typedef struct{	
	uint32 reserved1[255];															//0x000 ->3F8
	volatile uint32 GPIODATA;														//0x3FC
	volatile uint32 GPIODIR;														//0x400
	volatile uint32 GPIOIS;															//0x404
	volatile uint32 GPIOIBE;														//0x408
	volatile uint32 GPIOIEV;														//0x40C
	volatile uint32 GPIOIM;															//0x410
	volatile uint32 GPIORIS;														//0x414
	volatile uint32 GPIOMIS;														//0x418
	volatile uint32 GPIOICR;														//0x41C
	volatile uint32 GPIOAFSEL;													//0x420
	uint32 notused[58];																	//0x424->0x508
	volatile uint32 GPIOODR;														//0x50C
	volatile uint32 GPIOPUR;														//0x510
	volatile uint32 GPIOPDR;														//0x514
	volatile uint32 GPIOSLR;														//0x518
	volatile uint32 GPIODEN;														//0x51C
	volatile uint32 GPIOLOCK;														//0x520
	volatile uint32 GPIOCR;															//0x524
	volatile uint32 GPIOAMSEL;													//0x528
	volatile uint32 GPIOPCTL;														//0x52C
}GPIO_struct_t;												

typedef enum{
	GPIO_A=0,
	GPIO_B,
	GPIO_C,
	GPIO_D,
	GPIO_E,
	GPIO_F
}GPIO_SEL_t;	

typedef enum{
	INPUT=0,
	OUTPUT
}GPIO_DIR_t;

typedef enum{
	edge_sen=0,
	level_sen
}Interrupt_Sense_t;

typedef enum{
	One_Edge_sen=0,
	Both_Edge_sen
}Interrupt_Both_Edge_t;

typedef enum{
	Falling_Edge=0,
	Rising_Edge
}Interrupt_Event_Sel_t;

typedef enum{
	Analog=0,
	Digital
}AnalogorDigital_Sel_t;

typedef enum{
	Normal_GPIO=0,
	Alternate_Fun
}AFSEL_Sel_t;

typedef enum{
	PULL_UP_R=0,
	PULL_DOWN_R,
	NON_UP_DOWN_R
}Input_mode_t;

typedef enum{
	Open_Drain=0,
	PULL_PUSH
}Output_mode_t;
#endif
