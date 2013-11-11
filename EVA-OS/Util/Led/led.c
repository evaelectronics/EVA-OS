/*
 * led.c
 *
 * Created: 15-9-2013 15:59:50
 *  Author: Aran Dokoupil
 */ 

#include <sam4s.h>
#include <Led/led.h>
#include <Timebase/timebase.h>
#include <PinNames.h>

#define DEBUGLEDMASK 0xff000000

uint32_t currentRefreshrate = 0;
uint32_t lastRefreshTime = 0;
uint32_t barGraphScale = 4096;	

debugLedState currentLedState = MANUAL;

static inline uint32_t rev(uint32_t input);
static uint32_t calculateBar(uint32_t value);

static uint32_t calculateBar(uint32_t value)
{
	uint32_t barValue = 0;	
	for(uint32_t i = 1; i <= 8; i++){
		if(value > (barGraphScale/8)*i){
			barValue |= (1<<(i-1));
		}
	}
	return barValue;
}

void led_refresh(uint32_t value)
{
	if(currentRefreshrate == 0 || lastRefreshTime + currentRefreshrate < timebase || lastRefreshTime > timebase){
		switch(currentLedState)
		{
			case BINAIRY:
				PIOC->PIO_SODR = DEBUGLEDMASK;
				PIOC->PIO_CODR = (rev(value)) & DEBUGLEDMASK;
			break;
			case BARGRAPH:
				PIOC->PIO_SODR = DEBUGLEDMASK;
				PIOC->PIO_CODR = (rev(calculateBar(value))) & DEBUGLEDMASK;
			break;
			default:

			break;
		}
		lastRefreshTime = timebase;
	}	
}

/*! \brief executes the rev ARM instruction
 *	
 *	The rev instruction reverses a word of data making the MSB the LSB and vica versa 
 *  
 *	\param 	input The word to be reversed
 *
 *	\retval the input word in reversed order			
 *		       
 */
static inline uint32_t rev(uint32_t input)
{
	uint32_t output;
	asm("rbit %0, %1" : "=r" (output) : "r" (input));
	return output;
}

void led_configure(debugLedState mode, uint32_t refreshrate, uint32_t scale)
{
	currentLedState = mode;
	currentRefreshrate = refreshrate;
	barGraphScale = scale;
}



void led_setLed(uint32_t led, debugPinState newPinstate)
{	
	switch(newPinstate)
	{
		case ON:
			DEBUG_LED_PORT->PIO_CODR = led;
		break;
		case OFF:
			DEBUG_LED_PORT->PIO_SODR = led;
		break;
		case TOGGLE:
			if(DEBUG_LED_PORT->PIO_ODSR & led){
				DEBUG_LED_PORT->PIO_CODR = led;
			}else{
				DEBUG_LED_PORT->PIO_SODR = led;
			}
		break;
	}
	
}




