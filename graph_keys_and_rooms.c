/*
Title: Keys and Rooms

There are `n` rooms labeled from 0 to n - 1 and you start in room 0. 
Each room may contain keys to other rooms. 
Return true if you can visit all the rooms, otherwise return false.

Example:
Input: rooms = [[1],[2],[3],[]]
Output: true
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void dfs(int** rooms, int* roomsColSize, int room, bool* visited, int roomsSize) {
    if (visited[room]) return;
    visited[room] = true;

    for (int i = 0; i < roomsColSize[room]; ++i) {
        int key = rooms[room][i];
        dfs(rooms, roomsColSize, key, visited, roomsSize);
    }
}

bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize) {
    bool* visited = (bool*)calloc(roomsSize, sizeof(bool));
    dfs(rooms, roomsColSize, 0, visited, roomsSize);

    for (int i = 0; i < roomsSize; ++i) {
        if (!visited[i]) {
            free(visited);
            return false;
        }
    }

    free(visited);
    return true;
}

// Sample test
int main() {
    int data[4][3] = {{1}, {2}, {3}, {}};
    int sizes[] = {1, 1, 1, 0};
    int** rooms = (int**)malloc(sizeof(int*) * 4);
    for (int i = 0; i < 4; ++i) {
        rooms[i] = (int*)malloc(sizeof(int) * sizes[i]);
        for (int j = 0; j < sizes[i]; ++j) {
            rooms[i][j] = data[i][j];
        }
    }

    bool result = canVisitAllRooms(rooms, 4, sizes);
    printf("Output: %s\n", result ? "true" : "false");

    for (int i = 0; i < 4; ++i) free(rooms[i]);
    free(rooms);

    return 0;
}
