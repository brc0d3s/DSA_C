#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the stack
#define MAX_SIZE 100

// Define the stack structure
typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;

// Initialize an empty stack
void initialize(Stack* stack) {
    stack->top = -1;
}

// Check if the stack is empty
int is_empty(Stack* stack) {
    return stack->top == -1;
}

// Check if the stack is full
int is_full(Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

// Push an element onto the stack
void push(Stack* stack, int element) {
    if (is_full(stack)) {
        printf("Stack overflow\n");
    } else {
        stack->items[++stack->top] = element;
    }
}

// Pop an element from the stack
int pop(Stack* stack) {
    if (is_empty(stack)) {
        printf("Stack underflow\n");
        return -1; // Assuming -1 as an indicator of an error
    } else {
        return stack->items[stack->top--];
    }
}

// Peek at the top element of the stack without removing it
int peek(Stack* stack) {
    if (is_empty(stack)) {
        printf("Stack is empty\n");
        return -1; // Assuming -1 as an indicator of an error
    } else {
        return stack->items[stack->top];
    }
}

// Example usage
int main() {
    Stack myStack;
    initialize(&myStack);

    push(&myStack, 10);
    push(&myStack, 20);
    push(&myStack, 30);

    printf("Top element: %d\n", peek(&myStack));

    printf("Popped element: %d\n", pop(&myStack));
    printf("Popped element: %d\n", pop(&myStack));

    printf("Is the stack empty? %s\n", is_empty(&myStack) ? "Yes" : "No");

    return 0;
}
