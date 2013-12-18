/*
 * game.c
 *
 * Created: 12/14/2013 8:31:56 PM
 *  Author: Elmar
 */ 

#include <Games/Shokuban/screens/sokobanGame.h>
#include <Games/Shokuban/sokuban.h>

static void loadLevel(struct Map * map);
static void victory(Player * player);
static void draw(Screen * screen, GameDetails * gameDetails);
static void create(Screen * screen);

static uint8_t curLevel;

Screen * newSokobanGame(uint8_t level) 
{
	Screen * game = newScreen();
	game->draw = draw;
	game->create = create;
	curLevel = level;
	return game;
}

static void create(Screen * screen)
{
	loadLevel(map_loadLevel(curLevel));
}

static void draw(Screen * screen, GameDetails * gameDetails)
{
	uint8_t i = 0;
	graphical_drawRectangle(0,0,159,127,1,BLACK);	//Clear the screen
	graphical_drawRectangle(0,0,map_currentLevel()->width*CELL_SIZE,map_currentLevel()->height*CELL_SIZE,1,WHITE);	//Map
	for (i = 0; i<map_currentLevel()->width; i++)	{
		graphical_drawLine(i * CELL_SIZE, 0, i * CELL_SIZE, map_currentLevel()->width * CELL_SIZE, BLACK);
	}
	for (i = 0; i<map_currentLevel()->height; i++)	{
		graphical_drawLine(0, i * CELL_SIZE, map_currentLevel()->height * CELL_SIZE, i * CELL_SIZE, BLACK);
	}
}

static void loadLevel(struct Map * map)
{
	uint8_t x = 0;
	uint8_t y = 0;
	while (y<map->width) {
		if(map->data[x+y*map->height] == BOX_TYPE){
			game_addEntity(box_constructor(x*CELL_SIZE,y*CELL_SIZE));
		}else if(map->data[x+y*map->height] == PLAYER_TYPE){
			Player * player = (Player *) player_constructor(game_getEntityManager(),x*CELL_SIZE,y*CELL_SIZE);
			player->victory = victory;
			game_addEntity(player);
		}else if(map->data[x+y*map->height] == CRATE_TYPE){
			game_addEntity(crate_constructor(x*CELL_SIZE,y*CELL_SIZE));
		}else if(map->data[x+y*map->height] == GAP_TYPE){
			game_addEntity(gap_constructor(x*CELL_SIZE,y*CELL_SIZE));
		}
		x++;
		if(x>=map->height){
			y++;
			x = 0;
		}
	}
}

static void victory(Player * player)
{
	game_getEntityManager()->clear(game_getEntityManager());
	levelProgress = curLevel+1;
	game_setScreen(newSokobanLevelMenu());
}