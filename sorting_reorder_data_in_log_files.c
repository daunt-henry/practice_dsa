/*
Problem:
You are given an array of log entries. Reorder so that:
- All letter-logs come before digit-logs
- Letter-logs are sorted lexicographically by content, then identifier
- Digit-logs remain in original order

Approach:
- Detect if a log is a digit-log or letter-log
- Use custom comparator for sorting
- Digit-logs pushed to end using comparator logic

Time: O(n log n) due to sort
Space: O(1) (in-place)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int isDigitLog(const char* log) {
    while (*log && *log != ' ') log++; // skip identifier
    log++; // skip space
    return isdigit(*log);
}

int logCompare(const void* a, const void* b) {
    char* log1 = *(char**)a;
    char* log2 = *(char**)b;

    int isDigit1 = isDigitLog(log1);
    int isDigit2 = isDigitLog(log2);

    if (!isDigit1 && !isDigit2) {
        char* id1 = strchr(log1, ' ');
        char* id2 = strchr(log2, ' ');
        int cmp = strcmp(id1, id2);
        if (cmp != 0) return cmp;
        return strcmp(log1, log2);
    } else if (!isDigit1 && isDigit2) {
        return -1;
    } else if (isDigit1 && !isDigit2) {
        return 1;
    } else {
        return 0;
    }
}

char** reorderLogFiles(char** logs, int logsSize, int* returnSize) {
    qsort(logs, logsSize, sizeof(char*), logCompare);
    *returnSize = logsSize;
    return logs;
}

// Test
int main() {
    char* logs[] = {
        "dig1 8 1 5 1",
        "let1 art can",
        "dig2 3 6",
        "let2 own kit dig",
        "let3 art zero"
    };
    int size = sizeof(logs) / sizeof(logs[0]);
    int returnSize;

    char** result = reorderLogFiles(logs, size, &returnSize);

    printf("Output:\n");
    for (int i = 0; i < returnSize; i++) {
        printf("%s\n", result[i]);
    }

    return 0;
}

/*
========= OUTPUT =========
let1 art can
let3 art zero
let2 own kit dig
dig1 8 1 5 1
dig2 3 6
==========================
*/
