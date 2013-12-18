/*
 * dynamicList.c
 *
 * Created: 12/3/2013 11:26:09 PM
 *  Author: Elmar
 */ 

static void add(DynamicList * dynamicList, void * data);
static void * get(DynamicList * dynamicList, uint8_t index);
static void remove(DynamicList * dynamicList, uint8_t index);
static void clear(DynamicList * dynamicList);

DynamicList * newDynamicList(uint8_t size)
{
	DynamicList * dynamicList = malloc(sizeof(DynamicList));
	dynamicList->size = 0;
	
	dynamicList->dataStart = malloc(sizeof(struct ListNode));
	dynamicList->dataEnd = dynamicList->dataStart;
	dynamicList->dataStart->data = NULL;
	dynamicList->dataStart->previous = NULL;	
	
	dynamicList->add = add;
	dynamicList->get = get;
	dynamicList->remove = remove;
	dynamicList->clear = clear;
}

static void add(DynamicList * dynamicList, void * data)
{
	dynamicList->dataEnd->data = data;
	dynamicList->dataEnd->next = malloc(sizeof(ListNode));
	dynamicList->dataEnd->next->previous = dynamicList->dataEnd;
	dynamicList->dataEnd = dynamicList->dataEnd->next;
	dynamicList->dataEnd->data = NULL;
}

static void * get(DynamicList * dynamicList, uint8_t index)
{
	uint8_t temp = 0;
	struct ListNode * tempNode = dynamicList->dataStart;
	while (tempNode->data != NULL){
		if(temp == index) {
			return tempNode->data;
		}
		tempNode = tempNode->next;
		temp++;
	}
	return NULL;
}

static void remove(DynamicList * dynamicList, uint8_t index)
{
	uint8_t temp = 0;
	struct ListNode * tempNode = dynamicList->dataStart, *removalNode;
	while (tempNode->data != NULL){
		if(temp == index) {
			removalNode = tempNode;
			if(removalNode->previous == NULL){
				removalNode->next->previous = NULL;
			}else{
				removalNode->next->previous = removalNode->previous;
			}
			if(removalNode->next == NULL){
				removalNode->previous->next = NULL;
			}else{
				removalNode->previous->next = removalNode->next;
			}
			free(tempNode);
			break;
		} else {
			tempNode = tempNode->next;
			temp++;
		}
	}
}

static void clear(DynamicList * dynamicList)
{
	struct ListNode * tempNode = dynamicList->dataStart, *removalNode;
	while (tempNode->data != NULL){
		removalNode = tempNode;
		free(tempNode);
		
		tempNode = tempNode->next;
		temp++;
		}
	}
}

void dynamicList_startItterate(DynamicList * dynamicList)
{
	dynamicList->itterateNext = dynamicList->dataStart;
}

void * dynamicList_nextItem(DynamicList * dynamicList)
{
	void * data = dynamicList->itterateNext->data;
	dynamicList->itterateNext = dynamicList->itterateNext->next;
	return data;
}