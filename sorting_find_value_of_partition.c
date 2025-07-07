// Question:
// You are given an integer array nums.
// Partition the array into two non-empty subsets such that the absolute difference between
// the maximum of one subset and the minimum of the other is minimized.
// Return the minimum possible value of this difference.

// Note: The answer is simply the minimum difference between any two adjacent elements after sorting.

// Example:
// Input: nums = [1,3,6,10,15]
// Output: 2

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int findValueOfPartition(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int minDiff = INT_MAX;
    for (int i = 1; i < numsSize; i++) {
        int diff = nums[i] - nums[i - 1];
        if (diff < minDiff) minDiff = diff;
    }
    return minDiff;
}

int main() {
    int nums[] = {1, 3, 6, 10, 15};
    int size = sizeof(nums) / sizeof(nums[0]);
    int result = findValueOfPartition(nums, size);
    printf("Output: %d\n", result);
    return 0;
}
