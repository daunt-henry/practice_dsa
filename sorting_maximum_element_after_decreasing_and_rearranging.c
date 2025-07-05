/*
Problem: Maximum Element After Decreasing and Rearranging

You are given an array arr. 
You can perform two operations:
1. Decrease any element to any positive integer.
2. Rearrange the array.

Goal:
Rearrange and decrease elements such that:
- arr[0] == 1
- abs(arr[i] - arr[i - 1]) <= 1 for all i > 0

Return the maximum value in the array after operations.

Example:
Input: arr = [2,2,1,2,1]
Output: 2

Approach:
- Sort the array.
- Set first element to 1.
- Ensure each next element is at most +1 of the previous.
*/

#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int maximumElementAfterDecrementingAndRearranging(int* arr, int arrSize){
    qsort(arr, arrSize, sizeof(int), cmp);
    arr[0] = 1;

    for (int i = 1; i < arrSize; i++) {
        if (arr[i] > arr[i - 1] + 1) {
            arr[i] = arr[i - 1] + 1;
        }
    }

    return arr[arrSize - 1];
}
