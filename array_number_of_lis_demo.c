/*
Number of Longest Increasing Subsequence (LeetCode 673)

Given an integer array `nums`, return the number of different longest strictly
increasing subsequences.

Dynamic Programming (O(n²) time, O(n) space):
- Use dp[i] to store LIS length ending at i.
- Use cnt[i] to store count of such LIS ending at i.
- Keep track of global maxLen and result count.
*/

#include <stdio.h>
#include <stdlib.h>

// Core function
int findNumberOfLIS(int* nums, int numsSize) {
    if (numsSize == 0) return 0;

    int *dp = malloc(numsSize * sizeof(int));
    int *cnt = malloc(numsSize * sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        dp[i] = 1;
        cnt[i] = 1;
    }

    int maxLen = 1, result = 0;

    for (int i = 0; i < numsSize; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                if (dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    cnt[i] = cnt[j];
                } else if (dp[j] + 1 == dp[i]) {
                    cnt[i] += cnt[j];
                }
            }
        }
        if (dp[i] > maxLen) {
            maxLen = dp[i];
            result = cnt[i];
        } else if (dp[i] == maxLen) {
            result += cnt[i];
        }
    }

    free(dp);
    free(cnt);
    return result;
}

void test(int* arr, int n) {
    printf("Input: [");
    for (int i = 0; i < n; i++)
        printf("%d%s", arr[i], i+1 < n ? ", " : "");
    printf("] → Number of LIS: %d\n", findNumberOfLIS(arr, n));
}

int main(void) {
    int nums1[] = {1, 3, 5, 4, 7};
    test(nums1, 5);  // expected 2

    int nums2[] = {2, 2, 2, 2, 2};
    test(nums2, 5);  // expected 5

    int nums3[] = {1, 2, 1, 2, 1, 2};
    test(nums3, 6);  // expected 6

    return 0;
}
