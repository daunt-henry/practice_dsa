/*
Problem: Minimum Number of Moves to Seat Everyone

You are given two arrays:
- seats: representing positions of seats
- students: representing positions of students

You need to move each student to a seat, with the goal to minimize the total number of moves.
A move is defined as moving a student from position x to y and it costs |x - y|.

Example:
Input: seats = [3,1,5], students = [2,7,4]
Output: 4

Explanation:
Assign student at 2 -> seat at 1 (1 move)
Assign student at 4 -> seat at 3 (1 move)
Assign student at 7 -> seat at 5 (2 moves)
Total = 4

Approach:
Sort both arrays, then match each student to a seat by index.
*/

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int minMovesToSeat(int* seats, int seatsSize, int* students, int studentsSize) {
    qsort(seats, seatsSize, sizeof(int), cmp);
    qsort(students, studentsSize, sizeof(int), cmp);

    int moves = 0;
    for (int i = 0; i < seatsSize; i++) {
        moves += abs(seats[i] - students[i]);
    }
    return moves;
}
