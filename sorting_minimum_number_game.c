/*
Problem:
You are given an even-length array `nums`. In a game, Alice and Bob take turns
removing the smallest two numbers from the array. Alice picks first and takes
the smaller one, Bob takes the next.

Return the resulting array of numbers after pairing them such that Alice's pick comes first,
then Bob's pick, repeatedly. Essentially, output the rearranged array where each pair is swapped.

Example Input:
nums = [5, 4, 2, 3]

Expected Output:
[3, 2, 5, 4]
(Original sorted: [2, 3, 4, 5], paired as (2,3) → (3,2), (4,5) → (5,4))
*/

#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return (*(int*)a) - (*(int*)b);
}

int* numberGame(int* nums, int numsSize, int* returnSize) {
    qsort(nums, numsSize, sizeof(int), cmp);

    int* res = (int*)malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; i += 2) {
        res[i] = nums[i + 1];
        res[i + 1] = nums[i];
    }

    *returnSize = numsSize;
    return res;
}

int main() {
    int nums[] = {5, 4, 2, 3};
    int size = sizeof(nums) / sizeof(nums[0]);
    int returnSize;

    int* result = numberGame(nums, size, &returnSize);

    printf("Rearranged array: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);
    return 0;
}
