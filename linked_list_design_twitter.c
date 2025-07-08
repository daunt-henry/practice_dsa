/*
Problem:
Design a simplified version of Twitter:
- postTweet(userId, tweetId): Compose a new tweet.
- getNewsFeed(userId): Retrieve the 10 most recent tweet IDs from the user and people they follow.
- follow(followerId, followeeId): Follower follows a user.
- unfollow(followerId, followeeId): Follower unfollows a user.

Constraints:
- All tweets must be ordered from most recent to least recent.
- You must retrieve at most 10 tweets.
- You must store and track follow relationships.

Example:
Input:
["Twitter","postTweet","getNewsFeed","follow","postTweet","getNewsFeed","unfollow","getNewsFeed"]
[[],[1,5],[1],[1,2],[2,6],[1],[1,2],[1]]

Output:
[null,null,[5],null,null,[6,5],null,[5]]

-----------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_USERS 501
#define MAX_TWEETS 10001
#define MAX_FOLLOWEES 501
#define FEED_LIMIT 10

typedef struct Tweet {
    int tweetId;
    int time;
    struct Tweet* next;
} Tweet;

typedef struct {
    Tweet* tweets[MAX_USERS];
    bool follows[MAX_USERS][MAX_USERS];
    int timestamp;
} Twitter;

// Create a new tweet node
Tweet* createTweet(int tweetId, int time) {
    Tweet* t = (Tweet*)malloc(sizeof(Tweet));
    t->tweetId = tweetId;
    t->time = time;
    t->next = NULL;
    return t;
}

// Comparator for max-heap behavior (latest tweets first)
int compare(const void* a, const void* b) {
    Tweet* t1 = *(Tweet**)a;
    Tweet* t2 = *(Tweet**)b;
    return t2->time - t1->time;
}

// Constructor
Twitter* twitterCreate() {
    Twitter* obj = (Twitter*)malloc(sizeof(Twitter));
    for (int i = 0; i < MAX_USERS; ++i) {
        obj->tweets[i] = NULL;
        for (int j = 0; j < MAX_USERS; ++j)
            obj->follows[i][j] = false;
    }
    obj->timestamp = 0;
    return obj;
}

// Post a tweet
void twitterPostTweet(Twitter* obj, int userId, int tweetId) {
    Tweet* t = createTweet(tweetId, obj->timestamp++);
    t->next = obj->tweets[userId];
    obj->tweets[userId] = t;
}

// Get news feed
int* twitterGetNewsFeed(Twitter* obj, int userId, int* retSize) {
    Tweet* heap[MAX_USERS * 10];
    int heapSize = 0;

    // Add own tweets
    Tweet* t = obj->tweets[userId];
    while (t && heapSize < MAX_TWEETS) {
        heap[heapSize++] = t;
        t = t->next;
    }

    // Add followed users' tweets
    for (int i = 0; i < MAX_USERS; ++i) {
        if (obj->follows[userId][i]) {
            t = obj->tweets[i];
            while (t && heapSize < MAX_TWEETS) {
                heap[heapSize++] = t;
                t = t->next;
            }
        }
    }

    qsort(heap, heapSize, sizeof(Tweet*), compare);

    int* result = (int*)malloc(sizeof(int) * FEED_LIMIT);
    int count = 0;
    for (int i = 0; i < heapSize && count < FEED_LIMIT; ++i)
        result[count++] = heap[i]->tweetId;

    *retSize = count;
    return result;
}

// Follow another user
void twitterFollow(Twitter* obj, int followerId, int followeeId) {
    if (followerId == followeeId) return;
    obj->follows[followerId][followeeId] = true;
}

// Unfollow a user
void twitterUnfollow(Twitter* obj, int followerId, int followeeId) {
    if (followerId == followeeId) return;
    obj->follows[followerId][followeeId] = false;
}

// Free memory
void twitterFree(Twitter* obj) {
    for (int i = 0; i < MAX_USERS; ++i) {
        Tweet* curr = obj->tweets[i];
        while (curr) {
            Tweet* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
    free(obj);
}

// Driver to demo Twitter
int main() {
    Twitter* twitter = twitterCreate();

    twitterPostTweet(twitter, 1, 5);
    int size1;
    int* feed1 = twitterGetNewsFeed(twitter, 1, &size1);
    printf("Feed 1: ");
    for (int i = 0; i < size1; i++) printf("%d ", feed1[i]);
    printf("\n");  // Expected: 5

    twitterFollow(twitter, 1, 2);
    twitterPostTweet(twitter, 2, 6);
    int size2;
    int* feed2 = twitterGetNewsFeed(twitter, 1, &size2);
    printf("Feed 2: ");
    for (int i = 0; i < size2; i++) printf("%d ", feed2[i]);
    printf("\n");  // Expected: 6 5

    twitterUnfollow(twitter, 1, 2);
    int size3;
    int* feed3 = twitterGetNewsFeed(twitter, 1, &size3);
    printf("Feed 3: ");
    for (int i = 0; i < size3; i++) printf("%d ", feed3[i]);
    printf("\n");  // Expected: 5

    free(feed1);
    free(feed2);
    free(feed3);
    twitterFree(twitter);
    return 0;
}
