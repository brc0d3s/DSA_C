int is_full(Queue* queue) {
    return ((queue->rear + 1) % MAX_SIZE == queue->front);
}
