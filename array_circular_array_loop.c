/*
Problem: Circular Array Loop
URL: https://leetcode.com/problems/circular-array-loop/

Description:
You are given a circular array `nums` of length n. Each element in nums 
represents a movement:
- nums[i] > 0: move forward nums[i] steps.
- nums[i] < 0: move backward |nums[i]| steps.

Since the array is circular, movement wraps around.
Return true if there exists a cycle of length > 1 with all moves in the same direction.

Example:
Input: nums = [2,-1,1,2,2]
Output: true

Input: nums = [-1,2]
Output: false
*/

#include <stdio.h>
#include <stdbool.h>

bool circularArrayLoop(int* nums, int numsSize) {
    if (numsSize < 2) return false;

    for (int i = 0; i < numsSize; i++) {
        int slow = i, fast = i;
        bool forward = nums[i] > 0;

        while (true) {
            // move one step for slow
            int nextSlow = ((slow + nums[slow]) % numsSize + numsSize) % numsSize;
            if ((nums[nextSlow] > 0) != forward || nextSlow == slow) break;

            // move two steps for fast
            int nextFast = ((fast + nums[fast]) % numsSize + numsSize) % numsSize;
            if ((nums[nextFast] > 0) != forward || nextFast == fast) break;

            nextFast = ((nextFast + nums[nextFast]) % numsSize + numsSize) % numsSize;
            if ((nums[nextFast] > 0) != forward || nextFast == ((fast + nums[fast]) % numsSize + numsSize) % numsSize) break;

            slow = nextSlow;
            fast = nextFast;

            if (slow == fast) return true;
        }
    }
    return false;
}

int main() {
    int nums1[] = {2, -1, 1, 2, 2};
    int size1 = 5;
    printf("Output: %s\n", circularArrayLoop(nums1, size1) ? "true" : "false");

    int nums2[] = {-1, 2};
    int size2 = 2;
    printf("Output: %s\n", circularArrayLoop(nums2, size2) ? "true" : "false");

    int nums3[] = {-2, 1, -1, -2, -2};
    int size3 = 5;
    printf("Output: %s\n", circularArrayLoop(nums3, size3) ? "true" : "false");

    return 0;
}
