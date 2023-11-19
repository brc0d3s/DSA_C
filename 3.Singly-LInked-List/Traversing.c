#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to traverse and print the linked list
void traverseLinkedList(struct Node *head){
    struct Node *temp = head;
    printf("\n\nList elements are - \n");
    while (temp != NULL){
        printf("%d --->", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    // Create the linked list
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    head->data = 1;

    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    second->data = 2;

    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    third->data = 3;

    head->next = second;
    second->next = third;
    third->next = NULL;

    // Traverse and print the linked list
    traverseLinkedList(head);

    // Free the memory allocated for each node
    free(head);
    free(second);
    free(third);

    return 0;
}
