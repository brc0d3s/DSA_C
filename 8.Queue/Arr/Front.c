int front(Queue* queue) {
    if (is_empty(queue)) {
        printf("Queue is empty\n");
        return -1; // Indicator of an error
    } else {
        return queue->items[queue->front];
    }
}
