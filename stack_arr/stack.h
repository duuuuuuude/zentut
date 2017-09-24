#ifndef _STACK_H_
#define _STACK_H_

#include <stdio.h>

void push(int *s, int *top, int element);
int pop(int *s, int *top);
int full(int *top, const int size);
int empty(int *top);
void init(int *top);
void display(int *s, int *top);

#endif

