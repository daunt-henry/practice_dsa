/*
Problem: Employee Importance
URL: https://leetcode.com/problems/employee-importance/

Each employee has:
 - an ID
 - an importance value
 - a list of subordinates (by ID)

Goal: Given an ID, return the total importance of this employee and all subordinates.

Approach:
1. Build a map from ID -> Employee*
2. Use DFS to recursively sum importance.
3. Alternatively, BFS (queue) works as well.

Time Complexity: O(N)
Space Complexity: O(N)
*/

#include <bits/stdc++.h>
using namespace std;

class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
    Employee(int i, int imp, vector<int> subs) : id(i), importance(imp), subordinates(subs) {}
};

class Solution {
public:
    int dfs(unordered_map<int, Employee*>& mp, int id) {
        Employee* e = mp[id];
        int total = e->importance;
        for (int sub : e->subordinates) {
            total += dfs(mp, sub);
        }
        return total;
    }

    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> mp;
        for (auto e : employees) {
            mp[e->id] = e;
        }
        return dfs(mp, id);
    }
};

// ---------------- Demo ----------------
int main() {
    // Example:
    // Employee 1: importance=5, subordinates={2,3}
    // Employee 2: importance=3
    // Employee 3: importance=3

    Employee* e1 = new Employee(1, 5, {2, 3});
    Employee* e2 = new Employee(2, 3, {});
    Employee* e3 = new Employee(3, 3, {});

    vector<Employee*> employees = {e1, e2, e3};

    Solution sol;
    int result = sol.getImportance(employees, 1);
    cout << "Total importance for ID=1: " << result << " (expected 11)" << endl;

    // Free memory
    delete e1;
    delete e2;
    delete e3;

    return 0;
}
