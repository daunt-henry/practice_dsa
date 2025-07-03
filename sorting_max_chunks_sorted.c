/*
Problem: Max Chunks To Make Sorted (LeetCode 769)

Given a permutation array, split it into maximum chunks
such that sorting each chunk and concatenating results in a sorted array.

Approach:
- At index i, if max value from 0...i is i → new chunk possible

Time: O(n)
Space: O(1)
*/

#include <stdio.h>

int maxChunksToSorted(int* arr, int arrSize) {
    int chunks = 0;
    int maxVal = 0;

    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
        if (maxVal == i) {
            chunks++;
        }
    }

    return chunks;
}

// Test
int main() {
    int arr[] = {1, 0, 2, 3, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    int result = maxChunksToSorted(arr, size);
    printf("Output: %d\n", result);

    return 0;
}

/*
========= OUTPUT =========
Output: 4
==========================
*/
