/*
Problem:
You are given an array `nums`. For each element `nums[i]`, find the second greater number 
to its right. That is, the first number greater than `nums[i]`, and then the next number greater than that.

Return an array `res` where res[i] = second greater number for nums[i], or -1 if it doesn't exist.

Example Input:
nums = [2,4,0,9,6]

Expected Output:
[9,6,6,-1,-1]

Explanation:
- 2 → next greater is 4, then 9 → res[0] = 9
- 4 → next greater is 9, then 6 → res[1] = 6
- 0 → next greater is 9, then 6 → res[2] = 6
- 9 → no next greater → res[3] = -1
- 6 → no next greater → res[4] = -1
*/

#include <stdio.h>
#include <stdlib.h>

int* secondGreaterElement(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int* res = malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; ++i)
        res[i] = -1;

    int* stack1 = malloc(sizeof(int) * numsSize);
    int* stack2 = malloc(sizeof(int) * numsSize);
    int top1 = -1, top2 = -1;

    int* wait = malloc(sizeof(int) * numsSize);
    int waitTop = -1;

    for (int i = 0; i < numsSize; ++i) {
        while (top2 >= 0 && nums[i] > nums[stack2[top2]]) {
            res[stack2[top2--]] = nums[i];
        }

        waitTop = -1;
        while (top1 >= 0 && nums[i] > nums[stack1[top1]]) {
            wait[++waitTop] = stack1[top1--];
        }

        while (waitTop >= 0) {
            stack2[++top2] = wait[waitTop--];
        }

        stack1[++top1] = i;
    }

    free(stack1);
    free(stack2);
    free(wait);
    return res;
}

int main() {
    int nums[] = {2, 4, 0, 9, 6};
    int size = sizeof(nums) / sizeof(nums[0]);
    int returnSize;

    int* res = secondGreaterElement(nums, size, &returnSize);

    printf("Second greater elements:\n");
    for (int i = 0; i < returnSize; ++i)
        printf("%d ", res[i]);
    printf("\n");

    free(res);
    return 0;
}
