#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Stack
{
    struct Node *top;
};

void push(struct Stack *stack, int x)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(struct Stack *stack)
{
    if (stack->top == NULL)
    {
        printf("Stack underflow");
        return -1;
    }

    struct Node *temp = stack->top;
    int popElement = temp->data;
    stack->top = stack->top->next;
    free(temp);

    return popElement;
}

int main()
{
    struct Stack *stack = malloc(sizeof(struct Stack));
    stack->top = NULL;

    push(stack, 1);
    push(stack, 2);

    printf("Popped element is %d\n", pop(stack));

    return 0;
}