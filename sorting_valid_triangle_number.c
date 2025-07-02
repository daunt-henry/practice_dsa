/*
Problem: Valid Triangle Number

Given an integer array, return the number of triplets (i, j, k) that can form a valid triangle.

Triangle Condition:
- nums[i] + nums[j] > nums[k]
- All sides must be > 0
- Sorted + Two-pointer technique

Time: O(n^2)
Space: O(1)
*/

#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int triangleNumber(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), compare);
    int count = 0;

    for (int k = numsSize - 1; k >= 2; k--) {
        int i = 0, j = k - 1;
        while (i < j) {
            if (nums[i] + nums[j] > nums[k]) {
                count += j - i;
                j--;
            } else {
                i++;
            }
        }
    }

    return count;
}

// Test
int main() {
    int nums[] = {2, 2, 3, 4};
    int size = sizeof(nums) / sizeof(nums[0]);

    int result = triangleNumber(nums, size);
    printf("Number of valid triangles: %d\n", result);

    return 0;
}

/*
========= OUTPUT =========
Number of valid triangles: 3
==========================
*/
