/*
Check If N and Its Double Exist

Problem:
Given an array, check if there exists two indices i and j such that:
- i != j
- arr[i] == 2 * arr[j]

Approach:
- Sort the array
- For each element, binary search for its double (skip the same index)

Time: O(n log n)
Space: O(1)

Example Input:
arr = [10, 2, 5, 3]

Expected Output:
true
(Because 5 * 2 = 10)
*/

#include <stdbool.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

bool checkIfExist(int* arr, int arrSize) {
    qsort(arr, arrSize, sizeof(int), compare);

    for (int i = 0; i < arrSize; i++) {
        int target = 2 * arr[i];
        int left = 0, right = arrSize - 1;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (mid != i && arr[mid] == target)
                return true;
            if (arr[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
    }

    return false;
}
