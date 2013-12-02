/*
 * DefaultEntityManager.h
 *
 * Created: 12/2/2013 1:47:26 PM
 *  Author: Elmar
 */ 


#ifndef DEFAULTENTITYMANAGER_H_
#define DEFAULTENTITYMANAGER_H_

#include <Libs/Game/game.h>

struct DefaultManager{
	EntityManager manager;
	uint16_t maxSize;	
};

EntityManager * defaultManager_constructor(uint16_t maxSize);

#endif /* DEFAULTENTITYMANAGER_H_ */