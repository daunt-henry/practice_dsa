/*
Problem: Top K Frequent Elements

Description:
Given an integer array nums and an integer k,
return the k most frequent elements.

Approach:
1. Count frequency manually using a struct.
2. Sort by frequency.
3. Return top-k values.

Time: O(n^2) due to nested loop (can be optimized with hashmap in other languages)
*/

#include <stdio.h>
#include <stdlib.h>

// Frequency pair
typedef struct {
    int num;
    int freq;
} Pair;

// Sort descending by frequency
int cmp(const void* a, const void* b) {
    return ((Pair*)b)->freq - ((Pair*)a)->freq;
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    Pair map[numsSize];
    int mapSize = 0;

    for (int i = 0; i < numsSize; i++) {
        int found = 0;
        for (int j = 0; j < mapSize; j++) {
            if (map[j].num == nums[i]) {
                map[j].freq++;
                found = 1;
                break;
            }
        }
        if (!found) {
            map[mapSize].num = nums[i];
            map[mapSize].freq = 1;
            mapSize++;
        }
    }

    qsort(map, mapSize, sizeof(Pair), cmp);

    int* result = malloc(sizeof(int) * k);
    for (int i = 0; i < k; i++) {
        result[i] = map[i].num;
    }

    *returnSize = k;
    return result;
}

// Test
int main() {
    int nums[] = {1, 1, 1, 2, 2, 3};
    int size = sizeof(nums) / sizeof(nums[0]);
    int k = 2, returnSize = 0;

    int* result = topKFrequent(nums, size, k, &returnSize);

    printf("Top %d Frequent Elements: ", k);
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);
    return 0;
}

/*
========= OUTPUT =========
Top 2 Frequent Elements: 1 2
==========================
*/
