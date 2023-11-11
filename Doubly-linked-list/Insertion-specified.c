#include <stdio.h>
#include <stdlib.h>

// Structure for a doubly linked list node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to insert a node after a specified node in a doubly linked list
void insertAfter(struct Node* prevNode, int data) {
    // Check if the previous node is NULL
    if (prevNode == NULL) {
        printf("Previous node cannot be NULL.\n");
        return;
    }
    
    // Allocate memory for the new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    // Set the data of the new node
    newNode->data = data;
    
    // Set the next pointer of the new node to the next pointer of the previous node
    newNode->next = prevNode->next;
    
    // Set the prev pointer of the new node to the previous node
    newNode->prev = prevNode;
    
    // If the next pointer of the previous node is not NULL, update its prev pointer to the new node
    if (prevNode->next != NULL) {
        prevNode->next->prev = newNode;
    }
    
    // Update the next pointer of the previous node to the new node
    prevNode->next = newNode;
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
    insertAfter(head, 1); // Trying to insert after NULL, should print an error message
    insertAfter(head, 2); // Trying to insert after NULL, should print an error message
    
    // Create a doubly linked list
    struct Node* node1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* node2 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* node3 = (struct Node*)malloc(sizeof(struct Node));
    
    node1->data = 1;
    node2->data = 2;
    node3->data = 3;
    
    node1->prev = NULL;
    node1->next = node2;
    
    node2->prev = node1;
    node2->next = node3;
    
    node3->prev = node2;
    node3->next = NULL;
    
    head = node1;
    
    // Print the doubly linked list before insertion
    printf("Doubly linked list before insertion: ");
    printList(head);
    
    // Insert a node after the specified node
    insertAfter(node2, 4);
    
    // Print the doubly linked list after insertion
    printf("Doubly linked list after insertion: ");
    printList(head);
    
    return 0;
}
