/*
Problem:
You are given two integer arrays `nums` and `target`, both of the same length.
You can perform operations: increment or decrement any even number by 2,
and any odd number by 2.

Return the minimum number of operations required to make both arrays similar,
where similarity means both arrays have the same frequency of each value (in any order).

Example Input:
nums = [8,12,6]
target = [2,14,10]

Expected Output:
2

Explanation:
Operations:
- 8 → 10 (1 operation)
- 6 → 2 (2 operations)
- 12 → 14 (1 operation)
Total of 4 half-steps → 2 full operations.
*/

#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return (*(int*)a) - (*(int*)b);
}

long long makeSimilar(int* nums, int numsSize, int* target, int targetSize) {
    int* evenNums = malloc(sizeof(int) * numsSize);
    int* oddNums = malloc(sizeof(int) * numsSize);
    int* evenTarget = malloc(sizeof(int) * targetSize);
    int* oddTarget = malloc(sizeof(int) * targetSize);
    int e1 = 0, o1 = 0, e2 = 0, o2 = 0;

    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] % 2 == 0)
            evenNums[e1++] = nums[i];
        else
            oddNums[o1++] = nums[i];

        if (target[i] % 2 == 0)
            evenTarget[e2++] = target[i];
        else
            oddTarget[o2++] = target[i];
    }

    qsort(evenNums, e1, sizeof(int), cmp);
    qsort(oddNums, o1, sizeof(int), cmp);
    qsort(evenTarget, e2, sizeof(int), cmp);
    qsort(oddTarget, o2, sizeof(int), cmp);

    long long res = 0;
    for (int i = 0; i < e1; ++i)
        res += abs(evenNums[i] - evenTarget[i]) / 2;

    for (int i = 0; i < o1; ++i)
        res += abs(oddNums[i] - oddTarget[i]) / 2;

    free(evenNums);
    free(oddNums);
    free(evenTarget);
    free(oddTarget);

    return res / 2;
}

int main() {
    int nums[] = {8, 12, 6};
    int target[] = {2, 14, 10};
    int size = sizeof(nums) / sizeof(nums[0]);

    long long ops = makeSimilar(nums, size, target, size);
    printf("Minimum operations to make arrays similar: %lld\n", ops);

    return 0;
}
