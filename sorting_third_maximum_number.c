/*
Problem: Third Maximum Number

Description:
Return the third distinct maximum number in an array.
If it doesn't exist, return the maximum number.

Approach:
- Use three variables to track first, second, and third max.
- Skip duplicates.
- If third doesn't exist, return first.

Time: O(n)
Space: O(1)
*/

#include <stdio.h>
#include <limits.h>

int thirdMax(int* nums, int numsSize) {
    long first = LONG_MIN, second = LONG_MIN, third = LONG_MIN;

    for (int i = 0; i < numsSize; i++) {
        int num = nums[i];
        if (num == first || num == second || num == third) continue;

        if (num > first) {
            third = second;
            second = first;
            first = num;
        } else if (num > second) {
            third = second;
            second = num;
        } else if (num > third) {
            third = num;
        }
    }

    return third == LONG_MIN ? (int)first : (int)third;
}

// Test
int main() {
    int nums1[] = {3, 2, 1};
    int nums2[] = {1, 2};
    int nums3[] = {2, 2, 3, 1};

    printf("Test 1: %d\n", thirdMax(nums1, 3)); // Output: 1
    printf("Test 2: %d\n", thirdMax(nums2, 2)); // Output: 2
    printf("Test 3: %d\n", thirdMax(nums3, 4)); // Output: 1

    return 0;
}

/*
========= OUTPUT =========
Test 1: 1
Test 2: 2
Test 3: 1
==========================
*/
