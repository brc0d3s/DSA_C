#include<stdio.h>
#define MAx_SIZE 100

int stack[MAx_SIZE];
int top= -1;

void push(int element){
    if(top == MAx_SIZE - 1){
        printf("Overflow");
    }else{
        top++;
        stack[top]=element;
        printf("Element %d pushed to the stack.\n", element);
    }
}

int main(){
    push(200);
    push(3009);
    push(1443);

    return 0;
}