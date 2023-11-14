#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertAtMiddle(struct Node** head, int value, int position) {
    // Allocate memory for the new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    // Assign the data value to the new node
    newNode->data = value;

    // Traverse to the node just before the required position
    struct Node* temp = *head;
    for (int i = 2; i < position; i++) {
        if (temp->next != NULL) {
            temp = temp->next;
        }
    }

    // Change the next pointers to include the new node in between
    newNode->next = temp->next;
    temp->next = newNode;
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

    // Insert nodes at the middle
    insertAtMiddle(&head, 1, 1);
    insertAtMiddle(&head, 3, 2);
    insertAtMiddle(&head, 2, 2);
    insertAtMiddle(&head, 4, 4);

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
