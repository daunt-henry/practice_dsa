/*
Problem: Maximum Gap

Description:
Given an unsorted array, find the maximum difference between the successive elements in its sorted form.
Return 0 if the array contains less than 2 elements.
Must solve in linear time and space (use bucket sort).

Example:
Input: [3, 6, 9, 1]
Output: 3
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int maximumGap(int* nums, int numsSize) {
    if (numsSize < 2) return 0;

    int minVal = INT_MAX, maxVal = INT_MIN;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] < minVal) minVal = nums[i];
        if (nums[i] > maxVal) maxVal = nums[i];
    }

    if (minVal == maxVal) return 0;

    int bucketSize = (maxVal - minVal) / (numsSize - 1);
    if (bucketSize == 0) bucketSize = 1;

    int bucketCount = (maxVal - minVal) / bucketSize + 1;

    int* bucketMin = malloc(sizeof(int) * bucketCount);
    int* bucketMax = malloc(sizeof(int) * bucketCount);

    for (int i = 0; i < bucketCount; i++) {
        bucketMin[i] = INT_MAX;
        bucketMax[i] = INT_MIN;
    }

    for (int i = 0; i < numsSize; i++) {
        int idx = (nums[i] - minVal) / bucketSize;
        if (nums[i] < bucketMin[idx]) bucketMin[idx] = nums[i];
        if (nums[i] > bucketMax[idx]) bucketMax[idx] = nums[i];
    }

    int maxGap = 0, prevMax = minVal;
    for (int i = 0; i < bucketCount; i++) {
        if (bucketMin[i] == INT_MAX) continue;
        if (bucketMin[i] - prevMax > maxGap)
            maxGap = bucketMin[i] - prevMax;
        prevMax = bucketMax[i];
    }

    free(bucketMin);
    free(bucketMax);
    return maxGap;
}

int main() {
    int nums[] = {3, 6, 9, 1};
    int size = sizeof(nums) / sizeof(nums[0]);
    int result = maximumGap(nums, size);
    printf("Maximum gap: %d\n", result);
    return 0;
}

/*
========= OUTPUT =========
Maximum gap: 3
==========================
*/
