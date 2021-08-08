#ifndef KEY_PAD_H
#define KEY_PAD_H

#include "GPIO.h"


/*
output
PA4 ------->Row 1
PA5 ------->Row 2
PA6 ------->Row 3
PA7 ------->Row 4

input
PD2 ------->Col 1
PD3 ------->Col 2
PD6 ------->Col 3
PD7 ------->Col 4

*/

#define F1				'W'
#define F2				'X'
#define	F3				'Y'
#define F4				'Z'
#define Start			'S'
#define Stop			'T'


char Read_Key(void);


#endif
