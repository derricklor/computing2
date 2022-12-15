/***********************************************************
Author: Derrick Lor
Date: 15 February 2019
Effort: 9 mins
Purpose: <Purpose of this assignment in your own words>
 Interface proposal: <answer the last question in the specification>
***********************************************************/

#include <stdio.h>
#include "status.h"
#include "bit_flags.h"

Status bit_flags_set_flag(BIT_FLAGS hBit_flags, int flag_position);
Status bit_flags_unset_flag(BIT_FLAGS hBit_flags, int flag_position);
int bit_flags_check_flag(BIT_FLAGS hBit_flags, int flag_position);

void display_32_flags_as_array(unsigned int flag_holder);
void display_flags(unsigned int flag_holder[], int size);

int bit_flags_get_size(BIT_FLAGS hBit_flags);
int bit_flags_get_capacity(BIT_FLAGS hBit_flags);
void bit_flags_destroy(BIT_FLAGS* phBit_flags);

//int main(int argc, char* argv[])
//{
//	unsigned int flag_holder[5] = { 0 };//Set the first integer to zero and all others
//	//to zero by default.
//	set_flag(flag_holder, 3);
//	set_flag(flag_holder, 16);
//	set_flag(flag_holder, 31);
//	set_flag(flag_holder, 87);
//	display_flags(flag_holder, 5);
//	printf("\n\n");
//	unset_flag(flag_holder, 31);
//	unset_flag(flag_holder, 3);
//	set_flag(flag_holder, 99);
//	set_flag(flag_holder, 100);
//	display_flags(flag_holder, 5);
//	return 0;
//}

/*
PRECONDITION: Takes in array to a positive integer and position of the bit we want to turn on.
POSTCONDITION: Changes the value of the position-bit to one.

Ex. 0000 0000 is equivalent 0, so changing the bit in the 3rd position to a 1
will give use 0000 1000 which is equivalent to 8.
*/
Status bit_flags_set_flag(BIT_FLAGS hBit_flags, int flag_position)
{
	//cast to known type

	//find which integer out of the possible 5 to change
	int index = flag_position / 32;

	//find which position in that index to change
	flag_position = flag_position - index * 32;

	//use the left shift operator to "shift" all the bits of x towards the left
	//flag_position amount of spaces
	int x = 1 << flag_position;



	//now use the bitwise OR (|) and assignment (=) to store the value of x to flag_holder
	flag_holder[index] |= x;
}

/*
PRECONDITION: Takes in a array to a positive integer and the position of the bit we want to check.
POSTCONDITION:Prints 1 if there is a bit set to 1 in the binary representation
corresponding to flag_position, else print 0.
*/
int bit_flags_check_flag(BIT_FLAGS hBit_flags, int flag_position)
{
	//find which integer out of the possible 5 to change
	int index = flag_position / 32;

	//find which position in that index to change
	flag_position = flag_position - index * 32;

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

/*
PRECONDITON: Takes in array to a positive integer and position of the bit we want to turn off.
POSTCONDITION: Changes the value of the position-bit to zero.
*/
Status bit_flags_unset_flag(BIT_FLAGS hBit_flags, int flag_position)
{
	/*Example
	flag_holder = 1000 0001
	x = 0000 0001
	unset_flag(0)
	result=> 1000 0000
	---------------
	unset_flag:
	{
	 1000 0001
	~1000 0001
	result=> 0111 1110

	flag_holder |= x
	 0111 1110
	|0000 0001
	result=> 0111 1111

	~0111 1111
	result=> 1000 0000
	}
	*/

	//find which integer out of the possible 5 to change
	int index = flag_position / 32;

	//find which position in that index to change
	flag_position = flag_position - index * 32;

	//use the left shift operator to "shift" all the bits of z towards the left
	//flag_position amount of spaces
	int z = 1 << flag_position;

	//get the inverse bits(flip the bits) of flag_holder
	flag_holder[index] = ~flag_holder[index];

	//set the bits of z into flag_holder
	flag_holder[index] |= z;

	//undo the inverse bits
	flag_holder[index] = ~flag_holder[index];
}

/*
PRECONDITION:Takes in array of integers and number of integers to print
POSTCONDITION:Calls another function to display the flags
*/
void display_flags(unsigned int flag_holder[], int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		display_32_flags_as_array(flag_holder[i]);
	}
}

/*
PRECONDITION:Takes in integer to print bits
POSTCONDITION:Calls another function to print 0's or 1's
then equally spaces them 4 bits long
*/
void display_32_flags_as_array(unsigned int flag_holder)
{
	int i;
	for (i = 1; i <= 32; i++)
	{
		printf("%d", check_flag(&flag_holder, i - 1));
		if (i % 4 == 0)
		{
			printf(" ");
		}
	}
	printf("\n");
}

int bit_flags_get_size(BIT_FLAGS hBit_flags) 
{
	return 0;
}

int bit_flags_get_capacity(BIT_FLAGS hBit_flags)
{
	return 0;
}

void bit_flags_destroy(BIT_FLAGS* phBit_flags)
{

}