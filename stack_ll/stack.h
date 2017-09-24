#ifndef _STACK_LINKED_LIST_H_
#define _STACK_LINKED_LIST_H_

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
} node;

int empty(struct node* head);
struct node* push(struct node*, int);
struct node* pop(struct node*, int*);
void init(struct node*);
void display(struct node*);

#endif

