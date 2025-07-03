/*
Problem:
Return all coordinates of the matrix sorted by their Manhattan distance
from a given center cell.

Approach:
- Generate all (row, col) pairs.
- Store each point with center reference temporarily.
- Sort by Manhattan distance.
- Return the coordinates after trimming.

Time: O(n log n) for sorting
Space: O(n)
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int cmp(const void* a, const void* b) {
    int* p1 = *(int**)a;
    int* p2 = *(int**)b;
    int d1 = abs(p1[0] - p1[2]) + abs(p1[1] - p1[3]);
    int d2 = abs(p2[0] - p2[2]) + abs(p2[1] - p2[3]);
    return d1 - d2;
}

int** allCellsDistOrder(int rows, int cols, int rCenter, int cCenter, int* returnSize, int** returnColumnSizes) {
    int total = rows * cols;
    int** res = (int**)malloc(sizeof(int*) * total);
    *returnColumnSizes = (int*)malloc(sizeof(int) * total);
    *returnSize = total;

    for (int i = 0, idx = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++, idx++) {
            res[idx] = (int*)malloc(sizeof(int) * 4);
            res[idx][0] = i;
            res[idx][1] = j;
            res[idx][2] = rCenter;
            res[idx][3] = cCenter;
        }
    }

    qsort(res, total, sizeof(int*), cmp);

    for (int i = 0; i < total; i++) {
        res[i] = realloc(res[i], sizeof(int) * 2);
        (*returnColumnSizes)[i] = 2;
    }

    return res;
}

// Test
int main() {
    int rows = 2, cols = 3, rCenter = 1, cCenter = 2;
    int returnSize;
    int* returnColumnSizes;
    int** result = allCellsDistOrder(rows, cols, rCenter, cCenter, &returnSize, &returnColumnSizes);

    printf("Matrix cells in distance order:\n");
    for (int i = 0; i < returnSize; i++) {
        printf("[%d, %d]\n", result[i][0], result[i][1]);
        free(result[i]);
    }
    free(result);
    free(returnColumnSizes);

    return 0;
}

/*
========= OUTPUT =========
Matrix cells in distance order:
[1, 2]
[0, 2]
[1, 1]
[0, 1]
[1, 0]
[0, 0]
==========================
*/
