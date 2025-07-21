/*
Title: Longest Absolute File Path

Problem:
Given a string representing a file system in the following format, 
return the length of the longest absolute path to a file within it.

Input is a string with '\n' separating lines and '\t' representing indentation levels (i.e., depth).

Each line is either:
- A directory name (no '.')
- A file name (contains '.')

Example Input:
"dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext"

Visual Representation:
dir
├── subdir1
└── subdir2
    └── file.ext

Expected Output:
20

Explanation:
The longest path is "dir/subdir2/file.ext" and its length is 20 characters.

*/

#include <stdio.h>
#include <string.h>

int lengthLongestPath(char* input) {
    int maxLen = 0;
    int pathLen[100] = {0};  // pathLen[i] = total length up to depth i

    char *line = input;
    while (*line) {
        int depth = 0;
        while (*line == '\t') {
            depth++;
            line++;
        }

        char *nameStart = line;
        int isFile = 0, len = 0;
        while (*line && *line != '\n') {
            if (*line == '.') isFile = 1;
            line++;
            len++;
        }

        if (isFile) {
            int fullPathLen = pathLen[depth] + len;
            if (fullPathLen > maxLen) maxLen = fullPathLen;
        } else {
            pathLen[depth + 1] = pathLen[depth] + len + 1;  // +1 for '/'
        }

        if (*line == '\n') line++;
    }

    return maxLen;
}

// Example test
int main() {
    char input[] = "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext";
    int result = lengthLongestPath(input);
    printf("Longest absolute file path length: %d\n", result);  // Output: 20
    return 0;
}
