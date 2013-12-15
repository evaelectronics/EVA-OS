/*
 * crate.c
 *
 * Created: 12/2/2013 1:46:46 AM
 *  Author: Elmar
 */ 

#include <Games/Shokuban/entities/crate.h>

static void draw(GameDetails * gameDetails, void * entity);

void * crate_constructor(uint8_t x, uint8_t y)
{
	Crate * crate = (Crate*) malloc(sizeof(Crate));
	crate->entity.xPos = x;
	crate->entity.yPos = y;
	crate->entity.type = CRATE_TYPE;
	crate->entity.destructor = NULL;
	crate->entity.update = NULL;
	crate->entity.draw = draw;
	return crate;
}


static void draw(GameDetails * gameDetails, void * entity)
{
	Crate * self = (Crate *) entity;
	graphical_drawRectangle(self->entity.xPos,self->entity.yPos,self->entity.xPos + CELL_SIZE, self->entity.yPos + CELL_SIZE, 0, BLACK);
	graphical_drawRectangle(self->entity.xPos+1,self->entity.yPos+1,self->entity.xPos + CELL_SIZE - CELL_SIZE/8, self->entity.yPos + CELL_SIZE - CELL_SIZE/8, 1, BLUE);
}