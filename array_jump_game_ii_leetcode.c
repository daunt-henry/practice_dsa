/*
Problem: Jump Game II

You are given a 0-indexed array of integers nums of length n.
You are initially positioned at nums[0], and at each step,
you may jump to any index i + nums[i].

Return the minimum number of jumps to reach the last index.
You can assume that you can always reach the last index.

Example 1:
Input: nums = [2,3,1,1,4]
Output: 2
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:
Input: nums = [2,3,0,1,4]
Output: 2
*/

#include <stdio.h>

int jump(int* nums, int numsSize) {
    int jumps = 0, farthest = 0, current_end = 0;
    
    for (int i = 0; i < numsSize - 1; ++i) {
        if (i + nums[i] > farthest)
            farthest = i + nums[i];
        if (i == current_end) {
            jumps++;
            current_end = farthest;
        }
    }

    return jumps;
}

int main() {
    int nums[] = {2, 3, 1, 1, 4};
    int size = sizeof(nums) / sizeof(nums[0]);
    int result = jump(nums, size);
    printf("Minimum jumps to reach end: %d\n", result);
    return 0;
}

/*
Sample Output:
Minimum jumps to reach end: 2
*/
