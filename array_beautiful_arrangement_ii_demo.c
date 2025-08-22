/*
Beautiful Arrangement II (LeetCode 667)

Given two integers n and k, construct an array of length n using numbers 1 to n,
such that the array of absolute differences between consecutive elements has exactly k distinct values.
Any valid answer is acceptable.

Strategy:
1. First part: fill [1, 2, ..., n-k-1] in ascending order (all differences = 1).
2. Second part: alternate between low and high values within [n-k .. n]:
   low, high, low+1, high-1, ... — ensures distinct differences decreasing from k to 1.

Complexity: O(n) time and O(n) space.
*/

#include <stdio.h>
#include <stdlib.h>

int* constructArray(int n, int k, int* returnSize) {
    *returnSize = n;
    int* ans = malloc(n * sizeof(int));
    int idx = 0;

    for (int i = 1; i <= n - k - 1; i++) {
        ans[idx++] = i;
    }

    int low = n - k, high = n;
    for (int i = 0; i <= k; i++) {
        ans[idx++] = (i % 2 == 0) ? low++ : high--;
    }

    return ans;
}

void printArray(int* arr, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d%s", arr[i], i + 1 < size ? ", " : "");
    }
    printf("]\n");
}

int main(void) {
    int n1 = 3, k1 = 1, size1;
    int* a1 = constructArray(n1, k1, &size1);
    printf("n = %d, k = %d → ", n1, k1);
    printArray(a1, size1);
    free(a1);

    int n2 = 3, k2 = 2, size2;
    int* a2 = constructArray(n2, k2, &size2);
    printf("n = %d, k = %d → ", n2, k2);
    printArray(a2, size2);
    free(a2);

    int n3 = 7, k3 = 3, size3;
    int* a3 = constructArray(n3, k3, &size3);
    printf("n = %d, k = %d → ", n3, k3);
    printArray(a3, size3);
    free(a3);

    return 0;
}
