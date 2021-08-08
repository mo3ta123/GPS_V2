#ifndef UART_PRI_H
#define UART_PRI_H
#include "STD_TYPES.h"

#define UART0_BASE_ADD ((UART_Struct_t*)0x4000C000)
#define UART1_BASE_ADD ((UART_Struct_t*)0x4000D000)
#define UART2_BASE_ADD ((UART_Struct_t*)0x4000E000)
#define UART3_BASE_ADD ((UART_Struct_t*)0x4000F000)
#define UART4_BASE_ADD ((UART_Struct_t*)0x40010000)
#define UART5_BASE_ADD ((UART_Struct_t*)0x40011000)
#define UART6_BASE_ADD ((UART_Struct_t*)0x40012000)
#define UART7_BASE_ADD ((UART_Struct_t*)0x40013000)

typedef struct{
	uint32 UARTDR;								//0x000
	uint32 UARTRSR_UARTECR;				//0x004
	uint32 reserved[4];						//0x008 ----> 0x014
	uint32 UARTFR;								//0x018
	uint32 resetved1;							//0x01C	
	uint32 UARTILPR;							//0x020
	uint32 UARTIBRD;							//0x024
	uint32 UARTFBRD;							//0x028
	uint32 UARTLCRH;							//0x02C
	uint32 UARTCTL;								//0x030
	uint32 UARTIFLS;							//0x034
	uint32 UARTIM;								//0x038
	uint32 UARTRIS;								//0x03C
	uint32 UARTMIS;								//0x040
	uint32 UARTICR;								//0x044
	uint32 UARTDMACTL;						//0x048
}UART_Struct_t;

typedef enum{
	UART_0=0,
	UART_1,
	UART_2,
	UART_3,
	UART_4,
	UART_5,
	UART_6,
	UART_7
}UART_SEL_t;

typedef enum{
	Tx_only=0,
	Rx_only,
	Tx_Rx
}UART_MODE_t;
#endif
