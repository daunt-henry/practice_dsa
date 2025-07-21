/*
Title: Shortest Subarray to be Removed to Make Array Sorted

Description:
  Given an integer array `arr`, remove the shortest subarray 
  (possibly empty) such that the remaining array is non-decreasing.
  Return the length of the shortest subarray to remove.

Example:
  Input:  arr = [1,2,3,10,4,2,3,5]
  Output: 3

Explanation:
  Remove subarray [10,4,2] or [4,2,3]

Approach:
  - Find the longest non-decreasing prefix and suffix.
  - Then attempt to merge the two.
  - Try minimizing the number of elements to remove.

*/

#include <stdio.h>
#include <stdlib.h>

int findLengthOfShortestSubarray(int* arr, int arrSize) {
    int left = 0, right = arrSize - 1;

    while (left + 1 < arrSize && arr[left] <= arr[left + 1]) left++;
    if (left == arrSize - 1) return 0;

    while (right > 0 && arr[right - 1] <= arr[right]) right--;

    int minRemove = fmin(arrSize - left - 1, right);

    for (int i = 0; i <= left; i++) {
        while (right < arrSize && arr[right] < arr[i]) right++;
        minRemove = fmin(minRemove, right - i - 1);
    }

    return minRemove;
}

int main() {
    int arr[] = {1, 2, 3, 10, 4, 2, 3, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int result = findLengthOfShortestSubarray(arr, size);
    printf("Shortest subarray to remove: %d\n", result);  // Output: 3
    return 0;
}
