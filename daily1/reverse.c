#include <stdlib.h>
/*
Takes in a char pointer to the array of chars
and reverses the chars in the array by swapping
the chars in the first half of the array with
the chars in the second half of the array.
*/
char* reverse(char* pword)
{
	int i;
	int size = 0;
	char temp;

	////check if empty
	if (pword[0] == NULL)
	{
		return pword;
	}

	//find size
	for (i = 0; pword[i] != '\0'; i++)
	{
		size++;
	}
	size--;
	//size must decrease by 1 or will result in array out of bounds
	for (i = 0; i < size / 2; i++)//works with even or odd sizes
	{
		temp = pword[i];
		pword[i] = pword[size - i];
		pword[size - i] = temp;
	}
	return pword;
}