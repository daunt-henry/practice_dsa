/*
Problem:
A salesman can take multiple offers, where each offer has a start house, end house, and a profit.
He can't take overlapping offers (an offer's range overlaps with another).
Return the maximum profit he can earn by choosing non-overlapping offers.

Each offer is represented as [start, end, profit].

Example Input:
n = 5
offers = [[0, 2, 10], [1, 3, 20], [2, 4, 15]]

Expected Output:
Maximum Profit: 25
*/

#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
    int* x = *(int**)a;
    int* y = *(int**)b;
    return x[1] - y[1];
}

int binarySearch(int** offers, int r, int x) {
    int l = 0, res = -1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (offers[m][1] < x) {
            res = m;
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return res;
}

int maximizeTheProfit(int n, int** offers, int offersSize, int* offersColSize) {
    qsort(offers, offersSize, sizeof(int*), cmp);
    int dp[offersSize + 1];
    dp[0] = 0;

    for (int i = 0; i < offersSize; ++i) {
        int prev = binarySearch(offers, i - 1, offers[i][0]);
        int profit = offers[i][2] + (prev >= 0 ? dp[prev + 1] : 0);
        dp[i + 1] = dp[i] > profit ? dp[i] : profit;
    }

    return dp[offersSize];
}

int main() {
    int rawOffers[3][3] = {
        {0, 2, 10},
        {1, 3, 20},
        {2, 4, 15}
    };
    int* offers[3];
    int offersColSize[3] = {3, 3, 3};
    for (int i = 0; i < 3; ++i) {
        offers[i] = rawOffers[i];
    }

    int n = 5;
    int result = maximizeTheProfit(n, offers, 3, offersColSize);
    printf("Maximum Profit: %d\n", result);

    return 0;
}
