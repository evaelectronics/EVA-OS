/*
 * arrayList.h
 *
 * Created: 12/3/2013 11:19:55 PM
 *  Author: Elmar
 */ 


#ifndef ARRAYLIST_H_
#define ARRAYLIST_H_

typedef DynamicList DynamicList;

struct DynamicList{
	struct ListNode * dataStart;
	struct ListNode * dataEnd;
	struct ListNode * itterateNext;	uint8_t size;
	void (*clear)(DynamicList *);
	void (*add) (DynamicList *, void *);
	void * (*get)(DynamicList *, uint8_t);
	void (*remove)(DynamicList *);
};

struct ListNode{
	void * data;
	struct ListNode * next;
	struct ListNode * previous;
};

DynamicList * newDynamicList(uint8_t size);


#endif /* ARRAYLIST_H_ */