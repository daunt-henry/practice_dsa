/*
Problem: Set Mismatch

An array of length n contains numbers 1 to n with:
- One number duplicated
- One number missing

Return [duplicate, missing]

Approach:
- Use negation to mark visited indices
- First duplicate will be detected if already negative
- Positive index at end is the missing number

Time: O(n)
Space: O(1) (excluding result array)
*/

#include <stdio.h>
#include <stdlib.h>

int* findErrorNums(int* nums, int numsSize, int* returnSize) {
    int* res = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;

    for (int i = 0; i < numsSize; i++) {
        int index = abs(nums[i]) - 1;
        if (nums[index] < 0)
            res[0] = abs(nums[i]);
        else
            nums[index] = -nums[index];
    }

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > 0) {
            res[1] = i + 1;
            break;
        }
    }

    return res;
}

// Test
int main() {
    int nums[] = {1, 2, 2, 4};
    int size = sizeof(nums) / sizeof(nums[0]);
    int returnSize;

    int* result = findErrorNums(nums, size, &returnSize);
    printf("Duplicate: %d, Missing: %d\n", result[0], result[1]);

    free(result);
    return 0;
}

/*
========= OUTPUT =========
Duplicate: 2, Missing: 3
==========================
*/
