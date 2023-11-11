#include <stdio.h>

#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

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

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue(); // Queue is empty, cannot dequeue

    return 0;
}
