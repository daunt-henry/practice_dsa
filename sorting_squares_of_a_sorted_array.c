/*
Problem:
Given a sorted array of integers (including negatives),
return an array of the squares in non-decreasing order.

Approach:
- Use two pointers from left and right.
- Square the larger of the two ends and place from end of result.

Time: O(n)
Space: O(n)
*/

#include <stdio.h>
#include <stdlib.h>

int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    int* res = (int*)malloc(sizeof(int) * numsSize);
    int left = 0, right = numsSize - 1;
    int index = numsSize - 1;

    while (left <= right) {
        int leftSq = nums[left] * nums[left];
        int rightSq = nums[right] * nums[right];
        if (leftSq > rightSq) {
            res[index--] = leftSq;
            left++;
        } else {
            res[index--] = rightSq;
            right--;
        }
    }

    *returnSize = numsSize;
    return res;
}

// Test
int main() {
    int nums[] = {-4, -1, 0, 3, 10};
    int size = sizeof(nums) / sizeof(nums[0]);
    int returnSize;

    int* result = sortedSquares(nums, size, &returnSize);

    printf("Sorted Squares: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);
    return 0;
}

/*
========= OUTPUT =========
Sorted Squares: 0 1 9 16 100
==========================
*/
