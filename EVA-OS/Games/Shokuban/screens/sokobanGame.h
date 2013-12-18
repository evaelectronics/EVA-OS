/*
 * game.h
 *
 * Created: 12/14/2013 8:31:44 PM
 *  Author: Elmar
 */ 


#ifndef SOKOBANGAME_H
#define SOKOBANGAME_H

#include <sam4s.h>
#include <libs/Game/game.h>
#include <libs/Game/screen.h>
#include <Games/Shokuban/screens/sokobanLevelMenu.h>
#include <Games/Shokuban/map.h>

Screen * newSokobanGame(uint8_t level);

#endif /* GAME_H_ */