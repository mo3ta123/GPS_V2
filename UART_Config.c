#include "UART_Config.h"

void vUART_7_INT(void){
	vActive_CLK_GPIO(GPIO_CLK_E);
	vActive_CLK_UART(UART_7);
	
	//setting up GPIO_E for uart	pins-->0 only is needed for recieve in uart 7
	vGPIO_UNLOCK(GPIO_E);
	vGPIO_Commit_Change_ALL(GPIO_E);
	vGPIO_MODE_SETTING_PIN(GPIO_E,Digital,Alternate_Fun,0);
	vGPIO_PCTL_CONTROL(GPIO_E,0x01,0);
	

	
	//setting up uart 7
	vUART_DISABLE(UART_7);
	vUART_DATA_WLEN(UART_7,8);
	vUART_BAUD_RATE_SETUP(UART_7,9600);
	vUART_FIFO_ENABLE(UART_7);
	vUART_MODE_SETUP(UART_7,Rx_only);
	vUART_ENABLE(UART_7);
	
}

uint8 u8UART_7_DATA_RECIEVE(void){
	return u8UART_READ_DATA(UART_7);
}
