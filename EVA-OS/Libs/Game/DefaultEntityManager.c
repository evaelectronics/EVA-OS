/*
 * DefaultEntityManager.c
 *
 * Created: 12/2/2013 12:34:24 PM
 *  Author: Elmar
 */ 

/*

start
---
0|?
---

add entity
---   ----
E|N-->0|?
---   ----

add entity
---   ----  ---   
E|N-->E|N-->0|?
---   ----  ---   

remove entity
---   ----
E|N-->0|?
---   ----  
*/

#include <Libs/Game/DefaultEntityManager.h>

/*! \brief this is the DefaultEntityManager own's implementation of the update entities method
 *	\param [in]	entityManager The entity manager used. A reference is given here for easy entity aces
 *  \param [in] gameDetails Gamedetails are given here, these are used for updating an entity (contains input methods etc)     
 */
static void updateEntities(EntityManager * entityManager, GameDetails * gameDetails);
/*! \brief this is the DefaultEntityManager own's implementation to add entities
 *	\param [in]	entityManager The entity manager used. A reference is given here for easy entity access
 *  \param [in] newEntity this is a pointer to the new entity just made, possible to cast to an Entity
 *	Specifics about this implementation: adding an entity to the end of the list is fast. Adding an entity in
 *  the middle of the list is same speed as iterating. Also requires 1 empty entity to be available at
 *	all time (automated).  
 */
static void addEntity(EntityManager * entityManager, void * newEntity);
/*! \brief this is the DefaultEntityManager own's implementation of the getEntity method
 *	\param [in]	entityManager The entity manager used. A reference is given here for easy entity access
 *  \param [in] x the x vector
 *  \param [in] y the y vector
 *	\retval the first entity in the list with the same x and y vector     
 */
static void * getEntity(EntityManager * entityManager, uint16_t x, uint16_t y);
/*! \brief this is the DefaultEntityManager own's implementation of the clear method
 *	\param [in]	entityManager The entity manager used. A reference is given here for easy entity access 
 *	removes all the entities, and initializes the list again
 */
static void clear(EntityManager * entityManager);
/*! \brief this is the DefaultEntityManager own's implementation of the removeEntity method
 *	\param [in]	entityManager The entity manager used. A reference is given here for easy entity access
 *  \param [in] oldEntity pointer to the entity to be removed given     
 */
static uint8_t removeEntity(EntityManager * entityManager, void * oldEntity);


void * defaultManager_constructor(uint16_t maxSize)
{
	EntityManager * entityManager = malloc(sizeof(EntityManager));
	entityManager->entityId = 1;
	entityManager->entitySize = 0;
	entityManager->entityList = newList();
	entityManager->updateEntities = updateEntities;
	entityManager->addEntity = addEntity;
	entityManager->getEntity = getEntity;
	entityManager->removeEntity = removeEntity;
	entityManager->clear = clear;
	return entityManager;
}

static void updateEntities(EntityManager * entityManager, GameDetails * gameDetails)
{
	if(entityManager->entityList->size>0){
		Entity * entity;
		list_startItterate(entityManager->entityList);
		while((entity = (Entity *) list_next(entityManager->entityList)) != NULL){
			if(entity->update != NULL){
				entity->update(gameDetails,entity,gameDetails->deltaT);
			}
			if(entity->draw != NULL){
				entity->draw(gameDetails,entity);
			}
			if(entity->alive == 0){
				if(entity->destructor != NULL){
					entity->destructor(entity);
				}
				list_removeCurrent(entityManager->entityList);
			}
		}
	}
}

static void addEntity(EntityManager * entityManager, void * newEntity)
{
	Entity * entity = (Entity *) newEntity;
	entity->id = ++entityManager->entityId;
	entity->alive = 1;
	list_add(entityManager->entityList, newEntity);
}

static void * getEntity(EntityManager * entityManager, uint16_t x, uint16_t y)
{
	list_startItterate(entityManager->entityList);
	Entity * entity;
	while((entity = (Entity *) list_next(entityManager->entityList))!=NULL){
		if(entity->xPos == x && entity->yPos == y){
			return entity;
		}
	}
	return NULL;
}

static void clear(EntityManager * entityManager)
{
	list_startItterate(entityManager->entityList);
	Entity * entity;
	while((entity = (Entity *) list_next(entityManager->entityList))!=NULL){
		if(entity->destructor != NULL){
			entity->destructor(entity);
		}
		free(entity);
	}
	list_clear(entityManager->entityList);
}

static uint8_t removeEntity(EntityManager * entityManager, void * oldEntity)
{
	Entity * entity = (Entity *) oldEntity;
	entity->alive = 0;
	return 1;	
}