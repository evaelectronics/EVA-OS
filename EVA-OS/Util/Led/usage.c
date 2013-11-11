/*
 * usage.c
 *
 * Created: 11-11-2013 22:01:59
 *  Author: P
 */ 

#include <Led/led.h>
#include <Delay/delay.h>
#include <PinNames.h>

/**
 * \brief Application entry point.
 *
 * \return Unused (ANSI-C compatibility).
 */
int led_main(void)
{	
	/* Initialize the SAM system */
	SystemInit();
	WDT->WDT_MR = WDT_MR_WDDIS; //disable watchdog
 	pinDefinitions();
	 
	 led_setLed(DEBUG_LED0_PIN, ON);
	 led_setLed(DEBUG_LED1_PIN, OFF);
	 
	 while(1){		
			led_setLed(DEBUG_LED2_PIN, TOGGLE);
			delay_ms(500);		
	 }

}