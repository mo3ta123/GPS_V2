#include "UART.h"

UART_Struct_t* UART_SELECT_BASE_ADD(UART_SEL_t uart){
	UART_Struct_t* ptr;
	switch(uart){
		case UART_0:
			ptr=UART0_BASE_ADD;
			break;
		case UART_1:
			ptr=UART1_BASE_ADD;
			break;
		case UART_2:
			ptr=UART2_BASE_ADD;
			break;
		case UART_3:
			ptr=UART3_BASE_ADD;
			break;
		case UART_4:
			ptr=UART4_BASE_ADD;
			break;
		case UART_5:
			ptr=UART5_BASE_ADD;
			break;
		case UART_6:
			ptr=UART6_BASE_ADD;
			break;
		case UART_7:
			ptr=UART7_BASE_ADD;
			break;
	}
	return ptr;
}

////////////////////uart en/dis ////////////////////////////////////////
void vUART_ENABLE(UART_SEL_t num){
	UART_Struct_t* ptr;
	ptr=UART_SELECT_BASE_ADD(num);
	setBit(ptr->UARTCTL,0);
}

void vUART_DISABLE(UART_SEL_t num){
	UART_Struct_t* ptr;
	ptr=UART_SELECT_BASE_ADD(num);
	resetBit(ptr->UARTCTL,0);
}


/////////////////////////Baud rate////////////////////////////////////////
void vUART_BAUD_RATE_SETUP(UART_SEL_t num,uint32 BR){
	double Baud_Rate_Divisor,temp;
	uint32 Integer_Baud_Rate_Divisor,Fractional_Baud_Rate_Divisor;
	UART_Struct_t* ptr;
	ptr=UART_SELECT_BASE_ADD(num);
	
	Baud_Rate_Divisor=(1.0*CPU_CLK)/(BR*div);
	Integer_Baud_Rate_Divisor=(uint32)Baud_Rate_Divisor;
	
	temp=Baud_Rate_Divisor-Integer_Baud_Rate_Divisor;
	Fractional_Baud_Rate_Divisor=(uint32)(temp*64+0.5);
	
	ptr->UARTIBRD=Integer_Baud_Rate_Divisor;
	ptr->UARTFBRD=Fractional_Baud_Rate_Divisor;
}

/////////////////////////Uart Tx/Rx//////////////////////////////
void vUART_MODE_SETUP(UART_SEL_t num,UART_MODE_t mod){
	UART_Struct_t* ptr;
	ptr=UART_SELECT_BASE_ADD(num);
	
	switch(mod){
		case Tx_only:
			setBit(ptr->UARTCTL,8);
			resetBit(ptr->UARTCTL,9);
			break;
		case Rx_only:
			resetBit(ptr->UARTCTL,8);
			setBit(ptr->UARTCTL,9);
			break;
		case Tx_Rx:
			setBit(ptr->UARTCTL,8);
			setBit(ptr->UARTCTL,9);
			break;
	}
}

///////////////////////uart data////////////////////////////////
uint8 u8UART_READ_DATA(UART_SEL_t num){
	UART_Struct_t* ptr;
	ptr=UART_SELECT_BASE_ADD(num);
	if(u8UART_FIFO_EN_READ(num)==0){
		return ((uint8)((ptr->UARTDR)&0xFF));
	}
	else{
		while(u8UART_RX_FIFO_Empty(num)!=0);		//while fifo Rx is empty
		return ((uint8)((ptr->UARTDR)&0xFF));
	}
}
void vUART_WRITE_DATA(UART_SEL_t num,uint8 data){													
	UART_Struct_t* ptr;
	ptr=UART_SELECT_BASE_ADD(num);
	if(u8UART_FIFO_EN_READ(num)==0){
		 ptr->UARTDR	=data;
	}
	else{
		while(u8UART_TX_FIFO_FULL(num)!=0);		//while fifo Tx is FULL
		ptr->UARTDR	=data;
	}
	
}

//////////////UART setting/////////////////////////
void vUART_DATA_WLEN(UART_SEL_t num,uint8 len){
	UART_Struct_t* ptr;
	ptr=UART_SELECT_BASE_ADD(num);
		switch(len){
			case 5:
				len=0x00;
				break;
			case 6:
				len=0x01;
				break;
			case 7:
				len=0x02;
				break;
			case 8:
				len=0x03;
				break;
			default:
				len=0x03 ;	//defualt len is 8
				break;
		}
	ptr->UARTLCRH =((ptr->UARTLCRH)&(0x9F))|(len<<5);
}

void vUART_FIFO_ENABLE(UART_SEL_t num){
	UART_Struct_t* ptr;
	ptr=UART_SELECT_BASE_ADD(num);
	setBit(ptr->UARTLCRH,4);
}

void vUART_FIFO_DISABLE(UART_SEL_t num){
	UART_Struct_t* ptr;
	ptr=UART_SELECT_BASE_ADD(num);
	resetBit(ptr->UARTLCRH,4);
}

uint8 u8UART_FIFO_EN_READ(UART_SEL_t num){
	UART_Struct_t* ptr;
	ptr=UART_SELECT_BASE_ADD(num);
	return checkBit(ptr->UARTLCRH,4);
}

//////////////uart flags//////////////////////////////
uint8 u8UART_TX_FIFO_FULL(UART_SEL_t num){
	UART_Struct_t* ptr;
	ptr=UART_SELECT_BASE_ADD(num);
	
	return checkBit(ptr->UARTFR,5);
}
uint8 u8UART_RX_FIFO_Empty(UART_SEL_t num){
		UART_Struct_t* ptr;
	ptr=UART_SELECT_BASE_ADD(num);
	
	return checkBit(ptr->UARTFR,4);
}

//////////////////////DMA	Control /////////////////////////
void vUART_DMA_SETUP(UART_SEL_t num,UART_MODE_t dma,uint8 DMA_Error_disable_handle){
	UART_Struct_t* ptr;
	ptr=UART_SELECT_BASE_ADD(num);
	
	if(DMA_Error_disable_handle==0)resetBit(ptr->UARTDMACTL,2);
	else if(DMA_Error_disable_handle==1)setBit(ptr->UARTDMACTL,2);
	
	switch(dma){
		case Tx_only:
			setBit(ptr->UARTDMACTL,1);
			resetBit(ptr->UARTDMACTL,0);
			break;
		case Rx_only:
			resetBit(ptr->UARTDMACTL,1);
			setBit(ptr->UARTDMACTL,0);
			break;
		case Tx_Rx:
			setBit(ptr->UARTDMACTL,1);
			setBit(ptr->UARTDMACTL,0);
			break;
	}
	
}
void vUART_DMA_DISABLE(UART_SEL_t num){
	UART_Struct_t* ptr;
	ptr=UART_SELECT_BASE_ADD(num);
	
	resetBit(ptr->UARTDMACTL,1);
	resetBit(ptr->UARTDMACTL,0);
}
