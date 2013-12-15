/*
 * paddle.h
 *
 * Created: 12/6/2013 10:19:53 PM
 *  Author: Elmar
 */ 


#ifndef PADDLE_H_
#define PADDLE_H_

#include <Games/pong/pong.h>

typedef struct Paddle Paddle;

struct Paddle{
	Entity entity;
	uint8_t width;
	uint8_t height;
	uint8_t computer;
	uint8_t speed;
};

void * newPaddle(uint8_t x, uint8_t y, uint8_t computer);

#endif /* PADDLE_H_ */