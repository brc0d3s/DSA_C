#include<stdio.h>
#include<stdlib.h>

// Node structure
struct Node{
    int data;
    struct Node* pre;
    struct Node* next;
};


// Function to create a new node
struct Node* createNode(int data){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    if(newNode==NULL){
        printf("Memory allocation failed");
        return NULL;
    }
    newNode->data=data;
    newNode->pre=NULL;
    newNode->next=NULL;
    return newNode;
}


int main(){
    // Create a new node
    struct Node* newNode=createNode(20);

    // Access and print the data of the new node
    printf("Data of the new node: %d\n", newNode->data);

    // Free the memory allocated for the new node
    free(newNode);

    return 0;
    
}