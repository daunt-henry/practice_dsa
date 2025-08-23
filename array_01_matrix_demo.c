/*
Problem: 01 Matrix (LeetCode 542)
URL: https://leetcode.com/problems/01-matrix/

Given an m × n binary matrix `mat` (0s and 1s), return a matrix of the 
same dimensions where each cell's value is the distance to the nearest 0.
You can move up, down, left, or right.

Approach: Multi-Source Breadth-First Search
- Initialize result matrix `res` with 0s for original 0s, -1 for 1s.
- Enqueue all 0-cells.
- BFS layer by layer: for each neighbor unvisited (res = -1), set distance = current + 1 and enqueue.

Time Complexity: O(m · n)  
Space Complexity: O(m · n)
*/

#include <stdio.h>
#include <stdlib.h>

int* queue_r;
int* queue_c;

int** updateMatrix(int** mat, int matSize, int* matColSize, int* returnSize, int** returnColumnSizes) {
    int m = matSize, n = matColSize[0];
    *returnSize = m;
    *returnColumnSizes = malloc(m * sizeof(int));
    int** res = malloc(m * sizeof(int*));
    queue_r = malloc(m * n * sizeof(int));
    queue_c = malloc(m * n * sizeof(int));

    int front = 0, back = 0;
    for (int i = 0; i < m; i++) {
        res[i] = malloc(n * sizeof(int));
        (*returnColumnSizes)[i] = n;
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 0) {
                res[i][j] = 0;
                queue_r[back] = i;
                queue_c[back++] = j;
            } else {
                res[i][j] = -1;
            }
        }
    }

    int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    while (front < back) {
        int r = queue_r[front];
        int c = queue_c[front++];
        for (int d = 0; d < 4; d++) {
            int nr = r + dirs[d][0];
            int nc = c + dirs[d][1];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && res[nr][nc] == -1) {
                res[nr][nc] = res[r][c] + 1;
                queue_r[back] = nr;
                queue_c[back++] = nc;
            }
        }
    }

    free(queue_r);
    free(queue_c);
    return res;
}

void printMatrix(int** mat, int rows, int* cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols[i]; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int m = 3, n = 3;
    int colSize[] = {3, 3, 3};
    int mat0[] = {0, 0, 0};
    int mat1[] = {0, 1, 0};
    int mat2[] = {1, 1, 1};
    int* mat[] = {mat0, mat1, mat2};

    int returnSize, *returnCols;
    int** res = updateMatrix(mat, m, colSize, &returnSize, &returnCols);

    printf("Input:\n");
    printMatrix(mat, m, colSize);
    printf("\nOutput (distances):\n");
    printMatrix(res, returnSize, returnCols);

    // Cleanup
    for (int i = 0; i < returnSize; i++) {
        free(res[i]);
    }
    free(res);
    free(returnCols);

    return 0;
}
