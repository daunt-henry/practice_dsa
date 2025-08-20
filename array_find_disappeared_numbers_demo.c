/*
Find All Numbers Disappeared in an Array (LeetCode 448)

Given an array 'nums' of length n (elements in [1, n]), find all numbers
in the range [1, n] that do not appear in 'nums'.

Solution Overview:
- Negate the value at index abs(nums[i]) - 1 to mark that 'nums[i]' is present.
- In the second pass, any index i with a positive value implies (i + 1) is missing.
- Runs in O(n) time, O(1) extra space (excluding output).
*/

#include <stdio.h>
#include <stdlib.h>

int* findDisappearedNumbers(int* nums, int n, int* returnSize) {
    for (int i = 0; i < n; i++) {
        int idx = abs(nums[i]) - 1;
        if (nums[idx] > 0) {
            nums[idx] = -nums[idx];
        }
    }

    int* result = malloc(n * sizeof(int));
    *returnSize = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] > 0) {
            result[(*returnSize)++] = i + 1;
        }
    }
    return result;
}

int main(void) {
    int nums[] = {4, 3, 2, 7, 8, 2, 3, 1};
    int n = sizeof(nums) / sizeof(nums[0]);
    int returnSize;

    int* disappeared = findDisappearedNumbers(nums, n, &returnSize);
    printf("Missing numbers:");
    for (int i = 0; i < returnSize; i++) {
        printf(" %d", disappeared[i]);
    }
    printf("\n");  // Expected output: 5 6

    free(disappeared);
    return 0;
}
