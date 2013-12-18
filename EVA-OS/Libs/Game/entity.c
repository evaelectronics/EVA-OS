/*
 * entity.c
 *
 * Created: 12/16/2013 11:46:09 AM
 *  Author: Elmar
 */ 


#include <Libs/Game/entity.h>

static void update(GameDetails* gameDetails, void * entity, uint16_t deltaT);
static void draw(GameDetails * gameDetails, void * entity);
static void destructor(void * entity);

Entity * newEntity()
{
	Entity * entity = malloc(sizeof(Entity));
	entity->update = update;
	entity->draw = draw;
	entity->destructor = destructor;
	entity->alive = 1;
	entity->type = 0;
	entity->xPos = 0;
	entity->yPos = 0;
	return entity;
}

static void update(GameDetails* gameDetails, void * entity, uint16_t deltaT)
{
	//Intentionally left empty
}

static void draw(GameDetails * gameDetails, void * entity)
{
	//Intentionally left empty
}

static void destructor(void * entity)
{
	//Intentionally left empty
}