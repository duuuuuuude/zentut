#ifndef _QUEUE_H_
#define _QUEUE_H_

void init(int *head, int* tail);
void enqueue(int *q, int *tail, int element);
int dequeue(int *q, int *head);
int empty(int head, int tail);
int full(int tail, const int size);
void display(int *q, int head, int tail);

#endif
