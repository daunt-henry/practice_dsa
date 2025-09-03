/*
Problem: My Calendar I
URL: https://leetcode.com/problems/my-calendar-i/

Description:
Implement MyCalendar to book events without overlapping.
Each booking is an interval [start, end). Return true if it can be booked, 
or false if it conflicts with an existing booking.

Approach:
- Store intervals in an array inside MyCalendar struct.
- For each booking, check all existing intervals for overlap.
- If no conflict, add the booking.

Time Complexity: O(N^2) worst-case
Space Complexity: O(N)
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int start;
    int end;
} Interval;

typedef struct {
    Interval* bookings;
    int size;
    int cap;
} MyCalendar;

MyCalendar* myCalendarCreate() {
    MyCalendar* obj = malloc(sizeof(MyCalendar));
    obj->cap = 1000;
    obj->size = 0;
    obj->bookings = malloc(obj->cap * sizeof(Interval));
    return obj;
}

bool myCalendarBook(MyCalendar* obj, int start, int end) {
    for (int i = 0; i < obj->size; i++) {
        if (start < obj->bookings[i].end && obj->bookings[i].start < end) {
            return false;
        }
    }
    obj->bookings[obj->size++] = (Interval){start, end};
    return true;
}

void myCalendarFree(MyCalendar* obj) {
    free(obj->bookings);
    free(obj);
}

int main(void) {
    MyCalendar* cal = myCalendarCreate();

    printf("book(10,20): %s (expected: true)\n", myCalendarBook(cal, 10,20) ? "true" : "false");
    printf("book(15,25): %s (expected: false)\n", myCalendarBook(cal, 15,25) ? "true" : "false");
    printf("book(20,30): %s (expected: true)\n", myCalendarBook(cal, 20,30) ? "true" : "false");

    myCalendarFree(cal);
    return 0;
}
