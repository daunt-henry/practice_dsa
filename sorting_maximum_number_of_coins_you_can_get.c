/*
Maximum Number of Coins You Can Get

Problem:
- You are given 3n piles of coins.
- You will pick n piles using the following rule:
  - You and your friend pick alternately, and you always pick the second-largest.
- Return the maximum number of coins you can collect.

Approach:
- Sort the array.
- Always pick the second-largest from the remaining 3 each time.
- Start from index n to 3n, picking every second element.

Time: O(n log n)
Space: O(1)

Example:
Input: piles = [2,4,1,2,7,8]
Sorted:        [1,2,2,4,7,8]
Alice picks:        2, 4 (index 2, 4) → total = 6
Output: 9
*/

#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int maxCoins(int* piles, int pilesSize) {
    qsort(piles, pilesSize, sizeof(int), cmp);
    int result = 0;
    int i = pilesSize / 3;

    for (; i < pilesSize; i += 2) {
        result += piles[i];
    }
    return result;
}
