/*
Problem:
Given an integer array `nums`, repeatedly perform the following operation:
- If nums[i] < nums[i - 1], remove nums[i]

Do this until the array becomes non-decreasing.
Return the number of **steps** required to make the array non-decreasing.

Constraints:
- 1 <= nums.length <= 10^5

Example:
Input: nums = [5,3,4,4,7,3,6,11,8,5,11]
Output: 3

Explanation:
Step 1: remove 3 (index 1) → [5,4,4,7,3,6,11,8,5,11]  
Step 2: remove 3 (index 4) → [5,4,4,7,6,11,8,5,11]  
Step 3: remove 6 (index 4) → [5,4,4,7,11,8,5,11]

After step 3, it's non-decreasing.

-------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

int totalSteps(int* nums, int numsSize) {
    int* stack = (int*)malloc(numsSize * sizeof(int));
    int* days = (int*)calloc(numsSize, sizeof(int));
    int top = -1;
    int maxDays = 0;

    for (int i = 0; i < numsSize; i++) {
        int currDays = 0;
        while (top >= 0 && nums[i] >= nums[stack[top]]) {
            currDays = currDays > days[stack[top]] ? currDays : days[stack[top]];
            top--;
        }

        if (top >= 0) {
            days[i] = currDays + 1;
            maxDays = maxDays > days[i] ? maxDays : days[i];
        }

        stack[++top] = i;
    }

    free(stack);
    free(days);
    return maxDays;
}

// Demo
int main() {
    int nums[] = {5, 3, 4, 4, 7, 3, 6, 11, 8, 5, 11};
    int n = sizeof(nums) / sizeof(nums[0]);
    int result = totalSteps(nums, n);
    printf("Steps to make non-decreasing: %d\n", result); // Output: 3
    return 0;
}
