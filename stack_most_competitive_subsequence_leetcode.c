/*
Title: Find the Most Competitive Subsequence

Description:
  Given an integer array `nums` and a positive integer `k`, return the most competitive subsequence of `nums` of size `k`.
  A subsequence is **more competitive** if in the first position where they differ,
  the subsequence has a number less than the other.

Example:
  Input: nums = [3,5,2,6], k = 2
  Output: [2,6]

Explanation:
  We want the lexicographically smallest subsequence of length k = 2.
  [3,5] is valid, but [2,6] is smaller.

Approach:
  - Use a monotonic stack to build the result.
  - Maintain size k by popping elements when needed.

*/

#include <stdio.h>
#include <stdlib.h>

int* mostCompetitive(int* nums, int numsSize, int k, int* returnSize){
    int* stack = (int*)malloc(sizeof(int) * k);
    int top = -1;

    for (int i = 0; i < numsSize; i++) {
        while (top >= 0 && nums[i] < stack[top] && (numsSize - i + top) >= k) {
            top--;
        }
        if (top + 1 < k) {
            stack[++top] = nums[i];
        }
    }

    *returnSize = k;
    return stack;
}

int main() {
    int nums[] = {3, 5, 2, 6};
    int k = 2, returnSize;
    int* result = mostCompetitive(nums, 4, k, &returnSize);

    printf("Most competitive subsequence: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);
    return 0;
}
