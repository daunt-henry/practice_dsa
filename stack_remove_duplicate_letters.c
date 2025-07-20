// Remove Duplicate Letters
// Returns the lexicographically smallest string after removing duplicate letters
// ensuring each letter appears once and only once.

#include <stdio.h>

// Removes duplicate letters to form smallest lexicographic string
char* removeDuplicateLetters(char* s) {
    int count[26] = {0};     // Frequency count
    int visited[26] = {0};   // Tracks letters in stack
    static char stack[10001];
    int top = -1;

    // Count occurrences of each character
    for (int i = 0; s[i]; i++) {
        count[s[i] - 'a']++;
    }

    // Process each character
    for (int i = 0; s[i]; i++) {
        char c = s[i];
        count[c - 'a']--;

        if (visited[c - 'a']) continue;

        while (top >= 0 && stack[top] > c && count[stack[top] - 'a'] > 0) {
            visited[stack[top--] - 'a'] = 0;
        }

        stack[++top] = c;
        visited[c - 'a'] = 1;
    }

    stack[top + 1] = '\0';
    return stack;
}

int main() {
    char input1[] = "bcabc";
    char input2[] = "cbacdcbc";

    printf("Result for \"%s\": %s\n", input1, removeDuplicateLetters(input1)); // Output: "abc"
    printf("Result for \"%s\": %s\n", input2, removeDuplicateLetters(input2)); // Output: "acdb"

    return 0;
}
