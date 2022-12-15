#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct node;
typedef struct node Node;

struct node
{
	char ch;
	Node* next;
};

struct stack;
typedef struct stack Stack;

struct stack
{
	Node* head;
};

STACK stack_init_default(void)
{
	Stack* pStack;
	pStack = (Stack*)malloc(sizeof(Stack));

	if (pStack != NULL)
	{
		pStack->head = NULL;//first head points to NULL
	}
	return pStack;
}

Status stack_push(STACK hStack, char item)
{
	Stack* pStack = (Stack*)hStack;
	Node* pTemp;
	pTemp = (Node*)malloc(sizeof(Node));

	if (pTemp == NULL)
	{
		printf("Failed to allocate space for new node\n");
		return FAILURE;
	}
	else
	{
		pTemp->ch = item;
		pTemp->next = pStack->head;
		pStack->head = pTemp;
		return SUCCESS;
	}
}

//set current head to be next head
Status stack_pop(STACK hStack)
{
	Stack* pStack = (Stack*)hStack;

	//pStack->head->ch = pStack->head->next->ch;//change char to next char
	pStack->head = pStack->head->next;//change to next head

	return SUCCESS;
}

//returns true if stack is empty, else return false
Boolean stack_empty(STACK hStack)
{
	Stack* pStack = (Stack*)hStack;

	//stack is empty when the head is pointing to null
	//recall stack_init_default makes head first point to null
	if (pStack->head == NULL)
	{
		return TRUE;
	}

	return FALSE;
}

//Status stack_top(STACK hStack, int* pValue);

//returns char of the head
char stack_top(STACK hStack)
{
	Stack* pStack = (Stack*)hStack;
	
	return pStack->head->ch;
}

//frees the allocated space
void stack_destroy(STACK* phStack)
{
	Stack* pStack = (Stack*)*phStack;

	free(pStack->head);//free whatever stack is pointing to
	free(pStack);//free memory footprint
	*phStack = NULL;

}