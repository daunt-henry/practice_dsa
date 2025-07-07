/*
Problem:
You are given a list of transactions, each with:
- cost[i]: amount you need to pay
- cashback[i]: amount you receive back

You can do the transactions in any order. Each time, you must have at least `cost[i]` coins 
before starting the i-th transaction.

Find the **minimum** amount of money you must start with so that after all transactions,
you **never go negative**.

Example Input:
transactions = [[2,1],[5,0],[4,2]]

Expected Output:
10

Explanation:
You lose money in 2 transactions: [2,1] and [5,0]. Total loss: (2-1) + (5-0) = 6
But you must also ensure the max required upfront cash is available, so simulate worst case:
Max(maxNeed) = max(totalLoss + cashback, for each transaction)
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef long long ll;

long long minimumMoney(int** transactions, int transactionsSize, int* transactionsColSize) {
    ll maxNeed = 0, totalLoss = 0;

    for (int i = 0; i < transactionsSize; ++i) {
        int cost = transactions[i][0], cashback = transactions[i][1];
        if (cashback < cost)
            totalLoss += (ll)(cost - cashback);
    }

    for (int i = 0; i < transactionsSize; ++i) {
        int cost = transactions[i][0], cashback = transactions[i][1];
        if (cashback < cost)
            maxNeed = fmax(maxNeed, totalLoss + cashback);
        else
            maxNeed = fmax(maxNeed, totalLoss + cost);
    }

    return maxNeed;
}

int main() {
    int t0[] = {2, 1};
    int t1[] = {5, 0};
    int t2[] = {4, 2};
    int* transactions[] = {t0, t1, t2};
    int colSize[] = {2, 2, 2};

    long long result = minimumMoney(transactions, 3, colSize);
    printf("Minimum money required: %lld\n", result);

    return 0;
}
