/*
Number of Increasing Paths in a Grid

You are given an m x n integer matrix grid, where you can move in four directions (up, down, left, right).
Return the number of strictly increasing paths in the grid. Since the answer may be large, return it modulo 10^9 + 7.

Example:
Input: grid = [[1,1],[3,4]]
Output: 8

Explanation:
There are 8 increasing paths:
[1], [1], [3], [4], [1,3], [1,4], [1,4], [3,4]
*/

#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

int directions[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

int dfs(int** grid, int** dp, int m, int n, int i, int j) {
    if (dp[i][j] != -1) return dp[i][j];

    int res = 1; // Count the path that includes only the cell itself
    for (int d = 0; d < 4; d++) {
        int ni = i + directions[d][0];
        int nj = j + directions[d][1];
        if (ni >= 0 && ni < m && nj >= 0 && nj < n && grid[ni][nj] > grid[i][j]) {
            res = (res + dfs(grid, dp, m, n, ni, nj)) % MOD;
        }
    }
    dp[i][j] = res;
    return res;
}

int countPaths(int** grid, int gridSize, int* gridColSize){
    int m = gridSize, n = gridColSize[0];
    int** dp = (int**)malloc(sizeof(int*) * m);
    for (int i = 0; i < m; i++) {
        dp[i] = (int*)malloc(sizeof(int) * n);
        for (int j = 0; j < n; j++) dp[i][j] = -1;
    }

    long long total = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            total = (total + dfs(grid, dp, m, n, i, j)) % MOD;
        }
    }

    for (int i = 0; i < m; i++) free(dp[i]);
    free(dp);
    return (int)total;
}

// Sample test
int main() {
    int rows = 2, cols = 2;
    int** grid = (int**)malloc(sizeof(int*) * rows);
    int gridColSize[2] = {cols, cols};

    grid[0] = (int*)malloc(sizeof(int) * cols);
    grid[1] = (int*)malloc(sizeof(int) * cols);

    grid[0][0] = 1; grid[0][1] = 1;
    grid[1][0] = 3; grid[1][1] = 4;

    int result = countPaths(grid, rows, gridColSize);
    printf("Number of increasing paths: %d\n", result); // Expected: 8

    free(grid[0]);
    free(grid[1]);
    free(grid);
    return 0;
}
