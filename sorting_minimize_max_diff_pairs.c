#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Question:
// You are given an array nums and an integer p. 
// Form p pairs such that the maximum absolute difference among these pairs is minimized.
// Return the minimum possible value of that maximum absolute difference.

// Output:
// For nums = [1, 3, 6, 19, 20], p = 2
// Output: 2

int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

bool isValid(int* nums, int numsSize, int p, int mid) {
    int count = 0;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] - nums[i - 1] <= mid) {
            count++;
            i++; // skip the next one in the pair
        }
    }
    return count >= p;
}

int minimizeMax(int* nums, int numsSize, int p) {
    qsort(nums, numsSize, sizeof(int), cmp);
    
    int low = 0, high = nums[numsSize - 1] - nums[0], ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (isValid(nums, numsSize, p, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
}

// ---------- Main Test ----------
int main() {
    int nums[] = {1, 3, 6, 19, 20};
    int p = 2;
    int n = sizeof(nums) / sizeof(nums[0]);

    int result = minimizeMax(nums, n, p);
    printf("%d\n", result); // Output: 2

    return 0;
}
