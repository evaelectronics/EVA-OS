/*
 * gap.c
 *
 * Created: 12/2/2013 1:46:18 AM
 *  Author: Elmar
 */ 

#include <Games/Shokuban/gap.h>

static void draw(GameDetails * gameDetails, void * entity);

void * gap_constructor(uint8_t x, uint8_t y)
{
	Gap * gap = (Gap*) malloc(sizeof(Gap));
	gap->entity.xPos = x;
	gap->entity.yPos = y;
	gap->entity.alive = 1;
	gap->entity.id = 0;
	gap->entity.type = GAP_TYPE;
	gap->entity.destructor = NULL;
	gap->entity.update = NULL;
	gap->entity.draw = draw;
	return gap;
}


static void draw(GameDetails * gameDetails, void * entity)
{
	Gap * self = (Gap *) entity;
	graphical_drawRectangle(self->entity.xPos,self->entity.yPos,self->entity.xPos + 8, self->entity.yPos + 8, 1, BLACK);
}