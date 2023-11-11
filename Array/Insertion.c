#include<stdio.h>
int main(){
    int arr[20] = {18, 30, 15, 70, 12}; 
     int i,n=5,x=50,pos=5;

    printf("Array elements before insertion");  
    for ( i=0; i < n; i++){
        printf("\nArr[%d] = %d ",i,arr[i]);
    }

    //insertion
    n++;
    for (i = n-1; i >= pos; i--){
        arr[i] = arr[i - 1];
    }    
    arr[pos - 1] = x; 
    
    
    printf("\n\nArray elements after insertion"); 
    for ( i=0; i < n; i++){
        printf("\nArr[%d] = %d ",i,arr[i]);
    } 
}