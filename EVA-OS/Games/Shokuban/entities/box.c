/*
 * Box.c
 *
 * Created: 12/2/2013 12:52:27 AM
 *  Author: Elmar
 */ 

#include <Games/Shokuban/entities/Box.h>

static void draw(GameDetails * gameDetails, void * entity);

void * box_constructor(uint8_t x, uint8_t y)
{
	Box * box = (Box*) malloc(sizeof(Box));
	box->entity.xPos = x;
	box->entity.yPos = y;
	box->entity.alive = 1;
	box->entity.id = 0;
	box->entity.destructor = NULL;
	box->entity.update = NULL;
	box->entity.draw = draw;
	box->entity.type = BOX_TYPE;
	return box;
}


static void draw(GameDetails * gameDetails, void * entity)
{
	Box * self = (Box *) entity;
	graphical_drawRectangle(self->entity.xPos,self->entity.yPos,self->entity.xPos + CELL_SIZE, self->entity.yPos + CELL_SIZE, 0, BLACK);
	graphical_drawRectangle(self->entity.xPos+1,self->entity.yPos+1,self->entity.xPos + CELL_SIZE-CELL_SIZE/8, self->entity.yPos + CELL_SIZE-CELL_SIZE/8, 1, RED);	
}