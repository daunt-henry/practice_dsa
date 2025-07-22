/*
Problem: Longest Increasing Path in a Matrix

Given an m x n integers matrix, return the length of the longest increasing path in matrix.
From each cell, you can move in four directions (up, down, left, or right). 
You may not move diagonally or move outside the boundary.

Example:
Input:
    matrix = [[9,9,4],[6,6,8],[2,1,1]]
Output:
    4
Explanation:
    The longest increasing path is [1, 2, 6, 9].

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int directions[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};

int dfs(int** matrix, int matrixSize, int* matrixColSize, int i, int j, int** dp) {
    if (dp[i][j] != 0)
        return dp[i][j];

    int maxLen = 1;
    for (int d = 0; d < 4; d++) {
        int ni = i + directions[d][0];
        int nj = j + directions[d][1];
        if (ni >= 0 && ni < matrixSize && nj >= 0 && nj < matrixColSize[0] && matrix[ni][nj] > matrix[i][j]) {
            int len = 1 + dfs(matrix, matrixSize, matrixColSize, ni, nj, dp);
            if (len > maxLen)
                maxLen = len;
        }
    }

    dp[i][j] = maxLen;
    return maxLen;
}

int longestIncreasingPath(int** matrix, int matrixSize, int* matrixColSize){
    if (matrixSize == 0 || matrixColSize[0] == 0)
        return 0;

    int** dp = (int**)malloc(matrixSize * sizeof(int*));
    for (int i = 0; i < matrixSize; ++i)
        dp[i] = (int*)calloc(matrixColSize[0], sizeof(int));

    int maxPath = 0;
    for (int i = 0; i < matrixSize; ++i) {
        for (int j = 0; j < matrixColSize[0]; ++j) {
            int path = dfs(matrix, matrixSize, matrixColSize, i, j, dp);
            if (path > maxPath)
                maxPath = path;
        }
    }

    for (int i = 0; i < matrixSize; ++i)
        free(dp[i]);
    free(dp);

    return maxPath;
}

// Sample test
int main() {
    int rows = 3, cols = 3;
    int data[3][3] = {
        {9, 9, 4},
        {6, 6, 8},
        {2, 1, 1}
    };

    int** matrix = (int**)malloc(rows * sizeof(int*));
    int* matrixColSize = (int*)malloc(rows * sizeof(int));
    for (int i = 0; i < rows; ++i) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
        matrixColSize[i] = cols;
        for (int j = 0; j < cols; ++j)
            matrix[i][j] = data[i][j];
    }

    int result = longestIncreasingPath(matrix, rows, matrixColSize);
    printf("Longest Increasing Path Length: %d\n", result);

    for (int i = 0; i < rows; ++i)
        free(matrix[i]);
    free(matrix);
    free(matrixColSize);
    return 0;
}
