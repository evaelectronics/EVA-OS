/*
 * led.h
 *
 * Created: 15-9-2013 16:00:01
 *  Author: P
 */ 


#ifndef DEBUG_LED_H_
#define DEBUG_LED_H_

#include <sam4s.h>

typedef enum
{
	BINAIRY, BARGRAPH, MANUAL
}debugLedState;

typedef enum
{
	ON, OFF, TOGGLE
}debugPinState;


void led_refresh(uint32_t value);
void led_configure(debugLedState mode, uint32_t refreshrate, uint32_t scale);
void led_setLed(uint32_t led, debugPinState newPinstate);


#endif /* DEBUG_LED_H_ */