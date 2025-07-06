#include <stdio.h>
#include <stdlib.h>

// Question:
// Given an array nums, you can permute the array and count how many indices i where permuted[i] > nums[i].
// Return the maximum number of such indices (i.e., maximize the "greatness").

// Output: 4 (example)

int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int maximizeGreatness(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int i = 0, j = 0, count = 0;

    while (j < numsSize) {
        if (nums[j] > nums[i]) {
            count++;
            i++;
        }
        j++;
    }
    return count;
}

// ----------- Main / Test Code -----------
int main() {
    int nums[] = {1, 3, 5, 2, 1, 3};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int result = maximizeGreatness(nums, numsSize);
    printf("%d\n", result); // Output: 4

    return 0;
}
