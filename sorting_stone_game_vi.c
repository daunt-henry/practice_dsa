/*
Stone Game VI

Problem:
Alice and Bob take turns picking stones. Each stone has a value for Alice and Bob.
They pick stones to maximize their score. Return:
- 1 if Alice wins,
- -1 if Bob wins,
- 0 if tie.

Approach:
- Create a combined array of [aliceVal, bobVal]
- Sort by (aliceVal + bobVal) descending
- Alice picks at even indices, Bob at odd
- Compare final scores

Time Complexity: O(n log n)
Space Complexity: O(n)

Example:
Input: alice = [1,3], bob = [2,1]
Output: 1
Explanation: Alice picks stone 1 (3), Bob picks stone 0 (2) → 3 > 2 → Alice wins
*/

#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    int* p1 = *(int**)a;
    int* p2 = *(int**)b;
    return (p2[0] + p2[1]) - (p1[0] + p1[1]);
}

int stoneGameVI(int* aliceValues, int aliceValuesSize, int* bobValues, int bobValuesSize) {
    int** stones = malloc(sizeof(int*) * aliceValuesSize);
    for (int i = 0; i < aliceValuesSize; ++i) {
        stones[i] = malloc(sizeof(int) * 2);
        stones[i][0] = aliceValues[i];
        stones[i][1] = bobValues[i];
    }

    qsort(stones, aliceValuesSize, sizeof(int*), cmp);

    int aliceScore = 0, bobScore = 0;
    for (int i = 0; i < aliceValuesSize; ++i) {
        if (i % 2 == 0)
            aliceScore += stones[i][0];
        else
            bobScore += stones[i][1];
    }

    for (int i = 0; i < aliceValuesSize; ++i)
        free(stones[i]);
    free(stones);

    return (aliceScore > bobScore) ? 1 : (aliceScore < bobScore) ? -1 : 0;
}
