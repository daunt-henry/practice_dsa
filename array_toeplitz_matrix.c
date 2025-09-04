/*
 * Problem: Toeplitz Matrix
 * URL: https://leetcode.com/problems/toeplitz-matrix/
 *
 * A matrix is called Toeplitz if every diagonal from top-left 
 * to bottom-right has the same element.
 *
 * Example:
 * Input:
 * matrix = [
 *   [1,2,3,4],
 *   [5,1,2,3],
 *   [9,5,1,2]
 * ]
 * Output: true
 *
 * Explanation: 
 * Diagonals are consistent:
 * [1], [2,1], [3,2,5], [4,3,9], all have same values along diagonals.
 *
 * Approach:
 * We simply check if every element (except first row and first column)
 * is equal to its top-left neighbor.
 *
 * Time Complexity: O(m * n)
 * Space Complexity: O(1)
 */

#include <stdio.h>
#include <stdbool.h>

bool isToeplitzMatrix(int** matrix, int matrixSize, int* matrixColSize) {
    int m = matrixSize;
    int n = matrixColSize[0];
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (matrix[i][j] != matrix[i - 1][j - 1]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int arr[3][4] = {
        {1, 2, 3, 4},
        {5, 1, 2, 3},
        {9, 5, 1, 2}
    };

    int* matrix[3];
    for (int i = 0; i < 3; i++) {
        matrix[i] = arr[i];
    }
    int colSize = 4;

    bool result = isToeplitzMatrix(matrix, 3, &colSize);
    printf("Is Toeplitz? %s\n", result ? "true" : "false");

    return 0;
}
