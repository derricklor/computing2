#include <stdio.h>
#include <stdlib.h>
#include "priority_queue.h"

struct pair
{
	int priority;
	int value;
};
typedef struct pair Pair;

struct priority_queue
{
	int size;
	int capacity;
	int front;
	int back;
	Pair* data;
};
typedef struct priority_queue Priority_queue;

PRIORITY_QUEUE priority_queue_init_default(void)
{
	Priority_queue* pPriority_queue;
	pPriority_queue = (Priority_queue*)malloc(sizeof(Priority_queue));
	if (pPriority_queue != NULL)
	{
		pPriority_queue->size = 0;
		pPriority_queue->capacity = 1;
		pPriority_queue->front = 0;
		pPriority_queue->back = 0;
		pPriority_queue->data = (Pair*)malloc(sizeof(Pair)*pPriority_queue->capacity);
		if (pPriority_queue->data == NULL)
		{
			free(pPriority_queue);
			pPriority_queue = NULL;
		}
	}
	return pPriority_queue;
}

Status priority_queue_insert(PRIORITY_QUEUE hQueue, int priority_level, int data_item)
{
	//cast to known type
	Priority_queue* pPriority_queue = (Priority_queue*)hQueue;
	Pair* pTemp, pTemp2;
	int n, index;
	//if size is greater or equal to capacity, then double capacity
	//malloc new memory, free old memory
	if (pPriority_queue->size >= pPriority_queue->capacity)
	{
		pTemp = (Pair*)malloc(sizeof(Pair) * 2 * pPriority_queue->capacity);//double capacity
		if (pTemp == NULL)//check if failed
		{
			printf("Failure to allocate\n");
			return FAILURE;
		}
		//copy old data in queue to temp
		for (n = 0; n < pPriority_queue->size; n++)
		{
			pTemp[n] = pPriority_queue->data[n];
		}

		pPriority_queue->capacity *= 2;//double capacity
		free(pPriority_queue->data);//free old
		pPriority_queue->data = pTemp;//give it new
	}

	n = pPriority_queue->size;//n is index of child
	(pPriority_queue->data[n]).priority = priority_level;//assign new values to priority
	(pPriority_queue->data[n]).value = data_item;//assign new values to value

	//try
	index = (n - 1) / 2;//index of parent is (n-1)/2

	//if priority of child is greater than priority of parent, swap them
	while (n >= 1 && ((pPriority_queue->data[n]).priority > (pPriority_queue->data[index]).priority))//check
	{
		//do myswap function
		pTemp2 = pPriority_queue->data[index];
		pPriority_queue->data[index] = pPriority_queue->data[n];
		pPriority_queue->data[n] = pTemp2;

		//try again
		n = index;//assign parent index to child index
		index = (n - 1) / 2;//find new parent index
	}
	pPriority_queue->size++;//increase size
	pPriority_queue->front = 0;
	pPriority_queue->back = pPriority_queue->size - 1;
	return SUCCESS;
}

Status priority_queue_service(PRIORITY_QUEUE hQueue)
{
	//cast to known type
	Priority_queue* pPriority_queue = (Priority_queue*)hQueue;

	int n = 0, flag = 1;
	//heap has the complete tree property
	int left_index = 2 * n + 1;//index of left child 
	int right_index = 2 * n + 2;//right is 1 index bigger

	Pair* pTemp = (Pair*)malloc(sizeof(Pair));;
	Pair* pTemp2 = (Pair*)malloc(sizeof(Pair));;

	if (pTemp == NULL || pTemp2 == NULL)
	{
		printf("Failure to allocate\n");
		exit(1);
	}
	//check if queue is empty
	if (priority_queue_is_empty(pPriority_queue))
	{
		printf("Queue is empty, cannot service!\n");
		return FAILURE;
	}
	//swap max pair with a leaf pair
	*pTemp = pPriority_queue->data[0];
	pPriority_queue->data[0] = pPriority_queue->data[pPriority_queue->back];
	pPriority_queue->data[pPriority_queue->back] = *pTemp;
	pPriority_queue->size--;//decrease size

	//call fix down
	//flag means there is a pair not in order
	//while index of left child is less than size of queue and flag is 1- it hasn't finished fixing down and there is still a problem
	while (left_index < pPriority_queue->size && flag == 1)
	{
		flag = 0;
		//and index of right child is less than size of queue - it hasn't finished fixing down
		//and right child's priority is greater than left child's
		if (right_index < pPriority_queue->size &&
			(pPriority_queue->data[right_index]).priority >
			(pPriority_queue->data[left_index]).priority)
		{
			//and right child's priority is greater than parent's priority
			if ((pPriority_queue->data[right_index]).priority > (pPriority_queue->data[n]).priority)
			{
				//swap right child with the parent
				*pTemp2 = pPriority_queue->data[n];
				pPriority_queue->data[n] = pPriority_queue->data[right_index];
				pPriority_queue->data[right_index] = *pTemp2;

				n = right_index;//set index of right child to be new parent
				left_index = 2 * n + 1;//get new index of left child 
				right_index = 2 * n + 2;//right is 1 index bigger
				flag = 1;//there is still a problem
			}
		}
		else
		{
			//priority of left child is greater than priority of parent
			if ((pPriority_queue->data[left_index]).priority > (pPriority_queue->data[n]).priority)
			{
				//swap left child with parent
				*pTemp2 = pPriority_queue->data[n];
				pPriority_queue->data[n] = pPriority_queue->data[left_index];
				pPriority_queue->data[left_index] = *pTemp2;

				n = left_index;//set index of left child to be new parent
				left_index = 2 * n + 1;//get new index of left child 
				right_index = 2 * n + 2;//right is 1 index bigger
				flag = 1;//there is still a problem
			}
		}
		//only after the index of left child and index of right child is greater than size of queue
		//are we done fixing down
	}

	pPriority_queue->back = pPriority_queue->size - 1;

	return SUCCESS;

}
int priority_queue_front(PRIORITY_QUEUE hQueue, Status* pStatus)
{
	//cast to known type
	Priority_queue* pPriority_queue = (Priority_queue*)hQueue;
	//ignore status if NULL is passed in
	if (priority_queue_is_empty(pPriority_queue))//queue is empty
	{
		if (pStatus != NULL)
		{
			*pStatus = FAILURE;
		}
		return 0;
	}
	//there is something in the queue
	if (pStatus != NULL)
	{
		*pStatus = SUCCESS;
	}
	return (pPriority_queue->data[pPriority_queue->front]).value;
}

Boolean priority_queue_is_empty(PRIORITY_QUEUE hQueue)
{
	Priority_queue* pPriority_queue = (Priority_queue*)hQueue;

	return (Boolean)(pPriority_queue->size <= 0);
}

void priority_queue_destroy(PRIORITY_QUEUE* phQueue)
{
	Priority_queue* pPriority_queue = (Priority_queue*)*phQueue;
	free(pPriority_queue->data);
	free(*phQueue);
	*phQueue = NULL;
	return;
}