/*
Problem: Maximum Product Subarray

Given an integer array nums, find a contiguous non-empty subarray within the array 
that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.

Example 1:
Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.

Example 2:
Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.

*/

#include <stdio.h>
#include <math.h>

int maxProduct(int* nums, int numsSize) {
    if (numsSize == 0) return 0;

    int maxProd = nums[0];
    int minProd = nums[0];
    int result = nums[0];

    for (int i = 1; i < numsSize; i++) {
        int tempMax = maxProd;
        maxProd = fmax(fmax(nums[i], nums[i] * maxProd), nums[i] * minProd);
        minProd = fmin(fmin(nums[i], nums[i] * tempMax), nums[i] * minProd);
        result = fmax(result, maxProd);
    }

    return result;
}

// Sample test
int main() {
    int nums[] = {2, 3, -2, 4};
    int size = sizeof(nums) / sizeof(nums[0]);
    int result = maxProduct(nums, size);
    printf("Maximum product subarray: %d\n", result);
    return 0;
}
