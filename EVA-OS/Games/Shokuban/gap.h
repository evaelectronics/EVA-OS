/*
 * gap.h
 *
 * Created: 12/2/2013 1:46:26 AM
 *  Author: Elmar
 */ 


#ifndef GAP_H_
#define GAP_H_

#include <sam4s.h>
#include <Libs/Game/game.h>
#include <Games/Shokuban/types.h>

typedef struct Gap Gap;

struct Gap{
	Entity entity;
};

void * gap_constructor(uint8_t x, uint8_t y);




#endif /* GAP_H_ */