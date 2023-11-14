#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to traverse and print the linked list
void traverseLinkedList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    // Create the linked list
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 1;

    struct Node* second = (struct Node*)malloc(sizeof(struct Node));
    second->data = 2;

    struct Node* third = (struct Node*)malloc(sizeof(struct Node));
    third->data = 3;

    head->next = second;
    second->next = third;
    third->next = NULL;

    // Traverse and print the linked list
    traverseLinkedList(head);

    // Free the memory allocated for the linked list
    free(head);
    free(second);
    free(third);

    return 0;
}
