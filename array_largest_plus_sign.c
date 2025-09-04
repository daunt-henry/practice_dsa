/*
Problem: Largest Plus Sign (LeetCode 764)
Find the largest “plus sign” of 1s in an n × n grid with some 0-cells (mines).
Return the order k of the largest plus sign (arms length = k-1).

Approach (DP + directional passes):
- Initialize dp[i][j] = n for all cells, except mines = 0.
- For each row i and column i:
    - Compute left-to-right, right-to-left, top-down, bottom-up counts.
    - Update dp to be min(dp, directional count).
- After all sweeps, maximum dp[i][j] is the result.
Time: O(n²), Space: O(n²)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int orderOfLargestPlusSign(int n, int** mines, int minesSize, int* minesColSize) {
    int **dp = malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        dp[i] = malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) dp[i][j] = n;
    }

    for (int i = 0; i < minesSize; i++) {
        int r = mines[i][0], c = mines[i][1];
        dp[r][c] = 0;
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        int left = 0, right = 0, up = 0, down = 0;
        for (int j = 0, k = n - 1; j < n; j++, k--) {
            left = (dp[i][j] == 0) ? 0 : left + 1;
            dp[i][j] = dp[i][j] < left ? dp[i][j] : left;

            right = (dp[i][k] == 0) ? 0 : right + 1;
            dp[i][k] = dp[i][k] < right ? dp[i][k] : right;

            up = (dp[j][i] == 0) ? 0 : up + 1;
            dp[j][i] = dp[j][i] < up ? dp[j][i] : up;

            down = (dp[k][i] == 0) ? 0 : down + 1;
            dp[k][i] = dp[k][i] < down ? dp[k][i] : down;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dp[i][j] > ans) ans = dp[i][j];
        }
        free(dp[i]);
    }
    free(dp);

    return ans;
}

#ifdef DEMO
int main(void) {
    // Example: n = 5, one mine at (4,2)
    int n = 5;
    int msize = 1;
    int mines_data[1][2] = {{4,2}};
    int* mines[1]; mines[0] = mines_data[0];
    int minesCol[1] = {2};

    int result = orderOfLargestPlusSign(n, mines, msize, minesCol);
    printf("Expected 2, Got: %d\n", result);
    return 0;
}
#endif
