/*
Problem: Delete and Earn (LeetCode 740)
URL: https://leetcode.com/problems/delete-and-earn/

You earn points by deleting nums[i], which also causes the removal of nums[i]-1 and nums[i]+1.
Goal: Maximize total points.

Approach:
- Aggregate points per value: points[i] = i * frequency of i
- Since deleting i forbids choosing i-1 or i+1, this becomes a "House Robber" style DP:
  * prev2 = max points up to i-2
  * prev1 = max points up to i-1
  * curr = max(prev1, prev2 + points[i])

Time Complexity: O(N + M)
Space Complexity: O(M)
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_V 10000

int deleteAndEarn(int* nums, int numsSize) {
    if (numsSize == 0) return 0;

    long* points = calloc(MAX_V + 1, sizeof(long));
    int maxVal = 0;

    for (int i = 0; i < numsSize; i++) {
        points[nums[i]] += nums[i];
        if (nums[i] > maxVal) maxVal = nums[i];
    }

    long prev2 = 0, prev1 = points[0];

    for (int i = 1; i <= maxVal; i++) {
        long curr = prev1 > (prev2 + points[i]) ? prev1 : (prev2 + points[i]);
        prev2 = prev1;
        prev1 = curr;
    }

    free(points);
    return (int)prev1;
}

int main(void) {
    int nums1[] = {3, 4, 2};
    int n1 = sizeof(nums1)/sizeof(nums1[0]);
    printf("nums = [3,4,2] → deleteAndEarn = %d (expected: 6)\n", deleteAndEarn(nums1, n1));

    int nums2[] = {2, 2, 3, 3, 3, 4};
    int n2 = sizeof(nums2)/sizeof(nums2[0]);
    printf("nums = [2,2,3,3,3,4] → deleteAndEarn = %d (expected: 9)\n", deleteAndEarn(nums2, n2));

    return 0;
}
