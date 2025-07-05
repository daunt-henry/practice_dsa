/*
Problem: Frequency of the Most Frequent Element

Given an array of integers `nums` and an integer `k`, you can increment any element at most `k` times.
Return the **maximum frequency** of any element after at most `k` increments.

Input:
nums = [1,2,4]
k = 5

Output:
3

Explanation:
You can increment 1 twice and 2 once to make the array [4,4,4] => frequency of 4 is 3.

Approach:
1. Sort the array.
2. Use a sliding window to check the number of elements that can be made equal to `nums[right]` using at most `k` operations.

Time Complexity: O(n log n) due to sorting.
Space Complexity: O(1)
*/

#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int maxFrequency(int* nums, int numsSize, int k){
    qsort(nums, numsSize, sizeof(int), compare);
    long long left = 0, right = 0, total = 0, maxFreq = 0;

    for (right = 0; right < numsSize; right++) {
        total += nums[right];
        while ((right - left + 1) * (long long)nums[right] - total > k) {
            total -= nums[left];
            left++;
        }
        if (right - left + 1 > maxFreq)
            maxFreq = right - left + 1;
    }

    return (int)maxFreq;
}
