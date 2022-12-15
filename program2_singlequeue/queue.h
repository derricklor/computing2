#ifndef QUEUE_H
#define QUEUE_H
#include "status.h"

typedef void* QUEUE;

QUEUE queue_init_default(void);
//enqueue
Status queue_enqueue(QUEUE hQ, int item, char sideOfRiver);
//service
Status queue_service(QUEUE hQ);
//empty
Boolean queue_empty(QUEUE hQ);
//front
int queue_front_int(QUEUE hQ);
char queue_front_char(QUEUE hQ);


void queue_destroy(QUEUE* phQueue);

#endif