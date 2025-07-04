/*
Sell Diminishing-Valued Colored Balls

Problem:
You have an inventory of colored balls, each color has a certain quantity.
Each time you sell a ball of color with x quantity, you earn x coins and the quantity becomes x-1.
Return the maximum number of coins you can earn after selling `orders` balls.

Approach:
- Sort inventory in descending order
- Sell from the highest valued colors first
- Use arithmetic sum formula to efficiently calculate profit
- Apply modulo 1e9+7 as required

Time Complexity: O(n log n)
Space Complexity: O(1)

Example:
Input: inventory = [2,5], orders = 4
Output: 14 (Sell: 5,4,3,2)

*/

#include <stdlib.h>

#define MOD 1000000007

int cmp(const void* a, const void* b) {
    return (*(int*)b) - (*(int*)a); // Descending
}

long long sumRange(long long high, long long low) {
    return (high - low + 1) * (high + low) / 2;
}

int maxProfit(int* inventory, int inventorySize, int orders) {
    qsort(inventory, inventorySize, sizeof(int), cmp);

    int i = 0;
    long long profit = 0;

    while (orders > 0) {
        int current = inventory[i];
        int next = (i + 1 < inventorySize) ? inventory[i + 1] : 0;
        int count = i + 1;

        long long sellCount = (long long)(current - next) * count;

        if (orders >= sellCount) {
            profit += sumRange(current, next + 1) * count;
            orders -= sellCount;
        } else {
            int fullRows = orders / count;
            int remainder = orders % count;
            int low = current - fullRows + 1;
            profit += sumRange(current, low) * count;
            profit += (long long)(low - 1) * remainder;
            orders = 0;
        }

        profit %= MOD;
        i++;
    }

    return (int)profit;
}
