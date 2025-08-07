/*
Problem: Range Sum Query 2D - Immutable

Design a data structure that computes the sum of elements within a submatrix of a fixed 2D matrix.

Operations:
- Initialize with the matrix.
- For each query sumRegion(row1, col1, row2, col2), return the sum of all elements inside the rectangle defined by 
  its upper left corner (row1, col1) and lower right corner (row2, col2).

Example:
matrix = [
  [3, 0, 1, 4, 2],
  [5, 6, 3, 2, 1],
  [1, 2, 0, 1, 5],
  [4, 1, 0, 1, 7],
  [1, 0, 3, 0, 5]
]
sumRegion(2, 1, 4, 3) -> 8
sumRegion(1, 1, 2, 2) -> 11
sumRegion(1, 2, 2, 4) -> 12
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int rows;
    int cols;
    int** prefix;
} NumMatrix;

NumMatrix* numMatrixCreate(int** matrix, int matrixSize, int* matrixColSize) {
    int m = matrixSize;
    int n = matrixColSize[0];
    NumMatrix* obj = (NumMatrix*)malloc(sizeof(NumMatrix));
    obj->rows = m;
    obj->cols = n;
    obj->prefix = (int**)malloc((m + 1) * sizeof(int*));
    for (int i = 0; i <= m; i++) {
        obj->prefix[i] = (int*)calloc(n + 1, sizeof(int));
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            obj->prefix[i][j] = matrix[i - 1][j - 1]
                + obj->prefix[i - 1][j]
                + obj->prefix[i][j - 1]
                - obj->prefix[i - 1][j - 1];
        }
    }
    return obj;
}

int numMatrixSumRegion(NumMatrix* obj, int row1, int col1, int row2, int col2) {
    int r1 = row1 + 1, c1 = col1 + 1, r2 = row2 + 1, c2 = col2 + 1;
    return obj->prefix[r2][c2]
         - obj->prefix[r1 - 1][c2]
         - obj->prefix[r2][c1 - 1]
         + obj->prefix[r1 - 1][c1 - 1];
}

void numMatrixFree(NumMatrix* obj) {
    for (int i = 0; i <= obj->rows; i++) {
        free(obj->prefix[i]);
    }
    free(obj->prefix);
    free(obj);
}

int main() {
    int data[5][5] = {
        {3, 0, 1, 4, 2},
        {5, 6, 3, 2, 1},
        {1, 2, 0, 1, 5},
        {4, 1, 0, 1, 7},
        {1, 0, 3, 0, 5}
    };

    int* matrix[5];
    for (int i = 0; i < 5; i++) matrix[i] = data[i];
    int colSize = 5;

    NumMatrix* obj = numMatrixCreate(matrix, 5, &colSize);

    printf("sumRegion(2, 1, 4, 3) = %d\n", numMatrixSumRegion(obj, 2, 1, 4, 3)); // 8
    printf("sumRegion(1, 1, 2, 2) = %d\n", numMatrixSumRegion(obj, 1, 1, 2, 2)); // 11
    printf("sumRegion(1, 2, 2, 4) = %d\n", numMatrixSumRegion(obj, 1, 2, 2, 4)); // 12

    numMatrixFree(obj);
    return 0;
}
