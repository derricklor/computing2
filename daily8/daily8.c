/**********************************************************************
Program: daily8 - Implementing priority_queue.c
Author: Derrick Lor
Date: 5/2/2019
Time spent: 4hours 21 mins
Purpose: The purpose of this program is to implement the functions in
		 priority_queue.h by creating priority_queue.c, and test the 
		 functions by running it in main.
***********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "priority_queue.h"

int main(int argc, char* argv[])
{
	PRIORITY_QUEUE hQueue = NULL;
	int i;
	hQueue = priority_queue_init_default();

	if (hQueue == NULL)
	{
		printf("Failure to allocate memory for Queue\n");
		exit(1);
	}
	printf("Creating a queue with same priority level as value:\n");
	for (i = 1; i <= 10; i++)
	{
		priority_queue_insert(hQueue, i, i);
		printf("Inserting number: %d into Queue.\n", i);
	}
	
	printf("The front of the queue is: %d\n", priority_queue_front(hQueue, NULL));
	printf("\n");

	for (i = 1; i <= 10; i++)
	{
		printf("Servicing Queue...\n");
		priority_queue_service(hQueue);
		printf("The front of the queue is now: %d\n", priority_queue_front(hQueue, NULL));
	}
	

	printf("\nServicing Queue again after queue is already emptied.\n");
	priority_queue_service(hQueue);



	printf("\nCreating a queue with opposite priority level as value:\n");
	for (i = 1; i <= 10; i++)
	{
		priority_queue_insert(hQueue, 10-i, i);
		printf("Inserting number: %d into Queue.\n", i);
	}
	printf("The front of the queue is now: %d\n\n",priority_queue_front(hQueue, NULL));

	printf("Servicing Queue two times\n");
	priority_queue_service(hQueue);
	priority_queue_service(hQueue);
	printf("The front of the queue is now: %d\n\n",priority_queue_front(hQueue, NULL));

	printf("Servicing Queue three times\n");
	for (i = 0; i < 3; i++)
	{
		priority_queue_service(hQueue);
	}
	printf("The front of the queue is now: %d\n\n",priority_queue_front(hQueue, NULL));

	priority_queue_destroy(&hQueue);
	printf("Destroyed Queue.\n");


	return 0;
}