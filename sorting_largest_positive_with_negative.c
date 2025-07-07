/*
Problem:
You are given an array of integers. Return the **largest positive integer k**
such that both `k` and `-k` exist in the array.

If no such number exists, return -1.

Example Input:
nums = [-1, 2, -3, 3]

Expected Output:
3

Explanation:
Both 3 and -3 exist → return 3.
*/

#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int findMaxK(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);

    int left = 0, right = numsSize - 1;

    while (left < right) {
        if (nums[right] == -nums[left])
            return nums[right];
        else if (nums[right] > -nums[left])
            right--;
        else
            left++;
    }

    return -1;
}

int main() {
    int nums[] = {-1, 2, -3, 3};
    int size = sizeof(nums) / sizeof(nums[0]);

    int result = findMaxK(nums, size);
    printf("Largest positive with its negative: %d\n", result);

    return 0;
}
