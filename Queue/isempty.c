#include <stdio.h>

#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

void enqueue(int value) {
    if (rear == SIZE - 1) {
        printf("Queue is full. Cannot enqueue %d\n", value);
    } else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = value;
        printf("Enqueued %d\n", value);
    }
}

int dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1; // Return a sentinel value to indicate an empty queue
    } else {
        int value = queue[front];
        front++;
        printf("Dequeued %d\n", value);
        return value;
    }
}

int isEmpty() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty.\n");
        return 1;
    } else {
        printf("Queue is not empty.\n");
        return 0;
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    isEmpty();

    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue(); // Queue is empty, cannot dequeue

    isEmpty(); // Queue is empty

    return 0;
}
