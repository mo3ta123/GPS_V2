#ifndef LCD_H
#define LCD_H

#include "SYS_TICK.h"
#include "GPIO.h"
/*
PB0 -------------------->D0
PB1	-------------------->D1
PB2 -------------------->D2
PB3 -------------------->D3
PB4 -------------------->D4
PB5 -------------------->D5
PB6 -------------------->D6
PB7 -------------------->D7
   

GND -------------------->RW
PC6 -------------------->RS
PC7 -------------------->E
*/

/////LCD Instructions

#define LCD_Ins_ClearDisplay				0x01				//clear all display data
#define LCD_Ins_ReturnHome					0x02				//cursor return home 
#define LCD_Ins_EntryMode						0x06				//bits [2,1,0]--->[1,	(1->left inc,0->right inc)	,(1->shift of display ,0->no shift)]
#define LCD_Ins_DisplayOn						0x0F				//bits [3,2,1,0]->[1,	(1->Dis on,0->Dis off)	,(cursor)	,(Blink cursor)]
#define LCD_Ins_DisplayOff					0x08
#define LCD_Ins_FunctionSet					0x3C
#define LCD_Ins_NewLine							0xC0

void vLCD_Char(uint8 ch);
void vLCD_Instruction(uint8 Ins);
void vLCD_INT(void);
void vLCD_String(char string []);

#endif
