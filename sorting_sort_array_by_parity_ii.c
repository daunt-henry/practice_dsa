/*
Problem:
Rearrange an array such that:
- Even-indexed positions contain even numbers
- Odd-indexed positions contain odd numbers

Assumption:
- Array has equal number of even and odd integers.

Approach:
- Use two pointers: one for even indices, one for odd.
- Traverse the array and place values accordingly.

Time: O(n)
Space: O(n)
*/

#include <stdio.h>
#include <stdlib.h>

int* sortArrayByParityII(int* nums, int numsSize, int* returnSize) {
    int* res = malloc(sizeof(int) * numsSize);
    int even = 0, odd = 1;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] % 2 == 0) {
            res[even] = nums[i];
            even += 2;
        } else {
            res[odd] = nums[i];
            odd += 2;
        }
    }

    *returnSize = numsSize;
    return res;
}

// Test
int main() {
    int nums[] = {4, 2, 5, 7};
    int size = sizeof(nums) / sizeof(nums[0]);
    int returnSize;

    int* result = sortArrayByParityII(nums, size, &returnSize);

    printf("Output: [");
    for (int i = 0; i < returnSize; i++) {
        printf("%d", result[i]);
        if (i < returnSize - 1) printf(", ");
    }
    printf("]\n");

    free(result);
    return 0;
}

/*
========= OUTPUT =========
Output: [4, 5, 2, 7]
(Note: multiple valid outputs possible)
==========================
*/
