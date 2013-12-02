/*
 * game.c
 *
 * Created: 11/29/2013 1:05:03 PM
 *  Author: Elmar
 */
#include <Game/game.h>
#include <Libs/Graphical/graphical.h>

static void updateGameDetails();
static EntityManager * entityManager;

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
		
	entityManager->updateEntities(entityManager, gameDetails);
				
	buttons_update();
}
EntityManager * game_getEntityManager()
{
	return entityManager;
}

void game_setEntityManager(EntityManager * newEntityManager)
{
	entityManager = newEntityManager;
}

void game_removeEntity(void * entity)
{
	entityManager->removeEntity(entityManager,entity);
}

void game_addEntity(void * newEntity)
{
	entityManager->addEntity(entityManager, newEntity);
}

void game_loadGame(BaseGame * game)
{
	currentGame = game;	
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
	//TODO remove entityManager
	free(currentGame);
}

static void updateGameDetails()
{
	gameDetails->previousUpdateTime = gameDetails->updateTime;
	gameDetails->updateTime = gameDetails->previousUpdateTime + 1; // acquireTime
	gameDetails->deltaT = gameDetails->updateTime - gameDetails->previousUpdateTime;
	gameDetails->fps = 1000 / gameDetails->deltaT;
}


