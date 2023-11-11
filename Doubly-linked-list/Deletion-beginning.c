#include <stdio.h>
#include <stdlib.h>

// Structure for a doubly linked list node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to delete a node at the beginning of a doubly linked list
void deleteAtBeginning(struct Node** head) {
    // Check if the list is empty
    if (*head == NULL) {
        printf("List is empty. Deletion not possible.\n");
        return;
    }
    
    // Store the reference to the head node in a temporary variable
    struct Node* temp = *head;
    
    // Update the head pointer to point to the next node
    *head = (*head)->next;
    
    // If the new head is not NULL, set its prev pointer to NULL
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    
    // Free the memory occupied by the deleted node
    free(temp);
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
    head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 1;
    head->prev = NULL;
    head->next = NULL;
    
    struct Node* node2 = (struct Node*)malloc(sizeof(struct Node));
    node2->data = 2;
    node2->prev = NULL;
    node2->next = NULL;
    
    head->next = node2;
    node2->prev = head;
    
    // Print the doubly linked list before deletion
    printf("Doubly linked list before deletion: ");
    printList(head);
    
    // Delete a node at the beginning
    deleteAtBeginning(&head);
    
    // Print the doubly linked list after deletion
    printf("Doubly linked list after deletion: ");
    printList(head);
    
    return 0;
}
