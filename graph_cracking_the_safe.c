// Problem: Cracking the Safe
// Given two integers n and k, return any string of minimum length that contains every possible k-ary
// string of length n as a substring.
//
// Input: n = 2, k = 2
// Output: "00110" or any other valid de Bruijn sequence of length k^n + n - 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define MAX_LEN 1000000

void dfs(char* result, bool* visited, int n, int k, int* idx, int mod, int curr) {
    for (int i = 0; i < k; i++) {
        int next = curr * k + i;
        if (!visited[next]) {
            visited[next] = true;
            dfs(result, visited, n, k, idx, mod, next % mod);
            result[(*idx)++] = '0' + i;
        }
    }
}

char* crackSafe(int n, int k) {
    int mod = pow(k, n - 1);
    int total = pow(k, n);
    bool* visited = (bool*)calloc(total, sizeof(bool));
    char* result = (char*)malloc(total + n);
    int idx = 0;

    dfs(result, visited, n, k, &idx, mod, 0);

    for (int i = 0; i < n - 1; i++) {
        result[idx++] = '0';
    }

    result[idx] = '\0';
    free(visited);
    return result;
}

int main() {
    int n = 2, k = 2;
    char* result = crackSafe(n, k);
    printf("Output: %s\n", result);  // Example: "00110"
    free(result);
    return 0;
}
