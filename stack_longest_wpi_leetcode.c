/*
Title: Longest Well-Performing Interval

Description:
  Given an array hours representing the number of hours an employee worked per day,
  we define a well-performing interval as an interval where the number of tiring days
  (working more than 8 hours) is strictly greater than the number of non-tiring days.

  Return the length of the longest well-performing interval.

Example Input:
  hours = [9,9,6,0,6,6,9]

Example Output:
  3

Explanation:
  The interval [9,9,6] has two tiring days and one non-tiring day.
*/

#include <stdio.h>
#include <stdlib.h>

int longestWPI(int* hours, int hoursSize) {
    int* prefix = (int*)malloc((hoursSize + 1) * sizeof(int));
    prefix[0] = 0;
    for (int i = 0; i < hoursSize; ++i) {
        prefix[i + 1] = prefix[i] + (hours[i] > 8 ? 1 : -1);
    }

    int* stack = (int*)malloc((hoursSize + 1) * sizeof(int));
    int top = 0;
    stack[top++] = 0;

    for (int i = 1; i <= hoursSize; ++i) {
        if (prefix[i] < prefix[stack[top - 1]]) {
            stack[top++] = i;
        }
    }

    int res = 0;
    for (int i = hoursSize; i >= 0; --i) {
        while (top > 0 && prefix[i] > prefix[stack[top - 1]]) {
            if (res < i - stack[top - 1]) {
                res = i - stack[top - 1];
            }
            top--;
        }
    }

    free(prefix);
    free(stack);
    return res;
}

int main() {
    int hours[] = {9, 9, 6, 0, 6, 6, 9};
    int size = sizeof(hours) / sizeof(hours[0]);

    int result = longestWPI(hours, size);
    printf("Input: [9, 9, 6, 0, 6, 6, 9]\n");
    printf("Output: %d\n", result);  // Expected: 3

    return 0;
}
