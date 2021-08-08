#ifndef GPIO_H
#define GPIO_H
#include "GPIO_Pri.h"
#define GPIO_A_PINS	0xFC			//from pin 2 to 7 (0,1)are discarded used in code upload
#define GPIO_B_PINS 0xFF			//from pin 0 to 7
#define GPIO_C_PINS 0xF0			//from pin 4 to 7  (0 to 3)jtag
#define GPIO_D_PINS 0xFF			//from pin 0 to 7
#define GPIO_E_PINS 0x3F			//from pin 0 to 5
#define GPIO_F_PINS 0x1F			//from pin 0 to 4
//note to self pin PB6 --connected->PD0 
//						 pin PB7 --connected->PD1

//selection
GPIO_struct_t* GPIO_SELECT_BASE_ADD(GPIO_SEL_t);
uint8 GPIO_PINS(GPIO_SEL_t);
/////////////////////////////////////////////////////
//data write
void vGPIO_DATA_WRITE_ALL(GPIO_SEL_t num,uint8 data);
void vGPIO_DATA_WRITE_SET_ALL(GPIO_SEL_t num,uint8 data);
void vGPIO_DATA_WRITE_RESET_ALL(GPIO_SEL_t num,uint8 data);
//data read
uint8 u8GPIO_DATA_READ_ALL(GPIO_SEL_t num);
uint8 u8GPIO_DATA_READ_PIN(GPIO_SEL_t num,uint8 pin);
//////////////////////////////////////////////////////
//gpio dir
void vGPIO_DIR_WRITE_ALL(GPIO_SEL_t num,uint8 data);
void vGPIO_DIR_WRITE_PIN(GPIO_SEL_t num,uint8 pin_num ,GPIO_DIR_t mode);

uint8 u8GPIO_DIR_READ_ALL(GPIO_SEL_t num);
uint8 u8GPIO_DIR_READ_PIN(GPIO_SEL_t num,uint8 pin_num);

///////////////////////////////interrupt/////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
//gpio IS ------------------->interput sense(edge or level)
void vGPIO_IS_WRITE_PIN(GPIO_SEL_t num,Interrupt_Sense_t sense,uint8 pin_num);
//////////////////////////////////////////////////////////
//GPIO IBE ------------------------>interrept both edges
void vGPIO_IBE_WRITE_PIN(GPIO_SEL_t num,Interrupt_Both_Edge_t edge,uint8 pin_num);
//GPIO IEV
void vGPIO_IEV_WRITE_PIN(GPIO_SEL_t num,Interrupt_Event_Sel_t edge,uint8 pin_num);
//GPIO inturrpt enable
void vGPIO_Interrupt_ENABLE_PIN(GPIO_SEL_t num,uint8 pin_num);
void vGPIO_Interrupt_DISABLE_PIN(GPIO_SEL_t num,uint8 pin_num);
//GPIO inturrpt clear
void vGPIO_Interrupt_CLEAR_PIN(GPIO_SEL_t num,uint8 pin_num);
///////////////////////////////////////////////////////////////////////////////////////

//GPIO UNLOCK
void vGPIO_UNLOCK(GPIO_SEL_t num);
// comit change for AFSEL,PUR,PDR,DEN
void vGPIO_Commit_Change(GPIO_SEL_t num,uint8 pin_num);
void vGPIO_Commit_Change_ALL(GPIO_SEL_t num);
//pctl control
void vGPIO_PCTL_CONTROL(GPIO_SEL_t num,uint8 config,uint8 pin_num);

//digital/analog / alternative 
void vGPIO_MODE_SETTING_PIN(GPIO_SEL_t num,AnalogorDigital_Sel_t A_D,AFSEL_Sel_t atl,uint8 pin_num);
////////////////////////////////////////////////////////////////////////////////////
/*
input:
open drain :has no effect
pull up: default input is high 
pull down :default input is low
if pull up is enabled pull down is disabled automaticaly and viceversa
output:
open drain: 0----> is 0
						1----> is floating
*/
//selecting mode for input
void vGPIO_INPUT_MODE_PIN(GPIO_SEL_t num,Input_mode_t mod,uint8 pin_num);
//selecting mode for output
void vGPIO_OUTPUT_MODE_PIN(GPIO_SEL_t num,Output_mode_t mod,uint8 pin_num);
#endif
