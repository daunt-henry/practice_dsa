/*
Problem: Permutations

Given an array nums of distinct integers, return all the possible permutations.
You can return the answer in any order.

Example 1:
Input: nums = [1,2,3]
Output:
[
 [1,2,3],
 [1,3,2],
 [2,1,3],
 [2,3,1],
 [3,1,2],
 [3,2,1]
]

Example 2:
Input: nums = [0,1]
Output: [[0,1],[1,0]]
*/

#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void backtrack(int* nums, int numsSize, int start, int** res, int* returnSize, int* colSizes) {
    if (start == numsSize) {
        res[*returnSize] = (int*)malloc(sizeof(int) * numsSize);
        for (int i = 0; i < numsSize; ++i)
            res[*returnSize][i] = nums[i];
        colSizes[*returnSize] = numsSize;
        (*returnSize)++;
        return;
    }
    
    for (int i = start; i < numsSize; ++i) {
        swap(&nums[start], &nums[i]);
        backtrack(nums, numsSize, start + 1, res, returnSize, colSizes);
        swap(&nums[start], &nums[i]);
    }
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int total = 1;
    for (int i = 2; i <= numsSize; i++) total *= i;

    int** res = (int**)malloc(sizeof(int*) * total);
    int* colSizes = (int*)malloc(sizeof(int) * total);
    *returnSize = 0;
    
    backtrack(nums, numsSize, 0, res, returnSize, colSizes);
    *returnColumnSizes = colSizes;
    return res;
}

int main() {
    int nums[] = {1, 2, 3};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize;
    int* returnColumnSizes;

    int** result = permute(nums, numsSize, &returnSize, &returnColumnSizes);
    
    printf("Permutations:\n");
    for (int i = 0; i < returnSize; ++i) {
        printf("[");
        for (int j = 0; j < returnColumnSizes[i]; ++j) {
            printf("%d", result[i][j]);
            if (j < returnColumnSizes[i] - 1) printf(",");
        }
        printf("]\n");
        free(result[i]);
    }
    free(result);
    free(returnColumnSizes);
    return 0;
}

/*
Sample Output:
Permutations:
[1,2,3]
[1,3,2]
[2,1,3]
[2,3,1]
[3,2,1]
[3,1,2]
*/
