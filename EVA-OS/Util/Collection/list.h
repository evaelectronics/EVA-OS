/*
 * list.h
 *
 * Created: 12/4/2013 10:54:14 AM
 *  Author: Elmar
 */ 


#ifndef LIST_H_
#define LIST_H_

#include <Libs/System/systemservice.h>

typedef struct List List;
typedef struct Node Node;

struct List{
	struct Node * head;
	struct Node * tail;
	uint32_t size;
	Node * current;
};

struct Node{
	void * data;
	struct Node * nextNode;
	struct Node * prevNode;
};

List * newList();

void list_add(List * list, void * data);
void list_addAll( List * addTo, List * addFrom);

uint8_t list_remove(List * list, void * data);
void list_removeAll(List * removeFrom, List * removalList);
void list_clear(List * list);

void * list_next(List * list);
void * list_prev(List * list);

void list_startItterate(List * list);
void list_removeCurrent(List * list);

void * list_get(List * list, uint8_t index);

#endif /* LIST_H_ */