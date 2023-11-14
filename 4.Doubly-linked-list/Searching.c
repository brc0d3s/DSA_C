#include <stdio.h>
#include <stdlib.h>

// Structure for a doubly linked list node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to search for a specific data value in a doubly linked list
struct Node* search(struct Node* head, int value) {
    // Traverse the list until the end or the desired value is found
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == value) {
            return current; // Value found, return the pointer to the node
        }
        current = current->next;
    }
    
    return NULL; // Value not found
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
    
    // Print the doubly linked list
    printf("Doubly linked list: ");
    printList(head);
    
    // Search for a specific value
    int searchValue = 2;
    struct Node* result = search(head, searchValue);
    
    // Check if the value was found
    if (result != NULL) {
        printf("Value %d found in the list.\n", searchValue);
    } else {
        printf("Value %d not found in the list.\n", searchValue);
    }
    
    return 0;
}
