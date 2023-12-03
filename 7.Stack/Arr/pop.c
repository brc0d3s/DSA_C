int pop(Stack* stack) {
    if (is_empty(stack)) {
        printf("Stack underflow\n");
        return -1; // Assuming -1 as an indicator of an error
    } else {
        return stack->items[stack->top--];
    }
}
