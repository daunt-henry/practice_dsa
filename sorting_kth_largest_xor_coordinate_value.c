/*
Find Kth Largest XOR Coordinate Value

Problem:
Given a matrix of integers, compute the XOR of all elements in the submatrix from (0,0) to (i,j) for all i,j.
Return the K-th largest of these values.

Approach:
- Use a prefix XOR matrix similar to prefix sum.
- Use formula:
    xor[i][j] = matrix[i][j] ^ xor[i-1][j] ^ xor[i][j-1] ^ xor[i-1][j-1]
- Store all XORs, sort in descending order and return the k-th.

Example:
Input: matrix = [[5,2],[1,6]], k = 1
Output: 7
Explanation: The XOR coordinate values are [5,7,6,0]. 7 is the largest.

Time Complexity: O(m * n log(m * n)) due to sorting
*/

#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return (*(int*)b - *(int*)a);  // descending
}

int kthLargestValue(int** matrix, int matrixSize, int* matrixColSize, int k) {
    int m = matrixSize, n = matrixColSize[0];
    int** xorMat = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; ++i)
        xorMat[i] = (int*)calloc(n, sizeof(int));

    int* results = (int*)malloc(m * n * sizeof(int));
    int idx = 0;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            int top = i > 0 ? xorMat[i-1][j] : 0;
            int left = j > 0 ? xorMat[i][j-1] : 0;
            int topLeft = (i > 0 && j > 0) ? xorMat[i-1][j-1] : 0;
            xorMat[i][j] = matrix[i][j] ^ top ^ left ^ topLeft;
            results[idx++] = xorMat[i][j];
        }
    }

    qsort(results, m * n, sizeof(int), cmp);
    int ans = results[k-1];

    for (int i = 0; i < m; ++i) free(xorMat[i]);
    free(xorMat);
    free(results);
    return ans;
}
