/*
Problem: Combination Sum II

Description:
Given a collection of candidate numbers (candidates) and a target number (target), 
find all unique combinations in candidates where the candidate numbers sum to target. 
Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

Example:
Input: candidates = [10,1,2,7,6,1,5], target = 8
Output:
[
  [1,1,6],
  [1,2,5],
  [1,7],
  [2,6]
]

*/

#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void dfs(int* candidates, int candidatesSize, int target, int start, int* temp, int tempSize, int** result, int* returnSize, int** returnColumnSizes) {
    if (target == 0) {
        result[*returnSize] = malloc(sizeof(int) * tempSize);
        (*returnColumnSizes)[*returnSize] = tempSize;
        for (int i = 0; i < tempSize; i++) {
            result[*returnSize][i] = temp[i];
        }
        (*returnSize)++;
        return;
    }

    for (int i = start; i < candidatesSize; i++) {
        if (i > start && candidates[i] == candidates[i - 1]) continue;
        if (candidates[i] > target) break;

        temp[tempSize] = candidates[i];
        dfs(candidates, candidatesSize, target - candidates[i], i + 1, temp, tempSize + 1, result, returnSize, returnColumnSizes);
    }
}

int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    int** result = malloc(sizeof(int*) * 1000);
    *returnColumnSizes = malloc(sizeof(int) * 1000);
    int* temp = malloc(sizeof(int) * candidatesSize);

    qsort(candidates, candidatesSize, sizeof(int), cmp);
    dfs(candidates, candidatesSize, target, 0, temp, 0, result, returnSize, returnColumnSizes);
    free(temp);
    return result;
}

// Sample test case for demonstration
int main() {
    int candidates[] = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    int returnSize;
    int* returnColumnSizes;
    int** result = combinationSum2(candidates, 7, target, &returnSize, &returnColumnSizes);

    printf("Combinations summing to %d:\n", target);
    for (int i = 0; i < returnSize; i++) {
        printf("[");
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d", result[i][j]);
            if (j < returnColumnSizes[i] - 1) printf(", ");
        }
        printf("]\n");
        free(result[i]);
    }

    free(result);
    free(returnColumnSizes);
    return 0;
}
