/*
Problem: Gas Station

There are n gas stations along a circular route. You have two integer arrays gas and cost,
where gas[i] is the amount of gas at the ith station, and cost[i] is the cost of traveling
from the ith station to its next.

Return the starting gas station index if you can travel around the circuit once in the clockwise direction,
otherwise return -1. If there exists a solution, it is guaranteed to be unique.

Example:
Input: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
Output: 3

Input: gas = [2,3,4], cost = [3,4,3]
Output: -1
*/

#include <stdio.h>

int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize) {
    int totalGas = 0, totalCost = 0, tank = 0, start = 0;
    for (int i = 0; i < gasSize; i++) {
        totalGas += gas[i];
        totalCost += cost[i];
        tank += gas[i] - cost[i];
        if (tank < 0) {
            start = i + 1;
            tank = 0;
        }
    }
    return totalGas < totalCost ? -1 : start;
}

int main() {
    int gas[] = {1, 2, 3, 4, 5};
    int cost[] = {3, 4, 5, 1, 2};
    int n = sizeof(gas) / sizeof(gas[0]);

    int result = canCompleteCircuit(gas, n, cost, n);
    printf("Starting Station Index: %d\n", result);  // Output: 3

    return 0;
}
