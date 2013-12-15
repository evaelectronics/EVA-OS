/*
 * entityManager.c
 *
 * Created: 12/7/2013 2:07:17 AM
 *  Author: Elmar
 */ 

static void * newEntity(EntityManager * entityManager);

void * newEntityManager()
{
	EntityManager * entityManager = malloc(sizeof(EntityManager));
	entityManager->entityId = 0;
	entityManager->entitySize = 0;
	entityManager->newEntity = newEntity;
	return entityManager;
}

static void * newEntity(EntityManager * entityManager)
{
	Entity * entity = malloc(sizeof(Entity));
	if(entity == NULL){
		//TODO CRASH
		return NULL;
	}
	entity->alive = 1;
	entity->id = entityManager->entityId++;
	entity->destructor == NULL;
	entity->xPos = 0;
	entity->yPos = 0;
	entity->update = NULL;
	entity->draw = NULL;
	return entity;
}