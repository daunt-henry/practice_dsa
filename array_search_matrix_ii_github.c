/*
Problem: Search a 2D Matrix II

Write an efficient algorithm that searches for a value in an m x n integer matrix.
This matrix has the following properties:
- Integers in each row are sorted in ascending from left to right.
- Integers in each column are sorted in ascending from top to bottom.

Example:
Input: matrix = [
  [1, 4, 7, 11, 15],
  [2, 5, 8, 12, 19],
  [3, 6, 9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
], target = 5

Output: true
*/

#include <stdio.h>
#include <stdbool.h>

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    int row = 0;
    int col = matrixColSize[0] - 1;

    while (row < matrixSize && col >= 0) {
        if (matrix[row][col] == target)
            return true;
        else if (matrix[row][col] > target)
            col--;
        else
            row++;
    }
    return false;
}

// Sample matrix data for testing
int main() {
    int matData[5][5] = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    int* matrix[5];
    for (int i = 0; i < 5; ++i)
        matrix[i] = matData[i];

    int colSize = 5;
    int target = 5;

    bool found = searchMatrix(matrix, 5, &colSize, target);
    printf("Target %d %s in the matrix.\n", target, found ? "found" : "not found");

    return 0;
}
