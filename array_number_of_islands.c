/*
Problem: Number of Islands

Given a 2D grid map of '1's (land) and '0's (water), count the number of islands.
An island is surrounded by water and is formed by connecting adjacent lands 
(horizontally or vertically). You may assume all four edges of the grid are surrounded by water.

Example 1:
Input:
11110
11010
11000
00000
Output: 1

Example 2:
Input:
11000
11000
00100
00011
Output: 3
*/

#include <stdio.h>

void dfs(char** grid, int i, int j, int m, int n) {
    if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] != '1') return;
    grid[i][j] = '0'; // Mark as visited
    dfs(grid, i + 1, j, m, n);
    dfs(grid, i - 1, j, m, n);
    dfs(grid, i, j + 1, m, n);
    dfs(grid, i, j - 1, m, n);
}

int numIslands(char** grid, int gridSize, int* gridColSize) {
    int count = 0;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            if (grid[i][j] == '1') {
                dfs(grid, i, j, gridSize, gridColSize[i]);
                count++;
            }
        }
    }
    return count;
}

// This problem uses 2D dynamic input; main() demo is not trivial for C without preprocessing.
