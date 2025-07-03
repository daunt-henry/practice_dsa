/*
Problem: Fair Candy Swap 

Two people, Alice and Bob, exchange one candy each to equalize total candy amounts.

Approach:
- Let diff = (sumA - sumB) / 2
- For each a in A, check if (a - diff) exists in B

Time: O(n * m) for search (brute force)
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool find(int* arr, int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) return true;
    }
    return false;
}

int* fairCandySwap(int* A, int ASize, int* B, int BSize, int* returnSize) {
    int sumA = 0, sumB = 0;
    for (int i = 0; i < ASize; i++) sumA += A[i];
    for (int i = 0; i < BSize; i++) sumB += B[i];

    int diff = (sumA - sumB) / 2;

    int* res = malloc(2 * sizeof(int));
    for (int i = 0; i < ASize; i++) {
        int target = A[i] - diff;
        if (find(B, BSize, target)) {
            res[0] = A[i];
            res[1] = target;
            *returnSize = 2;
            return res;
        }
    }
    *returnSize = 0;
    return NULL;
}

// Test
int main() {
    int A[] = {1, 1};
    int B[] = {2, 2};
    int returnSize;

    int* result = fairCandySwap(A, 2, B, 2, &returnSize);
    if (result) {
        printf("Output: [%d, %d]\n", result[0], result[1]);  // Expected: [1, 2]
        free(result);
    } else {
        printf("No valid swap found.\n");
    }

    return 0;
}

/*
========= OUTPUT =========
Output: [1, 2]
==========================
*/
