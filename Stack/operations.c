#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Stack structure
struct Stack {
    int data[MAX_SIZE];
    int top;
};

typedef struct Stack Stack;

// Function to initialize the stack
void initialize(Stack* stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
int isFull(Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

// Function to push an element onto the stack
void push(Stack* stack, int element) {
    if (isFull(stack)) {
        printf("Stack Overflow: Cannot push element onto a full stack.\n");
        return;
    }

    stack->data[++stack->top] = element;
}

// Function to pop the top element from the stack
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow: Cannot pop element from an empty stack.\n");
        return -1;
    }

    return stack->data[stack->top--];
}

// Function to get the top element of the stack
int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return -1;
    }

    return stack->data[stack->top];
}

// Function to get the size of the stack
int count(Stack* stack) {
    return stack->top + 1;
}

// Function to change the element at the given position
void change(Stack* stack, int position, int newValue) {
    if (position < 0 || position > stack->top) {
        printf("Invalid position.\n");
        return;
    }

    stack->data[position] = newValue;
}

// Function to display all the elements in the stack
void display(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Elements in the stack: ");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->data[i]);
    }
    printf("\n");
}

int main() {
    Stack stack;
    initialize(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Top element: %d\n", peek(&stack));

    printf("Popped element: %d\n", pop(&stack));

    printf("Size of stack: %d\n", count(&stack));

    change(&stack, 1, 50);

    display(&stack);

    return 0;
}
