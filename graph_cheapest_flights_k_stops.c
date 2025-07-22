// Problem: Cheapest Flights Within K Stops
// Find the cheapest price from src to dst with at most k stops
//
// Input:
// n = 4
// flights = [[0,1,100],[1,2,100],[2,3,100],[0,3,500]]
// src = 0, dst = 3, k = 1
// Output: 500

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int findCheapestPrice(int n, int** flights, int flightsSize, int* flightsColSize,
                      int src, int dst, int k) {
    int* prices = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) prices[i] = INT_MAX;
    prices[src] = 0;

    for (int i = 0; i <= k; i++) {
        int* temp = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) temp[j] = prices[j];

        for (int j = 0; j < flightsSize; j++) {
            int u = flights[j][0], v = flights[j][1], w = flights[j][2];
            if (prices[u] != INT_MAX && prices[u] + w < temp[v]) {
                temp[v] = prices[u] + w;
            }
        }

        free(prices);
        prices = temp;
    }

    int ans = prices[dst] == INT_MAX ? -1 : prices[dst];
    free(prices);
    return ans;
}

int main() {
    int n = 4;
    int f1[] = {0, 1, 100};
    int f2[] = {1, 2, 100};
    int f3[] = {2, 3, 100};
    int f4[] = {0, 3, 500};
    int* flights[] = {f1, f2, f3, f4};
    int flightsColSize[] = {3, 3, 3, 3};
    int flightsSize = 4;

    int src = 0, dst = 3, k = 1;
    int result = findCheapestPrice(n, flights, flightsSize, flightsColSize, src, dst, k);
    printf("Cheapest Price: %d\n", result);  // Output: 500

    return 0;
}
