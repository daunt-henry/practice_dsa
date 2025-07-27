/*
Problem: Rotate Image

You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

Example:
Input:
matrix = [
  [1,2,3],
  [4,5,6],
  [7,8,9]
]

Output:
matrix = [
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
*/

#include <stdio.h>

void rotate(int** matrix, int matrixSize, int* matrixColSize){
    for(int i = 0; i < matrixSize; i++){
        for(int j = i + 1; j < matrixSize; j++){
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }

    for(int i = 0; i < matrixSize; i++){
        for(int j = 0; j < matrixSize / 2; j++){
            int temp = matrix[i][j];
            matrix[i][j] = matrix[i][matrixSize - j - 1];
            matrix[i][matrixSize - j - 1] = temp;
        }
    }
}

// Sample main function to test
int main() {
    int n = 3;
    int data[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int* matrix[3];
    int colSize[3];
    for (int i = 0; i < n; i++) {
        matrix[i] = data[i];
        colSize[i] = n;
    }

    rotate(matrix, n, colSize);

    printf("Rotated matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
