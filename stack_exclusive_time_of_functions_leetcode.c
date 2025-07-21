/*
Exclusive Time of Functions

You're given the number of functions `n`, and an array of logs representing function start and end times.
Each log string is in the format "function_id:start_or_end:timestamp".

Return the exclusive time of each function, i.e., time spent in the function excluding time spent in child calls.

Example:
Input:
n = 2,
logs = [
  "0:start:0",
  "1:start:2",
  "1:end:5",
  "0:end:6"
]
Output: [3, 4]
Explanation:
Function 0 starts at 0 and resumes at 6, but function 1 runs from 2 to 5.
So:
- Function 0 time = (2-0) + (6-5) = 3
- Function 1 time = (5-2+1) = 4
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* exclusiveTime(int n, char ** logs, int logsSize, int* returnSize) {
    int* result = (int*)calloc(n, sizeof(int));
    int* stack = (int*)malloc(sizeof(int) * logsSize);
    int top = -1;
    int prevTime = 0;

    for (int i = 0; i < logsSize; ++i) {
        char* log = logs[i];
        int id = 0, time = 0;
        char type[6];
        sscanf(log, "%d:%5[^:]:%d", &id, type, &time);

        if (type[0] == 's') {
            if (top != -1) {
                result[stack[top]] += time - prevTime;
            }
            stack[++top] = id;
            prevTime = time;
        } else {
            result[stack[top--]] += time - prevTime + 1;
            prevTime = time + 1;
        }
    }

    *returnSize = n;
    free(stack);
    return result;
}

// Test case
int main() {
    int n = 2;
    char* logs[] = {
        "0:start:0",
        "1:start:2",
        "1:end:5",
        "0:end:6"
    };
    int size;
    int* result = exclusiveTime(n, logs, 4, &size);

    for (int i = 0; i < size; i++) {
        printf("Function %d exclusive time: %d\n", i, result[i]);
    }

    free(result);
    return 0;
}
