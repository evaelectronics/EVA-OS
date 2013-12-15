/*
 * pong.c
 *
 * Created: 12/6/2013 7:23:08 PM
 *  Author: Elmar
 */ 

#include <Games/pong/pong.h>

static void update(GameDetails * gameDetails);
static void draw(GameDetails * gameDetails);

static struct PongContainer * pongContainer;

BaseGame * pongGame()
{
	BaseGame * game = calloc(1, sizeof(BaseGame));
	game->drawSpecific = draw;
	game->updateSpeficific = update;
	game_setEntityManager(syncManager_constructor(0));
	pongContainer = malloc(sizeof(struct PongContainer));
	pongContainer->ball = newBall(CANVASS_WIDTH/2,CANVASS_HEIGHT/2);
	pongContainer->player1 = newPaddle(0, CANVASS_HEIGHT /2, 1);
	pongContainer->player2 = newPaddle(CANVASS_WIDTH-5, CANVASS_HEIGHT/2, 1);
	pongContainer->scoreP1 = 0;
	pongContainer->scoreP2 = 0;
	game_addEntity(pongContainer->ball);
	game_addEntity(pongContainer->player1);
	game_addEntity(pongContainer->player2);
	return game;
}

static void update(GameDetails * gameDetails)
{
	if(pongContainer->player1->computer == 0){					// if not computer controlled
		if(gameDetails->gameInput->button_isPressed(BUTTONS_UP)){
			if((pongContainer->player1->entity.yPos + pongContainer->player1->height) < CANVASS_HEIGHT){
				pongContainer->player1->entity.yPos += gameDetails->deltaT * pongContainer->player1->speed;
			}
		}
		if(gameDetails->gameInput->button_isPressed(BUTTONS_DOWN)){
			if(pongContainer->player1->entity.yPos>1){
				pongContainer->player1->entity.yPos -= gameDetails->deltaT * pongContainer->player1->speed;
			}
		}
	} else {
		if(pongContainer->ball->entity.yPos > (pongContainer->player1->entity.yPos + (3 * pongContainer->player1->height) / 4)){
			if((pongContainer->player1->entity.yPos + pongContainer->player1->height) < CANVASS_HEIGHT){
				pongContainer->player1->entity.yPos += gameDetails->deltaT * pongContainer->player1->speed;
			}
		} else if (pongContainer->ball->entity.yPos < (pongContainer->player1->entity.yPos + (pongContainer->player1->height )/ 4)) {
			if(pongContainer->player1->entity.yPos>1){
				pongContainer->player1->entity.yPos -= gameDetails->deltaT * pongContainer->player1->speed;
			}
		}
	}	
	
	if(pongContainer->player2->computer == 0){					// if not computer controlled
		if(gameDetails->gameInput->button_isPressed(BUTTONS_UP)){
			if((pongContainer->player2->entity.yPos + pongContainer->player2->height) < CANVASS_HEIGHT){
				pongContainer->player2->entity.yPos += gameDetails->deltaT * pongContainer->player2->speed;
			}
		}
		if(gameDetails->gameInput->button_isPressed(BUTTONS_DOWN)){
			if(pongContainer->player2->entity.yPos>1){
				pongContainer->player2->entity.yPos -= gameDetails->deltaT * pongContainer->player2->speed;
			}
		}
	} else {
		if(pongContainer->ball->entity.yPos > (pongContainer->player2->entity.yPos + (3 * pongContainer->player2->height) / 4)){
			if((pongContainer->player2->entity.yPos + pongContainer->player2->height) < CANVASS_HEIGHT){
				pongContainer->player2->entity.yPos += gameDetails->deltaT * pongContainer->player2->speed;
			}
		} else if (pongContainer->ball->entity.yPos < (pongContainer->player2->entity.yPos + (pongContainer->player2->height) / 4)) {
			if(pongContainer->player2->entity.yPos>1){
				pongContainer->player2->entity.yPos -= gameDetails->deltaT * pongContainer->player2->speed;
			}
		}
	}
	
	if((pongContainer->ball->entity.yPos > pongContainer->player1->entity.yPos) && 
		pongContainer->ball->entity.yPos < pongContainer->player1->entity.yPos+ pongContainer->player1->height){
			if(((pongContainer->ball->entity.xPos + pongContainer->ball->size) > pongContainer->player1->entity.xPos) &&
				(pongContainer->ball->entity.xPos - pongContainer->ball->size) < pongContainer->player1->entity.xPos + pongContainer->player1->width){
					pongContainer->ball->dx *= -1;
					pongContainer->ball->hitCounter++;
			}
	}
	
	if((pongContainer->ball->entity.yPos > pongContainer->player2->entity.yPos) && 
		pongContainer->ball->entity.yPos < pongContainer->player2->entity.yPos+ pongContainer->player2->height){
			if(((pongContainer->ball->entity.xPos + pongContainer->ball->size) > pongContainer->player2->entity.xPos) &&
				(pongContainer->ball->entity.xPos - pongContainer->ball->size) < pongContainer->player2->entity.xPos + pongContainer->player2->width){
					pongContainer->ball->dx *= -1;
					pongContainer->ball->hitCounter++;
			}
	}
	if(pongContainer->ball->hitCounter >= 5){
		pongContainer->ball->hitCounter -= 5;
		pongContainer->ball->speed++;
		pongContainer->ball->size--;
	}
		
	if(pongContainer->ball->entity.yPos<  pongContainer->ball->size *2){
		pongContainer->ball->dy = 1;
	}else if (pongContainer->ball->entity.yPos>CANVASS_HEIGHT - pongContainer->ball->size * 2){
		pongContainer->ball->dy = -1;
	}
	
	if(pongContainer->ball->entity.xPos>CANVASS_WIDTH - (pongContainer->ball->size + 1)){
		pongContainer->ball->dx = -1;
		pongContainer->ball->entity.xPos = CANVASS_WIDTH/2;
		pongContainer->ball->entity.yPos = CANVASS_HEIGHT/2;
		pongContainer->ball->size = 5;
		pongContainer->ball->speed = 1;
		pongContainer->scoreP2++;
	} else if(pongContainer->ball->entity.xPos< 0 + (pongContainer->ball->size + 1)){
		pongContainer->ball->dx = -1;
		pongContainer->ball->entity.xPos = CANVASS_WIDTH/2;
		pongContainer->ball->entity.yPos = CANVASS_HEIGHT/2;
		pongContainer->ball->size = 5;
		pongContainer->ball->speed = 1;
		pongContainer->scoreP1++;
	}
	
	pongContainer->ball->entity.xPos += pongContainer->ball->dx * gameDetails->deltaT * pongContainer->ball->speed;
	pongContainer->ball->entity.yPos += pongContainer->ball->dy * gameDetails->deltaT * pongContainer->ball->speed;
	//Do nothing. Nothing of interest is to be done
}

