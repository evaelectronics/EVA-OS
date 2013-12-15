/*
 * Map.h
 *
 * Created: 12/2/2013 12:56:03 AM
 *  Author: Elmar
 */ 


#ifndef MAP_H_
#define MAP_H_

#include <Libs/System/systemservice.h>

struct Map{
	uint8_t * data;
	uint8_t height;
	uint8_t width;
	uint8_t type;
};

void map_loadMaps();
struct Map * map_loadLevel(uint8_t level);
struct Map * map_currentLevel();
							

#endif /* MAP_H_ */