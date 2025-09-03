/*
Problem: Partition to K Equal Sum Subsets (LeetCode 698)
URL: https://leetcode.com/problems/partition-to-k-equal-sum-subsets/

Given an integer array `nums` and integer `k`, determine if it's possible to divide
the array into `k` disjoint non-empty subsets whose sums are all equal.

Approach:
1. Calculate total sum; if not divisible by `k`, return false immediately.
2. Each subset must sum to `target = totalSum / k`.
3. Sort `nums` in descending order to help prune branches early.
4. Use backtracking to try building subsets:
   - Maintain an array `used[]` to track which elements are assigned.
   - Try filling one bucket (subset) at a time until it reaches target.
   - Once a bucket matches the target, recurse to fill next bucket starting from index 0.
5. Return true if all `k` buckets can be filled successfully.

Time: Approx O(k^n) with pruning optimizations  
Space: O(n) for `used[]` and recursion stack
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool dfs(int* nums, int numsSize, int k, int target, int currSum, int start, int* used) {
    if (k == 1) return true;
    if (currSum == target) {
        return dfs(nums, numsSize, k - 1, target, 0, 0, used);
    }
    for (int i = start; i < numsSize; i++) {
        if (!used[i] && currSum + nums[i] <= target) {
            used[i] = 1;
            if (dfs(nums, numsSize, k, target, currSum + nums[i], i + 1, used)) {
                return true;
            }
            used[i] = 0;
        }
    }
    return false;
}

bool canPartitionKSubsets(int* nums, int numsSize, int k) {
    if (k <= 0 || numsSize < k) return false;
    int sum = 0;
    for (int i = 0; i < numsSize; i++) sum += nums[i];
    if (sum % k != 0) return false;
    int target = sum / k;

    // sort descending
    for (int i = 0; i < numsSize - 1; i++)
        for (int j = i + 1; j < numsSize; j++)
            if (nums[j] > nums[i]) {
                int tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
            }

    int* used = calloc(numsSize, sizeof(int));
    bool res = dfs(nums, numsSize, k, target, 0, 0, used);
    free(used);
    return res;
}

int main(void) {
    int arr1[] = {4, 3, 2, 3, 5, 2, 1};
    int k1 = 4;
    printf("[4,3,2,3,5,2,1], k=4 -> %s (expected: true)\n",
           canPartitionKSubsets(arr1, 7, k1) ? "true" : "false");

    int arr2[] = {1, 2, 3, 4};
    int k2 = 3;
    printf("[1,2,3,4], k=3 -> %s (expected: false)\n",
           canPartitionKSubsets(arr2, 4, k2) ? "true" : "false");

    return 0;
}
