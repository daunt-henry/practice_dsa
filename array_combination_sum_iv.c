/*
Combination Sum IV

Problem:
Given an array of distinct integers `nums` and a target integer `target`,
return the number of possible combinations that add up to `target`.

The test cases are generated so that the answer can fit in a 32-bit integer.

Example:
Input: nums = [1,2,3], target = 4
Output: 7
Explanation:
The possible combination ways are:
(1,1,1,1), (1,1,2), (1,2,1), (1,3),
(2,1,1), (2,2), (3,1)

Constraints:
- 1 <= nums.length <= 200
- 1 <= nums[i] <= 1000
- All elements of nums are distinct
- 1 <= target <= 1000
*/

#include <stdio.h>
#include <stdlib.h>

int combinationSum4(int* nums, int numsSize, int target) {
    unsigned int* dp = (unsigned int*)calloc(target + 1, sizeof(unsigned int));
    dp[0] = 1;  // base case: one way to reach 0 sum

    for (int i = 1; i <= target; i++) {
        for (int j = 0; j < numsSize; j++) {
            if (i >= nums[j]) {
                dp[i] += dp[i - nums[j]];
            }
        }
    }

    int result = dp[target];
    free(dp);
    return result;
}

// Sample test
int main() {
    int nums[] = {1, 2, 3};
    int target = 4;
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int result = combinationSum4(nums, numsSize, target);
    printf("Number of combinations: %d\n", result); // Expected output: 7
    return 0;
}
