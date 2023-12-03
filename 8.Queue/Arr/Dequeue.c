int dequeue(Queue* queue) {
    if (is_empty(queue)) {
        printf("Queue underflow\n");
        return -1; // Indicator of an error
    } else {
        int removed_element = queue->items[queue->front];

        if (queue->front == queue->rear) {
            // If the queue has only one element, reset front and rear
            queue->front = queue->rear = -1;
        } else {
            // Move front to the next element in the circular queue
            queue->front = (queue->front + 1) % MAX_SIZE;
        }

        return removed_element;
    }
}
