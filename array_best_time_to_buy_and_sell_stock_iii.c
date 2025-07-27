/*
Problem: Best Time to Buy and Sell Stock III

You are given an array prices where prices[i] is the price of a given stock on the i-th day.
Find the maximum profit you can achieve with at most **two transactions**.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell before you buy again).

Example:
Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation:
Buy on day 4 (price = 0), sell on day 6 (price = 3), profit = 3.
Then buy on day 7 (price = 1), sell on day 8 (price = 4), profit = 3.
Total profit = 3 + 3 = 6.
*/

#include <stdio.h>

int maxProfit(int* prices, int pricesSize) {
    if (pricesSize == 0) return 0;

    int buy1 = -prices[0], sell1 = 0;
    int buy2 = -prices[0], sell2 = 0;

    for (int i = 1; i < pricesSize; i++) {
        buy1 = (buy1 > -prices[i]) ? buy1 : -prices[i];
        sell1 = (sell1 > buy1 + prices[i]) ? sell1 : buy1 + prices[i];
        buy2 = (buy2 > sell1 - prices[i]) ? buy2 : sell1 - prices[i];
        sell2 = (sell2 > buy2 + prices[i]) ? sell2 : buy2 + prices[i];
    }

    return sell2;
}

// Test Driver
int main() {
    int prices[] = {3, 3, 5, 0, 0, 3, 1, 4};
    int n = sizeof(prices) / sizeof(prices[0]);
    int result = maxProfit(prices, n);
    printf("Max Profit with at most two transactions: %d\n", result);  // Output: 6
    return 0;
}
