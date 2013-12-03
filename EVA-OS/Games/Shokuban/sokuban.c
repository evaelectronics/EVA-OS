/*
 * sokuban.c
 *
 * Created: 12/2/2013 7:48:42 PM
 *  Author: Elmar
 */ 
#include <Games/Shokuban/sokuban.h>
#include <TinyPrintf/printf.h>

static void victory(Player * player);
static void draw(GameDetails * gameDetails);
static void update(GameDetails * gameDetails);
static void loadLevel(struct Map map);

uint8_t level = 0;

BaseGame * sokubanGame()
{
	BaseGame * game = calloc(1, sizeof(BaseGame));
	game->drawSpecific = draw;
	game->updateSpeficific = update;
	game_setEntityManager(defaultManager_constructor(0));
	map_loadMaps();
	loadLevel(map_loadLevel(0));
	return game;
}

static void draw(GameDetails * gameDetails)
{
	graphical_drawRectangle(0,0,159,127,1,BLACK);	//Clear the screen
	graphical_drawRectangle(0,0,map_loadLevel(level).width*8,map_loadLevel(level).length*8,1,WHITE);	//Map
}

static void update(GameDetails * gameDetails)
{
	//Do nothing. Nothing of interest is to be done
}

static void loadLevel(struct Map map)
{
	uint8_t x = 0;
	uint8_t y = 0;
	while (y<map.width) {
		if(map.data[x+y*map.length] == BOX_TYPE){
			game_addEntity(box_constructor(x*8,y*8));
		}else if(map.data[x+y*map.length] == PLAYER_TYPE){
			Player * player = (Player *) player_constructor(game_getEntityManager(),x*8,y*8);
			player->victory = victory;
			game_addEntity(player);
		}else if(map.data[x+y*map.length] == CRATE_TYPE){
			game_addEntity(crate_constructor(x*8,y*8));
		}else if(map.data[x+y*map.length] == GAP_TYPE){
			game_addEntity(gap_constructor(x*8,y*8));
		}
		x++;
		if(x>=map.length){
			y++;
			x = 0;
		}
	}
}

static void victory(Player * player)
{
	player->entityManager->clear(player->entityManager);
	level++;
	loadLevel(map_loadLevel(level));
}