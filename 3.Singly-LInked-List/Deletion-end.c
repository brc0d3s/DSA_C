#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void deleteFromEnd(struct Node** head) {
    // If the linked list is empty, return
    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    // If there is only one node in the list, delete it
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    // Traverse to the second last element
    struct Node* temp = *head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    // Change the next pointer of the second last element to NULL
    free(temp->next);
    temp->next = NULL;
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

    // Insert nodes at the end
    struct Node* first = (struct Node*)malloc(sizeof(struct Node));
    first->data = 1;

    struct Node* second = (struct Node*)malloc(sizeof(struct Node));
    second->data = 2;

    struct Node* third = (struct Node*)malloc(sizeof(struct Node));
    third->data = 3;

    first->next = second;
    second->next = third;
    third->next = NULL;

    // Delete node from the end
    deleteFromEnd(&head);

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
