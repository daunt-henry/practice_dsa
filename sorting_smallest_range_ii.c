/*
Problem:
Given an array and an integer k, modify each element by either +k or -k once.
Return the smallest possible difference between the max and min of the new array.

Approach:
- Sort the array
- Try partitioning at every index i
  - Elements ≤ i are increased by k
  - Elements > i are decreased by k
- Track the minimum possible range

Time: O(n log n)
Space: O(1)
*/

#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int smallestRangeII(int* nums, int numsSize, int k) {
    qsort(nums, numsSize, sizeof(int), compare);
    int res = nums[numsSize - 1] - nums[0];

    for (int i = 0; i < numsSize - 1; i++) {
        int high = nums[numsSize - 1] - k > nums[i] + k ? nums[numsSize - 1] - k : nums[i] + k;
        int low = nums[0] + k < nums[i + 1] - k ? nums[0] + k : nums[i + 1] - k;
        if (res > high - low)
            res = high - low;
    }

    return res;
}

// Test
int main() {
    int nums[] = {1, 3, 6};
    int k = 3;
    int size = sizeof(nums) / sizeof(nums[0]);

    int result = smallestRangeII(nums, size, k);
    printf("Output: %d\n", result);  // Expected: 3

    return 0;
}

/*
========= OUTPUT =========
Output: 3
==========================
*/
