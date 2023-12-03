int peek(Stack* stack) {
    if (is_empty(stack)) {
        printf("Stack is empty\n");
        return -1; // Assuming -1 as an indicator of an error
    } else {
        return stack->items[stack->top];
    }
}
