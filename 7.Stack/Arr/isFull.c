#include <stdio.h>

#define MAX_SIZE 100

typedef struct {
    int arr[MAX_SIZE];
    int top;
    int maxSize;
} Stack;

void initialize(Stack *stack, int maxSize) {
    stack->top = -1;
    stack->maxSize = maxSize;
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

int isFull(Stack *stack) {
    return stack->top == stack->maxSize - 1;
}

void push(Stack *stack, int data) {
    if (isFull(stack)) {
        printf("Stack is full. Cannot push element.\n");
        return;
    }
    stack->arr[++stack->top] = data;
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
