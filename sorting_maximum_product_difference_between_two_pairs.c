/*
Problem:
Maximum Product Difference Between Two Pairs

You are given an array of integers nums. Choose two different pairs of indices (a, b) and (c, d) such that:
- nums[a] * nums[b] is maximized
- nums[c] * nums[d] is minimized
Return the maximum difference between these two products.

Example:
Input: nums = [5,6,2,7,4]
Output: 34
Explanation:
Max product = 7*6 = 42
Min product = 2*1 = 8
Answer = 42 - 8 = 34
*/

#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int maxProductDifference(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int max1 = nums[numsSize - 1];
    int max2 = nums[numsSize - 2];
    int min1 = nums[0];
    int min2 = nums[1];
    return (max1 * max2) - (min1 * min2);
}

/*
Sample Input:
nums = [5,6,2,7,4]

Sample Output:
34
*/
