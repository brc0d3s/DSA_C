#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

    printf("Enqueued %d\n", value);
}

int dequeue() {
    if (front == NULL) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1; // Return a sentinel value to indicate an empty queue
    } else {
        struct Node* temp = front;
        int value = temp->data;
        front = front->next;

        if (front == NULL) {
            rear = NULL;
        }

        free(temp);
        printf("Dequeued %d\n", value);
        return value;
    }
}

int peek() {
    if (front == NULL) {
        printf("Queue is empty. Cannot peek.\n");
        return -1; // Return a sentinel value to indicate an empty queue
    } else {
        int value = front->data;
        printf("Peeked %d\n", value);
        return value;
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    peek();

    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue(); // Queue is empty, cannot dequeue

    peek(); // Queue is empty, cannot peek

    return 0;
}
