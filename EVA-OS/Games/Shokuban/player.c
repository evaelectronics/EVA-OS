/*
* player.c
*
* Created: 11/30/2013 11:41:24 PM
*  Author: Elmar
*/
#include <Games/Shokuban/player.h>

static void update(GameDetails * gameDetails, void * entity, uint16_t deltaT);
static void draw(GameDetails * gameDetails, void * entity);

void * player_constructor(uint8_t x, uint8_t y)
{	
	Player * player = (Player*) malloc(sizeof(Player));
	player->entity.xPos = x;
	player->entity.yPos = y;
	player->moves = 0;
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
		self->entity.yPos+=8;
		self->moves++;
	}else if(gameDetails->gameInput->button_isTyped(BUTTONS_DOWN)){
		self->entity.yPos-=8;
		self->moves++;
	}else if(gameDetails->gameInput->button_isTyped(BUTTONS_LEFT)){
		self->entity.xPos-=8;
		self->moves++;
	}else if(gameDetails->gameInput->button_isTyped(BUTTONS_RIGHT)){
		self->entity.xPos+=8;
		self->moves++;
	}
	/*
	if(
	
	*/
}

static void draw(GameDetails * gameDetails, void * entity)
{
	Player * self = (Player *) entity;
	graphical_drawCircle(self->entity.xPos+4, self->entity.yPos+4, 4, 1, RED);
}