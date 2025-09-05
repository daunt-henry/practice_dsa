/*
 * Problem: Largest Sum of Averages (LeetCode 813)
 *
 * Partition an array into at most k adjacent groups to maximize the sum
 * of their averages. Use dynamic programming and prefix sums.
 *
 * Time Complexity: O(k * n^2)
 * Space Complexity: O(k * n)
 */

#include <stdio.h>
#include <stdlib.h>

double largestSumOfAverages(int* nums, int numsSize, int k) {
    int n = numsSize;
    double* prefix = malloc((n + 1) * sizeof(double));
    prefix[0] = 0.0;
    for (int i = 1; i <= n; i++)
        prefix[i] = prefix[i - 1] + nums[i - 1];

    double** dp = malloc((k + 1) * sizeof(double*));
    for (int j = 0; j <= k; j++) {
        dp[j] = calloc(n + 1, sizeof(double));
    }

    for (int i = 1; i <= n; i++) {
        dp[1][i] = prefix[i] / i;
    }

    for (int j = 2; j <= k; j++) {
        for (int i = j; i <= n; i++) {
            double best = 0.0;
            for (int m = j - 1; m < i; m++) {
                double avg = (prefix[i] - prefix[m]) / (i - m);
                double candidate = dp[j - 1][m] + avg;
                if (candidate > best) best = candidate;
            }
            dp[j][i] = best;
        }
    }

    double result = dp[k][n];

    for (int j = 0; j <= k; j++) free(dp[j]);
    free(dp);
    free(prefix);

    return result;
}

int main(void) {
    int nums1[] = {9, 1, 2, 3, 9};
    int k1 = 3;
    printf("Result: %.6f (expected: 20.000000)\n",
           largestSumOfAverages(nums1, 5, k1));

    int nums2[] = {1, 2, 3, 4, 5, 6, 7};
    int k2 = 4;
    printf("Result: %.6f (expected: 20.500000)\n",
           largestSumOfAverages(nums2, 7, k2));

    return 0;
}
