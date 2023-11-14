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
void deleteAtBeginning(Node** head) {
    if (*head == NULL) {
        printf("Circular doubly linked list is empty. Nothing to delete.\n");
        return;
    }

    Node* last = (*head)->prev;

    if (*head == last) {
        free(*head);
        *head = NULL;
    } else {
        Node* second = (*head)->next;

        second->prev = last;
        last->next = second;
        free(*head);
        *head = second;
    }
}

int main() {
    // Create a circular doubly linked list
    Node* head = NULL;

    // Insert nodes at the end
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);

    // Delete node at the beginning
    deleteAtBeginning(&head);

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
