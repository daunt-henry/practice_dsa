#include <stdio.h>
#include <limits.h>

// Question:
// You are given an array 'prices' of chocolate prices and an integer 'money'.
// You must buy exactly two different chocolates.
// Return the money left after buying the two cheapest ones.
// If you can't afford them, return the original amount of money.

// Output:
// Example: prices = [1,2,2], money = 3
// Output: 0

int buyChoco(int* prices, int pricesSize, int money){
    int min1 = INT_MAX, min2 = INT_MAX;
    for (int i = 0; i < pricesSize; ++i) {
        if (prices[i] < min1) {
            min2 = min1;
            min1 = prices[i];
        } else if (prices[i] < min2) {
            min2 = prices[i];
        }
    }

    int total = min1 + min2;
    return (total <= money) ? (money - total) : money;
}

// ---------- Main Test ----------
int main() {
    int prices[] = {1, 2, 2};
    int money = 3;
    int n = sizeof(prices) / sizeof(prices[0]);

    int result = buyChoco(prices, n, money);
    printf("%d\n", result); // Output: 0

    return 0;
}
