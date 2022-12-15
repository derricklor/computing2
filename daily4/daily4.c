/***********************************************************
Author: Derrick Lor
Date: 3 February 2019
Effort: 23mins
Purpose: Explore how to unset flags(bits) in binary notation using
~ operator to "flip the bits", then | to change a bit, then ~ again
to get original bits minus the bit we wanted to change.
***********************************************************/

#include <stdio.h>

void set_flag(unsigned int* flag_holder, int flag_position);
void unset_flag(unsigned int * flag_holder, int flag_position);
int check_flag(unsigned int flag_holder, int flag_position);
void display_32_flags(unsigned int flag_holder);


int main(int argc, char* argv[])
{
	unsigned int flag_holder = 0;
	set_flag(&flag_holder, 3);
	set_flag(&flag_holder, 16);
	set_flag(&flag_holder, 31);
	display_32_flags(flag_holder);
	unset_flag(&flag_holder, 31);
	unset_flag(&flag_holder, 3);
	set_flag(&flag_holder, 9);
	display_32_flags(flag_holder);
	return 0;
}

/*
PRECONDITION: Takes in pointer to a positive integer and position of the bit we want to turn on.
POSTCONDITION: Changes the value of the position-bit to one.

Ex. 0000 0000 is equivalent 0, so changing the bit in the 3rd position to a 1
will give use 0000 1000 which is equivalent to 8.
*/
void set_flag(unsigned int* flag_holder, int flag_position)
{
	//use the left shift operator to "shift" all the bits of x towards the left
	//flag_position amount of spaces
	int x = 1 << flag_position;

	//now use the bitwise OR (|) and assignment (=) to store the value of x to flag_holder
	*flag_holder |= x;
}

/*
PRECONDITION: Takes in a pointer to a positive integer and the position of the bit we want to check.
POSTCONDITION:Prints 1 if there is a bit set to 1 in the binary representation
corresponding to flag_position, else print 0.
*/
int check_flag(unsigned int flag_holder, int flag_position)
{
	//use left shift operator to assign y as the flag_position position of the 
	//bit where we want to check
	int y = 1 << flag_position;

	//compare flag_holder integer to the y integer using bitwise AND (&)
	//check if the bits in the flag_holder position matches the bits in the y position
	if (flag_holder & y)
	{
		return 1;
	}
	return 0;
}

/*
PRECONDITON: Takes in pointer to a positive integer and position of the bit we want to turn off.
POSTCONDITION: Changes the value of the position-bit to zero.
*/
void unset_flag(unsigned int * flag_holder, int flag_position)
{
	/*Example
	flag_holder = 1000 0001 
	x = 0000 0001
	unset_flag(0) 
	result=> 1000 0000
	---------------
	unset_flag:
	 1000 0001
	~1000 0001 
	result=> 0111 1110
	
	flag_holder |= x
	 0111 1110
	|0000 0001
	result=> 0111 1111

	~0111 1111
	result=> 1000 0000
	*/

	//use the left shift operator to "shift" all the bits of z towards the left
	//flag_position amount of spaces
	int z = 1 << flag_position;

	//get the inverse bits(flip the bits) of flag_holder
	*flag_holder = ~*flag_holder;

	//set the bits of z into flag_holder
	*flag_holder |= z;

	//undo the inverse bits
	*flag_holder = ~*flag_holder;
}

/*
PRECONDTION: Takes in a copy of an unsigned integer.
POSTCONDITION: Displays all of the bits of unsigned integer.
*/
void display_32_flags(unsigned int flag_holder)
{
	int i;
	for (i = 31; i >= 0; i--)
	{
		printf("%d", check_flag(flag_holder, i));
		if (i % 4 == 0)
		{
			printf(" ");
		}
	}
	printf("\n");
}