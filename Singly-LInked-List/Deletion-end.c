#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to delete the last node of the linked list
void deleteLast(struct Node** head) {
    struct Node* temp = *head;
    struct Node* last = NULL;

    if (*head == NULL)
        return;

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    // Find the second last node
    while (temp->next->next != NULL) {
        last = temp;
        temp = temp->next;
    }

    // Change next of second last
    last->next = NULL;

    // Free memory of last node
    free(temp);
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* current = head;
    printf("Linked List: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    // Create the linked list
    head = createNode(2);
    head->next = createNode(3);
    head->next->next = createNode(4);
    head->next->next->next = createNode(5);

    // Delete the last node
    deleteLast(&head);

    // Print the linked list
    printList(head);

    return 0;
}
