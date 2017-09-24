#include "stack.h"

void init(struct node* head) {
    head = NULL;
}

struct node* push(struct node* head, int data) {
    struct node *tmp = (struct node*)malloc(sizeof(struct node));
    if (tmp == NULL) {
        exit(0);
    }
    tmp->data = data;
    tmp->next = head;
    head = tmp;
    return head;
}

struct node* pop(struct node* head, int* element) {
    struct node *tmp = head;
    *element = head->data;
    head = head->next;
    free(tmp);
    return head;
}

int empty(struct node* head) {
    return head == NULL ? 1 : 0;
}

void display(struct node* head) {
    struct node *current;
    current = head;

    if (current != NULL) {
        printf("Stack: ");
        do {
            printf("%d ", current->data);
            current = current->next;
        } while (current != NULL);
        printf("\n");
    } else {
        printf("The stack is empty\n");
    }
}


