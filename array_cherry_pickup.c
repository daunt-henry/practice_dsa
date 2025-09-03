/*
Problem: Cherry Pickup (LeetCode 741)
URL: https://leetcode.com/problems/cherry-pickup/

We simulate two people simultaneously traveling from (0,0) to (n−1,n−1). Each step, both move either right or down. 
Let dp[r1][c1][r2] denote the max cherries collected when person1 is at (r1,c1) and person2 at (r2,c2),
where c2 = r1 + c1 − r2. We memoize to optimize overlapping subproblems.

Time Complexity: O(n^3)
Space Complexity: O(n^3)
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAXN 50

static int n;
static int grid[MAXN][MAXN];
static int memo[MAXN][MAXN][MAXN];

int dfs(int r1, int c1, int r2) {
    int c2 = r1 + c1 - r2;
    if (r1 >= n || c1 >= n || r2 >= n || c2 >= n ||
        grid[r1][c1] == -1 || grid[r2][c2] == -1) {
        return -INT_MAX / 2;
    }
    if (r1 == n-1 && c1 == n-1) {
        return grid[r1][c1];
    }
    int* mp = &memo[r1][c1][r2];
    if (*mp != INT_MIN) return *mp;
    int best = -INT_MAX / 2;
    best = best > dfs(r1+1, c1, r2+1) ? best : dfs(r1+1, c1, r2+1);
    best = best > dfs(r1+1, c1, r2) ? best : dfs(r1+1, c1, r2);
    best = best > dfs(r1, c1+1, r2+1) ? best : dfs(r1, c1+1, r2+1);
    best = best > dfs(r1, c1+1, r2) ? best : dfs(r1, c1+1, r2);
    int res = best + grid[r1][c1];
    if (r1 != r2) res += grid[r2][c2];
    return *mp = res;
}

int cherryPickup(int** inputGrid, int gridSize, int* gridColSize) {
    n = gridSize;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            grid[i][j] = inputGrid[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                memo[i][j][k] = INT_MIN;

    int ans = dfs(0, 0, 0);
    return ans < 0 ? 0 : ans;
}

int main(void) {
    int nTest = 3;
    int raw[3][3] = {
        {0, 1, -1},
        {1, 0, -1},
        {1, 1,  1}
    };
    int* grid[3];
    for (int i = 0; i < nTest; i++) grid[i] = raw[i];
    int colSize[3] = {3,3,3};

    int result = cherryPickup(grid, nTest, colSize);
    printf("Cherry Pickup result: %d (expected: 5)\n", result);
    return 0;
}
