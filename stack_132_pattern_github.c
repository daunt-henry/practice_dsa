/*
Problem: Detect 132 Pattern

Description:
Given an array of n integers nums, a 132 pattern is a subsequence of three integers nums[i], nums[j] and nums[k] such that i < j < k and nums[i] < nums[k] < nums[j].
Return true if there is a 132 pattern in nums, otherwise return false.

Example Input:
nums = [3, 1, 4, 2]

Example Output:
true
*/

#include <stdio.h>
#include <stdbool.h>

#define MAXN 100000

bool find132pattern(int* nums, int numsSize) {
    if (numsSize < 3) return false;

    int stack[MAXN];
    int top = -1;
    int s3 = -1000000001;

    for (int i = numsSize - 1; i >= 0; i--) {
        if (nums[i] < s3) return true;
        while (top >= 0 && nums[i] > stack[top]) {
            s3 = stack[top--];
        }
        stack[++top] = nums[i];
    }
    return false;
}

int main() {
    int nums[] = {3, 1, 4, 2};
    int size = sizeof(nums) / sizeof(nums[0]);

    if (find132pattern(nums, size))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}
