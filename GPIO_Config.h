#ifndef GPIO_CONFIG_H
#define GPIO_CONFIG_H

#include "GPIO.h"
#include "PER_CLK.h"
//
//color in led port f
#define			COLOR_RED 		0x02
#define			COLOR_BLUE 		0x04
#define			COLOR_GREEN		0x08
#define			COLOR_PURPLE	0x06
#define			COLOR_YELLOW	0x0A
#define			COLOR_WHITE		0x0E
#define			COLOR_AQUA		0x0C
#define			COLOR_OFF			0x00
//switches
#define 		SW1						4
#define			SW2						0

/////////////////////portf//////////////////////////////
// portf led control
void vGPIO_LED_INT(void);
void vGPIO_LED_COLOR_OUT(uint8 color);
// switches control portf
void vGPIO_SWITCH_INT(void);
uint8 u8GPIO_SWITCH_Input(uint8 sw);

/////////////////////LCD ---->GPIO B(0-->7),C(5,6,7)
void vGPIO_LCD_INT(void);

//////////////////KEYPAD-----> GPIO A(4-->7),GPIO D(4-->7)
void vGPIO_KeyPad_INT(void);

#endif
