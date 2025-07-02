/*
Problem: Kth Smallest Element in a Sorted Matrix

Description:
Given an n x n matrix where each row and column is sorted in ascending order,
return the kth smallest element in the matrix.

Approach:
1. Binary search between min and max values in matrix
2. For each mid, count how many elements <= mid using optimized 2D traversal

Time: O(n * log(max - min))
Space: O(1)
*/

#include <stdio.h>
#include <stdlib.h>

int countLessEqual(int** matrix, int n, int mid) {
    int count = 0;
    int row = n - 1, col = 0;

    while (row >= 0 && col < n) {
        if (matrix[row][col] <= mid) {
            count += row + 1;
            col++;
        } else {
            row--;
        }
    }

    return count;
}

int kthSmallest(int** matrix, int matrixSize, int* matrixColSize, int k) {
    int low = matrix[0][0];
    int high = matrix[matrixSize - 1][matrixSize - 1];

    while (low < high) {
        int mid = low + (high - low) / 2;
        int count = countLessEqual(matrix, matrixSize, mid);

        if (count < k) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }

    return low;
}

// Test
int main() {
    int raw[3][3] = {
        {1, 5, 9},
        {10, 11, 13},
        {12, 13, 15}
    };
    int n = 3;
    int k = 8;

    int** matrix = malloc(sizeof(int*) * n);
    int* colSizes = malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        matrix[i] = malloc(sizeof(int) * n);
        colSizes[i] = n;
        for (int j = 0; j < n; j++) {
            matrix[i][j] = raw[i][j];
        }
    }

    int result = kthSmallest(matrix, n, colSizes, k);
    printf("Kth smallest element (k=%d): %d\n", k, result);

    for (int i = 0; i < n; i++) free(matrix[i]);
    free(matrix);
    free(colSizes);
    return 0;
}

/*
========= OUTPUT =========
Kth smallest element (k=8): 13
==========================
*/
