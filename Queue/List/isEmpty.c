#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};

void initialize(struct Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

int isEmpty(struct Queue* queue) {
    return queue->front == NULL;
}

void enqueue(struct Queue* queue, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (isEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }

    printf("Enqueued %d\n", value);
}

int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1; // Return a sentinel value to indicate an empty queue
    } else {
        struct Node* temp = queue->front;
        int value = temp->data;
        queue->front = queue->front->next;

        // Check if the queue becomes empty after dequeue
        if (queue->front == NULL) {
            queue->rear = NULL;
        }

        free(temp);
        printf("Dequeued %d\n", value);
        return value;
    }
}

int isEmpty(struct Queue* queue) {
    if (queue->front == NULL && queue->rear == NULL) {
        printf("Queue is empty.\n");
        return 1;
    } else {
        printf("Queue is not empty.\n");
        return 0;
    }
}

int main() {
    struct Queue queue;
    initialize(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    enqueue(&queue, 40);
    enqueue(&queue, 50);

    isEmpty(&queue);

    dequeue(&queue);
    dequeue(&queue);
    dequeue(&queue);
    dequeue(&queue);
    dequeue(&queue);
    dequeue(&queue); // Queue is empty, cannot dequeue

    isEmpty(&queue); // Queue is empty

    return 0;
}
