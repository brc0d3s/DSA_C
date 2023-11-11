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

int isFull() {
    if (rear == SIZE - 1) {
        printf("Queue is full.\n");
        return 1;
    } else {
        printf("Queue is not full.\n");
        return 0;
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    isFull();

    return 0;
}
