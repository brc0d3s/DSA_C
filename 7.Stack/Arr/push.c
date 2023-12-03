void push(Stack* stack, int element) {
    if (is_full(stack)) {
        printf("Stack overflow\n");
    } else {
        stack->items[++stack->top] = element;
    }
}
