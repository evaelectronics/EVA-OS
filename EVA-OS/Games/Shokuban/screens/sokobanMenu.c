/*
 * mainMenu.c
 *
 * Created: 12/14/2013 1:03:18 PM
 *  Author: Elmar
 */ 

#include <Games/Shokuban/screens/sokobanMenu.h>

#define BUTTON_WIDTH 60
#define BUTTON_HEIGHT 20
#define BUTTON_SPACING 10

static void update(Screen * screen, GameDetails * gameDetails);
static void draw(Screen * screen, GameDetails * gameDetails);
static void dispose(Screen * screen);
static void startGame(GuiButton * guiButton);
static void exitGame(GuiButton * guiButton);

Screen * newSokobanMenu()
{
	SokobanMenu * mainMenu = malloc(sizeof(SokobanMenu));
	mainMenu->screen = *newScreen();
	mainMenu->screen.draw = draw;
	mainMenu->screen.update = update;
	mainMenu->screen.dispose = dispose;
	GuiButton * startGameButton = newGuiButton(CANVASS_WIDTH/2 - BUTTON_WIDTH/2, CANVASS_HEIGHT-(BUTTON_SPACING+BUTTON_HEIGHT), BUTTON_WIDTH, BUTTON_HEIGHT);
	startGameButton->action = startGame;
	startGameButton->selected = 1;
	GuiButton * levelSelectButton = newGuiButton(CANVASS_WIDTH/2 - BUTTON_WIDTH/2, CANVASS_HEIGHT-(BUTTON_SPACING * 2 + BUTTON_HEIGHT * 2), BUTTON_WIDTH, 20);
	GuiButton * optionsButton = newGuiButton(CANVASS_WIDTH/2 - BUTTON_WIDTH/2, CANVASS_HEIGHT-(BUTTON_SPACING * 3 +BUTTON_HEIGHT * 3), BUTTON_WIDTH, 20);
	GuiButton * exitGameButton = newGuiButton(CANVASS_WIDTH/2 - BUTTON_WIDTH/2, CANVASS_HEIGHT-(BUTTON_SPACING * 4 + BUTTON_HEIGHT * 4), BUTTON_WIDTH, 20);
	exitGameButton->action = exitGame;
	mainMenu->buttons = newList();
	list_add(mainMenu->buttons, startGameButton);
	list_add(mainMenu->buttons, levelSelectButton);
	list_add(mainMenu->buttons, optionsButton);
	list_add(mainMenu->buttons, exitGameButton);
	return &mainMenu->screen;
}

static void update(Screen * screen, GameDetails * gameDetails)
{
	SokobanMenu * mainMenu = (SokobanMenu *) screen;
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
				if(tempNode->nextNode->nextNode != NULL){
					((GuiButton *)tempNode->nextNode->data)->selected = 1;
				}	else {	//end of list, loop back
					((GuiButton *)mainMenu->buttons->head->data)->selected = 1;
				}
				break;
			}
			tempNode = tempNode->nextNode;
		}
	}
	if(gameDetails->gameInput->button_isTyped(BUTTONS_UP)){
		tempNode = mainMenu->buttons->head;
		while(tempNode->nextNode != NULL){
			if(((GuiButton *)tempNode->data)->selected){
				((GuiButton *)tempNode->data)->selected = 0;
				if(tempNode->prevNode != NULL){
					((GuiButton *)tempNode->prevNode->data)->selected = 1;
				}	else {	//end of list, loop back
					((GuiButton *)mainMenu->buttons->tail->prevNode->data)->selected = 1;
				}
				break;
			}
			tempNode = tempNode->nextNode;
		}
	}
}

static void draw(Screen * screen, GameDetails * gameDetails)
{
	graphical_drawRectangle(0,0,CANVASS_WIDTH,CANVASS_HEIGHT,1,WHITE);
	SokobanMenu * mainMenu = (SokobanMenu *) screen;
	Node * tempNode = mainMenu->buttons->head;
	while(tempNode->nextNode != NULL) {
		GuiButton * guiButton = (GuiButton *)tempNode->data;
		guiButton->draw(guiButton);
		tempNode = tempNode->nextNode;
	}
}

static void dispose(Screen * screen)
{
 	SokobanMenu * mainMenu = (SokobanMenu *) screen;
 	Node * tempNode = mainMenu->buttons->head;
 	while(tempNode->nextNode != NULL) {
 		free((GuiButton *)tempNode->data);
 		tempNode = tempNode->nextNode;
 	}
 	list_clear(mainMenu->buttons);
}

static void startGame(GuiButton * guiButton)
{
	game_setScreen(newSokobanLevelMenu());
}

static void exitGame(GuiButton * guiButton)
{
	//TODO return to os
}