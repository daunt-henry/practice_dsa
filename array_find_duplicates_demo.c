/*
Find All Duplicates in an Array (LeetCode 442)

Given an integer array where elements are in the range [1, n] and some appear twice:
Find all elements that appear twice, in O(n) time and O(1) extra space.

Approach:
- Use the array itself as a marker:
    For each num in nums:
       Let idx = abs(num) - 1.
       If nums[idx] is negative, it's already been visited—so it's a duplicate.
       Else, flip nums[idx] to negative.
- Collect duplicates into result.
*/

#include <stdio.h>
#include <stdlib.h>

int* findDuplicates(int* nums, int n, int* returnSize) {
    int* res = malloc(n * sizeof(int));
    *returnSize = 0;
    for (int i = 0; i < n; i++) {
        int v = abs(nums[i]);
        if (nums[v - 1] < 0) {
            res[(*returnSize)++] = v;
        } else {
            nums[v - 1] = -nums[v - 1];
        }
    }
    return res;
}

int main(void) {
    int nums[] = {4, 3, 2, 7, 8, 2, 3, 1};
    int n = sizeof(nums) / sizeof(nums[0]);
    int returnSize;

    int* dups = findDuplicates(nums, n, &returnSize);

    printf("Duplicates found: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", dups[i]);
    }
    printf("\n");  // Expected: "2 3"

    free(dups);
    return 0;
}
