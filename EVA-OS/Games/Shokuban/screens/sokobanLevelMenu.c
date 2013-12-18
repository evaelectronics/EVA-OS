/*
 * sokobanLevelMenu.c
 *
 * Created: 12/15/2013 2:07:50 PM
 *  Author: Elmar
 */ 
#include <games/Shokuban/screens/sokobanLevelMenu.h>

static void update(Screen * screen, GameDetails * gameDetails);
static void draw(Screen * screen, GameDetails * gameDetails);
static void create(Screen * screen);
static void dispose(Screen * screen);
static void loadLevel(GuiButton * guiButton);
static void levelSelect(SokobanLevelMenu * mainMenu, uint8_t level);
static void buttonDraw(GuiButton * guiButton);
static void mainMenu(GuiButton * button);

static struct RGBcolour * gray;
#define BUTTON_SIZE 25
#define BUTTON_OFFSET 6

Screen * newSokobanLevelMenu()
{
	SokobanLevelMenu * sokobanLevelMenu = malloc(sizeof(SokobanLevelMenu));
	sokobanLevelMenu->screen = *newScreen();
	sokobanLevelMenu->screen.draw = draw;
	sokobanLevelMenu->screen.update = update;
	sokobanLevelMenu->screen.dispose = dispose;
	sokobanLevelMenu->screen.create = create;
	return &sokobanLevelMenu->screen;
}

static void create(Screen * screen)
{
	SokobanLevelMenu * sokobanLevelMenu = (SokobanLevelMenu *) screen;
	gray = graphical_createRGBColour(100,100,100);
	sokobanLevelMenu->buttons = newList();
	sokobanLevelMenu->levelSelected = 1;
	sokobanLevelMenu->exitButton = newGuiButton(BUTTON_OFFSET,BUTTON_OFFSET,CANVASS_WIDTH - BUTTON_OFFSET * 2 + 2,25);
	sokobanLevelMenu->exitButton->action = mainMenu;
	uint8_t i  = 0;
	LevelButton * newLevel;
	for(i = 0; i<15; i++){
		newLevel = malloc(sizeof(LevelButton));
		newLevel->button = *newGuiButton(BUTTON_OFFSET + (i % 5) * (BUTTON_SIZE + BUTTON_OFFSET),CANVASS_HEIGHT - (1+(i/5))*(BUTTON_SIZE + BUTTON_OFFSET),BUTTON_SIZE,BUTTON_SIZE);
		newLevel->button.action = loadLevel;
		newLevel->button.draw = buttonDraw;
		newLevel->level = i + 1;
		list_add(sokobanLevelMenu->buttons, newLevel);
	}
	levelSelect(sokobanLevelMenu,1);
}

static void levelSelect(SokobanLevelMenu * mainMenu, uint8_t level)
{
	Node * tempNode = mainMenu->buttons->head;
	while(tempNode->nextNode != NULL) {
		LevelButton * guiButton = (LevelButton *)tempNode->data;
		if(guiButton->level == level){
			guiButton->button.selected = 1;	
		} else {
			guiButton->button.selected = 0;	
		}
		tempNode = tempNode->nextNode;	
	}
}

