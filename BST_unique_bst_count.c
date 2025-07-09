/*
Problem:
Given an integer `n`, return the number of structurally unique BSTs (binary search trees)
which have exactly `n` nodes of unique values from 1 to n.

This is solved using dynamic programming on Catalan numbers:
    G(n) = G(0)*G(n-1) + G(1)*G(n-2) + ... + G(n-1)*G(0)

Example:
Input: n = 3
Output: 5

------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

int numTrees(int n) {
    int* dp = malloc((n + 1) * sizeof(int));
    dp[0] = dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = 0;
        for (int j = 1; j <= i; j++) {
            dp[i] += dp[j - 1] * dp[i - j];
        }
    }

    int result = dp[n];
    free(dp);
    return result;
}

// Demo
int main() {
    int n = 3;
    int result = numTrees(n);
    printf("Number of unique BSTs for n = %d: %d\n", n, result); // Output: 5
    return 0;
}
