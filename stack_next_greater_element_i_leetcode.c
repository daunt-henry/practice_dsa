/*
Next Greater Element I

You are given two integer arrays `nums1` and `nums2` where `nums1` is a subset of `nums2`.

For each element in nums1, find the next greater element in nums2. If it does not exist, return -1.

Example:
Input:
    nums1 = [4,1,2]
    nums2 = [1,3,4,2]
Output:
    [-1,3,-1]

Input:
    nums1 = [2,4]
    nums2 = [1,2,3,4]
Output:
    [3,-1]
*/

#include <stdio.h>
#include <stdlib.h>

int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int* result = (int*)malloc(sizeof(int) * nums1Size);
    *returnSize = nums1Size;

    int map[10001];
    for (int i = 0; i <= 10000; ++i) map[i] = -1;

    int* stack = (int*)malloc(sizeof(int) * nums2Size);
    int top = -1;

    for (int i = 0; i < nums2Size; ++i) {
        while (top >= 0 && nums2[i] > stack[top]) {
            map[stack[top--]] = nums2[i];
        }
        stack[++top] = nums2[i];
    }

    for (int i = 0; i < nums1Size; ++i) {
        result[i] = map[nums1[i]];
    }

    free(stack);
    return result;
}

int main() {
    int nums1[] = {4, 1, 2};
    int nums2[] = {1, 3, 4, 2};
    int returnSize = 0;

    int* res = nextGreaterElement(nums1, 3, nums2, 4, &returnSize);
    printf("Output: ");
    for (int i = 0; i < returnSize; ++i) {
        printf("%d ", res[i]);
    }
    printf("\n");

    free(res);
    return 0;
}
