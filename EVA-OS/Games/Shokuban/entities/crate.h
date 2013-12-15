/*
 * crate.h
 *
 * Created: 12/2/2013 1:46:37 AM
 *  Author: Elmar
 */ 


#ifndef CRATE_H_
#define CRATE_H_

#include <sam4s.h>
#include <Libs/Game/game.h>
#include <Games/Shokuban/entities/types.h>

typedef struct Crate Crate;

struct Crate{
	Entity entity;
};

void * crate_constructor(uint8_t x, uint8_t y);




#endif /* CRATE_H_ */