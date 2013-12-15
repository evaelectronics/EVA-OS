/*
 * syncEntityManager.h
 *
 * Created: 12/3/2013 11:04:52 PM
 *  Author: Elmar
 */ 


#ifndef SYNCENTITYMANAGER_H_
#define SYNCENTITYMANAGER_H_

#include <Libs/Game/game.h>

typedef struct SyncManager SyncManager;

/*! 
 * A structure to wrap the entity manager in. Special features can be added here.
 */
struct SyncManager{
	/* @{ */
	EntityManager manager; /*!< the entity manager struct. This is necesary for all entity managers */
	uint16_t maxSize;	   /*!< manager specific variables here. This one has a max amount of entities */
	List * removeList;	   /*!< list containing all the entities to remove. TODO REPLACE WITH QUEUE */
	List * addList;		   /*!< list containing all the entities to add upon next update. TODO REPLACE WITH QUEUE */
};

/*!  */

/*! \brief this Function is used to obtain a new constructor and to initialize it as well. It is required for every entity manager
 *	\param [in]	maxSize The maximum amount of entities to be active at once.     
 *  \retval it will return a pointer to the place where the manager is made.	
 */
void * syncManager_constructor(uint16_t maxSize);



#endif /* SYNCENTITYMANAGER_H_ */