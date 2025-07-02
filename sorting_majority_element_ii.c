/*
Problem: Majority Element II

Description:
Find all elements that appear more than ⌊ n/3 ⌋ times.
You may return the answer in any order.

Example:
Input: [3,2,3]
Output: [3]
*/

#include <stdio.h>
#include <stdlib.h>

int* majorityElement(int* nums, int numsSize, int* returnSize) {
    int count1 = 0, count2 = 0;
    int candidate1 = 0, candidate2 = 1;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == candidate1) {
            count1++;
        } else if (nums[i] == candidate2) {
            count2++;
        } else if (count1 == 0) {
            candidate1 = nums[i];
            count1 = 1;
        } else if (count2 == 0) {
            candidate2 = nums[i];
            count2 = 1;
        } else {
            count1--;
            count2--;
        }
    }

    count1 = count2 = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == candidate1) count1++;
        else if (nums[i] == candidate2) count2++;
    }

    int* result = malloc(sizeof(int) * 2);
    *returnSize = 0;

    if (count1 > numsSize / 3) result[(*returnSize)++] = candidate1;
    if (count2 > numsSize / 3) result[(*returnSize)++] = candidate2;

    return result;
}

// Test
int main() {
    int nums[] = {1,1,1,3,3,2,2,2};
    int size = sizeof(nums) / sizeof(nums[0]);
    int returnSize = 0;

    int* result = majorityElement(nums, size, &returnSize);

    printf("Majority elements (> n/3): ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);
    return 0;
}

/*
========= OUTPUT =========
Majority elements (> n/3): 1 2
==========================
*/
