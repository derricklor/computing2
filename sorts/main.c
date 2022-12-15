#include <stdio.h>
#include <stdlib.h>

void show_binary(int number);
void my_swap(int* a, int* b);

void bubble_sort(int numbers[], int size);
void selection_sort(int numbers[], int size);
void vanilla_insertion_sort(int numbers[], int size);
void shell_sort(int numbers[], int size);
void insertion_sort(int numbers[], int size);
int assignment_count = 0;
int comparison_count = 0;

int main(int argc, char* argv[])
{
	const int SIZE = 10;
	int* pNumbers;
	int i;
	int temp;
	pNumbers = (int*)malloc(sizeof(int)*SIZE);
	if (pNumbers == NULL)
	{
		printf("Failed to allocate space for array\n");
		exit(1);
	}
	printf("Filling the array\n");
	for (i = 0; i < SIZE; i++)
	{
		pNumbers[i] = rand(); //(rand() << 15) + rand()
		//pNumbers[i] = SIZE - i;
		//printf("%d\n", pNumbers[i]);
	}
	printf("****\n\n");
	shell_sort(pNumbers, SIZE);
	for (i = 0; i < SIZE; i++)
	{
		printf("%d\n", pNumbers[i]);
	}
	printf("Number of assignments: %d\n", assignment_count);
	printf("Number of comparisons: %d\n", comparison_count);
	return 0;
}


void bubble_sort(int numbers[], int size)
{
	int i, j;

	assignment_count++; //i = 0
	for (i = 0; i < size - 1; i++)
	{
		comparison_count++; //condition
		assignment_count++; //i++
		assignment_count++; //j=0
		for (j = 0; j < size - 1 - i; j++)
		{
			comparison_count++; //condition
			assignment_count++; //j++
			comparison_count++;
			if (numbers[j] > numbers[j + 1])
			{
				my_swap(&numbers[j], &numbers[j + 1]);
			}
		}
		comparison_count++; //last comparison
	}
	comparison_count++; //last condition
}

void my_swap(int* a, int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
	assignment_count += 3;
}



void selection_sort(int numbers[], int size)
{
	int i;
	assignment_count++; // i = 0
	for (i = 0; i < size - 1; i++)
	{
		comparison_count++; //condition
		my_swap(&numbers[i], &numbers[find_min(numbers, i, size)]);
	}
	comparison_count++; //end of loop condition
}

int find_min(int numbers[], int start, int size)
{
	int i;
	int index_of_min = start;

	assignment_count++; //i = start
	for (i = start; i < size; i++)
	{
		comparison_count++; // condition
		assignment_count++; // i++
		comparison_count++; //if
		if (numbers[i] < numbers[index_of_min])
		{
			index_of_min = i;
			assignment_count++;
		}
	}
	return index_of_min;
}

void vanilla_insertion_sort(int numbers[], int size)
{
	int i;
	int j;
	assignment_count++; //i=1
	for (i = 1; i < size; i++)
	{
		comparison_count++; //condition
		assignment_count += 2; //i++ and j = i
		j = i;
		while (j > 0 && numbers[j] < numbers[j - 1])
		{
			comparison_count += 2;
			my_swap(&numbers[j], &numbers[j - 1]);
			assignment_count++; // j--
			j--;
		}
		if (j == 0)
		{
			comparison_count++;
		}
		else
		{
			comparison_count += 2;
		}
	}
}

void insertion_sort(int numbers[], int size)
{
	int i;
	int j;
	int temp;
	assignment_count++; // i=1
	for (i = 1; i < size; i++)
	{
		comparison_count++; //condition
		assignment_count += 3; //i++, j=i, temp
		j = i;
		temp = numbers[j];

		while (j > 0 && temp < numbers[j - 1])
		{
			comparison_count += 2;
			numbers[j] = numbers[j - 1]; //shifting improvement
			j--;
			assignment_count += 2;
		}
		if (j == 0)
		{
			comparison_count++;
		}
		else
		{
			comparison_count += 2;
		}
	}
	comparison_count++; //last loop iteration
}

void shell_sort(int numbers[], int size)
{
	int i;
	int j;
	int temp;
	int h = 1;

	while (h * 3 < size)
	{
		h <<= 1;
	}
	h--;


	while (h > 0)
	{
		for (i = h; i < size; i++)
		{
			j = i;
			temp = numbers[j];
			while (j - h + 1 > 0 && temp < numbers[j - h])//while inbounds and temp is smaller than other values
			{
				numbers[j] = numbers[j - h];  //shifting
				j -= h;
			}
			numbers[j] = temp;
		}
		h /= 2;
	}
}