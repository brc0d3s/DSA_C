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

// Function to insert a node at the end of the linked list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to search for an element in the linked list
struct Node* search(struct Node* head, int key) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == key) {
            return current; // Element found
        }
        current = current->next;
    }
    return NULL; // Element not found
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

    // Insert nodes at the end
    insertAtEnd(&head, 12);
    insertAtEnd(&head, 22);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 44);
    insertAtEnd(&head, 50);

    // Print the linked list
    printList(head);

    // Search for an element
    int key = 30;
    struct Node* result = search(head, key);
    if (result != NULL) {
        printf("Element %d found in the linked list.\n", key);
    } else {
        printf("Element %d not found in the linked list.\n", key);
    }

    return 0;
}
