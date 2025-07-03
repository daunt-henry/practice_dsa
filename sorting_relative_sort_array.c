/*
Problem:
Sort arr1 such that elements present in arr2 appear first in the same order, 
and the remaining elements appear in ascending order.

Approach:
- Count the frequency of all elements in arr1.
- Append elements from arr2 first (in order and count).
- Append remaining elements in ascending order.

Time: O(n + k + 1000)
Space: O(1001)
*/

#include <stdio.h>
#include <stdlib.h>

int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize) {
    int count[1001] = {0};
    for (int i = 0; i < arr1Size; i++) {
        count[arr1[i]]++;
    }

    int* result = (int*)malloc(sizeof(int) * arr1Size);
    int index = 0;

    for (int i = 0; i < arr2Size; i++) {
        while (count[arr2[i]] > 0) {
            result[index++] = arr2[i];
            count[arr2[i]]--;
        }
    }

    for (int i = 0; i <= 1000; i++) {
        while (count[i] > 0) {
            result[index++] = i;
            count[i]--;
        }
    }

    *returnSize = arr1Size;
    return result;
}

// Test
int main() {
    int arr1[] = {2,3,1,3,2,4,6,7,9,2,19};
    int arr2[] = {2,1,4,3,9,6};
    int size1 = sizeof(arr1)/sizeof(arr1[0]);
    int size2 = sizeof(arr2)/sizeof(arr2[0]);
    int returnSize;

    int* result = relativeSortArray(arr1, size1, arr2, size2, &returnSize);

    printf("Relative Sorted Array:\n");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);
    return 0;
}

/*
========= OUTPUT =========
Relative Sorted Array:
2 2 2 1 4 3 3 9 6 7 19
==========================
*/
