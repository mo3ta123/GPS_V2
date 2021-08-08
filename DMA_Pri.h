#ifndef DMA_PRI_H
#define DMA_PRI_H
#include "STD_TYPES.h"

#define DMA_BASE_ADD		0x400FF000

#define DMASTAT                (*((volatile uint32*)(DMA_BASE_ADD+0x000)))
#define DMACFG                 (*((volatile uint32*)(DMA_BASE_ADD+0x004)))
#define DMACTLBASE             (*((volatile uint32*)(DMA_BASE_ADD+0x008)))
#define DMAALTBASE             (*((volatile uint32*)(DMA_BASE_ADD+0x00C)))
#define DMAWAITSTAT            (*((volatile uint32*)(DMA_BASE_ADD+0x010)))
#define DMASWREQ               (*((volatile uint32*)(DMA_BASE_ADD+0x014)))
#define DMAUSEBURSTSET         (*((volatile uint32*)(DMA_BASE_ADD+0x018)))
#define DMAUSEBURSTCLR         (*((volatile uint32*)(DMA_BASE_ADD+0x01C)))
#define DMAREQMASKSET          (*((volatile uint32*)(DMA_BASE_ADD+0x020)))
#define DMAREQMASKCLR          (*((volatile uint32*)(DMA_BASE_ADD+0x024)))
#define DMAENASET              (*((volatile uint32*)(DMA_BASE_ADD+0x028)))
#define DMAENACLR              (*((volatile uint32*)(DMA_BASE_ADD+0x02C)))
#define DMAALTSET              (*((volatile uint32*)(DMA_BASE_ADD+0x030)))
#define DMAALTCLR              (*((volatile uint32*)(DMA_BASE_ADD+0x034)))
#define DMAPRIOSET             (*((volatile uint32*)(DMA_BASE_ADD+0x038)))
#define DMAPRIOCLR             (*((volatile uint32*)(DMA_BASE_ADD+0x03C)))
#define DMAERRCLR              (*((volatile uint32*)(DMA_BASE_ADD+0x04C)))
#define DMACHASGN              (*((volatile uint32*)(DMA_BASE_ADD+0x500)))
#define DMACHIS                (*((volatile uint32*)(DMA_BASE_ADD+0x504)))
#define DMACHMAP0              (*((volatile uint32*)(DMA_BASE_ADD+0x510)))
#define DMACHMAP1              (*((volatile uint32*)(DMA_BASE_ADD+0x514)))
#define DMACHMAP2              (*((volatile uint32*)(DMA_BASE_ADD+0x518)))
#define DMACHMAP3              (*((volatile uint32*)(DMA_BASE_ADD+0x51C)))

/////////////////////////////////////////////////////////////////////////////////
//inc in dma
#define Byte							0x0
#define Half_word					0x1
#define Word							0x2
#define No_increment			0x3
////////////////////////////////////////////////////////////////////////////////
// dma transfer modse
#define  Basic_Transfer_mode		0x1
#define  Auto_Request 					0x2
////////////////////////////////////////////////////////////////////////////////
typedef struct{
	volatile uint32 DMASRC;														//0x00
	volatile uint32 DMADST;														//0x04
	volatile uint32 DMACHCTL;													//0x08
	uint32 reserved;																	//0x0C
}Channel_Struct_t;


typedef enum{
	DMA_Defualt=0,
	DMA_High_pri
}DMA_Priority_t;

typedef enum{
	DMA_primary=0,
	DMA_alternate
}DMA_Primary_sel_t;

typedef enum{
	DMA_Brust_only,
	DMA_Brust_Single
}Brust_Single_mode_t;


#endif
