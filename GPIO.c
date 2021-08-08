#include "GPIO.h"

GPIO_struct_t* GPIO_SELECT_BASE_ADD(GPIO_SEL_t num){
	GPIO_struct_t* ptr;
	switch (num){
		case GPIO_A:
			ptr=GPIO_PORT_A_BASE_ADD;
			break;
		case GPIO_B:
			ptr=GPIO_PORT_B_BASE_ADD;
			break;
		case GPIO_C:
			ptr=GPIO_PORT_C_BASE_ADD;
			break;
		case GPIO_D:
			ptr=GPIO_PORT_D_BASE_ADD;
			break;
		case GPIO_E:
			ptr=GPIO_PORT_E_BASE_ADD;
			break;
		case GPIO_F:
			ptr=GPIO_PORT_F_BASE_ADD;
			break;
		
	}
	return ptr;
}

uint8 GPIO_PINS(GPIO_SEL_t num){
	uint8 sel;
	switch(num){
		case GPIO_A:
			sel=GPIO_A_PINS;
			break;
		case GPIO_B:
			sel=GPIO_B_PINS;
			break;
		case GPIO_C:
			sel=GPIO_C_PINS;
			break;
		case GPIO_D:
			sel=GPIO_D_PINS;
			break;
		case GPIO_E:
			sel=GPIO_E_PINS;
			break;
		case GPIO_F:
			sel=GPIO_F_PINS;
			break;
	}
	return sel;
}

// for gpio data 
void vGPIO_DATA_WRITE_ALL(GPIO_SEL_t num,uint8 data){
	GPIO_struct_t* ptr;
	uint8 pins;
	ptr=GPIO_SELECT_BASE_ADD(num);
	pins=GPIO_PINS(num);
	
	ptr->GPIODATA |=(pins&data);
	ptr->GPIODATA &=~(pins&(~data));
}

void vGPIO_DATA_WRITE_SET_ALL(GPIO_SEL_t num,uint8 data){
	GPIO_struct_t* ptr;
	uint8 pins;
	ptr=GPIO_SELECT_BASE_ADD(num);
	pins=GPIO_PINS(num);
	
	ptr->GPIODATA |=(pins&data);
}

void vGPIO_DATA_WRITE_RESET_ALL(GPIO_SEL_t num,uint8 data){
	GPIO_struct_t* ptr;
	uint8 pins;
	ptr=GPIO_SELECT_BASE_ADD(num);
	pins=GPIO_PINS(num);
	
	ptr->GPIODATA &=~(pins&data);
}

uint8 u8GPIO_DATA_READ_ALL(GPIO_SEL_t num){
	GPIO_struct_t* ptr;
	uint8 pins;
	ptr=GPIO_SELECT_BASE_ADD(num);
	pins=GPIO_PINS(num);
	
	return ((ptr->GPIODATA)&pins);
}
uint8 u8GPIO_DATA_READ_PIN(GPIO_SEL_t num,uint8 pin){
	GPIO_struct_t* ptr;
	ptr=GPIO_SELECT_BASE_ADD(num);
	
	return (checkBit(ptr->GPIODATA,pin));
}
//gpio direction
void vGPIO_DIR_WRITE_ALL(GPIO_SEL_t num,uint8 data){
	GPIO_struct_t* ptr;
	uint8 pins;
	ptr=GPIO_SELECT_BASE_ADD(num);
	pins=GPIO_PINS(num);
	
	ptr->GPIODIR |=(data&pins);
	ptr->GPIODIR &=~(pins&(~data));
}
void vGPIO_DIR_WRITE_PIN(GPIO_SEL_t num,uint8 pin_num ,GPIO_DIR_t mode){
	GPIO_struct_t* ptr;
	ptr=GPIO_SELECT_BASE_ADD(num);
	
	switch(mode){
		case INPUT:
			resetBit(ptr->GPIODIR,pin_num);
		break;
		case OUTPUT:
			setBit(ptr->GPIODIR,pin_num);
		break;
	}
}

uint8 u8GPIO_DIR_READ_ALL(GPIO_SEL_t num){
	GPIO_struct_t* ptr;
	uint8 pins;
	ptr=GPIO_SELECT_BASE_ADD(num);
	pins=GPIO_PINS(num);
	
	return ((ptr->GPIODIR)&pins);
}
uint8 u8GPIO_DIR_READ_PIN(GPIO_SEL_t num,uint8 pin_num){
	GPIO_struct_t* ptr;
	ptr=GPIO_SELECT_BASE_ADD(num);
	
	return (checkBit(ptr->GPIODIR,pin_num));
}
///////////////////////////////interrupt/////////////////////////////////////////////////////////////
//IS/////////////////////////////////////////////////////////////////
void vGPIO_IS_WRITE_PIN(GPIO_SEL_t num,Interrupt_Sense_t sense,uint8 pin_num){
	GPIO_struct_t* ptr;
	ptr=GPIO_SELECT_BASE_ADD(num);
	
	switch(sense){
		case edge_sen:
			resetBit(ptr->GPIOIS,pin_num);
		break;
		case level_sen:
			setBit(ptr->GPIOIS,pin_num);
			break;
	}
}
//IBE////////////////////////////////////////////////////////////////
void vGPIO_IBE_WRITE_PIN(GPIO_SEL_t num,Interrupt_Both_Edge_t edge,uint8 pin_num){
	GPIO_struct_t* ptr;
	ptr=GPIO_SELECT_BASE_ADD(num);
	
	switch(edge){
		case One_Edge_sen:
			resetBit(ptr->GPIOIBE,pin_num);
			break;
		case Both_Edge_sen:
			setBit(ptr->GPIOIBE,pin_num);
			break;
	}
}
//IVE////////////////////////////////////////////////////////////
void vGPIO_IEV_WRITE_PIN(GPIO_SEL_t num,Interrupt_Event_Sel_t edge,uint8 pin_num){
	GPIO_struct_t* ptr;
	ptr=GPIO_SELECT_BASE_ADD(num);
	
	switch(edge){
		case Falling_Edge:
			resetBit(ptr->GPIOIEV,pin_num);
			break;
		case Rising_Edge:
			setBit(ptr->GPIOIEV,pin_num);
			break;
	}
	
}

