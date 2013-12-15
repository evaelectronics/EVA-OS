/*
 * game.h
 *
 * Created: 11/29/2013 1:05:17 PM
 *  Author: Elmar
 */ 


#ifndef GAME_H_
#define GAME_H_

typedef struct GameDetails GameDetails;
typedef struct Entity Entity;
typedef struct BaseGame BaseGame;
typedef struct EntityManager EntityManager;

#include <Libs/Game/screen.h>
#include <Libs/System/systemservice.h>
#include <Drivers/Buttons/buttons.h>
#include <Libs/Graphical/graphical.h>
#include <Util/Collection/list.h>

#define CANVASS_WIDTH 159
#define CANVASS_HEIGHT 127

struct Entity {
	int16_t xPos;
	int16_t yPos;
	uint8_t alive;
	uint32_t id;
	uint8_t type;
	void (*update)(GameDetails *, void *, uint16_t);
	void (*draw)(GameDetails *, void *);
	void (*destructor)(Entity *);
};

struct GameDetails {
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
	struct Screen * screen;
	void (*updateSpeficific)(GameDetails *);
	void (*drawSpecific)(GameDetails *);
};

struct EntityManager{
	uint32_t entityId;
	uint16_t entitySize;
	
	List * entityList;
	
	Entity (*newEntity)(EntityManager *);
	void (*addEntity)(EntityManager *, void *);
	
	void * (*getEntity)(EntityManager *, uint16_t, uint16_t);
	void (*updateEntities)(EntityManager *, GameDetails *);
	
	uint8_t (*removeEntity)(EntityManager *, void * );
	uint8_t (*removeIndex)(EntityManager *, uint8_t);
	void (*clear)(EntityManager *);
};


BaseGame * currentGame;
GameDetails * gameDetails;

/*! \brief this function should ALWAYS be called prior to starting a game
 *   it will initialize and allocate memory for some base structs. And thus the system will crash
 *	 without calling this function.
 */
void game_init();
/*! \brief this function contains the logic to update and draw the game. Should be called as often as possible
 */
void game_render();
/*! \brief this function removes an entity from the entity manager. Depends on the entity manager implementation
 */
void game_removeEntity(void * entity);
/*! \brief this function loads a new game
 */
void game_loadGame(BaseGame * game);
/*! \brief this function adds an entity to the manager in use
 */
void game_addEntity(void * newEntity);
/*! \brief this function sets the screen and allows for different screen states
 */
void game_setScreen(struct Screen * screen);
/*! \brief this function sets a new entity manager. This allows you to have different implementation troughout different
 *	games.
 */
void game_setEntityManager(void * newEntityManager);
/*! \brief this function will return the entity manager and gives acces to more specific functions
 */
EntityManager * game_getEntityManager();

#endif /* GAME_H_ */