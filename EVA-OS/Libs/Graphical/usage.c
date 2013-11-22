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
#define COLOURAMOUNT 8


/**
 * \brief Application entry point.
 *
 * \return Unused (ANSI-C compatibility).
 */
int grapical_main(void)
{	
	struct RGBcolour* colourLookup[] = {RED, GREEN, BLUE, CYAN, MAGNETA, YELLOW, WHITE, graphical_createRGBColour(104,13,200)};
	uint8_t centerX = 14;
	uint8_t centerY = 22;
	int8_t slopeY = 2;
	int8_t slopeX = 1;
	uint8_t colourIndex[4] = {0,1,2,3};
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
				graphical_drawLine(centerX,centerY,i,10,colourLookup[colourIndex[0]]);
			}
			for(int i = 10; i <= 118; i+= 10){
				graphical_drawLine(centerX,centerY,10,i,colourLookup[colourIndex[1]]);
			}
			for(int i = 10; i <= 150; i+= 10){
				graphical_drawLine(centerX,centerY,i,118,colourLookup[colourIndex[2]]);
			}
			for(int i = 118; i >= 10; i-= 10){
				graphical_drawLine(centerX,centerY,150,i,colourLookup[colourIndex[3]]);
			}
			display_screenRefresh();
		}
		//delay_ms(MOVEMENTSPEED);
		graphical_init(BLACK);
		centerX += slopeX;
		if(centerX < 10){
			slopeX = -slopeX;
			colourIndex[1]++;
			colourIndex[1] = colourIndex[1] % COLOURAMOUNT;
			while(colourIndex[1] == colourIndex[0]||colourIndex[1] == colourIndex[2]||colourIndex[1] == colourIndex[3]){
				colourIndex[1]++;
				colourIndex[1] = colourIndex[1] % COLOURAMOUNT;
			}		
		}
		if(centerX > WIDTH-10){
			slopeX = -slopeX;
			colourIndex[3]++;
			colourIndex[3] = colourIndex[3] % COLOURAMOUNT;
			while(colourIndex[3] == colourIndex[1]||colourIndex[3] == colourIndex[2]||colourIndex[3] == colourIndex[0]){
				colourIndex[3]++;
				colourIndex[3] = colourIndex[3] % COLOURAMOUNT;
			}
		}
		centerY += slopeY;
		if(centerY < 10){
			slopeY = -slopeY;
			colourIndex[0]++;
			colourIndex[0] = colourIndex[0] %7;
			while(colourIndex[0] == colourIndex[1]||colourIndex[0] == colourIndex[2]||colourIndex[0] == colourIndex[3]){
				colourIndex[0]++;
				colourIndex[0] = colourIndex[0] %7;
			}
		}
		if(centerY > HEIGHT-10){
			slopeY = -slopeY;
			colourIndex[2]++;
			colourIndex[2] = colourIndex[2] % COLOURAMOUNT;
			while(colourIndex[2] == colourIndex[1]||colourIndex[2] == colourIndex[0]||colourIndex[2] == colourIndex[3]){
				colourIndex[2]++;
				colourIndex[2] = colourIndex[2] % COLOURAMOUNT;
			}
		}
    }
}