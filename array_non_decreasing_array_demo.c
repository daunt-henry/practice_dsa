/*
Problem: Non-decreasing Array (LeetCode 665)

Given an integer array `nums`, determine whether the array can become non-decreasing
by modifying at most one element.

Example:
Input: nums = [4, 2, 3]
Output: true  // Modify 4 to 2 → [2, 2, 3]

Input: nums = [4, 2, 1]
Output: false // More than one change required
*/

#include <stdio.h>
#include <stdbool.h>

bool checkPossibility(int* nums, int numsSize) {
    bool modified = false;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] < nums[i - 1]) {
            if (modified) return false;
            if (i == 1 || nums[i] >= nums[i - 2]) {
                nums[i - 1] = nums[i];
            } else {
                nums[i] = nums[i - 1];
            }
            modified = true;
        }
    }
    return true;
}

void test(int* arr, int size) {
    printf("Input: [");
    for (int i = 0; i < size; i++) {
        printf("%d%s", arr[i], (i + 1 < size) ? ", " : "");
    }
    printf("] → %s\n", checkPossibility(arr, size) ? "true" : "false");
}

int main(void) {
    int t1[] = {4, 2, 3};
    test(t1, 3);  // expected true

    int t2[] = {4, 2, 1};
    test(t2, 3);  // expected false

    int t3[] = {-1, 4, 2, 3};
    test(t3, 4);  // expected true

    int t4[] = {3, 4, 2, 3};
    test(t4, 4);  // expected false

    return 0;
}
