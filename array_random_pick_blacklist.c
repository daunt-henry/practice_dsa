/*
Problem: Random Pick with Blacklist (LeetCode 710)
URL: https://leetcode.com/problems/random-pick-with-blacklist/

Design a system to pick a random integer from [0, n-1] that is not in a given blacklist.
All valid integers should be equally likely. Minimize random generation calls.

Approach:
- Compute validCount = n - blacklistSize.
- Create a remapping from blacklisted indices in [0, validCount) to valid numbers in [validCount, n) not in the blacklist.
- For pick(): generate r in [0, validCount); return mapped value if present, otherwise r.

Time: O(B) preprocessing, O(1) per pick  
Space: O(B), where B = blacklist size
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

typedef struct {
    long long validCount;
    int* mapKeys;
    int* mapValues;
    int mapSize;
} Solution;

static int map_lookup(Solution* obj, int key) {
    for (int i = 0; i < obj->mapSize; i++) {
        if (obj->mapKeys[i] == key) return obj->mapValues[i];
    }
    return key;
}

Solution* solutionCreate(long long n, int* blacklist, int blacklistSize) {
    Solution* sol = malloc(sizeof(Solution));
    sol->validCount = n - blacklistSize;
    sol->mapKeys = malloc(blacklistSize * sizeof(int));
    sol->mapValues = malloc(blacklistSize * sizeof(int));
    sol->mapSize = 0;

    int* bl = malloc(blacklistSize * sizeof(int));
    for (int i = 0; i < blacklistSize; i++) bl[i] = blacklist[i];

    long long ptr = sol->validCount;
    for (int i = 0; i < blacklistSize; i++) {
        int b = blacklist[i];
        if (b < sol->validCount) {
            bool found;
            do {
                found = false;
                for (int j = 0; j < blacklistSize; j++) {
                    if (bl[j] == ptr) {
                        found = true;
                        ptr++;
                        break;
                    }
                }
            } while (found);

            sol->mapKeys[sol->mapSize] = b;
            sol->mapValues[sol->mapSize] = (int)ptr;
            sol->mapSize++;
            ptr++;
        }
    }

    free(bl);
    srand((unsigned)time(NULL));
    return sol;
}

int solutionPick(Solution* obj) {
    long long r = rand() % obj->validCount;
    return map_lookup(obj, (int)r);
}

void solutionFree(Solution* obj) {
    free(obj->mapKeys);
    free(obj->mapValues);
    free(obj);
}

int main(void) {
    long long n = 7;
    int blacklist[] = {2, 3, 5};
    int bsz = sizeof(blacklist) / sizeof(blacklist[0]);

    Solution* sol = solutionCreate(n, blacklist, bsz);

    printf("Random picks (valid: [0,1,4,6]):\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", solutionPick(sol));
    }
    printf("\n");

    solutionFree(sol);
    return 0;
}
