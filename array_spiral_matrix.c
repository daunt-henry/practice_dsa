/*
Problem: Spiral Matrix

Given an m x n matrix, return all elements of the matrix in spiral order.

Example 1:
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]

Example 2:
Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
*/

#include <stdio.h>
#include <stdlib.h>

int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int top = 0, bottom = matrixSize - 1;
    int left = 0, right = *matrixColSize - 1;
    int total = matrixSize * (*matrixColSize);
    *returnSize = 0;
    int* result = (int*)malloc(sizeof(int) * total);

    while (*returnSize < total) {
        for (int i = left; i <= right && *returnSize < total; i++)
            result[(*returnSize)++] = matrix[top][i];
        top++;
        for (int i = top; i <= bottom && *returnSize < total; i++)
            result[(*returnSize)++] = matrix[i][right];
        right--;
        for (int i = right; i >= left && *returnSize < total; i--)
            result[(*returnSize)++] = matrix[bottom][i];
        bottom--;
        for (int i = bottom; i >= top && *returnSize < total; i--)
            result[(*returnSize)++] = matrix[i][left];
        left++;
    }

    return result;
}

// Sample test
int main() {
    int data[3][4] = {{1, 2, 3, 4},
                      {5, 6, 7, 8},
                      {9,10,11,12}};
    int* matrix[3];
    for (int i = 0; i < 3; i++)
        matrix[i] = data[i];

    int colSize = 4, returnSize;
    int* result = spiralOrder(matrix, 3, &colSize, &returnSize);

    printf("Spiral Order: ");
    for (int i = 0; i < returnSize; i++)
        printf("%d ", result[i]);
    printf("\n");

    free(result);
    return 0;
}
