#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Stack {
    struct Node* top;
};

void push(struct Stack* stack, int data) {
    struct Node* newNode = malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed. Cannot push element %d.\n", data);
        return;
    }
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
    printf("Element %d pushed to the stack.\n", data);
}

int main() {
    struct Stack* stack = malloc(sizeof(struct Stack));
    stack->top = NULL;

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    return 0;
}
