#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void deleteFromBeginning(struct Node** head) {
    // If the linked list is empty, return
    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    // Point the head pointer to the second node
    *head = (*head)->next;
}

void traverseLinkedList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    // Insert nodes at the beginning
    head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 4;

    struct Node* second = (struct Node*)malloc(sizeof(struct Node));
    second->data = 3;

    struct Node* third = (struct Node*)malloc(sizeof(struct Node));
    third->data = 2;

    struct Node* fourth = (struct Node*)malloc(sizeof(struct Node));
    fourth->data = 1;

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = NULL;

    // Delete node from the beginning
    deleteFromBeginning(&head);

    // Traverse the linked list
    traverseLinkedList(head);

    // Free the memory
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
