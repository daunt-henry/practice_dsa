/*
Problem: Best Time to Buy and Sell Stock

You are given an array 'prices' where prices[i] is the price of a given stock on the i-th day.
You want to maximize your profit by choosing a single day to buy and a different day to sell.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

Example:
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6).
*/

#include <stdio.h>

int maxProfit(int* prices, int pricesSize) {
    int minPrice = prices[0];
    int maxProfit = 0;
    for (int i = 1; i < pricesSize; i++) {
        if (prices[i] < minPrice)
            minPrice = prices[i];
        else if (prices[i] - minPrice > maxProfit)
            maxProfit = prices[i] - minPrice;
    }
    return maxProfit;
}

// Test Driver
int main() {
    int prices[] = {7, 1, 5, 3, 6, 4};
    int pricesSize = sizeof(prices) / sizeof(prices[0]);
    int result = maxProfit(prices, pricesSize);
    printf("Max Profit: %d\n", result);  // Output: 5
    return 0;
}
