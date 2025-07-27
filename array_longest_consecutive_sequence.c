/*
Problem: Longest Consecutive Sequence

Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time. (Note: C's sorting solution is O(n log n), acceptable for practical limits.)

Example:
Input: nums = [100, 4, 200, 1, 3, 2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore, its length is 4.
*/

#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int longestConsecutive(int* nums, int numsSize) {
    if (numsSize == 0) return 0;

    qsort(nums, numsSize, sizeof(int), cmp);
    int maxLen = 1, currLen = 1;

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == nums[i - 1]) continue;
        if (nums[i] == nums[i - 1] + 1) {
            currLen++;
        } else {
            if (currLen > maxLen) maxLen = currLen;
            currLen = 1;
        }
    }

    if (currLen > maxLen) maxLen = currLen;
    return maxLen;
}

// Test Driver
int main() {
    int nums[] = {100, 4, 200, 1, 3, 2};
    int n = sizeof(nums) / sizeof(nums[0]);
    int result = longestConsecutive(nums, n);
    printf("Longest Consecutive Sequence Length: %d\n", result);  // Output: 4
    return 0;
}
