#include<stdio.h>
int main(){
    int arr[20] = {18, 30, 15, 70, 12}; 
     int i,n=5;

    printf("Array elements before deletion");  
    for ( i=0; i < n; i++){
        printf("\nArr[%d] = %d ",i,arr[i]);
    }

    //LEFT SHIFT[DELETION]
    for (i = 1; i < n-1; i++){
        arr[i]=arr[i+1];
    }
    n--;
    

    printf("\n\nArray elements after deletion"); 
    for ( i=0; i < n; i++){
        printf("\nArr[%d] = %d ",i,arr[i]);
    } 
}