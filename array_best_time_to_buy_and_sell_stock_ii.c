/*
Problem: Best Time to Buy and Sell Stock II

You are given an integer array prices where prices[i] is the price of a given stock on the i-th day.
On each day, you may decide to buy and/or sell the stock. You can only hold at most one share at a time.

Return the maximum profit you can achieve.

Example:
Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1), sell on day 3 (price = 5), profit = 4.
Then buy on day 4 (price = 3), sell on day 5 (price = 6), profit = 3.
Total profit = 4 + 3 = 7.
*/

#include <stdio.h>

int maxProfit(int* prices, int pricesSize) {
    int profit = 0;
    for (int i = 1; i < pricesSize; i++) {
        if (prices[i] > prices[i - 1])
            profit += prices[i] - prices[i - 1];
    }
    return profit;
}

// Test Driver
int main() {
    int prices[] = {7, 1, 5, 3, 6, 4};
    int n = sizeof(prices) / sizeof(prices[0]);
    int result = maxProfit(prices, n);
    printf("Max Profit: %d\n", result);  // Output: 7
    return 0;
}
