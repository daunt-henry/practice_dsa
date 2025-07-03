/*
Problem: Binary Trees With Factors (LeetCode 823)

Given an array of unique integers, count how many binary trees you can make where:
- Every node is from the array
- For any node, its value = left.val * right.val

Approach:
- Sort the array
- Use DP: dp[i] = ways to build tree with root = arr[i]
- Check for all (arr[j], arr[k]) pairs where arr[j] * arr[k] == arr[i]

Time: O(n^2 log n)
Space: O(n)
*/

#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int find(int* arr, int size, int target) {
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int numFactoredBinaryTrees(int* arr, int arrSize) {
    qsort(arr, arrSize, sizeof(int), cmp);
    long MOD = 1000000007;
    long* dp = (long*)malloc(sizeof(long) * arrSize);

    for (int i = 0; i < arrSize; i++)
        dp[i] = 1;

    for (int i = 0; i < arrSize; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] % arr[j] == 0) {
                int right = arr[i] / arr[j];
                int k = find(arr, arrSize, right);
                if (k != -1) {
                    dp[i] = (dp[i] + dp[j] * dp[k]) % MOD;
                }
            }
        }
    }

    long total = 0;
    for (int i = 0; i < arrSize; i++)
        total = (total + dp[i]) % MOD;

    free(dp);
    return (int)total;
}

// Test
int main() {
    int arr[] = {2, 4, 5, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    int result = numFactoredBinaryTrees(arr, size);
    printf("Output: %d\n", result);  // Expected: 7

    return 0;
}

/*
========= OUTPUT =========
Output: 7
==========================
*/
