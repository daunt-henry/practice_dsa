#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Question:
// A subset of the array nums is beautiful if it does not contain two integers with absolute difference k.
// Return the total number of non-empty beautiful subsets of the array nums.

// Output: 4 (for input nums = [2,4,6], k = 2)

int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int dfs(int* nums, int numsSize, int index, int k, int* count) {
    if (index == numsSize) return 1;

    int take = 0;
    if (nums[index] - k < 0 || count[nums[index] - k] == 0) {
        count[nums[index]]++;
        take = dfs(nums, numsSize, index + 1, k, count);
        count[nums[index]]--;
    }

    int notTake = dfs(nums, numsSize, index + 1, k, count);

    return take + notTake;
}

int beautifulSubsets(int* nums, int numsSize, int k) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int count[1001] = {0};
    return dfs(nums, numsSize, 0, k, count) - 1;
}

// -------- Main Test --------
int main() {
    int nums[] = {2, 4, 6};
    int k = 2;
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int result = beautifulSubsets(nums, numsSize, k);
    printf("%d\n", result); // Output: 4

    return 0;
}
