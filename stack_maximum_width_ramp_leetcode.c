/*
Title: Maximum Width Ramp

Description:
  A ramp is a pair of indices (i, j) where i < j and A[i] <= A[j].
  The width of such a ramp is j - i.
  Return the maximum width of a ramp in the array.

Example Input:
  nums = [6,0,8,2,1,5]

Example Output:
  4

Explanation:
  The ramp (1,5) gives a width of 4 (0 <= 5) and is the widest such pair.
*/

#include <stdio.h>

int maxWidthRamp(int* nums, int numsSize) {
    int stack[numsSize];
    int top = -1;

    // Build decreasing stack of indices
    for (int i = 0; i < numsSize; ++i) {
        if (top == -1 || nums[i] < nums[stack[top]]) {
            stack[++top] = i;
        }
    }

    int maxWidth = 0;
    for (int j = numsSize - 1; j >= 0; --j) {
        while (top >= 0 && nums[j] >= nums[stack[top]]) {
            int i = stack[top--];
            if (j - i > maxWidth)
                maxWidth = j - i;
        }
    }

    return maxWidth;
}

int main() {
    int nums1[] = {6, 0, 8, 2, 1, 5};
    printf("Input: [6, 0, 8, 2, 1, 5]\n");
    printf("Max Width Ramp: %d\n", maxWidthRamp(nums1, 6)); // Expected: 4

    int nums2[] = {9, 8, 1, 0, 1, 9};
    printf("Input: [9, 8, 1, 0, 1, 9]\n");
    printf("Max Width Ramp: %d\n", maxWidthRamp(nums2, 6)); // Expected: 5

    return 0;
}
