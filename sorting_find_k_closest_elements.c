/*
Problem: Find K Closest Elements

Given a sorted array arr, and integers k and x,
return k closest elements to x. The result should also be sorted.
If a tie occurs, prefer the smaller value.

Approach:
- Use binary search to find the left bound of a window of size k.
- Return arr[left .. left + k - 1]

Time: O(log(n - k) + k)
Space: O(k)
*/

#include <stdio.h>
#include <stdlib.h>

int* findClosestElements(int* arr, int arrSize, int k, int x, int* returnSize) {
    int left = 0, right = arrSize - k;

    while (left < right) {
        int mid = (left + right) / 2;
        if (x - arr[mid] > arr[mid + k] - x)
            left = mid + 1;
        else
            right = mid;
    }

    int* res = (int*)malloc(sizeof(int) * k);
    for (int i = 0; i < k; i++) {
        res[i] = arr[left + i];
    }

    *returnSize = k;
    return res;
}

// Test
int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int k = 4, x = 3;
    int size;

    int* result = findClosestElements(arr, 5, k, x, &size);

    printf("K Closest Elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);
    return 0;
}

/*
========= OUTPUT =========
K Closest Elements: 1 2 3 4
==========================
*/
