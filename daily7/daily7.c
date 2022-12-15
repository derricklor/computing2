/**********************************************************************
Program: Daily7 uva.onlinejudge problem 673
Author: Derrick Lor
Date: 2/24/2019
Time spent: 3hours 32mins 
Purpose: To check if an expression is valid or not.
***********************************************************************/
#include <stdio.h>
#include "stack.h"

Boolean test_case_is_valid(void);
void clear_keyboard_buffer(void);

int main(int argc, char* argv[])
{
	int n;
	int i;

																
	scanf("%d", &n);
	clear_keyboard_buffer();
	for (i = 0; i < n; i++)
	{
		
		if (test_case_is_valid())
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
																
	return 0;
}

Boolean test_case_is_valid(void)
{
	STACK head = stack_init_default();
	char c;
	int noc;

																
	noc = scanf("%c", &c);
	
	while (noc == 1 && c != '\n')//scan all of the input text
	{
		
		//if [ or ( add c to stack 
		if (c == '[' || c == '(')
		{
																
			stack_push(head, c);
																
		}
		
		//if ] or ) check top of stack to see if it matches
		//if it does not match or stack is empty, clear the stack and return false, move onto next
		if (c == ']' || c == ')')
		{
																	
			//check if stack is empty
			if (stack_empty(head))
			{
																	
				//stack is empty so
				//clear the stack, return false
				stack_destroy(&head);
																	
				clear_keyboard_buffer();
				return FALSE;
			}

			//check if top (left marker) matches with c (right marker)
																						
																					
					
			if ( (stack_top(head) == '[' && c == ']' ) || (stack_top(head) == '(' && c == ')') )
			{
																						
				//it matches so pop off
				stack_pop(head);
																						
			}
			else
			{
																						
				//did not match Ex. [), (]
				//clear the stack, return false
				stack_destroy(&head);
																						
				clear_keyboard_buffer();
				return FALSE;
			}
		}

		noc = scanf("%c", &c);
		//printf("next c is: %c\n", c);
	}

																						

	//you reach the end of the test case, so c is now \n
	//but if stack is not empty, you failed
	if (stack_empty(head))
	{
																						
	}
	else
	{
																							
		stack_destroy(&head);
																						
		return FALSE;
	}

																							
	//if you get to the end with no problems and receive a \n, then the input is correct
	if (c == '\n')
	{
																							
		stack_destroy(&head);
																							
		return TRUE;
	}
	stack_destroy(&head);
	clear_keyboard_buffer();
	return FALSE;
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