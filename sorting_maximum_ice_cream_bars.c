/*
Problem: Maximum Ice Cream Bars

Description:
You are given an array `costs` where costs[i] is the cost of the i-th ice cream bar.
You have `coins` coins. You can buy the ice cream bars in any order.

Return the maximum number of ice cream bars you can buy with your coins.

Example:
Input: costs = [1,3,2,4,1], coins = 7
Output: 4
Explanation: The costs of ice creams are [1,1,2,3,4]. You can buy 1+1+2+3 = 7.

Approach:
- Sort the array of costs.
- Keep subtracting from `coins` until you can't afford the next item.

Time Complexity: O(n log n) for sorting
Space Complexity: O(1) extra (in-place sort)
*/

#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int maxIceCream(int* costs, int costsSize, int coins) {
    qsort(costs, costsSize, sizeof(int), cmp);
    int count = 0;
    for (int i = 0; i < costsSize && coins >= costs[i]; i++) {
        coins -= costs[i];
        count++;
    }
    return count;
}

// Example usage
/*
int main() {
    int costs[] = {1, 3, 2, 4, 1};
    int coins = 7;
    int size = sizeof(costs)/sizeof(costs[0]);
    printf("Max Ice Creams: %d\n", maxIceCream(costs, size, coins)); // Output: 4
    return 0;
}
*/
