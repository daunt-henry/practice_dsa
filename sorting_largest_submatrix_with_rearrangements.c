/*
Largest Submatrix With Rearrangements

Problem:
Given a binary matrix, you can rearrange the columns of each row independently. 
Find the largest area of a submatrix consisting of only 1s after rearranging columns optimally.

Approach:
- First, compute heights of 1s column-wise.
- Then, for each row, sort it in descending order.
- Compute area as height * width and track max.

Example:
Input: matrix = [[0,0,1],[1,1,1],[1,0,1]]
Output: 4
Explanation:
After rearranging, the matrix becomes:
[[1,0,0],
 [1,1,1],
 [1,1,0]]
The largest submatrix with only 1s is of size 2x2 = 4.

Time Complexity: O(m * n log n)

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);  // descending
}

int largestSubmatrix(int** matrix, int matrixSize, int* matrixColSize){
    int m = matrixSize, n = matrixColSize[0];
    for (int i = 1; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j]) matrix[i][j] += matrix[i-1][j];
        }
    }

    int maxArea = 0;
    int* row = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < m; ++i) {
        memcpy(row, matrix[i], n * sizeof(int));
        qsort(row, n, sizeof(int), cmp);
        for (int j = 0; j < n; ++j) {
            int area = row[j] * (j + 1);
            if (area > maxArea) maxArea = area;
        }
    }
    free(row);
    return maxArea;
}
