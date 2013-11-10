/*
 * usage.c
 *
 * Created: 9-11-2013 14:10:25
 *  Author: P
 */ 


#include <sam4s.h>
#include <PinNames.h>
#include <Display/display.h>
#include <Delay/delay.h>
#include <Graphical/graphical.h>


#define MOVEMENTSPEED 10


/**
 * \brief Application entry point.
 *
 * \return Unused (ANSI-C compatibility).
 */
int main(void)
{	
	struct RGBcolour* colourLookup[7] = {RED, GREEN, BLUE, CYAN, MAGNETA, YELLOW, WHITE};
	uint8_t centerX = 10;
	uint8_t centerY = 10;
	int8_t slopeY = 2;
	int8_t slopeX = 2;
	uint8_t colourIndex = 0;
    /* Initialize the SAM system */
	SystemInit();
	WDT->WDT_MR = WDT_MR_WDDIS; //disable watchdog
 	pinDefinitions();
// 	dac_Init();
// 	dac_Enable_Channel(0);
// 	timebase_Init_Timer();
// 	dac_Set_Slewrate(0b11,0);
// 	dac_Enable_Interupt(DACC_IMR_TXRDY,3);
// 	debug_led_configure(BARGRAPH,50,16);
 	display_init();	 
	graphical_init(BLACK);
	display_screenRefresh();
	
	delay_ms(20);
    while(1){
		
		for(int j = 0; j < 1; j++){
			for(int i = 150; i >= 10; i-= 10){
				graphical_drawLine(centerX,centerY,i,10,colourLookup[(colourIndex)%7]);
			}
			for(int i = 10; i <= 118; i+= 10){
				graphical_drawLine(centerX,centerY,10,i,colourLookup[(colourIndex+1)%7]);
			}
			for(int i = 10; i <= 150; i+= 10){
				graphical_drawLine(centerX,centerY,i,118,colourLookup[(colourIndex+2)%7]);
			}
			for(int i = 118; i >= 10; i-= 10){
				graphical_drawLine(centerX,centerY,150,i,colourLookup[(colourIndex+3)%7]);
			}
			display_screenRefresh();
		}
		delay_ms(MOVEMENTSPEED);
		graphical_init(BLACK);
		centerX += slopeX;
		if(centerX < 10 || centerX > WIDTH-10){
			slopeX = -slopeX;
			colourIndex++;			
		}
		centerY += slopeY;
		if(centerY < 10 || centerY > HEIGHT-10){
			slopeY = -slopeY;
			colourIndex++;
		}
    }
}