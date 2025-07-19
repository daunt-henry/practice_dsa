/*
Title: Number of Recent Calls

You have a RecentCounter class that counts the number of recent requests within a 3000ms window.
Each time `ping(t)` is called, return the number of calls made from [t - 3000, t].

Example:
Input:
["RecentCounter", "ping", "ping", "ping", "ping"]
[[], [1], [100], [3001], [3002]]
Output:
[null, 1, 2, 3, 3]

Explanation:
- ping(1) -> 1
- ping(100) -> 2
- ping(3001) -> 3
- ping(3002) -> 3
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int queue[10000];
    int front;
    int rear;
} RecentCounter;

RecentCounter* recentCounterCreate() {
    RecentCounter* obj = malloc(sizeof(RecentCounter));
    obj->front = 0;
    obj->rear = 0;
    return obj;
}

int recentCounterPing(RecentCounter* obj, int t) {
    obj->queue[obj->rear++] = t;
    while (obj->queue[obj->front] < t - 3000) {
        obj->front++;
    }
    return obj->rear - obj->front;
}

void recentCounterFree(RecentCounter* obj) {
    free(obj);
}

int main() {
    RecentCounter* counter = recentCounterCreate();
    printf("%d\n", recentCounterPing(counter, 1));     // 1
    printf("%d\n", recentCounterPing(counter, 100));   // 2
    printf("%d\n", recentCounterPing(counter, 3001));  // 3
    printf("%d\n", recentCounterPing(counter, 3002));  // 3
    recentCounterFree(counter);
    return 0;
}
