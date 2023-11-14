#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Stack {
    struct Node* top;
};

void initialize(struct Stack* stack) {
    stack->top = NULL;
}

int isEmpty(struct Stack* stack) {
    return stack->top == NULL;
}

void push(struct Stack* stack, int element) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = element;
    newNode->next = stack->top;
    stack->top = newNode;
}

int main() {
    struct Stack stack;
    initialize(&stack);

    // Push some elements into the stack
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    // Print the elements in the stack
    printf("Elements in the stack: ");
    struct Node* current = stack.top;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    return 0;
}