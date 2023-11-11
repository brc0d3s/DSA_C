#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node Node;

void traverseCircularSinglyLinkedList(Node* head) {
    if (head == NULL) {
        printf("Circular singly linked list is empty.\n");
        return;
    }

    Node* current = head;

    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);

    printf("\n");
}

int main() {
    // Create a circular singly linked list
    Node* head = (Node*)malloc(sizeof(Node));
    Node* second = (Node*)malloc(sizeof(Node));
    Node* third = (Node*)malloc(sizeof(Node));

    head->data = 56;
    head->next = second;

    second->data = 87;
    second->next = third;

    third->data = 90;
    third->next = head; // Make it circular

    // Traverse the circular singly linked list
    printf("Circular Singly Linked List: ");
    traverseCircularSinglyLinkedList(head);

    // Free memory
    free(head);
    free(second);
    free(third);

    return 0;
}
