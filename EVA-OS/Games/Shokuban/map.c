/* 
 * map.c
 *
 * Created: 12/3/2013 12:38:06 AM
 *  Author: Elmar
 */ 

#include <Games/Shokuban/map.h>

static struct Map * maps;

void map_loadMaps()
{
	maps = malloc(sizeof(struct Map));
	maps->data = malloc(sizeof(uint8_t));
}

struct Map * map_currentLevel()
{
	return maps;
}

struct Map * map_loadLevel(uint8_t level)
{
	free(maps->data);
	uint8_t x = 0;
	uint8_t y = 0;
	uint8_t i = 0;
	if(level == 1){
		uint8_t level1[5][5] = {{1,1,1,1,1},
								{1,3,0,0,1},
								{1,0,2,0,1},
								{1,0,0,4,1},
								{1,1,1,1,1}};
		maps->width = 5;
		maps->height = 5;
		maps->type = 1;
		maps->data = malloc(sizeof(uint8_t)*maps->width*maps->height);
		for (x = 0; x<maps->width; x++)	{
			for(y = 0; y<maps->height; y++){
				maps->data[i] = level1[x][y];
				i++;
			}
		}
	}else if(level == 2){
		uint8_t level2[7][7] = {{1,1,1,1,1,1,1},
								{1,3,0,0,0,0,1},
								{1,0,0,0,0,0,1},
								{1,0,0,2,0,0,1},
								{1,0,0,0,0,0,1},
								{1,0,0,0,0,4,1},
								{1,1,1,1,1,1,1}};
		maps->width = 7;
		maps->height = 7;
		maps->type = 1;
		maps->data = malloc(sizeof(uint8_t)*maps->width*maps->height);
		for (x = 0; x<maps->width; x++)	{
			for(y = 0; y<maps->height; y++){
				maps->data[i] = level2[x][y];
				i++;
			}
		}
	} else if(level == 3) {
		uint8_t level3[7][7] = {{1,1,1,1,1,1,1},
								{1,0,2,0,1,0,1},
								{1,3,2,0,0,0,1},
								{1,0,2,0,1,0,1},
								{1,1,1,1,1,0,1},
								{1,4,0,0,2,0,1},
								{1,1,1,1,1,1,1}};
		maps->width = 7;
		maps->height = 7;
		maps->type = 1;
		maps->data = malloc(sizeof(uint8_t)*maps->width*maps->height);
		for (x = 0; x<maps->width; x++)	{
			for(y = 0; y<maps->height; y++){
				maps->data[i] = level3[x][y];
				i++;
			}
		}
	}else{
		uint8_t level1[5][5] = {{1,1,1,1,1},
								{1,3,0,0,1},
								{1,0,2,0,1},
								{1,0,0,4,1},
								{1,1,1,1,1}};
		maps->width = 5;
		maps->height = 5;
		maps->type = 1;
		maps->data = malloc(sizeof(uint8_t)*maps->width*maps->height);
		for (x = 0; x<maps->width; x++)	{
			for(y = 0; y<maps->height; y++){
				maps->data[i] = level1[x][y];
				i++;
			}
		}
	}	
	return maps;
}