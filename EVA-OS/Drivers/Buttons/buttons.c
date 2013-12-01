/*
* buttons.c
*
* Created: 11/16/2013 4:49:33 PM
*  Author: Elmar
*/

#include <Drivers/Buttons/buttons.h>
#include <Util/TinyPrintf/printf.h>

void button_init()
{
	PIOC->PIO_WPMR = 0x50494F;
	buttons[BUTTONS_LEFT] = &button_left;
	buttons[BUTTONS_LEFT]->pin = BUTTON_1_PIN;
	buttons[BUTTONS_RIGHT] = &button_right;
	buttons[BUTTONS_RIGHT]->pin = BUTTON_2_PIN;
	buttons[BUTTONS_UP] = &button_up;
	buttons[BUTTONS_UP]->pin = BUTTON_3_PIN;
	buttons[BUTTONS_DOWN] = &button_down;
	buttons[BUTTONS_DOWN]->pin = BUTTON_4_PIN;
	buttons[BUTTONS_SELECT] = &button_select;
	buttons[BUTTONS_SELECT]->pin = BUTTON_5_PIN;
	NVIC_EnableIRQ(PIOC_IRQn);
	uint8_t i = 0;
	for(i = 0; i<5; i++){
		buttons[i]->handled = 0;
		buttons[i]->pressed = 0;
		buttons[i]->runTime = 0;
		buttons[i]->startTime = 0;
		PIOC->PIO_PER    = (buttons[i]->pin);	// Enable PIO usage
		PIOC->PIO_PUDR   = (buttons[i]->pin);	// Disable pull up
		PIOC->PIO_PPDER  = (buttons[i]->pin) ;	// Enable pull down
		//PIOC->PIO_ODR  = (buttons[i]->pin) ;
		
		PIOC->PIO_IFER   = (buttons[i]->pin);	// Input filter
		PIOC->PIO_IER	 = (buttons[i]->pin);	// enable interrupt
		PIOC->PIO_ESR	 = (buttons[i]->pin);	// Edge detection
		PIOC->PIO_REHLSR = (buttons[i]->pin);	// Rising edge
		PIOC->PIO_FELLSR = (buttons[i]->pin);	// Falling edge
	}
}

void buttons_update()
{
	uint8_t i;
	for(i = 0; i<5; i++){
		if(buttons[i]->handled){
			buttons[i]->typed = 0;
		}
	}
}

uint8_t button_isTyped(uint8_t id)
{
	if(buttons[id]->typed)
		buttons[id]->handled = 1;
	return buttons[id]->typed;	
}

uint8_t button_isPressed(uint8_t id)
{
	return buttons[id]->pressed;
}

void PIOC_Handler()
{
	button_interrupt();
}


uint8_t button_interrupt()
{
	uint8_t i;
	uint32_t temp = PIOC->PIO_ISR;

	for(i = 0; i<5; i++){
		if (temp & (buttons[i]->pin)){
			if(PIOC->PIO_PDSR & buttons[i]->pin){
				button_up.runTime = 0;
				buttons[i]->pressed = 1;
				buttons[i]->typed = 1;
				//rising edge
			} else {
				//falling edge
				buttons[i]->pressed = 0;
				buttons[i]->typed = 0;
				buttons[i]->handled= 0;
				button_up.runTime = 0 - buttons[i]->startTime;
			}
		}
	}
	return 1;
}