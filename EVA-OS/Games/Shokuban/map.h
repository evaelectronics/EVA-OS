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
	uint8_t length;
	uint8_t width;
};

void map_loadMaps();
struct Map map_loadLevel(uint8_t level);

							

#endif /* MAP_H_ */