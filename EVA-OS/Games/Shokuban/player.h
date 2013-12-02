/*
 * player.h
 *
 * Created: 11/30/2013 11:41:39 PM
 *  Author: Elmar
 */ 

#ifndef PLAYER_H_
#define PLAYER_H_

#include <sam4s.h>
#include <Libs/Game/game.h>
#include <Games/Shokuban/types.h>

typedef struct Player Player;

struct Player {
	Entity entity;
	uint8_t moves;	
};

void * player_constructor(uint8_t x, uint8_t y);

#endif /* PLAYER_H_ */