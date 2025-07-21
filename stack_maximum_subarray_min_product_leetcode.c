 /*
Title: Maximum Subarray Min-Product

Description:
  Given an array of integers `nums`, the min-product of a non-empty subarray is 
  equal to the minimum value in the subarray multiplied by the sum of the subarray.
  Return the maximum min-product of any non-empty subarray.

Example:
  Input: nums = [1,2,3,2]
  Output: 14

Approach:
  - Use prefix sums to compute subarray sums in constant time.
  - Use monotonic stack to find left and right boundaries for each index,
    such that nums[i] is the minimum in that range.
  - For each such subarray, calculate min * sum and track the maximum.

Constraints:
  - 1 <= nums.length <= 10^5
  - 1 <= nums[i] <= 10^5
*/

#include <stdio.h>

#define MOD 1000000007

long long max(long long a, long long b) {
    return a > b ? a : b;
}

int maxSumMinProduct(int* nums, int numsSize) {
    long long prefix[100005] = {0};
    int left[100005], right[100005];
    long long stack[100005];
    int top = -1;

    for (int i = 0; i < numsSize; ++i)
        prefix[i + 1] = prefix[i] + nums[i];

    // Find left bounds
    for (int i = 0; i < numsSize; ++i) {
        while (top >= 0 && nums[stack[top]] >= nums[i]) top--;
        left[i] = top == -1 ? 0 : stack[top] + 1;
        stack[++top] = i;
    }

    top = -1;

    // Find right bounds
    for (int i = numsSize - 1; i >= 0; --i) {
        while (top >= 0 && nums[stack[top]] >= nums[i]) top--;
        right[i] = top == -1 ? numsSize - 1 : stack[top] - 1;
        stack[++top] = i;
    }

    long long result = 0;
    for (int i = 0; i < numsSize; ++i) {
        long long total = prefix[right[i] + 1] - prefix[left[i]];
        result = max(result, total * nums[i]);
    }

    return result % MOD;
}

int main() {
    int nums[] = {1, 2, 3, 2};
    int size = sizeof(nums) / sizeof(nums[0]);

    int result = maxSumMinProduct(nums, size);
    printf("Maximum subarray min-product: %d\n", result);  // Output: 14
    return 0;
}
