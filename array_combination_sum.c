/*
----------------------------------------
🧮 Problem: Combination Sum


Given an array of distinct integers `candidates` and a target integer `target`, return all unique combinations of candidates where the chosen numbers sum to target. You may reuse numbers as many times as needed.

Input:
    candidates = [2,3,6,7], target = 7

Output:
    [[2,2,3],[7]]

Explanation:
    - 2+2+3 = 7
    - 7 = 7

----------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

int** result;
int* resultColSizes;
int resultSize;

void dfs(int* candidates, int candidatesSize, int target, int* temp, int tempSize, int start) {
    if (target == 0) {
        result[resultSize] = (int*)malloc(sizeof(int) * tempSize);
        resultColSizes[resultSize] = tempSize;
        for (int i = 0; i < tempSize; i++) {
            result[resultSize][i] = temp[i];
        }
        resultSize++;
        return;
    }

    for (int i = start; i < candidatesSize; i++) {
        if (candidates[i] <= target) {
            temp[tempSize] = candidates[i];
            dfs(candidates, candidatesSize, target - candidates[i], temp, tempSize + 1, i);
        }
    }
}

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    result = (int**)malloc(sizeof(int*) * 1000);
    resultColSizes = (int*)malloc(sizeof(int) * 1000);
    resultSize = 0;
    int* temp = (int*)malloc(sizeof(int) * 1000);

    dfs(candidates, candidatesSize, target, temp, 0, 0);

    *returnSize = resultSize;
    *returnColumnSizes = resultColSizes;
    return result;
}

// 🔽 Sample Test Driver
int main() {
    int candidates[] = {2, 3, 6, 7};
    int target = 7;
    int returnSize;
    int* returnColSizes;

    int** combinations = combinationSum(candidates, 4, target, &returnSize, &returnColSizes);

    printf("Combinations that sum to %d:\n", target);
    for (int i = 0; i < returnSize; i++) {
        printf("[");
        for (int j = 0; j < returnColSizes[i]; j++) {
            printf("%d", combinations[i][j]);
            if (j < returnColSizes[i] - 1) printf(", ");
        }
        printf("]\n");
        free(combinations[i]);
    }

    free(combinations);
    free(returnColSizes);
    return 0;
}
