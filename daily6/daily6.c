/**********************************************************************
Program: Reverse linked list
Author: Derrick Lor
Date: 12 February 2019
Time spent: 1hr 16mins
Purpose: The purpose of this program is to reverse a given linked list.
***********************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct node;
typedef struct node Node;

struct node
{
	int data;
	Node* next;
};

//declare your function here.
void head_reverse(Node** pHead);
void print_list(Node* head);
void print_list_recursive(Node* head);



int main(int argc, char* argv[])
{
	Node* head = NULL;
	int i;
	Node* temp;

	//set up a test list with values 9->8->7->...->0
	for (i = 0; i < 10; i++)
	{
		temp = (Node*)malloc(sizeof(Node));
		if (temp == NULL)
		{
			printf("out of memory?\n");
			exit(1);
		}
		temp->data = i;
		temp->next = head;
		head = temp;
	}

	//call your function to reverse the list (should work for any list given the head node pointer).

	//print_list(head);

	head_reverse(&head);
	print_list_recursive(head);
	printf("****\n");
	head_reverse(&head);
	print_list_recursive(head);
	//print_list(head);
	

	return 0;
}

//Define your function here
void head_reverse(Node** pHead)
{

	Node* current;
	Node* next;
	Node* last;//the reversed list

	current = *pHead;//set current to head
	next = current->next;//set next to next head
	last = NULL;

	while (current != NULL)
	{
		current->next = last;//make current node point at previous node
		last = current;//set previous node to current node
		current = next;//set current node to next node
		if (next != NULL)//if next is not pointing to NULL
		{
			next = next->next;//set next to point towards next head
		}
		//repeat until end of list is reached
	}
	*pHead = last;
}


void print_list(Node* head)
{
	Node* temp;
	temp = head;
	
	//print the list.
	while (temp != NULL)
	{
		printf("%d\n", temp->data);
		temp = temp->next;
	}
}


void print_list_recursive(Node* head)
{

	if (head != NULL)
	{
		printf("%d\n", head->data);//head to tail
		print_list_recursive(head->next);
		//printf("%d\n", head->data);//tail to head
	}
}
