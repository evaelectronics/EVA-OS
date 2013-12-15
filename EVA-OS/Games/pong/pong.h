/*
 * pong.h
 *
 * Created: 12/6/2013 7:23:18 PM
 *  Author: Elmar
 */ 


#ifndef PONG_H_
#define PONG_H_

#include <libs/Game/syncEntityManager.h>
#include <Libs/Game/game.h>
#include <Games/pong/ball.h>
#include <Games/pong/paddle.h>

struct PongContainer {
	struct Paddle * player1;
	struct Paddle * player2;
	uint8_t scoreP1;
	uint8_t scoreP2;
	struct Ball * ball;	
};

BaseGame * pongGame();

#endif /* PONG_H_ */