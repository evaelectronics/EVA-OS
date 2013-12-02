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
	uint16_t size;	
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
	uint16_t entityId;
	struct EntityList * entityListHead;
	struct EntityList * entityListTail;
	void (*updateSpeficific)(GameDetails *);
	void (*drawSpecific)(GameDetails *);
};

struct BaseGame * currentGame;
struct GameDetails * gameDetails;

void game_init();
void game_render();
void game_loadGame(BaseGame * game);
void game_addEntity(void * newEntity);
Entity * game_createEntity();
void game_removeEntity(uint16_t id);

#endif /* GAME_H_ */