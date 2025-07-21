/*
Title: Sum of Subarray Ranges

Description:
  You are given an integer array nums. The range of a subarray of nums is the difference 
  between the largest and smallest element in the subarray.
  
  Return the sum of all subarray ranges of nums.

Example:
  Input: nums = [1,2,3]
  Output: 4
  Explanation:
    - Range of [1,2] is 1
    - Range of [2,3] is 1
    - Range of [1,2,3] is 2
    Total = 1 + 1 + 2 = 4

Constraints:
  - 1 <= nums.length <= 1000
  - -10^9 <= nums[i] <= 10^9
*/

#include <stdio.h>

long long subArrayRanges(int* nums, int numsSize) {
    long long res = 0;

    for (int i = 0; i < numsSize; ++i) {
        int minVal = nums[i], maxVal = nums[i];
        for (int j = i + 1; j < numsSize; ++j) {
            if (nums[j] < minVal) minVal = nums[j];
            if (nums[j] > maxVal) maxVal = nums[j];
            res += (maxVal - minVal);
        }
    }
    return res;
}

int main() {
    int nums[] = {1, 2, 3};
    int size = sizeof(nums) / sizeof(nums[0]);
    long long result = subArrayRanges(nums, size);
    printf("Output: %lld\n", result); // Output: 4
    return 0;
}
