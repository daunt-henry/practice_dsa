/*
Problem:
Find the largest perimeter of a triangle from an array of lengths,
where the triangle must satisfy triangle inequality.

Approach:
- Sort in descending order.
- Try each triplet and return the first that forms a triangle.

Time: O(n log n) for sorting
Space: O(1)
*/

#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

int largestPerimeter(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);

    for (int i = 0; i < numsSize - 2; i++) {
        if (nums[i] < nums[i + 1] + nums[i + 2]) {
            return nums[i] + nums[i + 1] + nums[i + 2];
        }
    }
    return 0;
}

// Test
int main() {
    int nums[] = {2, 1, 2};
    int size = sizeof(nums) / sizeof(nums[0]);

    int result = largestPerimeter(nums, size);
    printf("Largest Perimeter: %d\n", result);  // Expected: 5

    return 0;
}

/*
========= OUTPUT =========
Largest Perimeter: 5
==========================
*/
