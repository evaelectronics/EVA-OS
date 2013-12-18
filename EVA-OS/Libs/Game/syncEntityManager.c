/*
 * syncEntityManager.c
 *
 * Created: 12/3/2013 11:04:41 PM
 *  Author: Elmar
 */ 


#include <Libs/Game/syncEntityManager.h>

/*! \brief this is the DefaultEntityManager own's implementation of the update entities method
 *	\param [in]	entityManager The entity manager used. A reference is given here for easy entity access
 *  \param [in] gameDetails Gamedetails are given here, these are used for updating an entity (contains input methods etc)     
 *	In this case the update entities function also adds all the entities in the add list, and removes entities in the remove list
 */
static void updateEntities(EntityManager * entityManager, GameDetails * gameDetails);

/*! \brief this is the DefaultEntityManager own's implementation to add entities
 *	\param [in]	entityManager The entity manager used. A reference is given here for easy entity access
 *  \param [in] newEntity this is a pointer to the new entity just made, possible to cast to an Entity
 *	Specifics about this implementation: the goal of this entity manager is compatibility and ease over use
 *	over speed. Entities are added synchronous and at the start of an update. If the user adds an entity
 *	it will be added to a list  
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
 *	removes all the entities, and initializes the list again. This function is synchronous and is safe
 *  to use. It will add all the entities to the remove list, which results in the removal of all the entities
 *	once the entity manager is done updating them. This eliminates the problem that one entity points to an 
 *	already removed entity.
 */
static void clear(EntityManager * entityManager);

/*! \brief this is the DefaultEntityManager own's implementation of the removeEntity method
 *	\param [in]	entityManager The entity manager used. A reference is given here for easy entity access
 *  \param [in] oldEntity pointer to the entity to be removed given   
 *	removes an object in the list with the same memory as given
 */
static uint8_t removeEntity(EntityManager * entityManager, void * oldEntity);

/*! \brief this is the DefaultEntityManager own's implementation of the removeIndex method
 *	\param [in]	entityManager The entity manager used. A reference is given here for easy entity access
 *  \param [in] index the index of the object. 
 *	removes the Nth object in the list where N is given by index
 */
static uint8_t removeIndex(EntityManager * entityManager, uint8_t index);

void * syncManager_constructor(uint16_t maxSize)
{
	SyncManager * syncManager = malloc(sizeof(SyncManager));
	syncManager->addList = newList();
	syncManager->removeList = newList();

	syncManager->manager.entityId = 1;
	syncManager->manager.entitySize = 0;
	syncManager->manager.entityList = newList();
	
	syncManager->manager.updateEntities = updateEntities;
	syncManager->manager.addEntity = addEntity;
	syncManager->manager.getEntity = getEntity;
	syncManager->manager.removeEntity = removeEntity;
	syncManager->manager.removeIndex = removeIndex;
	syncManager->manager.clear = clear;
	
	return syncManager;
}

static void updateEntities(EntityManager * entityManager, GameDetails * gameDetails)
{
	SyncManager * sync = (SyncManager *) entityManager;
	Entity * entity;
	Node * tempNode;
		
	if(sync->addList->size>0){
		list_addAll(entityManager->entityList, sync->addList);
		list_clear(sync->addList);
	}
	
	if(entityManager->entityList->size>0){
		tempNode = entityManager->entityList->head;
		while(tempNode->nextNode != NULL){
			entity = (Entity *) tempNode->data;
			if(entity != NULL){
				entity->update(gameDetails,entity,gameDetails->deltaT);
				entity->draw(gameDetails,entity);
				if(entity->alive == 0){
					entityManager->removeEntity(entityManager,entity);
				}
			}
			tempNode = tempNode->nextNode;
		}
	}
	
	if(sync->removeList->size>0){
		tempNode = entityManager->entityList->head;
		while(tempNode->nextNode != NULL){
			entity = (Entity *) tempNode->data;
			if(entity != NULL){
				entity->destructor(entity);
			}
			tempNode = tempNode->nextNode;
		}
		list_removeAll(entityManager->entityList, sync->removeList);
		list_clear(sync->removeList);
	}
}

static void addEntity(EntityManager * entityManager, void * newEntity)
{
	SyncManager * sync = (SyncManager *) entityManager;
	Entity * entity = (Entity *) newEntity;
	entity->id = ++entityManager->entityId;
	entity->alive = 1;
	list_add(sync->addList, newEntity);
}

static void * getEntity(EntityManager * entityManager, uint16_t x, uint16_t y)
{
	Node * tempNode = entityManager->entityList->head;
	Entity * entity;
	while(tempNode->nextNode != NULL){
		entity = (Entity *) tempNode->data;
		if(entity != NULL){
			if(entity->xPos == x && entity->yPos == y){
				return entity;
			}
		}
		tempNode = tempNode->nextNode;
	}
	return NULL;
}

static void clear(EntityManager * entityManager)
{
	SyncManager * sync = (SyncManager *) entityManager;
	list_addAll(sync->removeList,entityManager->entityList);
}

static uint8_t removeEntity(EntityManager * entityManager, void * oldEntity)
{
	SyncManager * sync = (SyncManager *) entityManager;
	list_add(sync->removeList, oldEntity);
	return 1;	
}

static uint8_t removeIndex(EntityManager * entityManager, uint8_t index)
{
	SyncManager * sync = (SyncManager *) entityManager;
	list_add(sync->removeList, list_get(entityManager->entityList,index));
	return 1;
}
