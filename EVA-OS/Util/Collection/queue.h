/*
 * queue.h
 *
 * Created: 12/4/2013 2:38:29 PM
 *  Author: Elmar
 */ 


#ifndef QUEUE_H_
#define QUEUE_H_

#include <Util/Collection/list.h>

typedef List Queue;

Queue * newQueue();
void queue_push(Queue * queue, void * data);
void * queue_peek(Queue * queue);
void * queue_pop(Queue * queue);

#endif /* QUEUE_H_ */