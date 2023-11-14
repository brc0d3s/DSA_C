#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertAtMiddle(struct Node** head_ref, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = newNode;
    } else {
        struct Node* slow_ptr = *head_ref;
        struct Node* fast_ptr = *head_ref;

        while (fast_ptr != NULL && fast_ptr->next != NULL) {
            fast_ptr = fast_ptr->next->next;
            slow_ptr = slow_ptr->next;
        }

        newNode->next = slow_ptr->next;
        slow_ptr->next = newNode;
    }
}

void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    // Insert nodes into the linked list
    insertAtMiddle(&head, 1);
    insertAtMiddle(&head, 2);
    insertAtMiddle(&head, 3);
    insertAtMiddle(&head, 4);
    insertAtMiddle(&head, 5);

    // Print the linked list
    printf("Linked list: ");
    printList(head);

    // Free the memory
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
