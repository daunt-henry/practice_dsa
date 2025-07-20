/*
Title: Continuous Subarrays

Description:
You are given a 0-indexed integer array nums.
A subarray of nums is called continuous if:
- Let i and j be the indices of the first and last elements of the subarray, respectively.
Then, for every k in the range [i, j], inclusive, both of the following holds:
    - nums[k] <= nums[i] + 2, and
    - nums[k] >= nums[j] - 2
Return the total number of continuous subarrays.

Example:
Input: nums = [5,4,2,4]
Output: 8

Explanation:
There are 8 continuous subarrays: [5], [4], [2], [4], [5,4], [4,2], [2,4], [4,2,4]

*/

#include <stdio.h>
#include <stdlib.h>

#define MAXN 100005

long long continuousSubarrays(int* nums, int numsSize) {
    int left = 0;
    int maxDeque[MAXN], minDeque[MAXN];
    int maxFront = 0, maxBack = -1, minFront = 0, minBack = -1;
    long long count = 0;

    for (int right = 0; right < numsSize; right++) {
        while (maxBack >= maxFront && nums[right] > maxDeque[maxBack])
            maxBack--;
        maxDeque[++maxBack] = nums[right];

        while (minBack >= minFront && nums[right] < minDeque[minBack])
            minBack--;
        minDeque[++minBack] = nums[right];

        while (maxDeque[maxFront] - minDeque[minFront] > 2) {
            if (maxDeque[maxFront] == nums[left])
                maxFront++;
            if (minDeque[minFront] == nums[left])
                minFront++;
            left++;
        }

        count += right - left + 1;
    }

    return count;
}

int main() {
    int nums[] = {5, 4, 2, 4};
    int n = sizeof(nums) / sizeof(nums[0]);

    long long result = continuousSubarrays(nums, n);
    printf("Output: %lld\n", result); // Expected: 8

    return 0;
}
