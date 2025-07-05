/*
Problem: Minimize Maximum Pair Sum in Array

Given an array of even length `nums`, pair up the elements such that the maximum pair sum is minimized.
Return the minimized value of the maximum pair sum.

Example:
Input:  nums = [3,5,2,3]
Output: 7
Explanation: Pair (2,5) and (3,3). Max sum is 7.
*/

#include <stdio.h>
#include <stdlib.h>

// Compare function for qsort
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int minPairSum(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), compare);
    
    int maxSum = 0;
    for (int i = 0; i < numsSize / 2; i++) {
        int pairSum = nums[i] + nums[numsSize - 1 - i];
        if (pairSum > maxSum)
            maxSum = pairSum;
    }
    
    return maxSum;
}

// Sample usage
/*
int main() {
    int nums[] = {3, 5, 2, 3};
    int size = sizeof(nums) / sizeof(nums[0]);
    printf("Minimized Max Pair Sum: %d\n", minPairSum(nums, size));
    return 0;
}
*/
