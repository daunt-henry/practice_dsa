/*
Problem:
You are given two strings s1 and s2 of equal length.
You can swap any even-indexed characters with other even-indexed characters,
and odd-indexed characters with other odd-indexed characters, any number of times.

Return true if s1 can be transformed into s2 using any number of such operations.

Example Input:
s1 = "abcd"
s2 = "cdab"

Expected Output:
true
*/

#include <stdio.h>
#include <stdbool.h>

bool checkStrings(char* s1, char* s2) {
    int count1[2][26] = {0};
    int count2[2][26] = {0};

    for (int i = 0; s1[i]; ++i) {
        count1[i % 2][s1[i] - 'a']++;
        count2[i % 2][s2[i] - 'a']++;
    }

    for (int i = 0; i < 26; ++i) {
        if (count1[0][i] != count2[0][i] || count1[1][i] != count2[1][i])
            return false;
    }

    return true;
}

int main() {
    char s1[] = "abcd";
    char s2[] = "cdab";

    if (checkStrings(s1, s2))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}
