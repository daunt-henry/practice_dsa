/*
Problem:
You are given a 2D array nums where each nums[i] is an array of integers.
Return the intersection of all the arrays in nums (sorted in increasing order).

Approach:
- Use a count array to record how many times each number appears.
- Only count the number if it hasn’t been counted in the same list more than once.
- After processing all arrays, collect numbers that appear exactly numsSize times.
- Sort and return.

Time Complexity: O(N * M + K log K), where:
- N = number of arrays
- M = average size of each array
- K = size of intersection
*/

#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int* intersection(int** nums, int numsSize, int* numsColSize, int* returnSize) {
    int count[1001] = {0};
    for (int i = 0; i < numsSize; i++) {
        for (int j = 0; j < numsColSize[i]; j++) {
            int val = nums[i][j];
            if (count[val] == i) {
                count[val]++;
            }
        }
    }

    int* res = (int*)malloc(sizeof(int) * 1000);
    *returnSize = 0;

    for (int i = 1; i <= 1000; i++) {
        if (count[i] == numsSize) {
            res[(*returnSize)++] = i;
        }
    }

    qsort(res, *returnSize, sizeof(int), cmp);
    return res;
}

/*
Example:

Input:
nums = [[3,1,2,4,5],[1,2,3,4],[3,4,5,6]]

Output:
[3,4]

Explanation:
Only 3 and 4 are present in all arrays.
*/
