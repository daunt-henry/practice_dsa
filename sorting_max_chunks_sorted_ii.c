/*
Problem: Max Chunks To Make Sorted II (LeetCode 768)

Given an array, return the maximum number of chunks you can make so that sorting each chunk results in a fully sorted array.

Approach:
- Create a suffix minimum array from the right
- Iterate left to right comparing max-so-far and right minimum

Time: O(n)
Space: O(n)
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int maxChunksToSorted(int* arr, int arrSize) {
    int* rightMin = (int*)malloc(sizeof(int) * (arrSize + 1));
    rightMin[arrSize] = INT_MAX;

    for (int i = arrSize - 1; i >= 0; i--) {
        rightMin[i] = arr[i] < rightMin[i + 1] ? arr[i] : rightMin[i + 1];
    }

    int chunks = 0;
    int leftMax = arr[0];

    for (int i = 0; i < arrSize; i++) {
        if (leftMax <= rightMin[i + 1]) {
            chunks++;
        }
        if (i + 1 < arrSize && arr[i + 1] > leftMax) {
            leftMax = arr[i + 1];
        }
    }

    free(rightMin);
    return chunks;
}

// Test case
int main() {
    int arr[] = {5, 4, 3, 2, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    int result = maxChunksToSorted(arr, size);
    printf("Output: %d\n", result);

    return 0;
}

/*
========= OUTPUT =========
Output: 1
==========================
*/
