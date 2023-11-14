#include<stdio.h>

int main(){
    int Arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int rows = 3, cols = 3;
    int x = 50, rowPos = 1, colPos = 2;

    printf("2D Array elements before Update:\n");
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            printf("Arr[%d][%d] = %d ", i, j, Arr[i][j]);
        }
        printf("\n");
    }

    // Insertion
    Arr[rowPos][colPos] = x;

    printf("\n2D Array elements after Update:\n");
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            printf("Arr[%d][%d] = %d ", i, j, Arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}
