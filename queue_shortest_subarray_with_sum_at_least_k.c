/*
Title: Shortest Subarray with Sum at Least K

Example:
Input: nums = [2,-1,2], k = 3
Output: 3

Approach:
- Use prefix sums to track cumulative sum efficiently.
- Use a monotonic queue (deque) to find the shortest valid subarray.
*/

#include <stdio.h>

int shortestSubarray(int* nums, int numsSize, int k) {
    long long prefix[numsSize + 1];
    prefix[0] = 0;
    for (int i = 0; i < numsSize; i++) {
        prefix[i + 1] = prefix[i] + nums[i];
    }

    int deque[numsSize + 1];
    int head = 0, tail = 0;
    int res = numsSize + 1;

    for (int i = 0; i <= numsSize; i++) {
        while (tail > head && prefix[i] - prefix[deque[head]] >= k) {
            if (i - deque[head] < res) res = i - deque[head];
            head++;
        }
        while (tail > head && prefix[i] <= prefix[deque[tail - 1]]) {
            tail--;
        }
        deque[tail++] = i;
    }

    return res <= numsSize ? res : -1;
}

int main() {
    int nums[] = {2, -1, 2};
    int k = 3;
    int size = sizeof(nums) / sizeof(nums[0]);
    int result = shortestSubarray(nums, size, k);
    printf("Shortest subarray length: %d\n", result);  // Output: 3
    return 0;
}
