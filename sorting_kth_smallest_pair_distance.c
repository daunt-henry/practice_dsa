/*
Problem: Find K-th Smallest Pair Distance

Given an array of integers, find the k-th smallest absolute difference between any two elements.

Approach:
- Sort the array
- Use binary search on the answer (distance)
- For each guess, count how many pairs have distance <= guess

Time: O(n log n + n log D) where D is max distance
Space: O(1)
*/

#include <stdio.h>
#include <stdlib.h>

// Sort helper
int compare(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

// Count number of pairs with distance <= mid
int countPairs(int* nums, int numsSize, int mid) {
    int count = 0, left = 0;
    for (int right = 0; right < numsSize; right++) {
        while (nums[right] - nums[left] > mid)
            left++;
        count += right - left;
    }
    return count;
}

// Main function
int smallestDistancePair(int* nums, int numsSize, int k) {
    qsort(nums, numsSize, sizeof(int), compare);
    int low = 0, high = nums[numsSize - 1] - nums[0];

    while (low < high) {
        int mid = (low + high) / 2;
        int count = countPairs(nums, numsSize, mid);
        if (count < k)
            low = mid + 1;
        else
            high = mid;
    }

    return low;
}

// Test
int main() {
    int nums[] = {1, 3, 1};
    int k = 1;
    int result = smallestDistancePair(nums, 3, k);
    printf("K-th smallest pair distance: %d\n", result);
    return 0;
}

/*
========= OUTPUT =========
K-th smallest pair distance: 0
==========================
*/
