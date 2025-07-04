/*
Make Two Arrays Equal by Reversing Subarrays

Problem:
- You are given two integer arrays `target` and `arr`.
- You can reverse any number of subarrays of `arr`.
- Return true if you can make `arr` equal to `target`.

Observation:
- Reversing subarrays allows rearranging elements.
- So we only need to check if both arrays contain the same elements (frequency matters).

Approach:
- Sort both arrays.
- Compare them element-wise.

Time: O(n log n) — for sorting
Space: O(1) — in-place sorting

Example:
Input: target = [1,2,3,4], arr = [2,4,1,3]
Sorted: [1,2,3,4] == [1,2,3,4] → true

Output: true
*/

#include <stdlib.h>
#include <stdbool.h>

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

bool canBeEqual(int* target, int targetSize, int* arr, int arrSize) {
    if (targetSize != arrSize) return false;

    qsort(target, targetSize, sizeof(int), cmp);
    qsort(arr, arrSize, sizeof(int), cmp);

    for (int i = 0; i < targetSize; i++) {
        if (target[i] != arr[i]) return false;
    }

    return true;
}
