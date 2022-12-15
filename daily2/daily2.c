/***********************************************************
Author: Derrick Lor
Date: 25 January 2019
Effort: 5mins
Purpose: To explore the left shift operator(<<)
by iteration x by 1 using the left shift operator
until 0 is reached
***********************************************************/
#include <stdio.h>

int main(int argc, char* argv[])
{
	int i;
	unsigned int x = 1;
	for (i = 0; x != 0; i++)
	{
		printf("%d: %u\n", i, x);
		x = x << 1;
	}

	return 0;
}