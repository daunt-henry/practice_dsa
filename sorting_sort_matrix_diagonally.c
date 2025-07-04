/*
Sort the Matrix Diagonally

Approach:
- For each diagonal starting from the first column and then the first row (excluding [0][0]),
  we:
  1. Extract the diagonal into a temp array.
  2. Sort the temp array.
  3. Put the sorted elements back into the matrix.

Time: O(m * n * log(min(m, n))) — because each diagonal is sorted separately.
Space: O(min(m, n)) — temporary storage for one diagonal.

Example Input:
mat = [
  [3, 3, 1, 1],
  [2, 2, 1, 2],
  [1, 1, 1, 2]
]

Expected Output:
[
  [1, 1, 1, 1],
  [1, 2, 2, 2],
  [1, 2, 3, 3]
]
*/

#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int** diagonalSort(int** mat, int matSize, int* matColSize, int* returnSize, int** returnColumnSizes) {
    int m = matSize;
    int n = *matColSize;

    // Diagonals starting from first column
    for (int r = 0; r < m; r++) {
        int i = r, j = 0;
        int len = 0, temp[100];
        while (i < m && j < n) {
            temp[len++] = mat[i][j];
            i++; j++;
        }
        qsort(temp, len, sizeof(int), cmp);
        i = r; j = 0;
        for (int k = 0; k < len; k++) {
            mat[i++][j++] = temp[k];
        }
    }

    // Diagonals starting from first row (excluding 0,0)
    for (int c = 1; c < n; c++) {
        int i = 0, j = c;
        int len = 0, temp[100];
        while (i < m && j < n) {
            temp[len++] = mat[i][j];
            i++; j++;
        }
        qsort(temp, len, sizeof(int), cmp);
        i = 0; j = c;
        for (int k = 0; k < len; k++) {
            mat[i++][j++] = temp[k];
        }
    }

    *returnSize = m;
    *returnColumnSizes = (int*)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) {
        (*returnColumnSizes)[i] = n;
    }

    return mat;
}
