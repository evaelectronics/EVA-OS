/*
 * DefaultEntityManager.c
 *
 * Created: 12/2/2013 12:34:24 PM
 *  Author: Elmar
 */ 

#include <Libs/Game/DefaultEntityManager.h>

static void updateEntities(EntityManager * entityManager, GameDetails * gameDetails);
static void addEntity(EntityManager * entityManager, void * newEntity);
static void * getEntity(EntityManager * entityManager, uint16_t x, uint16_t y);
static uint8_t removeEntity(EntityManager * entityManager, void * oldEntity);


EntityManager * defaultManager_constructor(uint16_t maxSize)
{
	EntityManager * entityManager = malloc(sizeof(EntityManager));
	entityManager->entityId = 1;
	entityManager->entitySize = 0;
	entityManager->entityListRoot = malloc(sizeof(struct EntityList));
	entityManager->entityListRoot->entity = NULL;
	entityManager->entityListRoot->nextEntity = NULL;
	entityManager->entityListEnd = entityManager->entityListRoot;
	entityManager->updateEntities = updateEntities;
	entityManager->addEntity = addEntity;
	entityManager->getEntity = getEntity;
	entityManager->removeEntity = removeEntity;
	return entityManager;
}

static void updateEntities(EntityManager * entityManager, GameDetails * gameDetails)
{
	struct EntityList * currentNode = entityManager->entityListRoot;
	while(currentNode->entity != NULL){
		if(currentNode->entity->update != NULL){
			currentNode->entity->update(gameDetails, currentNode->entity, gameDetails->deltaT);
		}
		if(currentNode->entity->draw != NULL){
			currentNode->entity->draw(gameDetails, currentNode->entity);
		}
		if(currentNode->entity->alive == 0){
			if(currentNode->entity->destructor != NULL){
				currentNode->entity->destructor(currentNode->entity);
			}
			removeEntity(entityManager, currentNode->entity);
		}
		currentNode = currentNode->nextEntity;
	}
}

static void addEntity(EntityManager * entityManager, void * newEntity)
{
	entityManager->entityListEnd->entity = newEntity;
	entityManager->entityListEnd->nextEntity = malloc(sizeof(struct EntityList));
	entityManager->entityListEnd = entityManager->entityListEnd->nextEntity;
	entityManager->entityListEnd->entity = NULL;
}

static void * getEntity(EntityManager * entityManager, uint16_t x, uint16_t y)
{
	struct EntityList * currentNode = entityManager->entityListRoot;
	while(currentNode->nextEntity != NULL){
		if(currentNode->entity->xPos == x && currentNode->entity->yPos == y){
			return currentNode->entity;
		}
		currentNode = currentNode->nextEntity;
	}
	return NULL;
}

static void clear(EntityManager * entityManager)
{
	struct EntityList * currentNode = entityManager->entityListRoot;
	struct EntityList * tempNode;

	while(currentNode->entity != NULL){
		if(currentNode->entity->destructor!=NULL)
			currentNode->entity->destructor(currentNode->entity);
		free(currentNode->entity);
		
		tempNode = currentNode->nextEntity;
		free(currentNode);
		currentNode = tempNode;
	}
	entityManager->entityListRoot = malloc(sizeof(EntityList));
	entityManager->entityListRoot->entity = NULL;
	entityManager->entityListEnd = entityManager->entityListRoot;
}

static uint8_t removeEntity(EntityManager * entityManager, void * oldEntity)
{
	struct EntityList * currentNode = entityManager->entityListRoot;
	while(currentNode->entity != NULL){
		if(currentNode->entity == (Entity*)oldEntity){
			currentNode->entity->destructor(currentNode->entity);
			free(currentNode->entity);
			//Free the node TODO
		}
		currentNode = currentNode->nextEntity;
	}
	return 0;	
}
/*

start
---
0|0
---

add entity
---   ----
E|N-->0|0
---   ----

add entity
---   ----  ---   
E|N-->E|N-->0|0
---   ----  ---   

add entity
---   ----  ---   ----
E|N-->E|N-->E|N-->0|0
---   ----  ---   ----
*/