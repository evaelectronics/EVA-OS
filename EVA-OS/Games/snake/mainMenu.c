/*
 * menu.c
 *
 * Created: 12/14/2013 1:17:40 AM
 *  Author: Elmar
 */ 

#include <Games/snake/mainMenu.h>

static void update(Screen * screen, GameDetails * gameDetails);
static void draw(Screen * screen, GameDetails * gameDetails);

MainMenu * newMainMenu()
{
	MainMenu * mainMenu = malloc(sizeof(MainMenu));
	mainMenu->screen = *newScreen();
	mainMenu->screen.draw = draw;
	mainMenu->screen.update = update;
	return mainMenu;
}

static void update(Screen * screen, GameDetails * gameDetails)
{
	MainMenu * mainMenu = (MainMenu *) screen;
	Node * tempNode;
	if(gameDetails->gameInput->button_isTyped(BUTTONS_SELECT)){
		tempNode = mainMenu->buttons->head;
		while(tempNode->nextNode != NULL){
			if(((GuiButton *)tempNode->data)->selected){
				((GuiButton *)tempNode->data)->action((GuiButton *)tempNode->data);
			}
			tempNode = tempNode->nextNode;
		}
	}
	if(gameDetails->gameInput->button_isTyped(BUTTONS_DOWN)){
		tempNode = mainMenu->buttons->head;
		while(tempNode->nextNode != NULL){
			if(((GuiButton *)tempNode->data)->selected){
				((GuiButton *)tempNode->data)->selected = 0;
				
				((GuiButton *)tempNode->nextNode->data)->selected = 1;
				tempNode = tempNode->nextNode;
			}
			tempNode = tempNode->nextNode;
		}
	}
	
}

static void draw(Screen * screen, GameDetails * gameDetails)
{
	MainMenu * mainMenu = (MainMenu *) screen;
	Node * tempNode = mainMenu->buttons->head;
	while(tempNode->nextNode != NULL) {
		((GuiButton *)tempNode->data)->draw((GuiButton *)tempNode);
		tempNode = tempNode->nextNode;
	}
}