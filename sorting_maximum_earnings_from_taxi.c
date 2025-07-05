/*
Problem:
You are given n and a list of rides [start, end, tip]. 
You have to choose rides such that you don’t take overlapping rides and maximize the earnings.

Earning for a ride = (end - start + tip)

Approach:
- Sort the rides by their ending point.
- Use DP: dp[i] = max earnings until point i.
- For every ride ending at i, check if including it increases the earnings.

Example:
Input: n = 5, rides = [[2,5,4],[1,5,1]]
Output: 7
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
    int tip;
} Ride;

int cmp(const void* a, const void* b) {
    Ride* r1 = (Ride*)a;
    Ride* r2 = (Ride*)b;
    return r1->end - r2->end;
}

long long maxTaxiEarnings(int n, int** rides, int ridesSize, int* ridesColSize) {
    Ride* rideList = (Ride*)malloc(sizeof(Ride) * ridesSize);
    for (int i = 0; i < ridesSize; i++) {
        rideList[i].start = rides[i][0];
        rideList[i].end = rides[i][1];
        rideList[i].tip = rides[i][2];
    }

    qsort(rideList, ridesSize, sizeof(Ride), cmp);

    long long* dp = (long long*)calloc(n + 1, sizeof(long long));
    int idx = 0;

    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1];
        while (idx < ridesSize && rideList[idx].end == i) {
            int s = rideList[idx].start;
            int e = rideList[idx].end;
            int t = rideList[idx].tip;
            dp[i] = fmax(dp[i], dp[s] + (e - s + t));
            idx++;
        }
    }

    long long result = dp[n];
    free(dp);
    free(rideList);
    return result;
}

/*
Sample Input:
n = 5
rides = [[2,5,4],[1,5,1]]
Output: 7
*/
