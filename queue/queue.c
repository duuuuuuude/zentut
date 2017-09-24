#include <stdio.h>

void init(int *head, int *tail) {
    *head = *tail = 0;
}

void enqueue(int *q, int *tail, int element) {
    q[(*tail)++] = element;
}

int dequeue(int *q, int *head) {
    return q[(*head)++];
}

int full(int tail, const int size) {
    return tail == size;
}

int empty(int head, int tail) {
    return tail == head;
}

void display(int *q, int head, int tail) {
    int i = tail - 1;
    while(i >= head) {
        printf("%d ", q[i--]);
    }
    printf("\n");
}

