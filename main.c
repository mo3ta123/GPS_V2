#include <ctype.h>
#include "tm4c123.h"
#include "Distance.h"
#include "GPIO_Config.h"
#include "SYS_TICK.h"
#include "UART_Config.h"
#include "DMA_Config.h"
#include "LCD.h"
#include "GPS_Rx.h"
#include "NVIC_Config.h"
#include "KEY_PAD.h"

#define SIZE_BUFFER 	500

//program phases
#define GetData_Phase			0
#define Display_Phase			1
#define CalDis_Phase			2
#define Processing_Phase	3
#define CheckFinish_Phase 4

//display options
#define Display_Distance	0
#define Display_Time			1
#define Display_Status		2
#define Display_Timer			3


void SystemInit(){
	SCB->CPACR |=((3UL<<10*2)|(3UL<<11*2));
	
	vGPIO_LED_INT();
	vGPIO_SWITCH_INT();
	vTIMER_CLK_SRC_SETUP();
	vUART_7_INT();
	vDMA_UART7_Rx_SETUP();
	vGPIO_LCD_INT();
	vLCD_INT();
	vNVIC_PORTF_SETUP();
	vGPIO_KeyPad_INT();
}  


static	uint8 Display=Display_Status;
static 	uint8 FirstConnect_Flag=0;

int main(void){
	////////////////   variable used    /////////////////
	char buffer[SIZE_BUFFER];
	char buff_out[33];
	GPGLL_Struct_t GPGLL;
	float dist=0;
	float lat_old,long_old;
	uint8 ini_H=0,ini_M=0,ini_S=0;
	float max_dist=0;char c_buff='0';
	
	uint8	ErrorRecieve_Flag=0;
	
	uint8 Next_Phase=GetData_Phase;
	////////////////////////////////////////
//getting input from keyPad for max distance 
	while(c_buff != Start){
		if(isdigit(c_buff)!=0){
			max_dist = (max_dist*10) + (c_buff - '0');
			if(max_dist <1000)
				sprintf(buff_out,"MaxDis: %.0f m",max_dist);
			else
				sprintf(buff_out,"MaxDis: %.3f Km",max_dist/1000);
			
			
			vLCD_String(buff_out);
		}
		c_buff =Read_Key();
	}
	
	//program
	while (1){
		
		/// GetData_Phase
		if(Next_Phase == GetData_Phase){
			vDMA_UART7_Rx_Begin(buffer,SIZE_BUFFER);
			Next_Phase = Display_Phase;
		}
		
		/// CheckFinish_Phase
		else if(Next_Phase == CheckFinish_Phase){
			if(u8DMA_UART7_Rx_isDone()==0)
				Next_Phase = Display_Phase;
			else 
				Next_Phase = Processing_Phase;
		}
		
		
		/// Processing_Phase
		else if(Next_Phase == Processing_Phase){
			if(GPS_Rx(buffer,&GPGLL,SIZE_BUFFER)){
			//sprintf(buffer,"lat:  %.4f\nlong: %.4f",GPGLL.lat,GPGLL.lon); //should remove
			//vLCD_String(buffer);
				if(ErrorRecieve_Flag == 1){
					vGPIO_LED_COLOR_OUT(COLOR_GREEN);
					ErrorRecieve_Flag =0;
				}
				
				if(FirstConnect_Flag == 0)
					vGPIO_LED_COLOR_OUT(COLOR_GREEN);
				
			Next_Phase = CalDis_Phase;
		}
		else{
			if(FirstConnect_Flag == 1)
				ErrorRecieve_Flag=1;
			
				vGPIO_LED_COLOR_OUT(COLOR_RED);
				Next_Phase = GetData_Phase;
			}
		}
		
		
		/// CalDis_Phase
		else if(Next_Phase == CalDis_Phase){
			if(FirstConnect_Flag == 0){
				ini_H=GPGLL.time_H;
				ini_M=GPGLL.time_M;
				ini_S=GPGLL.time_S;
				FirstConnect_Flag=1;
			}
			else
				dist += distance(lat_old,long_old,GPGLL.lat,GPGLL.lon);
			
			if(dist >=max_dist)
				vGPIO_LED_COLOR_OUT(COLOR_YELLOW);
			
			lat_old = GPGLL.lat;
			long_old = GPGLL.lon;
			Next_Phase = GetData_Phase;
		}
		
		
		/// Display_Phase
		else if(Next_Phase == Display_Phase){
			
						//display distance
						if(Display == Display_Distance){
							if(dist<1000)
								sprintf(buff_out,"Distance : %.1f m",dist);
							else
								sprintf(buff_out,"Distance : %.3f km",dist/1000);
							
							vLCD_String(buff_out);
						}
						
						//display time
						else if(Display == Display_Time){
							sprintf(buff_out,"Time : %02d:%02d:%02d",GPGLL.time_H,GPGLL.time_M,GPGLL.time_S);
							vLCD_String(buff_out);
						}
						
						//display status
						else if(Display == Display_Status){
							if(FirstConnect_Flag ==0)
								vLCD_String("  Can't Obtain\n    Position");
							else if(ErrorRecieve_Flag ==0)
								vLCD_String(" Program working");  
							else if(ErrorRecieve_Flag == 1)
								vLCD_String(" Receive Operation\n   Error");
						}
						
						
						//display timer
						else if(Display == Display_Timer){
							sprintf(buff_out,"Timer : %02d:%02d:%02d",(GPGLL.time_H-ini_H),(GPGLL.time_M-ini_M),(GPGLL.time_S-ini_S));
							vLCD_String(buff_out);
						}
			
						//display delay
						wait_ms(700);
						
						Next_Phase = CheckFinish_Phase;
		}
		
	}
	
}

void GPIOF_Handler(void){
	vGPIO_Interrupt_CLEAR_PIN(GPIO_F,0);
	vGPIO_Interrupt_CLEAR_PIN(GPIO_F,4);
	
	if(FirstConnect_Flag ==0)
		Display = Display_Status;
	else{
		if(u8GPIO_SWITCH_Input(SW1)==1){    //for distance and status
			if(Display == Display_Distance)Display = Display_Status;
			else Display = Display_Distance;
		}
		else if(u8GPIO_SWITCH_Input(SW2)==1){  //for time and timer
			if(Display == Display_Timer)Display = Display_Time;
			else Display = Display_Time;
		}
	}
	
}
