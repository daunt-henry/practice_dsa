/*
Title: Crawler Log Folder

Description:
  The file system keeps a log of every folder access as a list of strings.
  Each log entry is one of the following:
    - "../" : Move to parent directory (if not at root).
    - "./"  : Stay in the current directory.
    - "x/"  : Move into a child directory named x.

  Task:
    Given a list of these logs, return the minimum number of operations 
    to return to the root folder.

Example:
  Input: logs = ["d1/", "d2/", "../", "d21/", "./"]
  Output: 2

Approach:
  - Simulate folder movement with a depth counter.
  - "../" decreases depth (unless already at root),
    "./" keeps depth unchanged,
    "x/" increases depth.

*/

#include <stdio.h>
#include <string.h>

int minOperations(char ** logs, int logsSize){
    int depth = 0;
    for (int i = 0; i < logsSize; i++) {
        if (strcmp(logs[i], "../") == 0) {
            if (depth > 0) depth--;
        } else if (strcmp(logs[i], "./") != 0) {
            depth++;
        }
    }
    return depth;
}

int main() {
    char *logs[] = {"d1/", "d2/", "../", "d21/", "./"};
    int size = sizeof(logs) / sizeof(logs[0]);
    int result = minOperations(logs, size);
    printf("Minimum operations to reach root: %d\n", result);  // Output: 2
    return 0;
}
