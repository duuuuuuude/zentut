#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

int main() {
    const int SIZE = 5;
    int head, tail, element;
    int queue[SIZE];

    init(&head, &tail);
    printf("--Enqueue elements--\n");

    while(!full(tail, SIZE)) {
        printf("Enter a number to enqueue: ");
        scanf("%d", &element);
        enqueue(queue, &tail, element);
        display(queue, head, tail);
    }
    printf("Queue is full\n\n");

    printf("--Dequeue elements--\n");
    while(!empty(head, tail)) {
        element = dequeue(queue, &head);
        printf("dequeue element %d \n", element);

        display(queue, head, tail);
    }
    printf("Queue is empty\n");
    return 0;
}


