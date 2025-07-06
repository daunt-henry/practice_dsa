/*
Problem:
Given a mapping of digits and a list of numbers, sort the numbers based on their mapped values.

Input:
mapping = [2,1,4,8,6,3,0,9,7,5]
nums = [990, 332, 981]

Output:
[981, 990, 332]

Explanation:
Mapped values: 
990 -> 555, 
332 -> 838, 
981 -> 437
Sorted by mapped: [437 (981), 555 (990), 838 (332)]
*/

#include <stdio.h>
#include <stdlib.h>

int mapDigit(int digit, int* mapping) {
    return mapping[digit];
}

int getMappedValue(int num, int* mapping) {
    if (num == 0) return mapping[0];

    int digits[10], count = 0;
    while (num > 0) {
        digits[count++] = num % 10;
        num /= 10;
    }

    int result = 0;
    for (int i = count - 1; i >= 0; i--) {
        result = result * 10 + mapping[digits[i]];
    }
    return result;
}

typedef struct {
    int original;
    int mapped;
} NumPair;

int cmp(const void* a, const void* b) {
    NumPair* x = (NumPair*)a;
    NumPair* y = (NumPair*)b;
    return x->mapped - y->mapped;
}

int* sortJumbled(int* mapping, int mappingSize, int* nums, int numsSize, int* returnSize){
    NumPair* pairs = (NumPair*)malloc(sizeof(NumPair) * numsSize);
    for (int i = 0; i < numsSize; i++) {
        pairs[i].original = nums[i];
        pairs[i].mapped = getMappedValue(nums[i], mapping);
    }

    qsort(pairs, numsSize, sizeof(NumPair), cmp);

    int* result = (int*)malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; i++) {
        result[i] = pairs[i].original;
    }

    *returnSize = numsSize;
    free(pairs);
    return result;
}

/*
Test Case:
mapping = [2,1,4,8,6,3,0,9,7,5]
nums = [990,332,981]
Output: [981, 990, 332]
*/
