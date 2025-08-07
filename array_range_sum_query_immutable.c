/*
Problem: Range Sum Query – Immutable

Design a data structure that allows you to compute the sum of elements
in a static integer array (`nums`) for multiple queries.

Operations:
- Initialize with the array.
- For each query sumRange(left, right), return the sum of elements from
  index 'left' to 'right' (inclusive).

Example:
nums = [-2, 0, 3, -5, 2, -1]
sumRange(0, 2) -> 1    // (-2 + 0 + 3)
sumRange(2, 5) -> -1   // (3 + -5 + 2 + -1)
sumRange(0, 5) -> -3   // total sum from index 0 to 5
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* prefix;
    int size;
} NumArray;

NumArray* numArrayCreate(int* nums, int numsSize) {
    NumArray* obj = (NumArray*)malloc(sizeof(NumArray));
    obj->size = numsSize;
    obj->prefix = (int*)malloc(sizeof(int) * (numsSize + 1));
    obj->prefix[0] = 0;
    for (int i = 0; i < numsSize; i++) {
        obj->prefix[i + 1] = obj->prefix[i] + nums[i];
    }
    return obj;
}

int numArraySumRange(NumArray* obj, int left, int right) {
    if (left < 0 || right >= obj->size || left > right) return 0;
    return obj->prefix[right + 1] - obj->prefix[left];
}

void numArrayFree(NumArray* obj) {
    free(obj->prefix);
    free(obj);
}

int main() {
    int nums[] = {-2, 0, 3, -5, 2, -1};
    int n = sizeof(nums) / sizeof(nums[0]);

    NumArray* arr = numArrayCreate(nums, n);

    printf("sumRange(0, 2) = %d\n", numArraySumRange(arr, 0, 2)); // 1
    printf("sumRange(2, 5) = %d\n", numArraySumRange(arr, 2, 5)); // -1
    printf("sumRange(0, 5) = %d\n", numArraySumRange(arr, 0, 5)); // -3

    numArrayFree(arr);
    return 0;
}
