/**********************************************************************
Program: Program 2, Ferry Loading, UVA problem 11034
Author: Derrick Lor
Date: 8 March, 2019
Time spent: 4hr 17min
Purpose: Use a single queue for both left and right sides
to output how many times it takes for
a ferry to carry cars across a river.
***********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void clear_keyboard_buffer(void);
void runProgram(int numberOfTestCases);

int main(int argc, char* argv[])
{
	int i;
	int numberOfTestCases;

	//get number of test cases
	scanf("%d", &numberOfTestCases);
	clear_keyboard_buffer();

	for (i = 0; i < numberOfTestCases; i++)
	{
		runProgram(numberOfTestCases);
	}

	//scanf("%d", &i);
	clear_keyboard_buffer();
	return 0;
}

void runProgram(int numberOfTestCases)
{

	QUEUE hQ;
	hQ = queue_init_default();

	int i;
	int lengthOfFerryInMeters = 0;
	int numberOfCars = 0;
	int lengthOfCarInCentimeters = 0;
	char ferrySide = 'l'; // l for left 108 , r for right 114
	char carSide = '\0';
	//ferry is initially on the left bank
	int tripCount = 0;

	if (hQ == NULL)
	{
		printf("Failed to allocate space for queue\n");
		exit(1);
	}

	//get length of ferry and how many cars all in one line
	scanf(" %d", &lengthOfFerryInMeters);
	scanf(" %d", &numberOfCars);
	clear_keyboard_buffer();

	for (i = 0; i < numberOfCars; i++)
	{
		//get each car's info all on separate lines
		scanf(" %d", &lengthOfCarInCentimeters);
		printf("Length of car in cm: %d. ", lengthOfCarInCentimeters);
		scanf(" %c", &carSide);//can only be 'l' or 'r'
		printf("Car is on side: %c\n", carSide);
		clear_keyboard_buffer();
		queue_enqueue(hQ, lengthOfCarInCentimeters, carSide);//add to queue
		printf("Enqueue success.\n");
	}


	//actually figure out number of trips
	printf("Begin solving\n");
	while (!queue_empty(hQ))//keep servicing cars until the queue is empty
	{

		//if ferryside and carside don't match, then we need to take a trip
		//to the other side, we dont actually service yet
		if (queue_front_char(hQ) != ferrySide)
		{
			printf("We need to take a trip!\n");
			tripCount++;
			ferrySide = queue_front_char(hQ);//set ferrySide to be carSide
		}


		//check if there is enough space to carry more than 1 car,
		//only if the next car is on the same side
		//i is length of ferry in centimeters. Convert meter to cm: 100cm per 1 meter
		i = 100 * lengthOfFerryInMeters;//resets every iteration
		while (queue_front_char(hQ) == ferrySide && i >= queue_front_int(hQ))
		{

			i -= queue_front_int(hQ);//subtract length of car from i before servicing
			queue_service(hQ);
			printf("Service car\n");
		}

		//default case, we need to service car(s)	
		tripCount++;
		printf("We need to take a trip!\n");
		//set ferryside to opposite side
		switch (ferrySide)
		{
		case 'l':
			ferrySide = 'r'; break;
		case 'r':
			ferrySide = 'l'; break;
		}

	}

	queue_destroy(&hQ);
	printf("%d\n", tripCount);
	return;
}

void clear_keyboard_buffer(void)
{
	char c;
	scanf("%c", &c);
	while (c != '\n')
	{
		scanf("%c", &c);
	}
}
