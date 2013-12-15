/*
 * DefaultEntityManager.h
 *
 * Created: 12/2/2013 1:47:26 PM
 *  Author: Elmar
 */ 


#ifndef DEFAULTENTITYMANAGER_H_
#define DEFAULTENTITYMANAGER_H_

#include <Libs/Game/game.h>

/*! 
 * A structure to wrap the entity manager in. Special features can be added here.
 */
struct DefaultManager{
	/* @{ */
	EntityManager manager; /*!< the entity manager struct. This is necesary for all entity managers */
	uint16_t maxSize; /*!< manager specific variables here. This one has a max amount of entities */
};

/*!  */

/*! \brief this Function is used to obtain a new constructor and to initialize it as well. It is required for every entity manager
 *	\param [in]	maxSize The maximum amount of entities to be active at once.     
 *  \retval it will return a pointer to the place where the manager is made.	
 */
void * defaultManager_constructor(uint16_t maxSize);

#endif /* DEFAULTENTITYMANAGER_H_ */