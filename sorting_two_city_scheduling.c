/*
Problem:
There are 2N people. You must send N to city A and N to city B.
Minimize the total cost of sending everyone.

Approach:
- Sort by cost difference between city A and B.
- Send first N to city A, last N to city B.

Time: O(n log n) due to sorting
Space: O(1)
*/

#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    int* costA = *(int**)a;
    int* costB = *(int**)b;
    return (costA[0] - costA[1]) - (costB[0] - costB[1]);
}

int twoCitySchedCost(int** costs, int costsSize, int* costsColSize) {
    qsort(costs, costsSize, sizeof(int*), cmp);
    int total = 0;
    for (int i = 0; i < costsSize / 2; i++) {
        total += costs[i][0];
    }
    for (int i = costsSize / 2; i < costsSize; i++) {
        total += costs[i][1];
    }
    return total;
}

// Test
int main() {
    int raw[][2] = {{10, 20}, {30, 200}, {50, 50}, {30, 20}};
    int* costs[4];
    for (int i = 0; i < 4; i++) costs[i] = raw[i];
    int costsColSize[4] = {2, 2, 2, 2};

    int result = twoCitySchedCost(costs, 4, costsColSize);
    printf("Minimum Total Cost: %d\n", result);  // Expected: 110

    return 0;
}

/*
========= OUTPUT =========
Minimum Total Cost: 110
==========================
*/
