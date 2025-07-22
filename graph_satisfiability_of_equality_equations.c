/*
Problem: Satisfiability of Equality Equations

You are given an array of strings equations that represent relationships 
between variables where each string equations[i] is of the form "a==b" or "a!=b".

Return true if it is possible to assign integers to variable names 
so as to satisfy all the given equations, or false otherwise.

Example:
Input: equations = ["a==b","b!=a"]
Output: false
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int find(int* parent, int x) {
    if (parent[x] != x)
        parent[x] = find(parent, parent[x]);
    return parent[x];
}

void unionSet(int* parent, int x, int y) {
    int rootx = find(parent, x);
    int rooty = find(parent, y);
    if (rootx != rooty)
        parent[rootx] = rooty;
}

bool equationsPossible(char** equations, int equationsSize) {
    int parent[26];
    for (int i = 0; i < 26; i++) parent[i] = i;

    // First, process all '==' equations
    for (int i = 0; i < equationsSize; i++) {
        if (equations[i][1] == '=')
            unionSet(parent, equations[i][0] - 'a', equations[i][3] - 'a');
    }

    // Then, process all '!=' equations and check for conflict
    for (int i = 0; i < equationsSize; i++) {
        if (equations[i][1] == '!')
            if (find(parent, equations[i][0] - 'a') == find(parent, equations[i][3] - 'a'))
                return false;
    }

    return true;
}

// Sample Test
int main() {
    char* equations[] = {"a==b", "b!=a"};
    int n = sizeof(equations) / sizeof(equations[0]);
    bool result = equationsPossible(equations, n);
    printf("Output: %s\n", result ? "true" : "false");  // Output: false
    return 0;
}
