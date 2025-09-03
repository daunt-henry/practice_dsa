/*
Problem: Max Area of Island (LeetCode 695)
URL: https://leetcode.com/problems/max-area-of-island/

Given a 2D grid of 0s (water) and 1s (land), find the size of the largest island.
An island is a group of adjacent 1s (horizontally or vertically connected).
Return 0 if no island exists.

Approach: Depth-First Search (DFS)
- Traverse each cell; when a '1' is found, start DFS to compute its island area.
- Mark visited cells by setting them to '0' to prevent revisits.
- Keep and return the maximum island area found.

Time Complexity: O(m * n)
Space Complexity: O(m * n) in the worst case for recursion depth
*/

#include <stdio.h>
#include <stdlib.h>

static int dfs(int** grid, int rows, int cols, int r, int c) {
    if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] != 1) {
        return 0;
    }
    grid[r][c] = 0;
    return 1
        + dfs(grid, rows, cols, r + 1, c)
        + dfs(grid, rows, cols, r - 1, c)
        + dfs(grid, rows, cols, r, c + 1)
        + dfs(grid, rows, cols, r, c - 1);
}

int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize) {
    int maxArea = 0;
    int rows = gridSize;
    int cols = (rows > 0) ? gridColSize[0] : 0;

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (grid[r][c] == 1) {
                int area = dfs(grid, rows, cols, r, c);
                if (area > maxArea) {
                    maxArea = area;
                }
            }
        }
    }
    return maxArea;
}

// Helper to allocate a 2D grid from a static array
int** buildGrid(int rows, int cols, int data[rows][cols], int* colSize) {
    int** grid = malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        grid[i] = malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            grid[i][j] = data[i][j];
        }
        colSize[i] = cols;
    }
    return grid;
}

void freeGrid(int** grid, int rows) {
    for (int i = 0; i < rows; i++) {
        free(grid[i]);
    }
    free(grid);
}

int main(void) {
    int data1[4][4] = {
        {0,0,1,0},
        {0,1,1,0},
        {0,0,1,0},
        {1,1,0,0}
    };
    int rows1 = 4, cols1 = 4, colSize1[4];
    int** grid1 = buildGrid(rows1, cols1, data1, colSize1);
    int result1 = maxAreaOfIsland(grid1, rows1, colSize1);
    printf("Max area (expected 5): %d\n", result1);
    freeGrid(grid1, rows1);

    int data2[3][3] = {
        {0,0,0},
        {0,0,0},
        {0,0,0}
    };
    int rows2 = 3, cols2 = 3, colSize2[3];
    int** grid2 = buildGrid(rows2, cols2, data2, colSize2);
    int result2 = maxAreaOfIsland(grid2, rows2, colSize2);
    printf("Max area (expected 0): %d\n", result2);
    freeGrid(grid2, rows2);

    return 0;
}
