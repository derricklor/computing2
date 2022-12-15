#include <stdio.h>
#include <stdlib.h>
#include "queue.h"



struct node;
typedef struct node Node;
struct node
{
	int data;
	char c;
	Node* next;
};

struct queue;
typedef struct queue Queue;
struct queue
{
	int size;
	Node* front;
	Node* last;
};


QUEUE queue_init_default(void)
{
	Queue* pQ;
	pQ = (Queue*)malloc(sizeof(Queue));
	if (pQ != NULL)
	{
		pQ->size = 0;
		pQ->front = NULL;
		pQ->last = NULL;

	}
	return (QUEUE)pQ;
}

//add item to end of queue, size++
Status queue_enqueue(QUEUE hQ, int item, char sideOfRiver)
{
	Queue* pQ = (Queue*)hQ;
	Node* pTemp;


	pTemp = (Node*)malloc(sizeof(Node));
	if (pTemp == NULL)
	{
		printf("Failed to allocate space for new node\n");
		return FAILURE;
	}

	//give pTemp values
	pTemp->data = item;
	pTemp->c = sideOfRiver;
	pTemp->next = NULL;

	//init case only at beginning
	if (pQ->last == NULL)
	{
		pQ->front = pTemp;
		pQ->last = pTemp;
	}

	//middle case
	//change last item in queue to point to the new pTemp
	pQ->last->next = pTemp;
	//set the new pTemp to be the last item
	pQ->last = pTemp;

	pQ->size++;
	return SUCCESS;
}

//remove node at front of queue, move front to next node, size--
Status queue_service(QUEUE hQ)
{
	Queue* pQ = (Queue*)hQ;
	if (queue_empty(hQ))
	{
		return FAILURE;
	}

	//set front to be front's next
	pQ->front = pQ->front->next;
	pQ->size--;
	return SUCCESS;
}

//returns true if size is less than or equal to 0, else return false
Boolean queue_empty(QUEUE hQ)
{
	Queue* pQ = (Queue*)hQ;

	return (Boolean)(pQ->size <= 0);
}

//returns the front's integer
int queue_front_int(QUEUE hQ)
{
	Queue* pQ = (Queue*)hQ;
	if (queue_empty(hQ))
	{

		return -1337;
	}

	return pQ->front->data;
}

//returns the front's char
char queue_front_char(QUEUE hQ)
{
	Queue* pQ = (Queue*)hQ;
	if (queue_empty(hQ))
	{

		return -1337;
	}

	return pQ->front->c;
}

void queue_destroy(QUEUE* phQueue)
{
	Queue* pQ = (Queue*)*phQueue;
	free(pQ->front);
	free(pQ);
	*phQueue = NULL;
}