/*
Title: Maximum Sum Circular Subarray

Example:
Input: nums = [1, -2, 3, -2]
Output: 3

Explanation:
- Max subarray without wrap: 3
- Max subarray with wrap: 1 + (-2) + 3 + (-2) = 0 → not better than 3
- So answer is 3.

Approach:
- Use Kadane’s algorithm to find max subarray sum (non-circular).
- Also compute min subarray sum.
- If total - minSum > maxSum, it means wrapping gives better result.
*/

#include <stdio.h>

int maxSubarraySumCircular(int* nums, int numsSize) {
    int total = 0, maxSum = nums[0], curMax = 0;
    int minSum = nums[0], curMin = 0;

    for (int i = 0; i < numsSize; i++) {
        total += nums[i];

        curMax = (curMax > 0 ? curMax : 0) + nums[i];
        maxSum = (curMax > maxSum) ? curMax : maxSum;

        curMin = (curMin < 0 ? curMin : 0) + nums[i];
        minSum = (curMin < minSum) ? curMin : minSum;
    }

    if (maxSum < 0) return maxSum;
    return (total - minSum > maxSum) ? total - minSum : maxSum;
}

int main() {
    int nums[] = {1, -2, 3, -2};
    int size = sizeof(nums) / sizeof(nums[0]);
    int result = maxSubarraySumCircular(nums, size);
    printf("Maximum circular subarray sum: %d\n", result);  // Output: 3
    return 0;
}
