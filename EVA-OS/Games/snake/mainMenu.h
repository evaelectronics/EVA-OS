/*
 * menu.h
 *
 * Created: 12/14/2013 1:17:48 AM
 *  Author: Elmar
 */ 


#ifndef MENU2_H_
#define MENU2_H_

#include <Libs/Game/game.h>
#include <Libs/Game/guiButton.h>

typedef struct MainMenu MainMenu;

struct MainMenu {
	Screen screen;
	List * buttons;	
};

MainMenu * newMainMenu();

#endif /* MENU_H_ */