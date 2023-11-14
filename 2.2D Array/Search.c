#include<stdio.h>

int main(){
    int Arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int rows = 3, cols = 3;
    int item = 5;

    printf("2D Array elements before search:\n");
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            printf("Arr[%d][%d] = %d ", i, j, Arr[i][j]);
        }
        printf("\n");
    }

    printf("\n\nArray element found after search:\n");
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            if (Arr[i][j] == item){
                printf("Found element %d at position [%d][%d]\n", item, i, j);
            }
        }
    }

    return 0;
}
