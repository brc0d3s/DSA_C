#include <stdio.h>
#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

void push(int element) {
    if (top == MAX_SIZE - 1) {
        printf("Stack Overflow: Cannot push element %d, stack is full.\n", element);
    } else {
        stack[++top] = element;
        printf("Element %d pushed to the stack.\n", element);
    }
}

int main() {
    push(10);
    push(20);
    push(30);

    return 0;
}
