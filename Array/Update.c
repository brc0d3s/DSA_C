int main(){
    int arr[20] = {18, 30, 15, 70, 12}; 
     int i,n=5,x=50,pos=2;

    printf("Array elements before Update");  
    for ( i=0; i < n; i++){
        printf("\nArr[%d] = %d ",i,arr[i]);
    }

    //INSERTION
    arr[pos]=x;


    printf("\n\nArray elements after Update"); 
    for ( i=0; i < n; i++){
        printf("\nArr[%d] = %d ",i,arr[i]);
    } 
}