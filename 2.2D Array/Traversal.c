#include<stdio.h>

int main(){
    int Arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int i, j, rows, cols;

    rows = 3;
    cols = 3;

    for (i = 0; i < rows; i++){
        for (j = 0; j < cols; j++){
            printf("Arr[%d][%d] = %d ", i, j, Arr[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
