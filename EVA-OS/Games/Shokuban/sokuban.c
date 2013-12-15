/*
 * sokuban.c
 *
 * Created: 12/2/2013 7:48:42 PM
 *  Author: Elmar
 */ 
#include <Games/Shokuban/sokuban.h>

BaseGame * sokubanGame()
{
	BaseGame * game = calloc(1, sizeof(BaseGame));
	levelProgress = 1;
	game_setEntityManager(syncManager_constructor(0));
	map_loadMaps();
	game_setScreen(newSokobanMenu());
	return game;
}