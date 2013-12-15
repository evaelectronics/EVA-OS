/*
* player.c
*
* Created: 11/30/2013 11:41:24 PM
*  Author: Elmar
*/
#include <Games/Shokuban/entities/player.h>

static void update(GameDetails * gameDetails, void * entity, uint16_t deltaT);
static void draw(GameDetails * gameDetails, void * entity);
static void move(int8_t deltaX, int8_t deltaY, Player * self);

void * player_constructor(EntityManager * entityManager, uint8_t x, uint8_t y)
{	
	Player * player = (Player*) malloc(sizeof(Player));
	player->entity.xPos = x;
	player->entity.yPos = y;
	player->moves = 0;
	player->entityManager = entityManager;
	player->entity.type = PLAYER_TYPE;
	player->entity.destructor = NULL;
	player->entity.update = update;
	player->entity.draw = draw;	
	return player;
}

static void update(GameDetails * gameDetails, void * entity, uint16_t deltaT)
{
	Player * self = (Player *) entity;
	if(gameDetails->gameInput->button_isTyped(BUTTONS_UP)){
		move(0, CELL_SIZE,self);
	}else if(gameDetails->gameInput->button_isTyped(BUTTONS_DOWN)){
		move(0, -CELL_SIZE,self);
	}else if(gameDetails->gameInput->button_isTyped(BUTTONS_LEFT)){
		move(-CELL_SIZE, 0,self);
	}else if(gameDetails->gameInput->button_isTyped(BUTTONS_RIGHT)){
		move(CELL_SIZE, 0,self);
	}
	if(gameDetails->gameInput->button_isTyped(BUTTONS_SELECT)){
		self->entityManager->removeEntity(self->entityManager,self);//self->entityManager->clear(self->entityManager);
	}
}

static void move(int8_t deltaX, int8_t deltaY, Player * self)
{
	Entity * other = (Entity* )self->entityManager->getEntity(self->entityManager,self->entity.xPos+deltaX, self->entity.yPos+deltaY);
	if(other == NULL){
		self->entity.yPos+=deltaY;
		self->entity.xPos+=deltaX;
		self->moves++;
	} else if(other->type == CRATE_TYPE){
		Entity * crateOther = (Entity* )self->entityManager->getEntity(self->entityManager,other->xPos+deltaX, other->yPos+deltaY);
		if(crateOther == NULL){
			self->entity.yPos+=deltaY;
			self->entity.xPos+=deltaX;
			other->yPos+=deltaY;
			other->xPos+=deltaX;
			self->moves++;
		}else if(crateOther->type == GAP_TYPE){
			self->entity.yPos+=deltaY;
			self->entity.xPos+=deltaX;
			other->yPos+=deltaY;
			other->xPos+=deltaX;
			self->moves++;
			self->victory(self);
			return;
		}
	} else if(other->type == GAP_TYPE){
		self->entity.alive = 0;
	}else{
			//Cant move here
	}
}

static void draw(GameDetails * gameDetails, void * entity)
{
	Player * self = (Player *) entity;
	graphical_drawCircle(self->entity.xPos+CELL_SIZE/2, self->entity.yPos+CELL_SIZE/2, CELL_SIZE/2 - 1, 0, BLACK);
	graphical_drawCircle(self->entity.xPos+CELL_SIZE/2, self->entity.yPos+CELL_SIZE/2, CELL_SIZE/2 - 2, 1, GREEN);
}