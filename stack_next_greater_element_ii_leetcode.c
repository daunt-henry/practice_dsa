/*
Next Greater Element II

Given a circular array, for each element, find the next greater element.
If no such element exists, output -1 for that index.

Input:
    nums = [1, 2, 1]
Output:
    [2, -1, 2]

Explanation:
- For 1, the next greater is 2
- For 2, no greater exists after it (even in circular wrap-around)
- For 1 (at index 2), the next greater is 2 (from beginning)
*/

#include <stdio.h>
#include <stdlib.h>

int* nextGreaterElements(int* nums, int numsSize, int* returnSize) {
    int* result = (int*)malloc(sizeof(int) * numsSize);
    int* stack = (int*)malloc(sizeof(int) * numsSize);
    int top = -1;

    for (int i = 2 * numsSize - 1; i >= 0; i--) {
        int index = i % numsSize;
        while (top >= 0 && stack[top] <= nums[index]) {
            top--;
        }
        result[index] = (top == -1) ? -1 : stack[top];
        stack[++top] = nums[index];
    }

    *returnSize = numsSize;
    free(stack);
    return result;
}

int main() {
    int nums[] = {1, 2, 1};
    int size = sizeof(nums) / sizeof(nums[0]);
    int returnSize;

    int* res = nextGreaterElements(nums, size, &returnSize);

    printf("Output: ");
    for (int i = 0; i < returnSize; ++i) {
        printf("%d ", res[i]);
    }
    printf("\n");

    free(res);
    return 0;
}
