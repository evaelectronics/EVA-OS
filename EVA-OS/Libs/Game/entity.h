/*
 * entity.h
 *
 * Created: 12/16/2013 11:46:16 AM
 *  Author: Elmar
 */ 


#ifndef ENTITY_H_
#define ENTITY_H_

#include <Libs/Game/game.h>

typedef struct Entity Entity;

struct Entity {
	int32_t xPos;
	int32_t yPos;
	uint32_t id;
	uint8_t alive;
	uint8_t type;
	void (*update)(GameDetails *, void *, uint16_t);
	void (*draw)(GameDetails *, void *);
	void (*destructor)(void *);
};

Entity * newEntity();



#endif /* ENTITY_H_ */