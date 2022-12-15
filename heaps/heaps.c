#include <stdio.h>


void heap_insert(int heap[], int* pSize, int capacity, int value);
int heap_remove_max(int heap[], int* pSize);

void fix_up(int heap[], int index);
void fix_down(int heap[], int index, int size);
void my_swap(int* a, int* b);




int main(int argc, char* argv[])
{
	int heap[50];//array called heaps
	int size = 0;
	int capacity = 50;
	int i;
	for (i = 0; i < 10; i++)
	{
		heap_insert(heap, &size, capacity, i);
	}
	for (i = 0; i < size; i++)
	{
		printf("%d\n", heap[i]);
	}

	printf("*****\n\n");

	while (size > 0)
	{
		heap_remove_max(heap, &size);
	}

	for (i = 0; i < 10; i++)
	{
		printf("%d\n", heap[i]);
	}
	return 0;
}

void heap_insert(int heap[], int* pSize, int capacity, int value)
{
	if (*pSize < capacity)
	{
		heap[*pSize] = value;
		(*pSize)++;
		fix_up(heap, *pSize - 1);
	}
}

void fix_up(int heap[], int index)
{
	int index_of_parent = -1;

	if (index > 0)
	{
		index_of_parent = (index - 1) / 2;
		if (heap[index] > heap[index_of_parent])
		{
			my_swap(&heap[index], &heap[index_of_parent]);
			fix_up(heap, index_of_parent);
		}
	}
}

void my_swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int heap_remove_max(int heap[], int* pSize)
{
	if (*pSize > 0)
	{
		my_swap(&heap[0], &heap[*pSize - 1]);
		(*pSize)--;
		fix_down(heap, 0, *pSize);
		return heap[*pSize + 1];
	}
	return -1337;
}

void fix_down(int heap[], int index, int size)
{
	int index_of_left_child = -1;
	int index_of_right_child = -1;
	int index_of_largest_child = -1;

	index_of_left_child = 2 * index + 1;
	index_of_right_child = 2 * index + 2;

	if (index_of_right_child < size) //i have two children
	{
		index_of_largest_child =
			(heap[index_of_left_child] > heap[index_of_right_child]) ?
			index_of_left_child : index_of_right_child;
		if (heap[index] < heap[index_of_largest_child])
		{
			my_swap(&heap[index], &heap[index_of_largest_child]);
			fix_down(heap, index_of_largest_child, size);
		}
	}
	else if (index_of_left_child < size) //i have only one child
	{
		index_of_largest_child = index_of_left_child;
		if (heap[index] < heap[index_of_largest_child])
		{
			my_swap(&heap[index], &heap[index_of_largest_child]);
			fix_down(heap, index_of_largest_child, size);
		}
	}
}