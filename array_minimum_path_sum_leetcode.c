/*
Minimum Path Sum
https://leetcode.com/problems/minimum-path-sum/

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, 
which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:
Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Path 1 → 3 → 1 → 1 → 1 minimizes the sum.

*/

#include <stdio.h>

int minPathSum(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize;
    int n = gridColSize[0];

    for (int i = 1; i < m; i++) {
        grid[i][0] += grid[i-1][0];
    }

    for (int j = 1; j < n; j++) {
        grid[0][j] += grid[0][j-1];
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (grid[i-1][j] < grid[i][j-1])
                grid[i][j] += grid[i-1][j];
            else
                grid[i][j] += grid[i][j-1];
        }
    }

    return grid[m-1][n-1];
}

// Sample test
int main() {
    int data[3][3] = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };
    int* grid[3];
    for (int i = 0; i < 3; i++) grid[i] = data[i];
    int colSize[3] = {3, 3, 3};
    int result = minPathSum(grid, 3, colSize);
    printf("Minimum Path Sum: %d\n", result);  // Output: 7
    return 0;
}
