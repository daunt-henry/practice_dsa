/*
Longest Common Prefix

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example:
Input: strs = ["flower","flow","flight"]
Output: "fl"

Filename: longest_common_prefix.c
*/

#include <stdio.h>
#include <string.h>

// Function to find longest common prefix
char* longestCommonPrefix(char** strs, int strsSize){
    if (strsSize == 0) return "";

    for (int i = 0; ; i++) {
        char c = strs[0][i];
        if (c == '\0') return strs[0];

        for (int j = 1; j < strsSize; j++) {
            if (strs[j][i] != c || strs[j][i] == '\0') {
                strs[0][i] = '\0';
                return strs[0];
            }
        }
    }
}

// Sample test
int main() {
    char* words[] = {"flower", "flow", "flight"};
    int size = sizeof(words) / sizeof(words[0]);

    char* prefix = longestCommonPrefix(words, size);
    printf("Longest Common Prefix: \"%s\"\n", prefix);  // Output: "fl"

    return 0;
}
