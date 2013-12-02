/*
 * game.h
 *
 * Created: 11/29/2013 1:05:17 PM
 *  Author: Elmar
 */ 


#ifndef GAME_H_
#define GAME_H_

#include <Libs/System/systemservice.h>
#include <Drivers/Buttons/buttons.h>
#include <Libs/Graphical/graphical.h>

typedef struct GameDetails GameDetails;
typedef struct Entity Entity;
typedef struct BaseGame BaseGame;
typedef struct EntityManager EntityManager;

struct Entity{
	uint16_t xPos;
	uint16_t yPos;
	uint8_t alive;
	uint16_t id;
	uint8_t type;
	void (*update)(GameDetails *, void *, uint16_t);
	void (*draw)(GameDetails *, void *);
	void (*destructor)(Entity *);
};

struct EntityList{
	uint8_t remove;
	Entity * entity;
	struct EntityList * nextEntity;
};

struct GameDetails{
	uint16_t previousUpdateTime;
	uint16_t updateTime;
	uint16_t deltaT;
	uint8_t fps;
	struct GameInput * gameInput;
};

struct GameInput{
	uint8_t (*button_isPressed)(uint8_t);
	uint8_t (*button_isTyped)(uint8_t);
	//Accelerometer
	//Wireless controller
};

struct BaseGame{
	uint8_t active;
	EntityManager * entityManager;
	void (*updateSpeficific)(GameDetails *);
	void (*drawSpecific)(GameDetails *);
};

struct EntityManager{
	uint16_t entityId;
	uint16_t entitySize;
	struct EntityList * entityListRoot;
	struct EntityList * entityListEnd;
	void (*updateEntities)(EntityManager *, GameDetails *);
	uint8_t (*removeEntity)(EntityManager *, void * );
	void (*addEntity)(EntityManager *, void *);
	void * (*getEntity)(EntityManager *, uint16_t, uint16_t);
	void (*clear)(EntityManager *);
};

BaseGame * currentGame;
GameDetails * gameDetails;

void game_init();
void game_render();
void game_removeEntity(void * entity);
void game_loadGame(BaseGame * game);
void game_addEntity(void * newEntity);
void game_setEntityManager(EntityManager * entityManager);
EntityManager * game_getEntityManager();

#endif /* GAME_H_ */