#include <stdio.h>
#include <stdlib.h>

// Structure for a doubly linked list node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to delete a node at a specified location in a doubly linked list
void deleteAtLocation(struct Node** head, int location) {
    // Check if the list is empty
    if (*head == NULL) {
        printf("List is empty. Deletion not possible.\n");
        return;
    }
    
    // Check if the specified location is less than 1
    if (location < 1) {
        printf("Invalid location. Deletion not possible.\n");
        return;
    }
    
    // If the specified location is 1, follow the steps to delete at the beginning
    if (location == 1) {
        struct Node* temp = *head;
        *head = (*head)->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        free(temp);
        return;
    }
    
    // Traverse the list to find the node at the specified location
    struct Node* current = *head;
    int count = 1;
    while (current != NULL && count < location) {
        current = current->next;
        count++;
    }
    
    // If the node at the specified location is not found
    if (current == NULL) {
        printf("Node at location %d not found in the list.\n", location);
        return;
    }
    
    // If the node at the specified location is the last node, follow the steps to delete at the end
    if (current->next == NULL) {
        current->prev->next = NULL;
        free(current);
        return;
    }
    
    // Update the next pointer of the previous node
    current->prev->next = current->next;
    
    // Update the prev pointer of the next node
    current->next->prev = current->prev;
    
    // Free the memory occupied by the current node
    free(current);
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
    
    struct Node* node3 = (struct Node*)malloc(sizeof(struct Node));
    node3->data = 3;
    node3->prev = NULL;
    node3->next = NULL;
    
    head->next = node2;
    node2->prev = head;
    
    node2->next = node3;
    node3->prev = node2;
    
    // Print the doubly linked list before deletion
    printf("Doubly linked list before deletion: ");
    printList(head);
    
    // Delete a node at the specified location
    deleteAtLocation(&head, 2);
    
    // Print the doubly linked list after deletion
    printf("Doubly linked list after deletion: ");
    printList(head);
    
    return 0;
}
