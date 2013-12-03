/* 
 * map.c
 *
 * Created: 12/3/2013 12:38:06 AM
 *  Author: Elmar
 */ 

#include <Games/Shokuban/map.h>

static struct Map * maps;
static uint8_t maxLevel = 4;

void map_loadMaps()
{
	maps = malloc(sizeof(struct Map) * maxLevel);
	uint8_t level1[5][5] = {{1,1,1,1,1},
							{1,3,0,0,1},
							{1,0,2,0,1},
							{1,0,0,4,1},
							{1,1,1,1,1}};	
	maps[0].length = 5;
	maps[0].width = 5;
	maps[0].data = malloc(sizeof(uint8_t) * 5 * 5);
	uint8_t i = 0;
	uint8_t x = 0;
	uint8_t y = 0;
	
	for(x = 0; x<5; x++){
		for(y = 0; y<5; y++){
			maps[0].data[i] = level1[y][x];
			i++;
		}
	}

	uint8_t level2[7][7] = {{1,1,1,1,1,1,1},
							{1,3,0,0,0,0,1},
							{1,0,0,0,0,0,1},
							{1,0,0,2,0,0,1},
							{1,0,0,0,0,0,1},
							{1,0,0,0,0,4,1},
							{1,1,1,1,1,1,1}};
	maps[1].length = 7;
	maps[1].width = 7;
	maps[1].data = malloc(sizeof(uint8_t)*7*7);
	i = 0;
	for(x = 0; x<7; x++){
		for(y = 0; y<7; y++){
			maps[1].data[i] = level2[y][x];
			i++;
		}
	}
	
	uint8_t level3[7][7] = {{1,1,1,1,1,1,1},
							{1,0,2,0,1,0,1},
							{1,3,2,0,0,0,1},
							{1,0,2,0,1,0,1},
							{1,1,1,1,1,0,1},
							{1,4,0,0,0,2,1},
							{1,1,1,1,1,1,1}};
	maps[2].length = 7;
	maps[2].width = 7;
	maps[2].data = malloc(sizeof(uint8_t)*7*7);
	i = 0;
	for(x = 0; x<7; x++){
		for(y = 0; y<7; y++){
			maps[2].data[i] = level3[y][x];
			i++;
		}
	}

}

struct Map map_loadLevel(uint8_t level)
{
	return maps[level];
}