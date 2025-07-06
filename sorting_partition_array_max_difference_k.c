/*
Problem:
Given an array of integers `nums` and an integer `k`, 
you need to partition the array into the minimum number 
of subsequences such that the difference between the 
maximum and minimum values in each subsequence is less than or equal to k.

Approach:
- Sort the array first.
- Use a greedy approach: start from the first element and grow the group until the difference exceeds k.
- Every time the difference exceeds k, start a new group.

Example:
Input: nums = [3,6,1,2,5], k = 2
Output: 2
*/

#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int partitionArray(int* nums, int numsSize, int k) {
    qsort(nums, numsSize, sizeof(int), compare);
    
    int count = 1;
    int start = nums[0];

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] - start > k) {
            count++;
            start = nums[i];
        }
    }

    return count;
}

/*
Output:
Input: nums = [3,6,1,2,5], k = 2
Output: 2
*/
