/*
Jump Game V

Problem:
- From any index i, you can jump left or right up to distance `d` 
  to a strictly smaller value, and must stop at the first taller or equal height.
- Return the maximum number of indices you can visit starting from any index.

Approach:
- Use memoized DFS (top-down DP).
- For each index, try jumping left and right up to `d` steps.
- Only proceed if the height is strictly decreasing.

Time: O(n * d)
Space: O(n)

Example Input:
arr = [6,4,14,6,8,13,9,7,10,6,12], d = 2

Expected Output:
4
*/

#include <stdlib.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int dfs(int* arr, int arrSize, int idx, int d, int* dp) {
    if (dp[idx] != -1) return dp[idx];

    int best = 1;

    for (int i = idx + 1; i <= idx + d && i < arrSize && arr[i] < arr[idx]; i++) {
        best = max(best, 1 + dfs(arr, arrSize, i, d, dp));
    }

    for (int i = idx - 1; i >= idx - d && i >= 0 && arr[i] < arr[idx]; i--) {
        best = max(best, 1 + dfs(arr, arrSize, i, d, dp));
    }

    dp[idx] = best;
    return best;
}

int maxJumps(int* arr, int arrSize, int d) {
    int* dp = (int*)malloc(sizeof(int) * arrSize);
    for (int i = 0; i < arrSize; i++) dp[i] = -1;

    int res = 0;
    for (int i = 0; i < arrSize; i++) {
        res = max(res, dfs(arr, arrSize, i, d, dp));
    }

    free(dp);
    return res;
}
