/*
Problem: Combination Sum III

Find all valid combinations of `k` numbers that sum up to `n` such that only numbers from 1 to 9 are used and each combination should be a unique set of numbers.

Example:
Input: k = 3, n = 7
Output: [[1,2,4]]

Input: k = 3, n = 9
Output: [[1,2,6],[1,3,5],[2,3,4]]
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void backtrack(int k, int n, int start, int* comb, int combSize, int** result, int* returnSize, int* returnColumnSizes) {
    if (combSize == k && n == 0) {
        result[*returnSize] = (int*)malloc(sizeof(int) * k);
        memcpy(result[*returnSize], comb, sizeof(int) * k);
        returnColumnSizes[*returnSize] = k;
        (*returnSize)++;
        return;
    }
    if (combSize > k || n < 0) return;

    for (int i = start; i <= 9; i++) {
        comb[combSize] = i;
        backtrack(k, n - i, i + 1, comb, combSize + 1, result, returnSize, returnColumnSizes);
    }
}

int** combinationSum3(int k, int n, int* returnSize, int** returnColumnSizes) {
    int** result = (int**)malloc(sizeof(int*) * 100);
    *returnColumnSizes = (int*)malloc(sizeof(int) * 100);
    *returnSize = 0;

    int comb[9];
    backtrack(k, n, 1, comb, 0, result, returnSize, *returnColumnSizes);
    return result;
}

void printResult(int** res, int resSize, int* colSizes) {
    printf("[\n");
    for (int i = 0; i < resSize; i++) {
        printf("  [");
        for (int j = 0; j < colSizes[i]; j++) {
            printf("%d", res[i][j]);
            if (j < colSizes[i] - 1) printf(",");
        }
        printf("]\n");
    }
    printf("]\n");
}

int main() {
    int returnSize;
    int* returnColumnSizes;
    int** result = combinationSum3(3, 9, &returnSize, &returnColumnSizes);
    printf("Output for k = 3, n = 9:\n");
    printResult(result, returnSize, returnColumnSizes);

    for (int i = 0; i < returnSize; i++) free(result[i]);
    free(result);
    free(returnColumnSizes);

    return 0;
}
