/*
 * ball.c
 *
 * Created: 12/6/2013 7:23:37 PM
 *  Author: Elmar
 */ 

#include <Games/pong/ball.h>

void * newBall(uint8_t x, uint8_t y)
{
	Ball * ball = malloc(sizeof(Ball));
	ball->entity.xPos = x;
	ball->entity.yPos = y;
	ball->speed = 1;
	ball->dx = 1;
	ball->dy = 1;
	ball->entity.update = NULL;
	ball->entity.draw = NULL;
	ball->size = 5;
	ball->hitCounter = 0;
	return ball;
}
