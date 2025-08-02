/*
Problem: House Robber

You are a professional robber planning to rob houses along a street.
Each house has a certain amount of money stashed, and the only constraint 
is that adjacent houses cannot be robbed on the same night.

Return the maximum amount of money you can rob tonight without alerting the police.

Example 1:
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (1) and house 3 (3).

Example 2:
Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (2), house 3 (9), and house 5 (1).
*/

#include <stdio.h>
#include <math.h>

int rob(int* nums, int numsSize) {
    if (numsSize == 0) return 0;
    if (numsSize == 1) return nums[0];

    int prev2 = 0;
    int prev1 = nums[0];
    for (int i = 1; i < numsSize; i++) {
        int temp = prev1;
        prev1 = fmax(prev1, prev2 + nums[i]);
        prev2 = temp;
    }
    return prev1;
}

// Sample test
int main() {
    int nums[] = {2, 7, 9, 3, 1};
    int n = sizeof(nums) / sizeof(nums[0]);
    int maxMoney = rob(nums, n);
    printf("Maximum money that can be robbed: %d\n", maxMoney);
    return 0;
}
