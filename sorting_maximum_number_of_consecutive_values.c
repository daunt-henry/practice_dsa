/*
Problem: Maximum Number of Consecutive Values You Can Make

Description:
You are given an integer array coins of length n representing coins of different denominations.
You can choose any number of coins (including zero). Return the *maximum number of consecutive integer values* starting from 0 that you can make.

That is, you can make every integer x where 0 <= x <= k for the maximum possible k.

Example 1:
Input: coins = [1, 3]
Output: 2
Explanation: We can make 0, 1, and 2. 
- 0 by choosing no coins
- 1 by using [1]
- 2 by using [1, 1] (not allowed here), so only [1] and [3] are available, thus max = 2.

Example 2:
Input: coins = [1, 1, 1, 4]
Output: 8

Example 3:
Input: coins = [1, 4, 10, 3, 1]
Output: 20

Approach:
- Sort the coins.
- Iterate through them and extend the range of possible values we can create.
- If the current coin > maxReach + 1, we can't make the next value, so we stop.

Time Complexity: O(n log n)
Space Complexity: O(1)
*/

#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int getMaximumConsecutive(int* coins, int coinsSize) {
    qsort(coins, coinsSize, sizeof(int), cmp);
    int maxReach = 0;

    for (int i = 0; i < coinsSize; i++) {
        if (coins[i] > maxReach + 1)
            break;
        maxReach += coins[i];
    }

    return maxReach + 1;
}

// Example usage (optional for testing)
/*
int main() {
    int coins[] = {1, 1, 1, 4};
    int size = sizeof(coins) / sizeof(coins[0]);
    int result = getMaximumConsecutive(coins, size);
    printf("Output: %d\n", result); // Output: 8
    return 0;
}
*/
