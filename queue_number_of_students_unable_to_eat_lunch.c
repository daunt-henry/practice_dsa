/*
Title: Number of Students Unable to Eat Lunch

Problem:
The school cafeteria offers lunch to students. There are n students and n sandwiches. 
Each student prefers either a circular (0) or a square (1) sandwich.

The sandwiches are placed in a stack. At each step:
- If the student at the front of the queue prefers the sandwich on the top, they take it and leave.
- Otherwise, they move to the end of the queue.

Return the number of students who are unable to eat.

Example:
Input: students = [1,1,0,0], sandwiches = [0,1,0,1]
Output: 0

Input: students = [1,1,1,0,0,1], sandwiches = [1,0,0,0,1,1]
Output: 3

Constraints:
- 1 <= students.length, sandwiches.length <= 100
- students.length == sandwiches.length
- students[i] is 0 or 1
- sandwiches[i] is 0 or 1
*/

#include <stdio.h>

int countStudents(int* students, int studentsSize, int* sandwiches, int sandwichesSize) {
    int count[2] = {0}; // 0 -> circular, 1 -> square

    for (int i = 0; i < studentsSize; i++) {
        count[students[i]]++;
    }

    for (int i = 0; i < sandwichesSize; i++) {
        if (count[sandwiches[i]] == 0) {
            return sandwichesSize - i;
        }
        count[sandwiches[i]]--;
    }

    return 0;
}

// Sample test
int main() {
    int students[] = {1, 1, 1, 0, 0, 1};
    int sandwiches[] = {1, 0, 0, 0, 1, 1};
    int n = sizeof(students) / sizeof(students[0]);

    int result = countStudents(students, n, sandwiches, n);
    printf("Number of students unable to eat: %d\n", result); // Output: 3

    return 0;
}
