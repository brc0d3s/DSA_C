#include <stdio.h>

#define MAX_SIZE 100

struct Stack
{
    int arr[MAX_SIZE];
    int top;
};

void initialize(struct Stack *stack)
{
    stack->top = -1;
}

int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

void push(struct Stack *stack, int x)
{
    if (stack->top == MAX_SIZE - 1)
    {
        printf("Stack overflow\n");
        return;
    }
    stack->arr[++stack->top] = x;
}

int pop(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack underflow\n");
        return -1;
    }
    return stack->arr[stack->top--];
}

int main()
{
    struct Stack stack;
    initialize(&stack);

    push(&stack, 1);
    push(&stack, 2);

    printf("Popped element is %d\n", pop(&stack));

    return 0;
}
