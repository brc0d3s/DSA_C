#include <stdio.h>
#include <stdlib.h>

// Structure for a doubly linked list node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to insert a node at the end of a doubly linked list
void insertAtEnd(struct Node** head, int data) {
    // Allocate memory for the new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    // Set the data of the new node
    newNode->data = data;
    
    // Set the next pointer of the new node to NULL
    newNode->next = NULL;
    
    // If the list is empty, set the new node as the head
    if (*head == NULL) {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }
    
    // Traverse the list to find the last node
    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    
    // Set the next pointer of the last node to the new node
    current->next = newNode;
    
    // Set the prev pointer of the new node to the last node
    newNode->prev = current;
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
    
    // Insert nodes at the end
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    
    // Print the doubly linked list
    printf("Doubly linked list after insertion: ");
    printList(head);
    
    return 0;
}
