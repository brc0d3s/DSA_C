#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node Node;

int searchCircularSinglyLinkedList(Node* head, int target) {
    if (head == NULL) {
        return 0; // Not Found
    }

    Node* current = head;

    do {
        if (current->data == target) {
            return 1; // Found
        }
        current = current->next;
    } while (current != head);

    return 0; // Not Found
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

    int target = 87;
    int result = searchCircularSinglyLinkedList(head, target);

    if (result) {
        printf("Element %d found in the circular singly linked list.\n", target);
    } else {
        printf("Element %d not found in the circular singly linked list.\n", target);
    }

    // Free memory
    free(head);
    free(second);
    free(third);

    return 0;
}
