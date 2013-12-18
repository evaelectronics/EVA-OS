/*
 * mainMenu.h
 *
 * Created: 12/14/2013 8:31:27 PM
 *  Author: Elmar
 */ 


#ifndef SOKOBANMENU_H_
#define SOKOBANMENU_H_

#include <Libs/Game/game.h>
#include <Libs/Game/guiButton.h>
#include <Games/Shokuban/screens/sokobanGame.h>

typedef struct SokobanMenu SokobanMenu;

struct SokobanMenu {
	Screen screen;
	List * buttons;
};

Screen * newSokobanMenu();



#endif /* MAINMENU_H_ */