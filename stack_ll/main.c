#include "stack.h"

int main() {
    struct node *head = NULL;
    int size, elem;
    int counter = 0;

    printf("Enter the number of stack elements:");
    scanf("%d", &size);

    printf("-- Push elements into the linked list stack --\n");

    init(head);

    while(counter < size) {
        printf("Enter a number to push into the stack: ");
        scanf("%d", &elem);
        head = push(head, elem);
        display(head);
        counter++;
    }

    printf("--- Pop elements from the linked stack --- \n");
    while(empty(head) == 0) {
        head = pop(head, &elem);
        printf("Pop %d from stack\n", elem);
        display(head);
    }

    return 0;
}


