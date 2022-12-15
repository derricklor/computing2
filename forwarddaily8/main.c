/**********************************************************************
Program: priority_queue.c
Author: Tony Dam
Date: 4/29/2019
Time spent: 1 hour
Purpose: The purpose of this program is to test the functions in
		 priority_queue.c by creating the queue, inserting the values,
		 servicing them and displaying the front of the queue while
		 destroying it as the end.
***********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "priority_queue.h"

int main(int argc, char* argv[])
{
	PRIORITY_QUEUE hQueue = NULL;

	hQueue = priority_queue_init_default();

	if (hQueue == NULL)
	{
		printf("Failure to allocate memory for Queue\n");
		exit(1);
	}

	priority_queue_insert(hQueue, 1, 10);
	priority_queue_insert(hQueue, 2, 11);
	priority_queue_insert(hQueue, 4, 12);
	priority_queue_insert(hQueue, 8, 13);
	priority_queue_insert(hQueue, 16, 14);
	priority_queue_insert(hQueue, 32, 15);

	printf("Inserting numbers: 10, 11, 12, 13, 14, 15 into Queue.\n\n");

	printf("TEST #1: The front of the queue is: %d\n",
		   priority_queue_front(hQueue, NULL));
	printf("\n");

	printf("TEST #2: Servicing Queue...\n");
	priority_queue_service(hQueue);
	printf("The front of the queue is now: %d\n\n",
		priority_queue_front(hQueue, NULL));

	printf("TEST #3: Servicing Queue twice...\n");
	priority_queue_service(hQueue);
	priority_queue_service(hQueue);
	printf("The front of the queue is now: %d\n\n",
		priority_queue_front(hQueue, NULL));

	printf("TEST #4: Inserting value '50' into Queue.\n");
	priority_queue_insert(hQueue, 64, 50);
	printf("The front of the queue is now: %d\n\n",
		priority_queue_front(hQueue, NULL));

	printf("TEST #5: Servicing Queue thrice...\n");
	priority_queue_service(hQueue);
	priority_queue_service(hQueue);
	priority_queue_service(hQueue);
	printf("The front of the queue is now: %d\n\n",
		priority_queue_front(hQueue, NULL));

	printf("TEST #6: Servicing Queue to be empty\n");
	priority_queue_service(hQueue);
	printf("The front of the queue is now: %d\n\n",
		priority_queue_front(hQueue, NULL));

	printf("TEST #6: Attempting to service an empty Queue\n");
	priority_queue_service(hQueue);
	printf("\n");

	priority_queue_destroy(&hQueue);
	printf("TEST #7: Destroyed Queue.\n");


		return 0;
}