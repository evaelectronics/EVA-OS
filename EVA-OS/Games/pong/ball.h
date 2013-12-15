/*
 * ball.h
 *
 * Created: 12/6/2013 7:31:27 PM
 *  Author: Elmar
 */ 


#ifndef BALL_H_
#define BALL_H_

#include <Games/pong/pong.h>

typedef struct Ball Ball;

struct Ball {
	Entity entity;
	uint8_t size;
	int8_t dx;
	int8_t dy;
	uint8_t speed;
	uint8_t hitCounter;
};

void * newBall(uint8_t x, uint8_t y);



#endif /* BALL_H_ */