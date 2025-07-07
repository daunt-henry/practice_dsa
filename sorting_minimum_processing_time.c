/*
Problem:
You are given `n` processors and `4 * n` tasks.
Each processor has a setup time from `processorTime[]` and can handle exactly 4 tasks.
Each task has a time from the `tasks[]` array.
You must assign 4 tasks per processor such that the processing time is minimized.

Processing time = max over all processors of (setup time + max of their 4 tasks)

Example Input:
processorTime = [2, 3]
tasks = [3, 1, 4, 2, 8, 5, 6, 7]

Expected Output:
Minimum Processing Time: 10
*/

#include <stdio.h>
#include <stdlib.h>

int cmpAsc(const void* a, const void* b) {
    return (*(int*)a) - (*(int*)b);
}

int cmpDesc(const void* a, const void* b) {
    return (*(int*)b) - (*(int*)a);
}

int minProcessingTime(int* processorTime, int processorTimeSize, int* tasks, int tasksSize) {
    qsort(processorTime, processorTimeSize, sizeof(int), cmpAsc);
    qsort(tasks, tasksSize, sizeof(int), cmpDesc);

    int maxTime = 0, j = 0;
    for (int i = 0; i < processorTimeSize; ++i) {
        int curMax = 0;
        for (int k = 0; k < 4; ++k) {
            curMax = tasks[j++] > curMax ? tasks[j - 1] : curMax;
        }
        int time = processorTime[i] + curMax;
        maxTime = time > maxTime ? time : maxTime;
    }
    return maxTime;
}

int main() {
    int processorTime[] = {2, 3};
    int tasks[] = {3, 1, 4, 2, 8, 5, 6, 7};
    int result = minProcessingTime(processorTime, 2, tasks, 8);
    printf("Minimum Processing Time: %d\n", result);
    return 0;
}
