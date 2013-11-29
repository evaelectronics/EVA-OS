/*
 * buttons.h
 *
 * Created: 11/16/2013 4:41:15 PM
 *  Author: Elmar
 */ 


#ifndef BUTTONS_H_
#define BUTTONS_H_

#include <Drivers/Buttons/button.h>
#include <PinNames.h>
#include <sam4s.h>

#define BUTTONS_LEFT 0
#define BUTTONS_RIGHT 1
#define BUTTONS_UP 2
#define BUTTONS_DOWN 3
#define BUTTONS_SELECT 4

typedef struct {
	uint8_t id;
	uint32_t pin;
	volatile uint8_t pressed;
	uint8_t runTime;
	uint8_t startTime;
	volatile uint8_t handled;
	volatile uint8_t typed;
} Button;

Button * buttons[5];

uint8_t button_isPressed(uint8_t id);
uint8_t button_isTyped(uint8_t id);
uint8_t button_interrupt();
void button_init();
void buttons_update();

Button button_up;
Button button_down;
Button button_left;
Button button_right;
Button button_select;


#endif /* BUTTONS_H_ */