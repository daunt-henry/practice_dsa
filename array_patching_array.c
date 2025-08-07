/*
Problem: Patching Array

Given a sorted array `nums` of positive integers and a target `n`,
find the minimum number of patches (extra numbers) to add to `nums`
so that every number in the range [1, n] inclusive can be formed by
summing elements from the array.

Example 1:
nums = [1, 3], n = 6
Output: 1
Explanation: We can form 1, 3, 4. Adding patch 2 allows forming 1–6.

Example 2:
nums = [1, 5, 10], n = 20
Output: 2
Possible patches: 2 and 4.

Example 3:
nums = [1, 2, 2], n = 5
Output: 0
*/

#include <stdio.h>
#include <stdlib.h>

int minPatches(int* nums, int numsSize, int n) {
    long miss = 1;
    int patches = 0, i = 0;

    while (miss <= n) {
        if (i < numsSize && nums[i] <= miss) {
            miss += nums[i++];
        } else {
            miss += miss;
            patches++;
        }
    }

    return patches;
}

int main() {
    int nums1[] = {1, 3};
    printf("Patches needed (nums=[1,3], n=6): %d\n", minPatches(nums1, 2, 6)); // Expected: 1

    int nums2[] = {1, 5, 10};
    printf("Patches needed (nums=[1,5,10], n=20): %d\n", minPatches(nums2, 3, 20)); // Expected: 2

    int nums3[] = {1, 2, 2};
    printf("Patches needed (nums=[1,2,2], n=5): %d\n", minPatches(nums3, 3, 5)); // Expected: 0

    return 0;
}
