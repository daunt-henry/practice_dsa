/*
Target Sum (LeetCode 494)

Given an array nums and an integer target, you assign '+' or '-' 
to each array element and concatenate them to form expressions.
Return the number of different expressions that evaluate to target.

Transform: Let P be sum of nums with '+', N be sum of nums with '-'.
We want P - N = target and P + N = sum => P = (sum + target) / 2

Thus, count the number of subsets with sum = (sum + target) / 2.

Approach: Use 1D DP to count subsets: dp[j] = #ways to make sum j.

Time: O(n * s), Space: O(s), where s = (sum − target) / 2
*/

#include <stdio.h>
#include <stdlib.h>

int findTargetSumWays(int* nums, int numsSize, int target) {
    int sum = 0;
    for (int i = 0; i < numsSize; i++) sum += nums[i];

    if (sum < abs(target) || (sum - target) % 2 != 0) return 0;
    int s = (sum - target) / 2;

    int* dp = calloc(s + 1, sizeof(int));
    dp[0] = 1;

    for (int i = 0; i < numsSize; i++) {
        int v = nums[i];
        for (int j = s; j >= v; j--) {
            dp[j] += dp[j - v];
        }
    }

    int res = dp[s];
    free(dp);
    return res;
}

int main(void) {
    int nums1[] = {1, 1, 1, 1, 1};
    int target1 = 3, size1 = 5;
    printf("Output: %d (expected 5)\n",
           findTargetSumWays(nums1, size1, target1));

    int nums2[] = {1, 2, 3, 4, 5};
    int target2 = 3, size2 = 5;
    printf("Output: %d (expected ?)\n",  // Placeholder if needed
           findTargetSumWays(nums2, size2, target2));

    return 0;
}
