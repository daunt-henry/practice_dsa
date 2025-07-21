/*
Title: Sum of Subarray Minimums

Description:
  Given an array of integers, find the sum of the minimum value of every subarray.
  Return the sum modulo 10^9 + 7.

Example Input:
  arr = [3, 1, 2, 4]

Example Output:
  17

Explanation:
  Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]
  Minimums are   3    1    2    4    1      1      2      1         1        1
  Sum = 17
*/

#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007

int sumSubarrayMins(int* arr, int arrSize) {
    int* stack = (int*)malloc(sizeof(int) * arrSize);
    int top = -1;

    int* prev = (int*)malloc(sizeof(int) * arrSize);
    int* next = (int*)malloc(sizeof(int) * arrSize);

    // Calculate Previous Less Element
    for (int i = 0; i < arrSize; ++i) {
        while (top >= 0 && arr[stack[top]] > arr[i]) top--;
        prev[i] = (top == -1) ? -1 : stack[top];
        stack[++top] = i;
    }

    // Reset stack for Next Less Element
    top = -1;
    for (int i = arrSize - 1; i >= 0; --i) {
        while (top >= 0 && arr[stack[top]] >= arr[i]) top--;
        next[i] = (top == -1) ? arrSize : stack[top];
        stack[++top] = i;
    }

    long result = 0;
    for (int i = 0; i < arrSize; ++i) {
        long left = i - prev[i];
        long right = next[i] - i;
        result = (result + (arr[i] * left % MOD) * right % MOD) % MOD;
    }

    free(stack);
    free(prev);
    free(next);
    return (int)result;
}

int main() {
    int arr[] = {3, 1, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Input: [3, 1, 2, 4]\n");
    printf("Output: %d\n", sumSubarrayMins(arr, n)); // Expected: 17

    int arr2[] = {11, 81, 94, 43, 3};
    n = sizeof(arr2) / sizeof(arr2[0]);
    printf("Input: [11, 81, 94, 43, 3]\n");
    printf("Output: %d\n", sumSubarrayMins(arr2, n)); // Expected: 444

    return 0;
}
