/*
Problem: Course Schedule

You are given `numCourses` courses labeled from 0 to numCourses - 1 and a list of `prerequisites` where prerequisites[i] = [ai, bi] indicates that you must take course `bi` before course `ai`.

Return true if you can finish all courses. Otherwise, return false.

Example:
Input:
    numCourses = 2,
    prerequisites = [[1,0]]
Output:
    true
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {
    int* indegree = (int*)calloc(numCourses, sizeof(int));
    int** graph = (int**)malloc(numCourses * sizeof(int*));
    int* graphColSize = (int*)calloc(numCourses, sizeof(int));

    for (int i = 0; i < numCourses; ++i) {
        graph[i] = (int*)malloc(1000 * sizeof(int));  // max possible edges per course
    }

    for (int i = 0; i < prerequisitesSize; ++i) {
        int course = prerequisites[i][0];
        int prereq = prerequisites[i][1];
        graph[prereq][graphColSize[prereq]++] = course;
        indegree[course]++;
    }

    int* queue = (int*)malloc(numCourses * sizeof(int));
    int front = 0, rear = 0;

    for (int i = 0; i < numCourses; ++i) {
        if (indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    int visited = 0;
    while (front < rear) {
        int node = queue[front++];
        visited++;
        for (int i = 0; i < graphColSize[node]; ++i) {
            int neighbor = graph[node][i];
            if (--indegree[neighbor] == 0) {
                queue[rear++] = neighbor;
            }
        }
    }

    for (int i = 0; i < numCourses; ++i) {
        free(graph[i]);
    }
    free(graph);
    free(graphColSize);
    free(indegree);
    free(queue);

    return visited == numCourses;
}

// Sample Test
int main() {
    int numCourses = 2;
    int prerequisitesSize = 1;
    int prerequisitesColSize[] = {2};
    int** prerequisites = (int**)malloc(sizeof(int*) * prerequisitesSize);
    prerequisites[0] = (int*)malloc(sizeof(int) * 2);
    prerequisites[0][0] = 1;
    prerequisites[0][1] = 0;

    bool result = canFinish(numCourses, prerequisites, prerequisitesSize, prerequisitesColSize);
    printf("Can finish courses: %s\n", result ? "true" : "false");

    free(prerequisites[0]);
    free(prerequisites);
    return 0;
}
