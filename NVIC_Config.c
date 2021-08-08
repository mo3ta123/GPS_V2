#include "NVIC_Config.h"

#define PORTF_Interrupt_num  30
void vNVIC_PORTF_SETUP(void){
	vNVIC_ENABLE(PORTF_Interrupt_num);
	vNVIC_SET_PRI(PORTF_Interrupt_num,5);
	
	vGPIO_Interrupt_CLEAR_PIN(GPIO_F,0);
	vGPIO_Interrupt_CLEAR_PIN(GPIO_F,4);
	
	vGPIO_Interrupt_ENABLE_PIN(GPIO_F,0);
	vGPIO_Interrupt_ENABLE_PIN(GPIO_F,4);
	
	vGPIO_IS_WRITE_PIN(GPIO_F,edge_sen,0);
	vGPIO_IS_WRITE_PIN(GPIO_F,edge_sen,4);
	
	vGPIO_IBE_WRITE_PIN(GPIO_F,One_Edge_sen,0);
	vGPIO_IBE_WRITE_PIN(GPIO_F,One_Edge_sen,4);
	
	vGPIO_IEV_WRITE_PIN(GPIO_F,Falling_Edge,0);
	vGPIO_IEV_WRITE_PIN(GPIO_F,Falling_Edge,4);

	
}
