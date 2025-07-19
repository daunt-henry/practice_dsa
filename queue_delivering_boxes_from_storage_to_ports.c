/*
Title: Delivering Boxes from Storage to Ports

Problem:
You have a warehouse and a truck. There are `n` boxes represented by a 2D array `boxes`, 
where boxes[i] = [port, weight]. You must deliver boxes in order, subject to these constraints:
- At most `maxBoxes` boxes on the truck at once.
- Total truck weight ≤ `maxWeight`.
- Boxes must be delivered in the order they are given.
- Multiple boxes to same port should be delivered together for fewer trips.

You can return to the warehouse any number of times, and each port visit costs 1 trip.

Return the minimum number of trips required.

Example:
Input: boxes = [[1,1],[2,1],[1,1]], portsCount = 2, maxBoxes = 2, maxWeight = 3  
Output: 4

Explanation:
- Trip 1: Deliver [1,1] and [2,1] → 2 port visits (ports 1 and 2), return to warehouse.
- Trip 2: Deliver [1,1] → 1 port visit (port 1), return to warehouse.
- Total trips = 4

Constraints:
- 1 <= boxes.length <= 10^5
- Each box[i] has [port, weight]
- 1 <= port <= portsCount <= 10^4
- 1 <= maxBoxes, maxWeight <= 10^4
*/

#include <stdio.h>
#include <stdlib.h>

int boxDelivering(int** boxes, int boxesSize, int* boxesColSize, int portsCount, int maxBoxes, int maxWeight) {
    int* dp = (int*)malloc((boxesSize + 1) * sizeof(int));
    int j = 0, trips = 0, weight = 0;

    dp[0] = 0;

    for (int i = 1; i <= boxesSize; ++i) {
        weight += boxes[i - 1][1];
        if (i == 1 || boxes[i - 1][0] != boxes[i - 2][0]) ++trips;

        while (i - j > maxBoxes || weight > maxWeight || (j < i - 1 && dp[j] == dp[j + 1])) {
            weight -= boxes[j][1];
            if (boxes[j][0] != boxes[j + 1][0]) --trips;
            ++j;
        }

        dp[i] = dp[j] + trips + 1;
    }

    int result = dp[boxesSize];
    free(dp);
    return result;
}

// Sample test
int main() {
    int arr[][2] = {{1,1},{2,1},{1,1}};
    int portsCount = 2, maxBoxes = 2, maxWeight = 3;
    int boxesSize = sizeof(arr) / sizeof(arr[0]);

    int** boxes = malloc(boxesSize * sizeof(int*));
    int* boxesColSize = malloc(boxesSize * sizeof(int));
    for (int i = 0; i < boxesSize; i++) {
        boxes[i] = malloc(2 * sizeof(int));
        boxes[i][0] = arr[i][0];
        boxes[i][1] = arr[i][1];
        boxesColSize[i] = 2;
    }

    int result = boxDelivering(boxes, boxesSize, boxesColSize, portsCount, maxBoxes, maxWeight);
    printf("Minimum trips required: %d\n", result);

    for (int i = 0; i < boxesSize; i++) free(boxes[i]);
    free(boxes);
    free(boxesColSize);
    return 0;
}
