/*
Problem: Random Pick with Blacklist

Design a data structure that allows picking random numbers from the range [0, n),
excluding the numbers in a given blacklist.

Approach:
- Let M = n - blacklistSize.
- Pick a number x in [0, M).
- If x is blacklisted, map it to a non-blacklisted value in [M, n).
- Use binary search to detect blacklist entries.

Time: O(blacklistSize + 1) setup, O(1) pick
Space: O(blacklistSize)
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int M;
    int* mapping;
    int mapSize;
} Solution;

int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

// Binary search to check if value is blacklisted
int isInList(int* arr, int size, int target) {
    int l = 0, r = size - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (arr[mid] == target) return 1;
        if (arr[mid] < target) l = mid + 1;
        else r = mid - 1;
    }
    return 0;
}

Solution* solutionCreate(int n, int* blacklist, int blacklistSize) {
    Solution* obj = (Solution*)malloc(sizeof(Solution));
    obj->M = n - blacklistSize;
    obj->mapping = (int*)calloc(n, sizeof(int));  // use calloc to track 0 vs not mapped
    obj->mapSize = obj->M;

    qsort(blacklist, blacklistSize, sizeof(int), cmp);

    int last = n - 1;

    for (int i = 0; i < blacklistSize; i++) {
        if (blacklist[i] < obj->M) {
            while (isInList(blacklist, blacklistSize, last)) last--;
            obj->mapping[blacklist[i]] = last;
            last--;
        }
    }

    srand(time(NULL));
    return obj;
}

int solutionPick(Solution* obj) {
    int x = rand() % obj->M;
    if (obj->mapping[x] != 0 || x == 0)  // account for 0 possibly being mapped
        return obj->mapping[x];
    return x;
}

void solutionFree(Solution* obj) {
    free(obj->mapping);
    free(obj);
}

// Test
int main() {
    int blacklist[] = {2, 3, 5};
    int n = 7;
    int size = sizeof(blacklist) / sizeof(blacklist[0]);

    Solution* obj = solutionCreate(n, blacklist, size);

    printf("Random picks excluding blacklist {2, 3, 5} from [0, 7):\n");
    for (int i = 0; i < 10; i++) {
        int val = solutionPick(obj);
        printf("%d ", val);
    }
    printf("\n");

    solutionFree(obj);
    return 0;
}

/*
========= OUTPUT (sample) =========
Random picks excluding blacklist {2, 3, 5} from [0, 7):
4 6 1 4 6 0 0 1 6 4
==================================
(Note: Output varies due to randomness)
*/
