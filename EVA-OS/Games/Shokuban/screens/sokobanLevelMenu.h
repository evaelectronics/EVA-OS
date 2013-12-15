/*
 * sokobanLevelMenu.h
 *
 * Created: 12/15/2013 2:07:40 PM
 *  Author: Elmar
 */ 


#ifndef SOKOBANLEVELMENU_H_
#define SOKOBANLEVELMENU_H_

#include <Games/Shokuban/sokuban.h>

typedef struct LevelButton LevelButton;
typedef struct SokobanLevelMenu SokobanLevelMenu;

struct LevelButton{
	GuiButton button;
	uint8_t level;	
	char * location;
};

struct SokobanLevelMenu {
	Screen screen;
	List * buttons;
	GuiButton * exitButton;
	uint8_t levelSelected;
};


SokobanLevelMenu * newSokobanLevelMenu();

#endif /* SOKOBANLEVELMENU_H_ */