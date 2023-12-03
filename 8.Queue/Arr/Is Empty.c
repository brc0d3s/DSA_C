int is_empty(Queue* queue) {
    return (queue->front == -1 && queue->rear == -1);
}