// interrupt masking
void vGPIO_Interrupt_ENABLE_PIN(GPIO_SEL_t num,uint8 pin_num){
	GPIO_struct_t* ptr;
	ptr=GPIO_SELECT_BASE_ADD(num);
	
	setBit(ptr->GPIOIM,pin_num);
}
void vGPIO_Interrupt_DISABLE_PIN(GPIO_SEL_t num,uint8 pin_num){
	GPIO_struct_t* ptr;
	ptr=GPIO_SELECT_BASE_ADD(num);
	
	setBit(ptr->GPIOIM,pin_num);
}

//inturrupt clearing

void vGPIO_Interrupt_CLEAR_PIN(GPIO_SEL_t num,uint8 pin_num){
	GPIO_struct_t* ptr;
	ptr=GPIO_SELECT_BASE_ADD(num);
	
	setBit(ptr->GPIOICR,pin_num);
}

//unlocking gpio
void vGPIO_UNLOCK(GPIO_SEL_t num){
	GPIO_struct_t* ptr;
	ptr=GPIO_SELECT_BASE_ADD(num);
	
	ptr->GPIOLOCK=GPIO_UNLOCK_KEY;
}

//commit change
void vGPIO_Commit_Change(GPIO_SEL_t num,uint8 pin_num){
	GPIO_struct_t* ptr;
	ptr=GPIO_SELECT_BASE_ADD(num);
	
	setBit(ptr->GPIOCR,pin_num);
	
}

void vGPIO_Commit_Change_ALL(GPIO_SEL_t num){
	GPIO_struct_t* ptr;
	uint8 pins;
	ptr=GPIO_SELECT_BASE_ADD(num);
	pins=GPIO_PINS(num);
	
	ptr->GPIOCR |=(pins);
}

//PCTL control alt
void vGPIO_PCTL_CONTROL(GPIO_SEL_t num,uint8 config,uint8 pin_num){
	GPIO_struct_t* ptr;
	ptr=GPIO_SELECT_BASE_ADD(num);
	
	ptr->GPIOPCTL=(ptr->GPIOPCTL&(~(0xF<<(pin_num*4))))|(config<<(pin_num*4));
}

void vGPIO_MODE_SETTING_PIN(GPIO_SEL_t num,AnalogorDigital_Sel_t A_D,AFSEL_Sel_t alt,uint8 pin_num){
	GPIO_struct_t* ptr;
	ptr=GPIO_SELECT_BASE_ADD(num);
	
	switch(A_D){
		case Analog:
			setBit(ptr->GPIOAMSEL,pin_num);
			resetBit(ptr->GPIODEN,pin_num);
			break;
		case Digital:
			setBit(ptr->GPIODEN,pin_num);
			resetBit(ptr->GPIOAMSEL,pin_num);
			break;
	}
	
	switch(alt){
		case Normal_GPIO:
			resetBit(ptr->GPIOAFSEL,pin_num);
			break;
		case Alternate_Fun:
			setBit(ptr->GPIOAFSEL,pin_num);
			break;
	}
}	

void vGPIO_INPUT_MODE_PIN(GPIO_SEL_t num,Input_mode_t mod,uint8 pin_num){
	GPIO_struct_t* ptr;
	ptr=GPIO_SELECT_BASE_ADD(num);
	
	switch(mod){
		case PULL_UP_R:
			setBit(ptr->GPIOPUR,pin_num); //pull down is automatically disabled
			break;
		case PULL_DOWN_R:
			setBit(ptr->GPIOPDR,pin_num); //pull up is automatically disable
			break;
		case NON_UP_DOWN_R:
			resetBit(ptr->GPIOPUR,pin_num);
			resetBit(ptr->GPIOPDR,pin_num);
		break;
	}
}

void vGPIO_OUTPUT_MODE_PIN(GPIO_SEL_t num,Output_mode_t mod,uint8 pin_num){
	GPIO_struct_t* ptr;
	ptr=GPIO_SELECT_BASE_ADD(num);
	
	switch(mod){
		case Open_Drain:
			setBit(ptr->GPIOODR,pin_num);
			break;
		case PULL_PUSH:
			resetBit(ptr->GPIOODR,pin_num);
		break;
	}
}
