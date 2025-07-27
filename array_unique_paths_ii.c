/*
Unique Paths II

You are given an m x n integer array grid called obstacleGrid. Return the number of unique paths from the top-left to the bottom-right corner, considering that 1 represents an obstacle and 0 represents a free space. You can only move right or down.

Example:
Input: obstacleGrid = [
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
Output: 2
*/

#include <stdio.h>
#include <stdlib.h>

int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize) {
    int m = obstacleGridSize;
    int n = *obstacleGridColSize;

    int** dp = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        dp[i] = (int*)calloc(n, sizeof(int));
    }

    dp[0][0] = (obstacleGrid[0][0] == 0) ? 1 : 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (obstacleGrid[i][j] == 1 || (i == 0 && j == 0)) continue;
            if (i > 0) dp[i][j] += dp[i - 1][j];
            if (j > 0) dp[i][j] += dp[i][j - 1];
        }
    }

    int result = dp[m - 1][n - 1];
    for (int i = 0; i < m; i++) free(dp[i]);
    free(dp);
    return result;
}

// Sample driver code
int main() {
    int rows = 3, cols = 3;
    int** grid = (int**)malloc(rows * sizeof(int*));
    int data[3][3] = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };
    for (int i = 0; i < rows; i++) {
        grid[i] = (int*)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            grid[i][j] = data[i][j];
        }
    }

    int result = uniquePathsWithObstacles(grid, rows, &cols);
    printf("Number of unique paths: %d\n", result);  // Output: 2

    for (int i = 0; i < rows; i++) free(grid[i]);
    free(grid);
    return 0;
}
