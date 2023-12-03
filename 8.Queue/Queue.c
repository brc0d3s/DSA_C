#include <stdio.h>

// Define the maximum size of the queue
#define MAX_SIZE 5

// Define the queue structure
typedef struct {
    int items[MAX_SIZE];
    int front;
    int rear;
} Queue;

// Function prototypes
void initialize(Queue* queue);
void enqueue(Queue* queue, int element);
int dequeue(Queue* queue);
int front(Queue* queue);
int is_empty(Queue* queue);
int is_full(Queue* queue);

int main() {
    Queue myQueue;
    initialize(&myQueue);

    enqueue(&myQueue, 10);
    enqueue(&myQueue, 20);
    enqueue(&myQueue, 30);

    printf("Front element: %d\n", front(&myQueue));

    printf("Dequeued element: %d\n", dequeue(&myQueue));
    printf("Dequeued element: %d\n", dequeue(&myQueue));

    printf("Is the queue empty? %s\n", is_empty(&myQueue) ? "Yes" : "No");

    return 0;
}

// Initialize an empty queue
void initialize(Queue* queue) {
    queue->front = queue->rear = -1;
}

// Check if the queue is empty
int is_empty(Queue* queue) {
    return (queue->front == -1 && queue->rear == -1);
}

// Check if the queue is full
int is_full(Queue* queue) {
    return ((queue->rear + 1) % MAX_SIZE == queue->front);
}

// Enqueue an element into the queue
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

// Dequeue an element from the queue
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

// Peek at the front element of the queue without removing it
int front(Queue* queue) {
    if (is_empty(queue)) {
        printf("Queue is empty\n");
        return -1; // Indicator of an error
    } else {
        return queue->items[queue->front];
    }
}
