/*
Can Make Arithmetic Progression From Sequence

Problem:
- Given an array, check if it can be rearranged to form an arithmetic progression.

Approach:
- Sort the array.
- Check if the difference between consecutive elements is consistent.

Time: O(n log n) for sorting
Space: O(1)

Example:
Input: [3, 5, 1]
Output: true
Explanation: Rearranged as [1, 3, 5], common difference is 2.
*/

#include <stdbool.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

bool canMakeArithmeticProgression(int* arr, int arrSize) {
    qsort(arr, arrSize, sizeof(int), cmp);
    int diff = arr[1] - arr[0];
    for (int i = 2; i < arrSize; i++) {
        if (arr[i] - arr[i - 1] != diff)
            return false;
    }
    return true;
}
