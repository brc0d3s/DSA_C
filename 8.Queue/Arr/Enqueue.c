void enqueue(Queue* queue, int element) {
    if (is_full(queue)) {
        printf("Queue overflow\n");
    } else {
        queue->rear = (queue->rear + 1) % MAX_SIZE;
        queue->items[queue->rear] = element;

        if (is_empty(queue)) {
            // If the queue was empty, set front to the newly added element
            queue->front = queue->rear;
        }
    }
}
