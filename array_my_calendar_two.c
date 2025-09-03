/*
Problem: My Calendar II
URL: https://leetcode.com/problems/my-calendar-ii/

Design a calendar that can book new events, allowing double bookings but rejecting triple bookings.

Approach:
- Maintain two dynamic arrays of intervals:
   1. singles     — all booked events.
   2. doubles     — overlapping segments between booked events.
- On each booking:
   * If it overlaps a double-booked segment → reject.
   * Else, record any overlaps with singles as new doubles.
   * Then add the booking to singles.

Time Complexity: O(N^2)
Space Complexity: O(N)
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct { int start, end; } Interval;

typedef struct {
    Interval* singles;
    int singleCount, singleCap;
    Interval* doubles;
    int doubleCount, doubleCap;
} MyCalendarTwo;

MyCalendarTwo* myCalendarTwoCreate() {
    MyCalendarTwo* obj = malloc(sizeof(MyCalendarTwo));
    obj->singleCap = obj->doubleCap = 1000;
    obj->singleCount = obj->doubleCount = 0;
    obj->singles = malloc(obj->singleCap * sizeof(Interval));
    obj->doubles = malloc(obj->doubleCap * sizeof(Interval));
    return obj;
}

bool myCalendarTwoBook(MyCalendarTwo* obj, int start, int end) {
    // Check against existing double bookings
    for (int i = 0; i < obj->doubleCount; i++) {
        if (start < obj->doubles[i].end && obj->doubles[i].start < end) {
            return false;
        }
    }
    // Record new overlaps
    for (int i = 0; i < obj->singleCount; i++) {
        int s = obj->singles[i].start, e = obj->singles[i].end;
        if (start < e && s < end) {
            int ovS = start > s ? start : s;
            int ovE = end < e ? end : e;
            obj->doubles[obj->doubleCount++] = (Interval){ovS, ovE};
        }
    }
    // Add booking
    obj->singles[obj->singleCount++] = (Interval){start, end};
    return true;
}

void myCalendarTwoFree(MyCalendarTwo* obj) {
    free(obj->singles);
    free(obj->doubles);
    free(obj);
}

int main(void) {
    MyCalendarTwo* cal = myCalendarTwoCreate();

    printf("book(10,20): %s (expected: true)\n", myCalendarTwoBook(cal, 10,20) ? "true" : "false");
    printf("book(50,60): %s (expected: true)\n", myCalendarTwoBook(cal, 50,60) ? "true" : "false");
    printf("book(10,40): %s (expected: true)\n", myCalendarTwoBook(cal, 10,40) ? "true" : "false");
    printf("book(5,15): %s (expected: false)\n", myCalendarTwoBook(cal, 5,15) ? "true" : "false");
    printf("book(5,10): %s (expected: true)\n", myCalendarTwoBook(cal, 5,10) ? "true" : "false");
    printf("book(25,55): %s (expected: true)\n", myCalendarTwoBook(cal, 25,55) ? "true" : "false");

    myCalendarTwoFree(cal);
    return 0;
}
