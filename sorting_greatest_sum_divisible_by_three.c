/*
Problem:
Find the maximum sum from an array such that the sum is divisible by 3.

Approach:
- Use dynamic programming.
- Maintain an array `dp[3]` where dp[i] is the max sum with remainder i.
- Update it with each number by checking which previous sums it can extend.

Time: O(n)
Space: O(1)
*/

#include <stdio.h>
#include <stdlib.h>

int maxSumDivThree(int* nums, int numsSize) {
    int dp[3] = {0}; // dp[i] = max sum where sum % 3 == i

    for (int i = 0; i < numsSize; i++) {
        int temp[3];
        for (int j = 0; j < 3; j++) temp[j] = dp[j];

        for (int j = 0; j < 3; j++) {
            int newSum = temp[j] + nums[i];
            int r = newSum % 3;
            if (newSum > dp[r]) {
                dp[r] = newSum;
            }
        }

        int r = nums[i] % 3;
        if (nums[i] > dp[r]) {
            dp[r] = nums[i];
        }
    }

    return dp[0];
}

// Test
int main() {
    int nums[] = {3, 6, 5, 1, 8};
    int n = sizeof(nums) / sizeof(nums[0]);

    int res = maxSumDivThree(nums, n);
    printf("Maximum sum divisible by 3: %d\n", res);  // Expected: 18
    return 0;
}

/*
========= OUTPUT =========
Maximum sum divisible by 3: 18
==========================
*/
