/*
 * queue.c
 *
 * Created: 12/4/2013 2:38:38 PM
 *  Author: Elmar
 */ 

#include <Util/Collection/queue.h>

Queue * newQueue()
{
	Queue * queue = malloc(sizeof(Queue));
	queue = newList();
	return queue;
}

void * queue_peek(Queue * queue)
{
	return list_get(queue, 0);
}

void * queue_pop(Queue * queue)
{
	void * data = list_get(queue, 0);
	list_remove(queue, data);
	return data;
}

void queue_push(Queue * queue, void * data)
{
	list_add(queue,data);
}

//pop
//push