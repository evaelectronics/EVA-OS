/*
 * game.c
 *
 * Created: 11/29/2013 1:05:03 PM
 *  Author: Elmar
 */
#include <Game/game.h>
#include <Libs/Graphical/graphical.h>

static void updateGameDetails();
static void updateEntities();

void game_init()
{
	button_init();
	gameDetails = calloc(1, sizeof(GameDetails));
	gameDetails->gameInput = malloc(sizeof(struct GameInput));
	gameDetails->gameInput->button_isPressed = button_isPressed;
	gameDetails->gameInput->button_isTyped = button_isTyped;
}

void game_render()
{
	updateGameDetails();
		
	if(currentGame->updateSpeficific != NULL)
		currentGame->updateSpeficific(gameDetails);
	if(currentGame->drawSpecific != NULL)
		currentGame->drawSpecific(gameDetails);
		
	updateEntities();
				
	buttons_update();
}

static void updateEntities()
{
	struct EntityList * currentEntityList;
	currentEntityList = currentGame->entityListHead;
	
	while(currentEntityList->nextEntity != NULL) {
		currentEntityList = currentEntityList->nextEntity;
		if(currentEntityList->entity->update != NULL)
			currentEntityList->entity->update(gameDetails, currentEntityList->entity, gameDetails->deltaT);
		if(currentEntityList->entity->draw != NULL)
			currentEntityList->entity->draw(gameDetails, currentEntityList->entity);
	
		if (currentEntityList->entity->alive == 0){
			if(currentEntityList->entity->destructor!=NULL)
				currentEntityList->entity->destructor(currentEntityList->entity);
			//TODO removal code
		}
	}
}

void game_removeEntity(uint16_t id)
{
	struct EntityList * currentEntityList;
	currentEntityList = currentGame->entityListHead;
	while (currentEntityList->nextEntity!=NULL){
		if(currentEntityList->entity->id == id){
			//TODO removal code
			return;
		}
	}
}

void game_addEntity(void * newEntity)
{
	Entity * entity = (Entity *) newEntity;
	struct EntityList * itterator = currentGame->entityListHead;
	
	while(itterator->nextEntity != NULL){
		itterator = itterator->nextEntity;
	}
	
	itterator->nextEntity = malloc(sizeof(struct EntityList));
	itterator = itterator->nextEntity;
	itterator->nextEntity = NULL;
	entity->id = currentGame->entityId;
	currentGame->entityId++;
	itterator->entity = entity;
}

void game_loadGame(BaseGame * game)
{
	currentGame = game;	
	currentGame->entityListHead = malloc(sizeof(struct EntityList)); 
	currentGame->entityListHead->entity = calloc(1, sizeof(Entity)); // dummy to show the start with
	currentGame->entityListHead->nextEntity = NULL;
	currentGame->entityListTail = currentGame->entityListHead;
	currentGame->entityId = 0;
	currentGame->active = 1;
}

void game_clearEntities()
{
	//TODO clearing code
}

void game_stopGame()
{
	if(currentGame!=NULL){
		currentGame->active = 0;
	}
	game_clearEntities();
	free(currentGame->entityListTail);
	free(currentGame->entityListHead);
	free(currentGame);
}

static void updateGameDetails()
{
	gameDetails->previousUpdateTime = gameDetails->updateTime;
	gameDetails->updateTime = gameDetails->previousUpdateTime + 1; // acquireTime
	gameDetails->deltaT = gameDetails->updateTime - gameDetails->previousUpdateTime;
	gameDetails->fps = 1000 / gameDetails->deltaT;
}