static void update(Screen * screen, GameDetails * gameDetails) 
{
	SokobanLevelMenu * sokobanlevelMenu = (SokobanLevelMenu *) screen;
	if(gameDetails->gameInput->button_isTyped(BUTTONS_SELECT)){
		Node * tempNode = sokobanlevelMenu->buttons->head;
		while(tempNode->nextNode != NULL){
			if(((GuiButton *)tempNode->data)->selected){
				((GuiButton *)tempNode->data)->action((GuiButton *)tempNode->data);
			}
			tempNode = tempNode->nextNode;
		}
		if(sokobanlevelMenu->exitButton->selected){
			sokobanlevelMenu->exitButton->action(sokobanlevelMenu->exitButton);
		}
	}
	if(gameDetails->gameInput->button_isTyped(BUTTONS_DOWN)){
		if(sokobanlevelMenu->levelSelected<11) {
			sokobanlevelMenu->levelSelected+=5;
			levelSelect(sokobanlevelMenu,sokobanlevelMenu->levelSelected);
		} else {
			if(sokobanlevelMenu->exitButton->selected){
				sokobanlevelMenu->levelSelected%=10;
				sokobanlevelMenu->exitButton->selected = 0;
				levelSelect(sokobanlevelMenu,sokobanlevelMenu->levelSelected);
			} else {
				levelSelect(sokobanlevelMenu,0);	//Deselect
				sokobanlevelMenu->exitButton->selected = 1;
			}
		}
	}
	if(gameDetails->gameInput->button_isTyped(BUTTONS_UP)){
		if(sokobanlevelMenu->levelSelected>5) {
			sokobanlevelMenu->levelSelected-=5;
			levelSelect(sokobanlevelMenu,sokobanlevelMenu->levelSelected);
		} else {
			if(sokobanlevelMenu->exitButton->selected){
				sokobanlevelMenu->levelSelected+=10;
				sokobanlevelMenu->exitButton->selected = 0;
				levelSelect(sokobanlevelMenu,sokobanlevelMenu->levelSelected);
			} else {
				levelSelect(sokobanlevelMenu,0);	//Deselect
				sokobanlevelMenu->exitButton->selected = 1;
			}
		}
	}
	if(gameDetails->gameInput->button_isTyped(BUTTONS_LEFT)){
		if(!sokobanlevelMenu->exitButton->selected){
			if(sokobanlevelMenu->levelSelected  == 1){	//If most left uppercorner is selected
				sokobanlevelMenu->levelSelected = 15;
			} else {
				sokobanlevelMenu->levelSelected--;
			}
			levelSelect(sokobanlevelMenu,sokobanlevelMenu->levelSelected);
		}
	}
	if(gameDetails->gameInput->button_isTyped(BUTTONS_RIGHT)){
		if(!sokobanlevelMenu->exitButton->selected){
			if(sokobanlevelMenu->levelSelected  == 15){	//If most right bottom corner is selected
				sokobanlevelMenu->levelSelected = 1;
			} else {
				sokobanlevelMenu->levelSelected++;
			}
			levelSelect(sokobanlevelMenu,sokobanlevelMenu->levelSelected);
		}
	}
}

static void draw(Screen * screen, GameDetails * gameDetails)
{
	graphical_drawRectangle(0,0,CANVASS_WIDTH,CANVASS_HEIGHT,1,WHITE);
	SokobanLevelMenu * mainMenu = (SokobanLevelMenu *) screen;
	Node * tempNode = mainMenu->buttons->head;
	while(tempNode->nextNode != NULL) {
		LevelButton * guiButton = (LevelButton *)tempNode->data;
		guiButton->button.draw(&guiButton->button);
		tempNode = tempNode->nextNode;
	}
	mainMenu->exitButton->draw(mainMenu->exitButton);
}

static void buttonDraw(GuiButton * guiButton)
{
	LevelButton * levelButton = (LevelButton *) guiButton;
	if(levelButton->level <= levelProgress){
		graphical_drawRectangle(guiButton->x,guiButton->y,guiButton->x+guiButton->width-3,guiButton->y+guiButton->height-3,1,RED);
	} else {
		graphical_drawRectangle(guiButton->x,guiButton->y,guiButton->x+guiButton->width-3,guiButton->y+guiButton->height-3,1,gray);
	}
	if(guiButton->selected){
		graphical_drawRectangle(guiButton->x,guiButton->y,guiButton->x+guiButton->width,guiButton->y+guiButton->height,0,GREEN);
	} else {
		graphical_drawRectangle(guiButton->x,guiButton->y,guiButton->x+guiButton->width,guiButton->y+guiButton->height,0,BLACK);
	}
}

static void dispose(Screen * screen)
{
	SokobanLevelMenu * levelMenu = (SokobanLevelMenu *) screen;
 	Node * tempNode = levelMenu->buttons->head;
 	while(tempNode->nextNode != NULL) {
 		free((LevelButton *)tempNode->data);
 		tempNode = tempNode->nextNode;
 	}
 	list_clear(levelMenu->buttons);
	 free(gray);
}

static void loadLevel(GuiButton * button)
{
	LevelButton * levelButton = (LevelButton *) button;
	if(levelProgress >= levelButton->level){
		game_setScreen(newSokobanGame(levelButton->level));
	}
}

static void mainMenu(GuiButton * button)
{
	game_setScreen(newSokobanMenu());
}