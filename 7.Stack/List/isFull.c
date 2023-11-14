#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* top;
    int size;
    int maxSize;
} Stack;

void initialize(Stack* stack, int maxSize) {
    stack->top = NULL;
    stack->size = 0;
    stack->maxSize = maxSize;
}

int isEmpty(Stack* stack) {
    return stack->top == NULL;
}

int isFull(Stack* stack) {
    return stack->size == stack->maxSize;
}

void push(Stack* stack, int data) {
    if (isFull(stack)) {
        printf("Stack is full. Cannot push element.\n");
        return;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
    stack->size++;
}

int main() {
    Stack stack;
    initialize(&stack, MAX_SIZE);

    if (isFull(&stack)) {
        printf("Stack is full.\n");
    } else {
        printf("Stack is not full.\n");
    }

    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);

    if (isFull(&stack)) {
        printf("Stack is full.\n");
    } else {
        printf("Stack is not full.\n");
    }

    return 0;
}
