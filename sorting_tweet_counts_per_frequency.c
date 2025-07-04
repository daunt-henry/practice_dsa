/*
Tweet Counts Per Frequency

Design an object to:
1. Record tweets with names and times.
2. Retrieve counts of tweets for a given frequency interval (minute, hour, day) between time ranges.

Approach:
- Use an array of structs to simulate a class in C.
- Each struct stores tweet name, times[] and count.
- On query, sort the times and count tweets in proper intervals.

Example:
Input:
RecordTweet("tweet3", 0)
RecordTweet("tweet3", 60)
RecordTweet("tweet3", 10)
GetTweetCountsPerFrequency("minute", "tweet3", 0, 59)

Output:
[2]

GetTweetCountsPerFrequency("hour", "tweet3", 0, 210)

Output:
[3]
*/

#include <stdlib.h>
#include <string.h>

#define MAX_TWEETS 10000
#define MAX_NAME_LEN 101

typedef struct {
    char name[MAX_NAME_LEN];
    int times[MAX_TWEETS];
    int count;
} Tweet;

typedef struct {
    Tweet tweets[1000];
    int tweetCount;
} TweetCounts;

TweetCounts* tweetCountsCreate() {
    TweetCounts* obj = (TweetCounts*)malloc(sizeof(TweetCounts));
    obj->tweetCount = 0;
    return obj;
}

void tweetCountsRecordTweet(TweetCounts* obj, char* tweetName, int time) {
    for (int i = 0; i < obj->tweetCount; ++i) {
        if (strcmp(obj->tweets[i].name, tweetName) == 0) {
            obj->tweets[i].times[obj->tweets[i].count++] = time;
            return;
        }
    }

    strcpy(obj->tweets[obj->tweetCount].name, tweetName);
    obj->tweets[obj->tweetCount].times[0] = time;
    obj->tweets[obj->tweetCount].count = 1;
    obj->tweetCount++;
}

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int* tweetCountsGetTweetCountsPerFrequency(TweetCounts* obj, char* freq, char* tweetName, int startTime, int endTime, int* returnSize) {
    int interval = 60;
    if (strcmp(freq, "hour") == 0) interval = 3600;
    else if (strcmp(freq, "day") == 0) interval = 86400;

    int size = (endTime - startTime) / interval + 1;
    int* result = (int*)calloc(size, sizeof(int));

    for (int i = 0; i < obj->tweetCount; ++i) {
        if (strcmp(obj->tweets[i].name, tweetName) == 0) {
            qsort(obj->tweets[i].times, obj->tweets[i].count, sizeof(int), compare);
            for (int j = 0; j < obj->tweets[i].count; ++j) {
                int t = obj->tweets[i].times[j];
                if (t >= startTime && t <= endTime) {
                    int index = (t - startTime) / interval;
                    result[index]++;
                }
            }
            break;
        }
    }

    *returnSize = size;
    return result;
}

void tweetCountsFree(TweetCounts* obj) {
    free(obj);
}
