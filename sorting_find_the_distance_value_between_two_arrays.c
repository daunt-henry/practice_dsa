/*
Find the Distance Value Between Two Arrays

Problem:
- Count how many elements in arr1 are such that no element in arr2 
  is within distance `d` from them.

Approach:
- Sort arr2.
- For each element in arr1, binary search arr2 to check if 
  there’s any number within distance `d`.

Time: O(n log m), where n = len(arr1), m = len(arr2)
Space: O(1)

Example:
Input: arr1 = [4,5,8], arr2 = [10,9,1,8], d = 2
Output: 2
(Only 4 and 5 are valid)
*/

#include <stdlib.h>
#include <math.h>

int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int binarySearch(int* arr, int size, int target, int d) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (abs(arr[mid] - target) <= d) {
            return 0;
        }
        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return 1;
}

int findTheDistanceValue(int* arr1, int arr1Size, int* arr2, int arr2Size, int d) {
    qsort(arr2, arr2Size, sizeof(int), cmp);
    int count = 0;
    for (int i = 0; i < arr1Size; i++) {
        if (binarySearch(arr2, arr2Size, arr1[i], d))
            count++;
    }
    return count;
}
