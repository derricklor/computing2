#ifndef STACK_H
#define STACK_H

#include "status.h"
typedef void* STACK;

STACK stack_init_default(void);


Status stack_push(STACK hStack, char item);

Status stack_pop(STACK hStack);

Boolean stack_empty(STACK hStack);

//Status stack_top(STACK hStack, int* pValue);
char stack_top(STACK hStack);

//PRECONDITION:must pass address of head in order to change it
void stack_destroy(STACK* phStack);

#endif