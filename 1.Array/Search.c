#include<stdio.h>
int main(){
    int arr[20] = {18, 30, 15, 70, 12}; 
     int i,n=5,item=70;

    printf("Array elements before insertion");  
    for ( i=0; i < n; i++){
        printf("\nArr[%d] = %d ",i,arr[i]);
    }


    printf("\n\nArray element found after search"); 
    for ( i=0; i < n; i++){
        if (arr[i]==item){
            printf("\nFound element %d at position %d\n", item, i+1);
        }
        
    } 
}