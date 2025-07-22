/*
Problem: Course Schedule II

There are a total of `numCourses` courses you have to take, labeled from 0 to numCourses - 1. 
Some courses may have prerequisites, given as a list `prerequisites` where prerequisites[i] = [ai, bi] means you must take course `bi` before course `ai`.

Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. 
If it is impossible to finish all courses, return an empty array.

Example:
Input:
    numCourses = 4
    prerequisites = [[1,0],[2,0],[3,1],[3,2]]
Output:
    [0,2,1,3] or [0,1,2,3]
*/

#include <stdio.h>
#include <stdlib.h>

int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int* returnSize) {
    int* indegree = (int*)calloc(numCourses, sizeof(int));
    int** graph = (int**)malloc(numCourses * sizeof(int*));
    int* graphColSize = (int*)calloc(numCourses, sizeof(int));
    for (int i = 0; i < numCourses; ++i)
        graph[i] = (int*)malloc(1000 * sizeof(int));

    for (int i = 0; i < prerequisitesSize; ++i) {
        int course = prerequisites[i][0];
        int prereq = prerequisites[i][1];
        graph[prereq][graphColSize[prereq]++] = course;
        indegree[course]++;
    }

    int* queue = (int*)malloc(numCourses * sizeof(int));
    int front = 0, rear = 0;
    for (int i = 0; i < numCourses; ++i)
        if (indegree[i] == 0) queue[rear++] = i;

    int* order = (int*)malloc(numCourses * sizeof(int));
    int index = 0;

    while (front < rear) {
        int node = queue[front++];
        order[index++] = node;
        for (int i = 0; i < graphColSize[node]; ++i) {
            int next = graph[node][i];
            if (--indegree[next] == 0)
                queue[rear++] = next;
        }
    }

    *returnSize = (index == numCourses) ? numCourses : 0;
    for (int i = 0; i < numCourses; ++i) free(graph[i]);
    free(graph);
    free(graphColSize);
    free(indegree);
    free(queue);

    return (*returnSize == 0) ? NULL : order;
}

// Sample test
int main() {
    int numCourses = 4;
    int prerequisitesSize = 4;
    int prerequisitesColSize[] = {2, 2, 2, 2};

    int** prerequisites = (int**)malloc(sizeof(int*) * prerequisitesSize);
    int data[4][2] = {{1,0},{2,0},{3,1},{3,2}};
    for (int i = 0; i < prerequisitesSize; ++i) {
        prerequisites[i] = (int*)malloc(sizeof(int) * 2);
        prerequisites[i][0] = data[i][0];
        prerequisites[i][1] = data[i][1];
    }

    int returnSize = 0;
    int* result = findOrder(numCourses, prerequisites, prerequisitesSize, prerequisitesColSize, &returnSize);

    printf("Course Order: ");
    for (int i = 0; i < returnSize; ++i)
        printf("%d ", result[i]);
    printf("\n");

    for (int i = 0; i < prerequisitesSize; ++i) free(prerequisites[i]);
    free(prerequisites);
    free(result);

    return 0;
}
