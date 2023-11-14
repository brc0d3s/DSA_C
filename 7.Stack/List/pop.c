#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Stack {
    int arr[MAX_SIZE];
    int top;
};

void initialize(struct Stack* stack) {
    stack->top = -1;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot pop.\n");
        return -1;
    }
    int data = stack->arr[stack->top];
    stack->top--;
    return data;
}

int main() {
    struct Stack stack;
    initialize(&stack);

    // Push some elements into the stack
    stack.arr[++stack.top] = 10;
    stack.arr[++stack.top] = 20;
    stack.arr[++stack.top] = 30;

    // Pop elements from the stack
    printf("Popped element: %d\n", pop(&stack));
    printf("Popped element: %d\n", pop(&stack));
    printf("Popped element: %d\n", pop(&stack));

    return 0;
}
