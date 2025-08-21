/*
Ones and Zeroes (LeetCode 474)

You’re given an array of binary strings `strs` and two integers `m` (zeros limit)
and `n` (ones limit). Find the size of the largest subset of `strs` such that
the total count of '0's is ≤ m and '1's is ≤ n.

Solution: 2D Knapsack (DP with dual constraints)
- dp[i][j]: max number of strings with at most i zeros and j ones
- Update dp in reverse when processing each string
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Count zeroes and ones in a binary string
void countZeroesOnes(const char* s, int* zeros, int* ones) {
    *zeros = *ones = 0;
    while (*s) {
        if (*s == '0') (*zeros)++;
        else if (*s == '1') (*ones)++;
        s++;
    }
}

int findMaxForm(char** strs, int strsSize, int m, int n) {
    int dp[m + 1][n + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < strsSize; i++) {
        int zeros, ones;
        countZeroesOnes(strs[i], &zeros, &ones);
        for (int z = m; z >= zeros; z--) {
            for (int o = n; o >= ones; o--) {
                int candidate = dp[z - zeros][o - ones] + 1;
                if (candidate > dp[z][o]) dp[z][o] = candidate;
            }
        }
    }
    return dp[m][n];
}

int main(void) {
    char* strs1[] = {"10","0001","111001","1","0"};
    int size1 = sizeof(strs1) / sizeof(strs1[0]);
    printf("Expected: 4, Got: %d\n", findMaxForm(strs1, size1, 5, 3));

    char* strs2[] = {"10","0","1"};
    int size2 = sizeof(strs2) / sizeof(strs2[0]);
    printf("Expected: 2, Got: %d\n", findMaxForm(strs2, size2, 1, 1));

    return 0;
}
