#include<stdio.h>
#include<stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

int main() {
    struct Node* head = NULL;
    struct Node* ptr;

    // Create a new node
    ptr = (struct Node*)malloc(sizeof(struct Node));
    if (ptr == NULL) {
        printf("Memory allocation failed!");
        return 0;
    }
    ptr->data = 10;
    ptr->next = NULL;

    // Assign the new node to the head of the linked list
    head = ptr;

    // Print the data of the new node
    printf("Data of the new node: %d\n", head->data);

    // Free the memory allocated for the new node
    free(ptr);

    return 0;
}
