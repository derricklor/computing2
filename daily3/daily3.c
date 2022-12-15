/***********************************************************
Author: Derrick Lor
Date: 29 January
Effort: 1hr 4mins
Purpose: Explore how to store data in the binary representation
of a number using left and right shift operators, and &,| operators.
***********************************************************/

#include <stdio.h>

void set_flag(int* flag_holder, int flag_position);
int check_flag(int flag_holder, int flag_position);

int main(int argc, char* argv[])
{
	//do not change
	int flag_holder = 0;
	int i;
	set_flag(&flag_holder, 3);
	set_flag(&flag_holder, 16);
	set_flag(&flag_holder, 31);
	for (i = 31; i >= 0; i--)
	{
		printf("%d", check_flag(flag_holder, i));
		if (i % 4 == 0)
		{
			printf(" ");
		}
	}
	printf("\n");
	return 0;
}

/*
PRECONDITION: First parameter is a pointer to the address of an integer starting
at 0, so we can change it. Second parameter is the position of where we want 
to store the bit(1's) in the binary representation of the integer.
POSTCONDITION:The value of the integer is changed corresponding to what position
we wanted the bit to be located. 
Ex. 0000 0000 is equivalent 0, so changing the bit in the 3rd position to a 1
will give use 0000 1000 which is equivalent to 8.
*/
void set_flag(int* flag_holder, int flag_position)
{
	//use the left shift operator to "shift" all the bits of x towards the left
	//flag_position amount of spaces
	int x =  1 << flag_position;

	//now use the bitwise OR (|) and assignment (=) to store the value of x to flag_holder
	*flag_holder |= x;
}

/*
PRECONDITION:First parameter is a pointer to the address of an integer. Second parameter
is the position of the bit where we want to check.
POSTCONDITION:Prints 1 if there is a bit set to 1 in the binary representation 
corresponding to flag_position, else print 0.
*/
int check_flag(int flag_holder, int flag_position)
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
