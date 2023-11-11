#include <stdio.h>
#include <stdlib.h>

// Node structure for circular doubly linked list
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

typedef struct Node Node;

// Function to traverse the circular doubly linked list
void traverseCircularDoublyLinkedList(Node* head) {
    if (head == NULL) {
        printf("Circular doubly linked list is empty.\n");
        return;
    }

    Node* current = head;

    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);

    printf("\n");
}

// Function to insert a node at the end of the circular doubly linked list
void insertAtEnd(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    if (*head == NULL) {
        newNode->prev = newNode;
        newNode->next = newNode;
        *head = newNode;
    } else {
        Node* last = (*head)->prev;

        newNode->prev = last;
        newNode->next = *head;
        (*head)->prev = newNode;
        last->next = newNode;
    }
}

int main() {
    // Create an empty circular doubly linked list
    Node* head = NULL;

    // Insert nodes at the end
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);

    // Traverse the circular doubly linked list
    printf("Circular Doubly Linked List: ");
    traverseCircularDoublyLinkedList(head);

    // Free memory
    Node* current = head;

    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
