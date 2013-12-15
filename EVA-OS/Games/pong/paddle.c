/*
 * player.c
 *
 * Created: 12/6/2013 7:23:27 PM
 *  Author: Elmar
 */ 
#include <Games/pong/paddle.h>

void * newPaddle(uint8_t x, uint8_t y, uint8_t computer)
{
	Paddle * paddle = malloc(sizeof(Paddle));
	paddle->width = 4;
	paddle->height = 30;
	paddle->speed = 2;
	paddle->computer = computer;
	paddle->entity.update = NULL;
	paddle->entity.draw = NULL;
	paddle->entity.destructor = NULL;
	paddle->entity.xPos = x;
	paddle->entity.yPos = y;
	return paddle;
}