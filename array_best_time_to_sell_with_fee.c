/*
Problem: Best Time to Buy and Sell Stock with Transaction Fee (LeetCode 714)
URL: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

You have an array of stock prices `prices[]` and a transaction fee `fee`. You can perform
as many buy/sell operations as you like, but each time you sell, you must pay the fee.
Compute the maximum profit possible.

Approach: Dynamic Programming with Rolling States
- Maintain two variables:
  - `cash`: max profit when not holding any stock
  - `hold`: max profit when holding a stock
- On each day:
  - Update `cash` by considering selling the stock held (minus fee)
  - Update `hold` by considering buying stock with current cash
- `cash` at the end is the maximum profit without holding any stock

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <stdio.h>

int maxProfit(int* prices, int pricesSize, int fee) {
    if (pricesSize == 0) return 0;
    int cash = 0;
    int hold = -prices[0];

    for (int i = 1; i < pricesSize; i++) {
        int prevCash = cash;
        cash = (hold + prices[i] - fee) > cash ? (hold + prices[i] - fee) : cash;
        hold = (prevCash - prices[i]) > hold ? (prevCash - prices[i]) : hold;
    }
    return cash;
}

int main(void) {
    int prices1[] = {1, 3, 2, 8, 4, 9};
    int n1 = sizeof(prices1) / sizeof(prices1[0]);
    int fee1 = 2;
    printf("Example 1: maxProfit = %d (expected 8)\n", maxProfit(prices1, n1, fee1));

    int prices2[] = {1, 3, 7, 5, 10, 3};
    int n2 = sizeof(prices2) / sizeof(prices2[0]);
    int fee2 = 3;
    printf("Example 2: maxProfit = %d (expected 6)\n", maxProfit(prices2, n2, fee2));

    return 0;
}
