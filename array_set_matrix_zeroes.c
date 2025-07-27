/*
--------------------------------------
Problem: Set Matrix Zeroes
--------------------------------------

Given an m x n integer matrix, if an element is 0, set its entire row and column to 0 in-place.

Example:
Input:
matrix = [
  [1,1,1],
  [1,0,1],
  [1,1,1]
]

Output:
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]

*/

#include <stdio.h>
#include <stdbool.h>

void setZeroes(int** matrix, int matrixSize, int* matrixColSize){
    bool firstRow = false, firstCol = false;

    for (int i = 0; i < matrixSize; i++) {
        if (matrix[i][0] == 0) firstCol = true;
    }
    for (int j = 0; j < *matrixColSize; j++) {
        if (matrix[0][j] == 0) firstRow = true;
    }

    for (int i = 1; i < matrixSize; i++) {
        for (int j = 1; j < *matrixColSize; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    for (int i = 1; i < matrixSize; i++) {
        for (int j = 1; j < *matrixColSize; j++) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }

    if (firstRow) {
        for (int j = 0; j < *matrixColSize; j++) {
            matrix[0][j] = 0;
        }
    }

    if (firstCol) {
        for (int i = 0; i < matrixSize; i++) {
            matrix[i][0] = 0;
        }
    }
}
