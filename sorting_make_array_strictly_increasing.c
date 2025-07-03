/*
Problem:
You can replace elements in arr1 using elements from arr2 to make arr1 strictly increasing.
Find the minimum number of operations needed.

Approach:
- Sort arr2 to allow binary search for next greater values.
- Use DP to store the minimum last element for a given number of replacements.
- dp[i][j] = minimum last value in a valid strictly increasing array using first i elements and j replacements.

Time: O(n * m), where n = len(arr1), m = len(arr2)
Space: O(n * m)
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int min(int a, int b) {
    return a < b ? a : b;
}

int upperBound(int* arr, int size, int target) {
    int left = 0, right = size;
    while (left < right) {
        int mid = (left + right) / 2;
        if (arr[mid] <= target)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

int makeArrayIncreasing(int* arr1, int arr1Size, int* arr2, int arr2Size) {
    qsort(arr2, arr2Size, sizeof(int), compare);

    int dp[arr1Size + 1][arr2Size + 1];
    for (int i = 0; i <= arr1Size; i++)
        for (int j = 0; j <= arr2Size; j++)
            dp[i][j] = INT_MAX;

    dp[0][0] = -1;

    for (int i = 1; i <= arr1Size; i++) {
        for (int j = 0; j <= arr2Size; j++) {
            if (dp[i - 1][j] == INT_MAX) continue;

            if (arr1[i - 1] > dp[i - 1][j])
                dp[i][j] = min(dp[i][j], arr1[i - 1]);

            if (j < arr2Size) {
                int ub = upperBound(arr2, arr2Size, dp[i - 1][j]);
                if (ub < arr2Size)
                    dp[i][j + 1] = min(dp[i][j + 1], arr2[ub]);
            }
        }
    }

    for (int j = 0; j <= arr2Size; j++) {
        if (dp[arr1Size][j] != INT_MAX)
            return j;
    }
    return -1;
}

// Test
int main() {
    int arr1[] = {1,5,3,6,7};
    int arr2[] = {1,3,2,4};
    int res = makeArrayIncreasing(arr1, 5, arr2, 4);
    printf("Minimum operations to make array strictly increasing: %d\n", res);  // Expected: 1
    return 0;
}

/*
========= OUTPUT =========
Minimum operations to make array strictly increasing: 1
==========================
*/
