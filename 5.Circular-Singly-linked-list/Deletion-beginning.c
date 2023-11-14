#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void deleteAtBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("Circular linked list is empty. Nothing to delete.\n");
        return;
    }

    struct Node* temp = *head;
    struct Node* last = *head;

    while (last->next != *head) {
        last = last->next;
    }

    last->next = (*head)->next;
    *head = (*head)->next;

    free(temp);
}

void display(struct Node* head) {
    if (head == NULL) {
        printf("Circular linked list is empty.\n");
        return;
    }

    struct Node* current = head;
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    // Insert nodes into the circular linked list
    head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 10;

    struct Node* second = (struct Node*)malloc(sizeof(struct Node));
    second->data = 20;

    struct Node* third = (struct Node*)malloc(sizeof(struct Node));
    third->data = 30;

    head->next = second;
    second->next = third;
    third->next = head;

    // Display the circular linked list before deletion
    printf("Circular Linked List before deletion at the beginning: ");
    display(head);

    // Delete a node at the beginning
    deleteAtBeginning(&head);

    // Display the circular linked list after deletion
    printf("Circular Linked List after deletion at the beginning: ");
    display(head);

    // Free the memory allocated for the nodes
    free(head);
    free(second);
    free(third);

    return 0;
}
