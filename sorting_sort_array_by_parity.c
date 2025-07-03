/*
Problem:
Given an integer array, reorder it so that all even numbers come before all odd numbers.

Approach:
- Use two pointers to fill a new array:
  - Left side for evens
  - Right side for odds

Time: O(n)
Space: O(n)
*/

#include <stdio.h>
#include <stdlib.h>

int* sortArrayByParity(int* nums, int numsSize, int* returnSize) {
    int* res = malloc(sizeof(int) * numsSize);
    int left = 0, right = numsSize - 1;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] % 2 == 0) {
            res[left++] = nums[i];
        } else {
            res[right--] = nums[i];
        }
    }

    *returnSize = numsSize;
    return res;
}

// Test
int main() {
    int nums[] = {3, 1, 2, 4};
    int size = sizeof(nums) / sizeof(nums[0]);
    int returnSize;
    int* result = sortArrayByParity(nums, size, &returnSize);

    printf("Output: [");
    for (int i = 0; i < returnSize; i++) {
        printf("%d", result[i]);
        if (i < returnSize - 1) printf(", ");
    }
    printf("]\n");

    free(result);
    return 0;
}

/*
========= OUTPUT =========
Output: [4, 2, 1, 3]  // Order may vary but evens come before odds
==========================
*/
