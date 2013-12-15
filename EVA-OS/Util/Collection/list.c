/*
 * list.c
 *
 * Created: 12/4/2013 10:54:05 AM
 *  Author: Elmar
 */ 
#include <Util/Collection/list.h>

List * newList()
{
	List * list = malloc(sizeof(List));
	list->head = malloc(sizeof(Node));
	list->head->data = NULL;
	list->head->nextNode = NULL;
	list->head->prevNode = NULL;
	list->tail = list->head;
	list->size = 0;
	return list;
}

void list_clear(List * list)
{
	Node * tempNode = list->head;
	Node * nextNode = tempNode->nextNode;
	while(tempNode->nextNode != NULL) {
		list_remove(list, tempNode->data);
		tempNode = nextNode;
		nextNode = tempNode->nextNode;
	}
}

void list_add(List * list, void * data)
{			
	list->tail->data = data;
	list->size++;
	list->tail->nextNode = malloc(sizeof(Node));
	list->tail->nextNode->prevNode = list->tail;
	list->tail = list->tail->nextNode;
	list->tail->nextNode = NULL;				
}

uint8_t list_remove(List * list, void * data)
{
	Node * tempNode = list->head;
	while(tempNode->nextNode != NULL){
		if(tempNode->data == data){
			if(tempNode->prevNode != NULL){
				tempNode->prevNode->nextNode = tempNode->nextNode;
			} else{
				list->head = tempNode->nextNode;
			}
			tempNode->nextNode->prevNode = tempNode->prevNode;
			list->size--;
			free(tempNode);
			return 1;
		}
		tempNode = tempNode->nextNode;
	}
	return 0;
}

void list_removeCurrent(List * list)
{
	list_remove(list,list->current);
}

void * list_next(List * list)
{
	if(list->current->nextNode == NULL){
		return NULL;				// no data
	}
	list->current = list->current->nextNode;
	return list->current->data;
}


void * list_prev(List * list)
{
	if(list->current->prevNode == NULL){
		return NULL;			//Start of array
	}
	list->current = list->current->prevNode;
	return list->current->data;
}

void list_startItterate(List * list)
{
	list->current = list->head; 
}

void * list_get(List * list, uint8_t index)
{
	uint8_t tempI = 0;
	Node * tempNode = list->head;
	while(tempNode->nextNode != NULL){
		if(tempI == index)
			return tempNode->data;
		tempI++;
		tempNode = tempNode->nextNode;
	}
	return NULL;
}

void list_addAll( List * addTo, List * addFrom)
{
	Node * tempNode = addFrom->head;
	while(tempNode->nextNode!=NULL){
		list_add(addTo, tempNode->data);
		tempNode = tempNode->nextNode;
	}
}

void list_removeAll(List * removeFrom, List * removalList)
{
	Node * tempNode = removalList->head;
	while(tempNode->nextNode!=NULL){
		list_remove(removeFrom, tempNode->data);
		tempNode = tempNode->nextNode;
	}
}

/*
1
-----	
N|N|?
-----
C = N
P = 1

1
-----
N|D|2
-----
2
-----
P|N|?
-----
C = N
P = 2









*/