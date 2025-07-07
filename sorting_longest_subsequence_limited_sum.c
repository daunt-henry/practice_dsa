/*
Problem:
Given an array `nums`, for each query in `queries`, return the maximum number of elements 
you can pick from the start of the sorted `nums` array such that their sum ≤ query value.

Example Input:
nums = [4, 5, 2, 1]
queries = [3, 10, 21]

Expected Output:
[2, 3, 4]

Explanation:
Sorted nums: [1, 2, 4, 5]
Prefix sums: [1, 3, 7, 12]
- For 3 → [1,2] => 2 elements
- For 10 → [1,2,4] => 3 elements
- For 21 → all 4 elements
*/

#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return (*(int*)a) - (*(int*)b);
}

int* answerQueries(int* nums, int numsSize, int* queries, int queriesSize, int* returnSize) {
    qsort(nums, numsSize, sizeof(int), cmp);

    int* prefix = (int*)malloc(sizeof(int) * numsSize);
    prefix[0] = nums[0];
    for (int i = 1; i < numsSize; ++i) {
        prefix[i] = prefix[i - 1] + nums[i];
    }

    int* res = (int*)malloc(sizeof(int) * queriesSize);
    for (int i = 0; i < queriesSize; ++i) {
        int left = 0, right = numsSize;
        while (left < right) {
            int mid = (left + right) / 2;
            if (prefix[mid] <= queries[i])
                left = mid + 1;
            else
                right = mid;
        }
        res[i] = left;
    }

    *returnSize = queriesSize;
    return res;
}

int main() {
    int nums[] = {4, 5, 2, 1};
    int queries[] = {3, 10, 21};
    int n = sizeof(nums) / sizeof(nums[0]);
    int q = sizeof(queries) / sizeof(queries[0]);
    int returnSize;

    int* result = answerQueries(nums, n, queries, q, &returnSize);

    printf("Result: ");
    for (int i = 0; i < returnSize; ++i)
        printf("%d ", result[i]);
    printf("\n");

    free(result);
    return 0;
}
