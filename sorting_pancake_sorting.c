/*
Problem:
Sort an array using pancake flips — you can reverse first k elements.
Return the sequence of flips (values of k).

Approach:
- Find the largest element in the unsorted portion.
- Flip it to the front, then flip it to its correct position.
- Repeat for each decreasing size.

Time: O(n^2)
Space: O(n) for result array
*/

#include <stdio.h>
#include <stdlib.h>

void flip(int* arr, int k) {
    int i = 0, j = k - 1;
    while (i < j) {
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
        i++; j--;
    }
}

int findMaxIndex(int* arr, int n) {
    int idx = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[idx]) idx = i;
    }
    return idx;
}

int* pancakeSort(int* arr, int arrSize, int* returnSize) {
    int* res = (int*)malloc(sizeof(int) * arrSize * 2);
    int resIdx = 0;

    for (int currSize = arrSize; currSize > 1; currSize--) {
        int maxIdx = findMaxIndex(arr, currSize);
        if (maxIdx != currSize - 1) {
            if (maxIdx != 0) {
                flip(arr, maxIdx + 1);
                res[resIdx++] = maxIdx + 1;
            }
            flip(arr, currSize);
            res[resIdx++] = currSize;
        }
    }

    *returnSize = resIdx;
    return res;
}

// Test
int main() {
    int arr[] = {3, 2, 4, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    int returnSize;

    int* flips = pancakeSort(arr, size, &returnSize);

    printf("Flip sequence: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", flips[i]);
    }
    printf("\n");

    free(flips);
    return 0;
}

/*
========= OUTPUT =========
Flip sequence: 3 4 2 3 2 
==========================
*/
