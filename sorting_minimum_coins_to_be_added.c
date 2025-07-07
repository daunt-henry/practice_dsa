/*
Problem:
You are given an array of positive integers `coins` and an integer `target`.
You can add new coins of any value to the array.
Return the **minimum number of coins** that need to be added so that
all amounts from 1 to `target` (inclusive) can be formed using the coins.

Example Input:
coins = [1, 3]
target = 6

Expected Output:
1  (add coin = 2 to be able to form all values 1 to 6)
*/

#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return (*(int*)a) - (*(int*)b);
}

int minimumAddedCoins(int* coins, int coinsSize, int target) {
    qsort(coins, coinsSize, sizeof(int), cmp);

    long long curr = 1;
    int i = 0, added = 0;

    while (curr <= target) {
        if (i < coinsSize && coins[i] <= curr) {
            curr += coins[i++];
        } else {
            curr += curr;
            added++;
        }
    }

    return added;
}

int main() {
    int coins[] = {1, 3};
    int target = 6;
    int size = sizeof(coins) / sizeof(coins[0]);

    int result = minimumAddedCoins(coins, size, target);
    printf("Minimum coins to be added: %d\n", result);

    return 0;
}
