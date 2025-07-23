/*
Get Watched Videos by Your Friends

You have a list of videos watched by each user and a friendship graph.
Given your ID and a level, return the list of videos watched by friends at that level,
sorted by frequency and then lexicographically.

Example:
Input:
watchedVideos = [["A","B"],["C"],["B","C"],["D"]]
friends = [[1,2],[0,3],[0,3],[1,2]]
id = 0
level = 1

Output:
["B","C"]
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_VIDEOS 10000

typedef struct {
    char* name;
    int freq;
} VideoFreq;

int compare(const void* a, const void* b) {
    VideoFreq* va = (VideoFreq*)a;
    VideoFreq* vb = (VideoFreq*)b;
    if (va->freq != vb->freq) return va->freq - vb->freq;
    return strcmp(va->name, vb->name);
}

char** watchedVideosByFriends(char*** watchedVideos, int watchedVideosSize, int* watchedVideosColSize, int** friends, int friendsSize, int* friendsColSize, int id, int level, int* returnSize) {
    int visited[MAX_USERS] = {0};
    int queue[MAX_USERS];
    int front = 0, back = 0;
    visited[id] = 1;
    queue[back++] = id;

    // BFS to get friends at specific level
    for (int l = 0; l < level; l++) {
        int len = back - front;
        for (int i = 0; i < len; i++) {
            int u = queue[front++];
            for (int j = 0; j < friendsColSize[u]; j++) {
                int v = friends[u][j];
                if (!visited[v]) {
                    visited[v] = 1;
                    queue[back++] = v;
                }
            }
        }
    }

    // Count frequencies
    VideoFreq map[MAX_VIDEOS];
    int mapSize = 0;

    for (int i = front; i < back; i++) {
        int friendId = queue[i];
        for (int j = 0; j < watchedVideosColSize[friendId]; j++) {
            char* video = watchedVideos[friendId][j];
            int found = 0;
            for (int k = 0; k < mapSize; k++) {
                if (strcmp(map[k].name, video) == 0) {
                    map[k].freq++;
                    found = 1;
                    break;
                }
            }
            if (!found) {
                map[mapSize].name = video;
                map[mapSize].freq = 1;
                mapSize++;
            }
        }
    }

    qsort(map, mapSize, sizeof(VideoFreq), compare);

    char** result = (char**)malloc(sizeof(char*) * mapSize);
    for (int i = 0; i < mapSize; i++) {
        result[i] = map[i].name;
    }

    *returnSize = mapSize;
    return result;
}

int main() {
    char* user0[] = {"A", "B"};
    char* user1[] = {"C"};
    char* user2[] = {"B", "C"};
    char* user3[] = {"D"};
    char** watchedVideos[] = {user0, user1, user2, user3};
    int watchedVideosColSize[] = {2, 1, 2, 1};

    int f0[] = {1, 2};
    int f1[] = {0, 3};
    int f2[] = {0, 3};
    int f3[] = {1, 2};
    int* friends[] = {f0, f1, f2, f3};
    int friendsColSize[] = {2, 2, 2, 2};

    int returnSize;
    char** result = watchedVideosByFriends(watchedVideos, 4, watchedVideosColSize, friends, 4, friendsColSize, 0, 1, &returnSize);

    printf("Watched videos at level 1:\n");
    for (int i = 0; i < returnSize; i++) {
        printf("%s\n", result[i]);
    }

    return 0;
}
