#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int data){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    if(newNode==NULL){
        printf("Memory allocation failed");
        return NULL;
    }
    newNode->data=data;
    newNode->prev=NULL;
    newNode->next=NULL;
    return newNode;
}

int main(){
    struct Node* newNode=createNode(45);
    
    printf("The data at the node is %d",newNode->data);
    
    free(newNode);
    
    return 0;
}