/**********************************************************************
Program: Program 2, Ferry Loading, UVA problem 11034
Author: Derrick Lor
Date: 13 March 2019
Time spent: 5hr 41min
Purpose: Use two queues for left and then right sides
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
	//clear_keyboard_buffer();//used to stop program from closing
	//testcases.txt must end in new line
	return 0;
}

void runProgram(int numberOfTestCases)
{

	QUEUE hQLeft;
	QUEUE hQRight;
	hQLeft = queue_init_default();
	hQRight = queue_init_default();

	int i;
	int lengthOfFerryInMeters = 0;
	int numberOfCars = 0;
	int lengthOfCarInCentimeters = 0;
	char ferrySide = 'l'; // l for left 108 , r for right 114
	char carSide = '\0';
	//ferry is initially on the left bank
	int tripCount = 0;

	if (hQLeft == NULL)
	{
		printf("Failed to allocate space for queue\n");
		exit(1);
	}

	if (hQRight == NULL)
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
																							//printf("Length of car in cm: %d. ", lengthOfCarInCentimeters);
		scanf(" %c", &carSide);//can only be 'l' or 'r'
																							//printf("Car is on side: %c\n", carSide);
		clear_keyboard_buffer();

		if (carSide == 'l' || carSide == 'L')//account for capitals
		{
			queue_enqueue(hQLeft, lengthOfCarInCentimeters, 'l');//add to left queue
																							//printf("Enqueue left side success.\n");
		}
		else if (carSide == 'r' || carSide == 'R')//account for capitals
		{
			queue_enqueue(hQRight, lengthOfCarInCentimeters, 'r');//add to right queue
																							//printf("Enqueue right side success.\n");
		}
	}


	//actually figure out number of trips
																							//printf("Begin solving\n");
	while (!queue_empty(hQLeft) || !queue_empty(hQRight))//keep servicing cars until both queues are empty
	{

		//if ferryside and carside don't match, then we need to take a trip
		//to the other side, we dont actually service yet
		//How do we decide which queue we are servicing? use ferrySide
		if (ferrySide == 'l' && queue_empty(hQLeft))//if ferry is on left, but left is empty, then go to other side
		{
																							//printf("We need to take a trip to the right!\n");
			tripCount++;
			ferrySide = 'r';//set ferrySide to be right carSide
		}
		if (ferrySide == 'r' && queue_empty(hQRight))//if ferry is on right, but right is empty, then go to other side
		{
																							//printf("We need to take a trip to the left!\n");
			tripCount++;
			ferrySide = 'l';//set ferrySide to be left carSide
		}
		//else ferry and car are both on same sides, do nothing
		
		

		//check if there is enough space to carry more than 1 car,
		//for when ferry is on either sides
		//i is length of ferry in centimeters. Convert meter to cm: 100cm per 1 meter
		i = 100 * lengthOfFerryInMeters;//reset i to be ferry length in cm
		
		//***********************************fix here*****************

		//for when ferry is on left side and left queue is not empty
		if (ferrySide == 'l' && !queue_empty(hQLeft))
		{
			while (i >= queue_front_int(hQLeft) && !queue_empty(hQLeft))//service as many cars as we can fit on the ferry
			{
				i -= queue_front_int(hQLeft);//subtract length of car from i before servicing
																							//printf("%d", i);
				queue_service(hQLeft);
																							//printf("Service car on left\n");
			}
			
		}


		//for when ferry is on right side and right queue is not empty
		if (ferrySide == 'r' && !queue_empty(hQRight))
		{
			while (i >= queue_front_int(hQRight) && !queue_empty(hQRight))//service as many cars as we can fit on the ferry
			{

				i -= queue_front_int(hQRight);//subtract length of car from i before servicing
																							//printf("%d", i);
				queue_service(hQRight);
																							//printf("Service car on right\n");
			}

		}
		//default case, we need to bring the car(s)	to the other side
		tripCount++;
																							//printf("We need to take a trip!\n");
		//set ferryside to opposite side
		switch (ferrySide)
		{
		case 'l':
			ferrySide = 'r'; break;
		case 'r':
			ferrySide = 'l'; break;
		}
																							
	}

	queue_destroy(&hQLeft);
	queue_destroy(&hQRight);
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
