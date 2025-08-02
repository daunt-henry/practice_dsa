/*
Problem: Best Time to Buy and Sell Stock IV

You are given an integer k and an array prices[] of length n.
You are allowed to complete at most k transactions (a buy followed by a sell).
Return the maximum profit you can achieve.

Example:
Input: k = 2, prices = [2,4,1]
Output: 2

Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7

Explanation:
- Buy at 2, sell at 4 — profit = 2
- Buy at 0, sell at 3 — profit = 3
- Buy at 2, sell at 6 — profit = 4
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int maxProfit(int k, int* prices, int pricesSize){
    if (pricesSize == 0 || k == 0) return 0;
    
    if (k >= pricesSize / 2) {
        int maxProfit = 0;
        for (int i = 1; i < pricesSize; ++i) {
            if (prices[i] > prices[i - 1])
                maxProfit += prices[i] - prices[i - 1];
        }
        return maxProfit;
    }

    int** dp = (int**)malloc((k + 1) * sizeof(int*));
    for (int i = 0; i <= k; ++i)
        dp[i] = (int*)calloc(pricesSize, sizeof(int));
    
    for (int t = 1; t <= k; ++t) {
        int maxDiff = -prices[0];
        for (int d = 1; d < pricesSize; ++d) {
            dp[t][d] = fmax(dp[t][d - 1], prices[d] + maxDiff);
            maxDiff = fmax(maxDiff, dp[t - 1][d] - prices[d]);
        }
    }

    int result = dp[k][pricesSize - 1];
    for (int i = 0; i <= k; ++i)
        free(dp[i]);
    free(dp);
    return result;
}

// Sample test
int main() {
    int prices[] = {3, 2, 6, 5, 0, 3};
    int k = 2;
    int n = sizeof(prices)/sizeof(prices[0]);
    int profit = maxProfit(k, prices, n);
    printf("Max profit with %d transactions: %d\n", k, profit);  // Output: 7
    return 0;
}
