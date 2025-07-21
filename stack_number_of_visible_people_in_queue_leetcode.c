/*
Title: Number of Visible People in a Queue

Description:
  There are n people in a queue, and each person can see the person in front of them
  if everyone between them is shorter. A person stops seeing others when someone
  equal or taller appears. Return an array representing the number of people
  each person can see in the queue.

Example:
  Input: heights = [10,6,8,5,11,9]
  Output: [3,1,2,1,1,0]

Approach:
  - Use a stack to simulate visibility from the end of the queue to the front.
  - Maintain a decreasing stack of heights.
  - For each person, count visible people in front based on height comparisons.

Constraints:
  - 1 <= heights.length <= 10^5
  - 1 <= heights[i] <= 10^5
*/

#include <stdio.h>
#include <stdlib.h>

int* canSeePersonsCount(int* heights, int heightsSize, int* returnSize) {
    int* res = (int*)calloc(heightsSize, sizeof(int));
    int* stack = (int*)malloc(sizeof(int) * heightsSize);
    int top = -1;

    for (int i = heightsSize - 1; i >= 0; --i) {
        while (top >= 0 && heights[i] > stack[top]) {
            res[i]++;
            top--;
        }
        if (top >= 0) res[i]++;
        stack[++top] = heights[i];
    }

    *returnSize = heightsSize;
    free(stack);
    return res;
}

int main() {
    int heights[] = {10, 6, 8, 5, 11, 9};
    int size = sizeof(heights) / sizeof(heights[0]);
    int returnSize = 0;

    int* result = canSeePersonsCount(heights, size, &returnSize);
    printf("Input: [10, 6, 8, 5, 11, 9]\nOutput: [");
    for (int i = 0; i < returnSize; ++i) {
        printf("%d%s", result[i], i < returnSize - 1 ? ", " : "");
    }
    printf("]\n");

    free(result);
    return 0;
}
