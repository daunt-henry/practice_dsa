/*
Title: Daily Temperatures

Description:
  Given an array of integers `temperatures` representing the daily temperatures,
  return an array `answer` such that `answer[i]` is the number of days you have to wait after the ith day
  to get a warmer temperature. If there is no future day for which this is possible, put 0 instead.

Example Input:
  temperatures = [73, 74, 75, 71, 69, 72, 76, 73]

Example Output:
  [1, 1, 4, 2, 1, 1, 0, 0]

Explanation:
  - Day 0: Wait 1 day (74)
  - Day 1: Wait 1 day (75)
  - Day 2: Wait 4 days (76)
  - Day 3: Wait 2 days (72)
  - Day 4: Wait 1 day (72)
  - Day 5: Wait 1 day (76)
  - Day 6: No warmer day
  - Day 7: No warmer day
*/

#include <stdio.h>
#include <stdlib.h>

int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    int* res = (int*)calloc(temperaturesSize, sizeof(int));
    int* stack = (int*)malloc(temperaturesSize * sizeof(int));
    int top = -1;

    for (int i = temperaturesSize - 1; i >= 0; i--) {
        while (top != -1 && temperatures[i] >= temperatures[stack[top]]) {
            top--;
        }
        if (top != -1) {
            res[i] = stack[top] - i;
        }
        stack[++top] = i;
    }

    *returnSize = temperaturesSize;
    free(stack);
    return res;
}

int main() {
    int temps[] = {73, 74, 75, 71, 69, 72, 76, 73};
    int n = sizeof(temps) / sizeof(temps[0]);
    int returnSize = 0;

    int* result = dailyTemperatures(temps, n, &returnSize);

    printf("Output: [");
    for (int i = 0; i < returnSize; ++i) {
        printf("%d", result[i]);
        if (i != returnSize - 1) printf(", ");
    }
    printf("]\n");

    free(result);
    return 0;
}