static void draw(GameDetails * gameDetails)
{
	graphical_drawRectangle(0,0,159,127,1,WHITE);	//Clear the screen
	graphical_drawCircle(CANVASS_WIDTH/2,CANVASS_HEIGHT/2,20,0,RED);
	graphical_drawLine(CANVASS_WIDTH/2,0,CANVASS_WIDTH/2,CANVASS_HEIGHT,RED);
	
	graphical_drawCircle(pongContainer->ball->entity.xPos, pongContainer->ball->entity.yPos, pongContainer->ball->size,1,BLUE);
	graphical_drawCircle(pongContainer->ball->entity.xPos, pongContainer->ball->entity.yPos, pongContainer->ball->size,0,BLACK);
	
	graphical_drawRectangle(pongContainer->player1->entity.xPos,
							pongContainer->player1->entity.yPos,
							pongContainer->player1->entity.xPos+pongContainer->player1->width,
							pongContainer->player1->entity.yPos+pongContainer->player1->height,
							1,
							BLUE);
	graphical_drawRectangle(pongContainer->player1->entity.xPos,
							pongContainer->player1->entity.yPos,
							pongContainer->player1->entity.xPos+pongContainer->player1->width,
							pongContainer->player1->entity.yPos+pongContainer->player1->height,
							0,
							BLACK);
	graphical_drawRectangle(pongContainer->player2->entity.xPos,
							pongContainer->player2->entity.yPos,
							pongContainer->player2->entity.xPos+pongContainer->player2->width,
							pongContainer->player2->entity.yPos+pongContainer->player2->height,
							1,
							BLUE);
	graphical_drawRectangle(pongContainer->player2->entity.xPos,
							pongContainer->player2->entity.yPos,
							pongContainer->player2->entity.xPos+pongContainer->player2->width,
							pongContainer->player2->entity.yPos+pongContainer->player2->height,
							0,
							BLACK);
}