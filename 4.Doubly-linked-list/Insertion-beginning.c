#include <stdio.h>
#include <stdlib.h>

// Structure for a doubly linked list node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to insert a node at the beginning of a doubly linked list
void insertAtBeginning(struct Node** head, int data) {
    // Allocate memory for the new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    // Set the data of the new node
    newNode->data = data;
    
    // Set the next pointer of the new node to the current head
    newNode->next = *head;
    
    // Set the prev pointer of the new node to NULL
    newNode->prev = NULL;
    
    // If the current head is not NULL, set its prev pointer to the new node
    if (*head != NULL) {
        (*head)->prev = newNode;
    }
    
    // Update the head pointer to point to the new node
    *head = newNode;
}

// Function to print the doubly linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Driver code
int main() {
    struct Node* head = NULL;
    
    // Insert nodes at the beginning
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 1);
    
    // Print the doubly linked list
    printf("Doubly linked list after insertion: ");
    printList(head);
    
    return 0;
}
