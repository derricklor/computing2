/**********************************************************************
Program: Program 3 Number Filter
Author: Derrick Lor
Date: 5/1/19
Time spent: 3hr 20min
Purpose: Read in a whole bunch of numbers, set the bit to 1 corresponding
to the nth number and nth bit. Filter out any duplicates and print the
corresponding nth bit to the nth number.
***********************************************************************/

#include <stdio.h>
#include <stdlib.h>

void set_flag(unsigned int* flag_holder, int flag_position);
int check_flag(unsigned int* flag_holder, int flag_position);
void display_integer_of_flags(unsigned int* flag_holder, int size);
void clear_keyboard_buffer(void);


int main(int argc, char* argv[])
{	//80,000,000
	
	int capacity = 80000000;
	unsigned int* flag_holder = (unsigned int*)malloc(sizeof(unsigned int)*capacity);
	int i = 0;
	int size = 0;

	for (i = 0; i < capacity; i++)
	{
		flag_holder[i] = 0;
	}

	//get input
	//any number above 100,000,000 will start to slow down the program
	//anything above 2,000,000,000 will crash the program
	scanf("%d", &i);//try
	clear_keyboard_buffer();
	while (i != -1)//check
	{

		if (check_flag(flag_holder, i) == 0)//do
		{
			set_flag(flag_holder, i);
			size++;
		}

		scanf("%d", &i);
		clear_keyboard_buffer();//try
	}

	//printf("size is: %d\n", size);
	display_integer_of_flags(flag_holder, size);
	return 0;
}


/*
PRECONDITION: Takes in array to a positive integer and position of the bit we want to turn on.
POSTCONDITION: Changes the value of the position-bit to one.

Ex. 0000 0000 is equivalent 0, so changing the bit in the 3rd position to a 1
will give use 0000 1000 which is equivalent to 8.
*/
void set_flag(unsigned int* flag_holder, int flag_position)
{
	//find which integer out of the possible ones to change
	int index = flag_position / (sizeof(int) * 8);

	//find which position in that index to change
	flag_position = flag_position - index * (sizeof(int) * 8);

	//use the left shift operator to "shift" all the bits of x towards the left
	//flag_position amount of spaces
	int x = 1 << flag_position;



	//now use the bitwise OR (|) and assignment (=) to store the value of x to flag_holder
	flag_holder[index] |= x;
}

/*
PRECONDITION: Takes in a array to a positive integer and the position of the bit we want to check.
POSTCONDITION: Returns 1 if there is a bit set to 1 in the binary representation
corresponding to flag_position, else return 0.
*/
int check_flag(unsigned int* flag_holder, int flag_position)
{
	//find which integer out of the possible ones to check
	int index = flag_position / (sizeof(int) * 8);

	//find which position in that index to check
	flag_position = flag_position - index * (sizeof(int) * 8);

	//use left shift operator to assign y as the flag_position position of the 
	//bit where we want to check
	int y = 1 << flag_position;

	//compare flag_holder integer to the y integer using bitwise AND (&)
	//check if the bits in the flag_holder position matches the bits in the y position
	if (flag_holder[index] & y)
	{
		return 1;
	}
	return 0;
}


//prints out all of the nth bits as the nth integer
//they are corresponding to
void display_integer_of_flags(unsigned int* flag_holder, int size)
{
	int i = 0;
	int count = 0;
	while (count < size)
	{
		if (check_flag(flag_holder, i) == 1)
		{
			printf("%d\n", i);
			count++;
		}
		i++;
	}
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