/*
 * sokuban.h
 *
 * Created: 12/2/2013 6:30:12 PM
 *  Author: Elmar
 */ 


#ifndef SOKUBAN_H_
#define SOKUBAN_H_

#include <libs/Game/syncEntityManager.h>
#include <libs/Game/game.h>
#include <Games/Shokuban/map.h>
#include <Games/Shokuban/entities/types.h>
#include <Games/Shokuban/screens/sokobanMenu.h>
#include <Games/Shokuban/screens/sokobanGame.h>
#include <Games/Shokuban/screens/sokobanLevelMenu.h>

uint8_t levelProgress;
BaseGame * sokubanGame();

#endif /* SOKUBAN_H_ */